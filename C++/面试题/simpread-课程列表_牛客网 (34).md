> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [www.nowcoder.com](https://www.nowcoder.com/study/live/690/2/35)

> 牛客网是 IT 求职神器, 国内一流互联网公司面试中常见的算法题及考察点系统讲解，帮大家系统梳理面试所需要的算法知识，提高刷题效率，轻松搞定算法面试。

#### 4.3.3 MySQL 的 ACID 特性分别是怎么实现的？

**参考答案**

原子性实现原理：

实现原子性的关键，是当事务回滚时能够撤销所有已经成功执行的 sql 语句。InnoDB 实现回滚靠的是 undo log，当事务对数据库进行修改时，InnoDB 会生成对应的 undo log。如果事务执行失败或调用了 rollback，导致事务需要回滚，便可以利用 undo log 中的信息将数据回滚到修改之前的样子。

undo log 属于逻辑日志，它记录的是 sql 执行相关的信息。当发生回滚时，InnoDB 会根据 undo log 的内容做与之前相反的工作。对于 insert，回滚时会执行 delete。对于 delete，回滚时会执行 insert。对于 update，回滚时则会执行相反的 update，把数据改回去。

持久性实现原理：

InnoDB 作为 MySQL 的存储引擎，数据是存放在磁盘中的，但如果每次读写数据都需要磁盘 IO，效率会很低。为此，InnoDB 提供了缓存 (Buffer Pool)，Buffer Pool 中包含了磁盘中部分数据页的映射，作为访问数据库的缓冲。当从数据库读取数据时，会首先从 Buffer Pool 中读取，如果 Buffer Pool 中没有，则从磁盘读取后放入 Buffer Pool。当向数据库写入数据时，会首先写入 Buffer Pool，Buffer Pool 中修改的数据会定期刷新到磁盘中（这一过程称为刷脏）。

Buffer Pool 的使用大大提高了读写数据的效率，但是也带了新的问题：如果 MySQL 宕机，而此时 Buffer Pool 中修改的数据还没有刷新到磁盘，就会导致数据的丢失，事务的持久性无法保证。

于是，redo log 被引入来解决这个问题。当数据修改时，除了修改 Buffer Pool 中的数据，还会在 redo log 记录这次操作。当事务提交时，会调用 fsync 接口对 redo log 进行刷盘。如果 MySQL 宕机，重启时可以读取 redo log 中的数据，对数据库进行恢复。redo log 采用的是 WAL（Write-ahead logging，预写式日志），所有修改先写入日志，再更新到 Buffer Pool，保证了数据不会因 MySQL 宕机而丢失，从而满足了持久性要求。

既然 redo log 也需要在事务提交时将日志写入磁盘，为什么它比直接将 Buffer Pool 中修改的数据写入磁盘 (即刷脏) 要快呢？主要有以下两方面的原因：

*   刷脏是随机 IO，因为每次修改的数据位置随机，但写 redo log 是追加操作，属于顺序 IO。
*   刷脏是以数据页（Page）为单位的，MySQL 默认页大小是 16KB，一个 Page 上一个小修改都要整页写入。而 redo log 中只包含真正需要写入的部分，无效 IO 大大减少。

隔离性实现原理：

隔离性追求的是并发情形下事务之间互不干扰。简单起见，我们主要考虑最简单的读操作和写操作 (加锁读等特殊读操作会特殊说明)，那么隔离性的探讨，主要可以分为两个方面。

第一方面，(一个事务)写操作对 (另一个事务) 写操作的影响：锁机制保证隔离性。

隔离性要求同一时刻只能有一个事务对数据进行写操作，InnoDB 通过锁机制来保证这一点。锁机制的基本原理可以概括为：事务在修改数据之前，需要先获得相应的锁。获得锁之后，事务便可以修改数据。该事务操作期间，这部分数据是锁定的，其他事务如果需要修改数据，需要等待当前事务提交或回滚后释放锁。

按照粒度，锁可以分为表锁、行锁以及其他位于二者之间的锁。表锁在操作数据时会锁定整张表，并发性能较差。行锁则只锁定需要操作的数据，并发性能好。但是由于加锁本身需要消耗资源，因此在锁定数据较多情况下使用表锁可以节省大量资源。MySQL 中不同的存储引擎支持的锁是不一样的，例如 MyIsam 只支持表锁，而 InnoDB 同时支持表锁和行锁，且出于性能考虑，绝大多数情况下使用的都是行锁。

第二方面，(一个事务)写操作对 (另一个事务) 读操作的影响：MVCC 保证隔离性。

InnoDB 默认的隔离级别是 RR（REPEATABLE READ），RR 解决脏读、不可重复读、幻读等问题，使用的是 MVCC。MVCC 全称 Multi-Version Concurrency Control，即多版本的并发控制协议。它最大的优点是读不加锁，因此读写不冲突，并发性能好。InnoDB 实现 MVCC，多个版本的数据可以共存，主要基于以下技术及数据结构：

1.  隐藏列：InnoDB 中每行数据都有隐藏列，隐藏列中包含了本行数据的事务 id、指向 undo log 的指针等。
2.  基于 undo log 的版本链：每行数据的隐藏列中包含了指向 undo log 的指针，而每条 undo log 也会指向更早版本的 undo log，从而形成一条版本链。
3.  ReadView：通过隐藏列和版本链，MySQL 可以将数据恢复到指定版本。但是具体要恢复到哪个版本，则需要根据 ReadView 来确定。所谓 ReadView，是指事务（记做事务 A）在某一时刻给整个事务系统（trx_sys）打快照，之后再进行读操作时，会将读取到的数据中的事务 id 与 trx_sys 快照比较，从而判断数据对该 ReadView 是否可见，即对事务 A 是否可见。

一致性实现原理：

可以说，一致性是事务追求的最终目标。前面提到的原子性、持久性和隔离性，都是为了保证数据库状态的一致性。此外，除了数据库层面的保障，一致性的实现也需要应用层面进行保障。实现一致性的措施包括：

*   保证原子性、持久性和隔离性，如果这些特性无法保证，事务的一致性也无法保证。
*   数据库本身提供保障，例如不允许向整形列插入字符串值、字符串长度不能超过列的限制等。
*   应用层面进行保障，例如如果转账操作只扣除转账者的余额，而没有增加接收者的余额，无论数据库实现的多么完美，也无法保证状态的一致。

#### 4.3.4 谈谈 MySQL 的事务隔离级别

**参考答案**

SQL 标准定义了四种隔离级别，这四种隔离级别分别是：

*   读未提交（READ UNCOMMITTED）；
*   读提交 （READ COMMITTED）；
*   可重复读 （REPEATABLE READ）；
*   串行化 （SERIALIZABLE）。

事务隔离是为了解决脏读、不可重复读、幻读问题，下表展示了 4 种隔离级别对这三个问题的解决程度：

<table><thead><tr><th>隔离级别</th><th>脏读</th><th>不可重复读</th><th>幻读</th></tr></thead><tbody><tr><td>READ UNCOMMITTED</td><td>可能</td><td>可能</td><td>可能</td></tr><tr><td>READ COMMITTED</td><td>不可能</td><td>可能</td><td>可能</td></tr><tr><td>REPEATABLE READ</td><td>不可能</td><td>不可能</td><td>可能</td></tr><tr><td>SERIALIZABLE</td><td>不可能</td><td>不可能</td><td>不可能</td></tr></tbody></table>

上述 4 种隔离级别 MySQL 都支持，并且 InnoDB 存储引擎默认的支持隔离级别是 REPEATABLE READ，但是与标准 SQL 不同的是，InnoDB 存储引擎在 REPEATABLE READ 事务隔离级别下，使用 Next-Key Lock 的锁算法，因此避免了幻读的产生。所以，InnoDB 存储引擎在默认的事务隔离级别下已经能完全保证事务的隔离性要求，即达到 SQL 标准的 SERIALIZABLE 隔离级别。

**扩展阅读**

并发情况下，读操作可能存在的三类问题：

1.  脏读：当前事务 (A) 中可以读到其他事务 (B) 未提交的数据（脏数据），这种现象是脏读。
2.  不可重复读：在事务 A 中先后两次读取同一个数据，两次读取的结果不一样，这种现象称为不可重复读。脏读与不可重复读的区别在于：前者读到的是其他事务未提交的数据，后者读到的是其他事务已提交的数据。
3.  幻读：在事务 A 中按照某个条件先后两次查询数据库，两次查询结果的条数不同，这种现象称为幻读。不可重复读与幻读的区别可以通俗的理解为：前者是数据变了，后者是数据的行数变了。

#### 4.3.5 MySQL 的事务隔离级别是怎么实现的？

**参考答案**

READ UNCOMMITTED：

它是性能最好、也最野蛮的方式，因为它压根儿就不加锁，所以根本谈不上什么隔离效果，可以理解为没有隔离。

SERIALIZABLE：

读的时候加共享锁，其他事务可以并发读，但是不能写。写的时候加排它锁，其他事务不能并发写也不能并发读。

REPEATABLE READ & READ COMMITTED：

为了解决不可重复读，MySQL 采用了 MVVC (多版本并发控制) 的方式。

我们在数据库表中看到的一行记录可能实际上有多个版本，每个版本的记录除了有数据本身外，还要有一个表示版本的字段，记为 row trx_id，而这个字段就是使其产生的事务的 id，事务 ID 记为 transaction id，它在事务开始的时候向事务系统申请，按时间先后顺序递增。

如下图，一行记录现在有 3 个版本，每一个版本都记录这使其产生的事务 ID，比如事务 A 的 transaction id 是 100，那么版本 1 的 row trx_id 就是 100，同理版本 2 和版本 3。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-1.jpg)

