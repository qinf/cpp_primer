##13.1 
拷贝构造函数：如果一个构造函数的第一个参数是自身类类型的引用，且任何额外的参数都有默认值。
1. 使用=定义变量
2. 将一个对象作为实参传递给一个非引用类型对象
3. 从一个返回类型为非引用类型的函数返回一个对象
4. 用花括号列表初始化一个数组中的元素或一个聚合类中的成员
5. 某些类还会对它们所分配的对象使用拷贝初始化
##13.2
因为为了调用拷贝构造函数，我们必须拷贝它的实参，但是为了拷贝实参，我们有需要调用拷贝构造函数，无限循环。