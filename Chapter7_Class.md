### 7.5.2 委托构造函数
委托构成函数执行流程：
- 先执行受委托的构造函数
- 然后执行委托构造函数
举例:
```c++
class A{
public:
    A(int i, double b): _i(i), _b(b) {}
    A(): A(0, 0) {}
private:
    int _i;
    double _b;
};
# 使用A()定义变量是，会先执行构造函数A(int i, double b)，在执行A()。
```
- 如果switch语句中想定义变量，则变量必须放到花括号中。