可重复读是在事务开始的时候生成一个当前事务全局性的快照，而读提交则是每次执行语句的时候都重新生成一次快照。对于一个快照来说，它能够读到那些版本数据，要遵循以下规则：

1.  当前事务内的更新，可以读到；
2.  版本未提交，不能读到；
3.  版本已提交，但是却在快照创建后提交的，不能读到；
4.  版本已提交，且是在快照创建前提交的，可以读到。

再强调一次，两者主要的区别就是在快照的创建上，可重复读仅在事务开始是创建一次，而读提交每次执行语句的时候都要重新创建一次。

MySQL 已经在可重复读隔离级别下解决了幻读的问题，用的是间隙锁。MySQL 把行锁和间隙锁合并在一起，解决了并发写和幻读的问题，这个锁叫做 Next-Key 锁。

假设现在表中有两条记录，并且 age 字段已经添加了索引，两条记录 age 的值分别为 10 和 30。此时，在数据库中会为索引维护一套 B + 树，用来快速定位行记录。B + 索引树是有序的，所以会把这张表的索引分割成几个区间。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-2.jpg)

此时，在数据库中会为索引维护一套 B + 树，用来快速定位行记录。B + 索引树是有序的，所以会把这张表的索引分割成几个区间。如图所示，分成了 3 个区间，在这 3 个区间是可以加间隙锁的。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-3.jpg)

