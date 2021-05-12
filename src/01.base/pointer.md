# 指针

### 指针的概念及基础操作

指针就是内存地址，指针变量就是存放内存地址的变量，和普通变量没什么区别。

```c++
#include <stdio.h>

int main () {
    // 声明一个整数变量
    int a = 10;
    // 声明一个指针变量，并置空
    int *p = NULL;
    // 将 a 的地址赋值给 p
    p = &a;

    printf("a 的地址: %p\n", &a);
    printf("p 的值: %p\n", p);
    // 访问 p 指向的地址里面的值
    printf("p 指向的地址里存放的值: %d\n", *p);
    return 0;
}

// 输出：
// a 的地址: 0x100000
// p 的值: 0x100000
// p 指向的地址里存放的值: 10
```

### 指向指针的指针

声明时要使用 **。

指向指针变量A的指针变量B，即指针变量B的值是指针变量A的地址。

```c++
#include <stdio.h>

int main () {
    int v = 100;
    int *ptr1 = NULL;
    int **ptr2 = NULL;
    ptr1 = &v;
    ptr2 = &ptr1;

    printf("v: %d\n", v);
    printf("ptr1: %p\n", ptr1);
    printf("ptr1 point to: %d\n", *ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr2 point to ptr1 point to: %d\n", **ptr2);
    return 0;
}

// 输出：
```

### 传递指针给函数

```c++
#include <stdio.h>

// 函数声明
void setValue (int *p);

int main () {
    int v = 100;
    printf("value: %d\n", v);
    setValue(&v);
    printf("value: %d\n", v);
    return 0;
}

// 函数定义
void setValue (int *p) {
    *p = 1024;
}

// 输出：
// value: 100
// value: 1024
// 可见，将指针传递给函数是可以在函数内对函数外该指针指向的变量做修改的
```
