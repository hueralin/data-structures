# 内存管理

## 1. 申请内存空间

**malloc 函数** `void *malloc(int num);`

在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。

```c++
#include <stdio.h>
#include <stdlib.h>

int main () {
    // 强制类型转换成 int 型指针
    int *data = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        data[i] = i + 1;
        printf("data[%d] is %d\n", i, data[i]);
    }
    return 0;
}

// data[0] is 1
// data[1] is 2
// data[2] is 3
// data[3] is 4
// data[4] is 5
```

为什么要使用强制类型转换？答案是为了方便我们访问内存空间。malloc 函数只是申请了一块连续的内存空间，返回的是这块内存空间的首地址。而我们想通过 `data[i]` 的方式去访问该内存空间的某一部分，但是编译器并不知道 `data[i]` 到底从这块内存空间的哪个地方开始访问，也不知道这一部分的大小是多少。而我们强制类型转换后，编译器就会根据该类型所占的字节数自动计算 `data[i]` 的起始地址，空间大小。例如 int 在 C 语言中占四个字节：

![malloc](../../img/malloc.png)

## 2. 释放内存空间

**free 函数** `void free(void *address);`

在不需要内存时，都应该调用 free() 来释放内存。free(ptr) 不会改变 ptr 变量本身的值，调用 free() 后它仍然会指向相同的内存空间，free(ptr) 仅仅是告知系统，这块堆空间我不要了。系统是立即回收，还是以后回收，那是系统的事。所以建议将 ptr 的值设置为 NULL。

```c++
#include <stdio.h>
#include <stdlib.h>

int main () {
    int *data = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        data[i] = i + 1;
        printf("data[%d] is %d\n", i, data[i]);
    }
    // 释放内存
    free(data);
    return 0;
}
```