之后，我用下面的两个事务演示一下加锁过程。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-4.jpg)

在事务 A 提交之前，事务 B 的插入操作只能等待，这就是间隙锁起得作用。当事务 A 执行`update user set name='风筝2号’ where age = 10;` 的时候，由于条件 where age = 10 ，数据库不仅在 age =10 的行上添加了行锁，而且在这条记录的两边，也就是 (负无穷, 10]、(10,30] 这两个区间加了间隙锁，从而导致事务 B 插入操作无法完成，只能等待事务 A 提交。不仅插入 age = 10 的记录需要等待事务 A 提交，age<10、10<age<30 的记录页无法完成，而大于等于 30 的记录则不受影响，这足以解决幻读问题了。

这是有索引的情况，如果 age 不是索引列，那么数据库会为整个表加上间隙锁。所以，如果是没有索引的话，不管 age 是否大于等于 30，都要等待事务 A 提交才可以成功插入。

#### 4.3.6 事务可以嵌套吗？

**参考答案**

可以，因为嵌套事务也是众多事务分类中的一种，它是一个层次结构框架。有一个顶层事务控制着各个层次的事务，顶层事务之下嵌套的事务被称为子事务，它控制每一个局部的变换。

需要注意的是，MySQL 数据库不支持嵌套事务。

#### 4.3.7 如何实现可重复读？

**参考答案**

为了实现可重复读，MySQL 采用了 MVVC (多版本并发控制) 的方式。

我们在数据库表中看到的一行记录可能实际上有多个版本，每个版本的记录除了有数据本身外，还要有一个表示版本的字段，记为 row trx_id，而这个字段就是使其产生的事务的 id，事务 ID 记为 transaction id，它在事务开始的时候向事务系统申请，按时间先后顺序递增。

如下图，一行记录现在有 3 个版本，每一个版本都记录这使其产生的事务 ID，比如事务 A 的 transaction id 是 100，那么版本 1 的 row trx_id 就是 100，同理版本 2 和版本 3。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-1.jpg)

可重复读是在事务开始的时候生成一个当前事务全局性的快照。对于一个快照来说，它能够读到那些版本数据，要遵循以下规则：

1.  当前事务内的更新，可以读到；
2.  版本未提交，不能读到；
3.  版本已提交，但是却在快照创建后提交的，不能读到；
4.  版本已提交，且是在快照创建前提交的，可以读到。

#### 4.3.8 如何解决幻读问题？

**参考答案**

MySQL 已经在可重复读隔离级别下解决了幻读的问题，用的是间隙锁。MySQL 把行锁和间隙锁合并在一起，解决了并发写和幻读的问题，这个锁叫做 Next-Key 锁。

