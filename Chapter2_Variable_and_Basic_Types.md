rithmetic type,字符、整形数、布尔值、浮点数)和空类型(void)。

### 2.1.1 算数类型
算数类型分为：整型(包括字符和布尔类型)和浮点型。
类型范围：
| 类型 | 含义 | 最小尺寸 |
| :----:   | :-----:  | :----:  |
| bool | 布尔类型 | 未定义 |
| char | 字符 | 8位 |
| wchar_t | 宽字符 | 16位 |
| char16_t | Unicode字符 | 16位 |
| char32_t | Unicode字符 | 32位 |
| short | 短整型 | 16位 |
| int | 整型 | 16位 |
| long | 长整形 | 32位 |
| long long | 长整形 | 64位 |
| float | 单精度浮点数 | 6位有效数字 |
| double | 双精度浮点数 | 10位有效数字 |
| long double | 扩展精度浮点数 | 10位有效数字 |


* C++语言规定一个int至少和一个short一样大，一个long至少和一个int一样大，一个long long至少和long一样大。其中long long在C++11种新定义的。
*  内存中可寻址的最小内存成为"字节`byte`"，每个字节关联一个地址。
*  `unsigned int`可以缩写为`unsigned`。
*  int,short,long,long long可以有带符号和无符号两种表示。
*  字符型分为三种：char，signed char，unsigned char。**尽管字符型分位三种类型，但是表现形式只有两种，带符号的和无符号的。具体表现为哪种，有编译器决定。**
## 2.3 复合类型
### 2.3.1 引用
- c++11中引入右值引用
- **引用不是对象**，引用只是已存在对象的别名。
- 初始化变量和应用的区别：一般初始化变量时，初始值会被拷贝到新建的对象中。定义引用时，程序把引用和它的初始值绑定到一起，而不是将初始值拷贝给引用。**引用无法重新绑定到另一个对象上，因此引用必须初始化。**
### 2.3.2 指针
- 指针(pointer)是指向另一种类型的符合类型。
- 指针与引用的不同：
 1. 指针本身是一个对象，允许对指针赋值和拷贝，可以指向同类型的不同对象。
 2. 指针无须在定义时初始化。
- 获取对象的地址，使用取地址符(操作法&).
- 指针值的四种状态：指向一个对象，指向对象所占空间的下一个位置，空指针，无效指针。
- 空指针
 把int型变量直接赋值给指针是错误的操作，即使int变量的值恰好等于0也不行。
```
int *p1 = nullptr; //c++11推荐
int *p2 = 0;
int *p3 = NULL; // #inlcude cstdlib
```
## 2.4 const限定符
- const对象一旦创建后其值就不能在改变，所以const对象必须初始化。
- 默认状态下，const仅在文件内有效。使用extern关键字可以在其它文件中使用。
```
//file_1.cc 定义并初始化一个常量，该常量能被其他文件访问
extern const int bufSize = fcn();
// file_1.h头文件
extern const int bufSize; //与file_1.cc中定义的是同一个
```
### 2.4.1 const的引用
- 对常量的引用(reference to const)：把引用绑定到const对象上，就像绑定到其他对象上一样。**对常量的引用不能被用作修改它所邦定的对象。**
```
const int ci = 1024;
const int &r1 = ci; // 正确：引用及其对应的对象都是常量
r1 = 42; // 错误：r1是都常量的引用
int &r2 = ci; // 错误：试图让一个非常量引用指向一个常量对象
```
#### 初始化和对const的引用
**引用的类型必须与其所引用对象的类型一致**，有两个例外。第一种列外：在初始化常量引用时允许用任意表达式作为初始值，只要该表达式结果能转换成引用的类型即可。尤其，允许为一个常量引用邦定非常量的对象、字面值，甚至是一般表达式：
```
int i = 42;
const int &r1 = i;
const int &r2 = 42;
const int &r3 = r1 * 2;
int &r4 = r1 * 2; // 错误：r4是一个普通的非常量引用
```
#### 对const的引用可能引用一个并非const的对象
常量引用仅对引用可参与的操作做出了限定，对于引用的对象本身是不是常量未作限定。
```
int i = 42;
int &r1 = i;
const int &r2 = i;
r1 = 0;
r2 = 0; // 错误：r2是一个常量引用
```
### 2.4.2 指针和const
- 指向常量的指针：不能用于改变其所指对象的值。
- 指针的类型必须与其所指对象的类型一致。例外：第一种例外情况是允许另一个常量的指针指向一个非常量对象：
```
const double p = 3.14;
doube *ptr = &p; // 错误：ptr是一个普通指针
const double *cptr = &p;
*cptr = 42; //错误：不能给*cptr赋值
```
#### const指针
常量指针必须初始化，而且一旦初始化完成，则它的值就不能被改变。
```
int errNumb = 0;
int *const curErr = &errNumb;
const double p = 3.14159;
const double *const pip = &p;
```