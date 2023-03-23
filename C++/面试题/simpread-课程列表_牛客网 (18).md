> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [www.nowcoder.com](https://www.nowcoder.com/study/live/690/2/19)

> 牛客网是 IT 求职神器, 国内一流互联网公司面试中常见的算法题及考察点系统讲解，帮大家系统梳理面试所需要的算法知识，提高刷题效率，轻松搞定算法面试。

#### 1.4.18 说说 push_back 和 emplace_back 的区别

**参考回答**

​ 如果要将一个临时变量 push 到容器的末尾，push_back() 需要先构造临时对象，再将这个对象拷贝到容器的末尾，而 emplace_back() 则直接在容器的末尾构造对象，这样就省去了拷贝的过程。

**答案解析**

​ 参考代码：

```
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class A {
public:
    A(int i){
        str = to_string(i);
        cout << "构造函数" << endl; 
    }
    ~A(){}
    A(const A& other): str(other.str){
        cout << "拷贝构造" << endl;
    }

public:
    string str;
};

int main()
{
    vector<A> vec;
    vec.reserve(10);
    for(int i=0;i<10;i++){
        vec.push_back(A(i)); //调用了10次构造函数和10次拷贝构造函数,
//        vec.emplace_back(i);  //调用了10次构造函数一次拷贝构造函数都没有调用过
    }


```

#### 1.4.19 STL 中 vector 与 list 具体是怎么实现的？常见操作的时间复杂度是多少？

**参考回答**

1.  vector 一维数组（元素在内存连续存放）
    
    ​ 是动态数组，在堆中分配内存，元素连续存放，有保留内存，如果减少大小后，内存也不会释放；如果新增大小当前大小时才会重新分配内存。
    
    ​ 扩容方式： a. 倍放开辟三倍的内存
    
    ​ b. 旧的数据开辟到新的内存
    
    ​ c. 释放旧的内存
    
    ​ d. 指向新内存
    
2.  list 双向链表（元素存放在堆中）
    
    ​ 元素存放在堆中，每个元素都是放在一块内存中，它的内存空间可以是不连续的，通过指针来进行数据的访问，这个特点，使得它的随机存取变得非常没有效率，因此它没有提供 [ ] 操作符的重载。但是由于链表的特点，它可以很有效的支持任意地方的删除和插入操作。
    
    ​ 特点：a. 随机访问不方便
    
    ​ b. 删除插入操作方便
    
3.  常见时间复杂度
    
    （1）vector 插入、查找、删除时间复杂度分别为：O(n)、O(1)、O(n)；
    
    （2）list 插入、查找、删除时间复杂度分别为：O(1)、O(n)、O(1)。