假设现在表中有两条记录，并且 age 字段已经添加了索引，两条记录 age 的值分别为 10 和 30。此时，在数据库中会为索引维护一套 B + 树，用来快速定位行记录。B + 索引树是有序的，所以会把这张表的索引分割成几个区间。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-2.jpg)

此时，在数据库中会为索引维护一套 B + 树，用来快速定位行记录。B + 索引树是有序的，所以会把这张表的索引分割成几个区间。如图所示，分成了 3 个区间，在这 3 个区间是可以加间隙锁的。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-3.jpg)

之后，我用下面的两个事务演示一下加锁过程。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/tx-4.jpg)

在事务 A 提交之前，事务 B 的插入操作只能等待，这就是间隙锁起得作用。当事务 A 执行`update user set name='风筝2号’ where age = 10;` 的时候，由于条件 where age = 10 ，数据库不仅在 age =10 的行上添加了行锁，而且在这条记录的两边，也就是 (负无穷, 10]、(10,30] 这两个区间加了间隙锁，从而导致事务 B 插入操作无法完成，只能等待事务 A 提交。不仅插入 age = 10 的记录需要等待事务 A 提交，age<10、10<age<30 的记录页无法完成，而大于等于 30 的记录则不受影响，这足以解决幻读问题了。

这是有索引的情况，如果 age 不是索引列，那么数据库会为整个表加上间隙锁。所以，如果是没有索引的话，不管 age 是否大于等于 30，都要等待事务 A 提交才可以成功插入。

#### 4.3.9 MySQL 事务如何回滚？

**参考答案**

在 MySQL 默认的配置下，事务都是自动提交和回滚的。当显示地开启一个事务时，可以使用 ROLLBACK 语句进行回滚。该语句有两种用法：

*   ROLLBACK：要使用这个语句的最简形式，只需发出 ROLLBACK。同样地，也可以写为 ROLLBACK WORK，但是二者几乎是等价的。回滚会结束用户的事务，并撤销正在进行的所有未提交的修改。
*   ROLLBACK TO [SAVEPOINT] identifier ：这个语句与 SAVEPOINT 命令一起使用。可以把事务回滚到标记点，而不回滚在此标记点之前的任何工作。

### 4.4 锁

#### 4.4.1 了解数据库的锁吗？

**参考答案**

锁是数据库系统区别于文件系统的一个关键特性，锁机制用于管理对共享资源的并发访问。下面我们以 MySQL 数据库的 InnoDB 引擎为例，来说明锁的一些特点。

锁的类型：

InnoDB 存储引擎实现了如下两种标准的行级锁：

*   共享锁（S Lock），允许事务读一行数据。
*   排他锁（X Lock），允许事务删除或更新一行数据。

如果一个事务 T1 已经获得了行 r 的共享锁，那么另外的事务 T2 可以立即获得行 r 的共享锁，因为读取并没有改变行 r 的数据，称这种情况为锁兼容。但若有其他的事务 T3 想获得行 r 的排他锁，则其必须等待事务 T1、T2 释放行 r 上的共享锁，这种情况称为锁不兼容。下图显示了共享锁和排他锁的兼容性，可以发现 X 锁与任何的锁都不兼容，而 S 锁仅和 S 锁兼容。需要特别注意的是，S 和 X 锁都是行锁，兼容是指对同一记录（row）锁的兼容性情况。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/dblock-1.png)

锁的粒度：

InnoDB 存储引擎支持多粒度锁定，这种锁定允许事务在行级上的锁和表级上的锁同时存在。为了支持在不同粒度上进行加锁操作，InnoDB 存储引擎支持一种额外的锁方式，称之为意向锁。意向锁是将锁定的对象分为多个层次，意向锁意味着事务希望在更细粒度上进行加锁。

InnoDB 存储引擎支持意向锁设计比较简练，其意向锁即为表级别的锁。设计目的主要是为了在一个事务中揭示下一行将被请求的锁类型。其支持两种意向锁：

*   意向共享锁（IS Lock），事务想要获得一张表中某几行的共享锁。
*   意向排他锁（IX Lock），事务想要获得一张表中某几行的排他锁。

由于 InnoDB 存储引擎支持的是行级别的锁，因此意向锁其实不会阻塞除全表扫以外的任何请求。故表级意向锁与行级锁的兼容性如下图所示。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/dblock-2.png)

锁的算法：

InnoDB 存储引擎有 3 种行锁的算法，其分别是：

