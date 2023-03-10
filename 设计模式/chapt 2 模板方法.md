#note 
 ## 重构获得模式
 1. 面向对象设计模式是“好的面向对象设计”，是指那些可以满足“应对变化，提高复用”的设计模式
 2. 现代软件设计需求频繁变化。寻找变化点，在变化点处应用设计模式，从而更好适应需求的变化。什么时候，什么地方使用比如何使用更重要
 3. 不宜先入为主，没有一步到位的设计模式，没有一步到位的设计模式
 #thought  先追求功能实现，再实现设计模式
 $$重构关键技法 \to \begin{cases} 静态&\to&动态 \\ 早绑定 &\to& 晚绑定 \\ 继承 &\to& 组合 \\ 编译时依赖 &\to& 运行时依赖 \\紧耦合&\to&松耦合\end{cases}$$
 ------
 ## 组件协作模式
 - 现代软件专业分工之后第一个结果“框架和应用程序的划分“，组件协作模式通过晚期绑定实现框架间的松耦合
 - 典型模式 
	 * Template Method
	 * Strategy
	 * Observer/Event
------
## 动机
- 在软件构建过程中，对于某一项任务，常常具有稳定的整体操作结构，但各个子步骤却有很多改变的需求