*   Record Lock：单个行记录上的锁。
*   Gap Lock：间隙锁，锁定一个范围，但不包含记录本身。
*   Next-Key Lock∶Gap Lock+Record Lock，锁定一个范围，并且锁定记录本身。

Record Lock 总是会去锁住索引记录，如果 InnoDB 存储引擎表在建立的时候没有设置任何一个索引，那么这时 InnoDB 存储引擎会使用隐式的主键来进行锁定。Next-Key Lock 是结合了 Gap Lock 和 Record Lock 的一种锁定算法，在 Next-Key Lock 算法下，InnoDB 对于行的查询都是采用这种锁定算法。采用 Next-Key Lock 的锁定技术称为 Next-Key Locking，其设计的目的是为了解决 Phantom Problem（幻读）。而利用这种锁定技术，锁定的不是单个值，而是一个范围，是谓词锁（predict lock）的一种改进。

关于死锁：

死锁是指两个或两个以上的事务在执行过程中，因争夺锁资源而造成的一种互相等待的现象。若无外力作用，事务都将无法推进下去。

解决死锁问题最简单的一种方法是超时，即当两个事务互相等待时，当一个等待时间超过设置的某一阈值时，其中一个事务进行回滚，另一个等待的事务就能继续进行。

除了超时机制，当前数据库还都普遍采用 wait-for graph（等待图）的方式来进行死锁检测。较之超时的解决方案，这是一种更为主动的死锁检测方式。InnoDB 存储引擎也采用的这种方式。wait-for graph 要求数据库保存以下两种信息：

*   锁的信息链表；
*   事务等待链表；

通过上述链表可以构造出一张图，而在这个图中若存在回路，就代表存在死锁，因此资源间相互发生等待。这是一种较为主动的死锁检测机制，在每个事务请求锁并发生等待时都会判断是否存在回路，若存在则有死锁，通常来说 InnoDB 存储引擎选择回滚 undo 量最小的事务。

锁的升级：

锁升级（Lock Escalation）是指将当前锁的粒度降低。举例来说，数据库可以把一个表的 1000 个行锁升级为一个页锁，或者将页锁升级为表锁。

InnoDB 存储引擎不存在锁升级的问题。因为其不是根据每个记录来产生行锁的，相反，其根据每个事务访问的每个页对锁进行管理的，采用的是位图的方式。因此不管一个事务锁住页中一个记录还是多个记录，其开销通常都是一致的。

#### 4.4.2 介绍一下间隙锁

**参考答案**

InnoDB 存储引擎有 3 种行锁的算法，间隙锁（Gap Lock）是其中之一。间隙锁用于锁定一个范围，但不包含记录本身。它的作用是为了阻止多个事务将记录插入到同一范围内，而这会导致幻读问题的产生。

#### 4.4.3 InnoDB 中行级锁是怎么实现的？

**参考答案**

InnoDB 行级锁是通过给索引上的索引项加锁来实现的。只有通过索引条件检索数据，InnoDB 才使用行级锁，否则，InnoDB 将使用表锁。

当表中锁定其中的某几行时，不同的事务可以使用不同的索引锁定不同的行。另外，不论使用主键索引、唯一索引还是普通索引，InnoDB 都会使用行锁来对数据加锁。

#### 4.4.4 数据库在什么情况下会发生死锁？

**参考答案**

死锁是指两个或两个以上的事务在执行过程中，因争夺锁资源而造成的一种互相等待的现象。若无外力作用，事务都将无法推进下去。下图演示了死锁的一种经典的情况，即 A 等待 B、B 等待 A，这种死锁问题被称为 AB-BA 死锁。

![](https://static.nowcoder.com/images/activity/2021jxy/c/assert/dblock-3.png)

#### 4.4.5 说说数据库死锁的解决办法

**参考答案**

解决死锁问题最简单的一种方法是超时，即当两个事务互相等待时，当一个等待时间超过设置的某一阈值时，其中一个事务进行回滚，另一个等待的事务就能继续进行。

除了超时机制，当前数据库还都普遍采用 wait-for graph（等待图）的方式来进行死锁检测。较之超时的解决方案，这是一种更为主动的死锁检测方式。InnoDB 存储引擎也采用的这种方式。wait-for graph 要求数据库保存以下两种信息：

*   锁的信息链表；
*   事务等待链表；

通过上述链表可以构造出一张图，而在这个图中若存在回路，就代表存在死锁，因此资源间相互发生等待。这是一种较为主动的死锁检测机制，在每个事务请求锁并发生等待时都会判断是否存在回路，若存在则有死锁，通常来说 InnoDB 存储引擎选择回滚 undo 量最小的事务。