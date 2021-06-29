# 数组

## 定义数组的方法

1. 声明一个包含 5 个整型数据的数组：`int arr[5];`
2. 声明一个包含 5 个整型数据的数组并初始化：`int arr[5] = { 1, 2, 3, 4, 5 };`
3. 声明一个不定长度的数组并初始化：`int arr[] = { 1, 2, 3, 4, 5 };` 如果省略掉了数组的大小，那么数组的大小则为初始化时元素的个数（5）。

## 获取数组的长度

`sizeof(arr) / sizeof(arr[0])`

## 向函数中传递数组参数

1. `void func (int *arr);` 形式参数是一个指针
2. `void func (int arr[5]);` 形式参数是一个已定义大小的数组
3. `void func (int arr[]);` 形式参数是一个未定义大小的数组

## 指向数组的指针

`int arr[5] = { 1, 2, 3, 4, 5 };`

arr 本身是一个指向数组中第一个元素的指针，即数组中第一个元素的地址。使用数组名作为常量指针是合法的，反之亦然。因此，`*(arr + 4)` 是一种访问 `arr[4]` 数据的合法方式。

```c++
#include <stdio.h>

int main () {
    int arr[5] = { 1, 2, 3, 4, 5 };
    printf("%d\n", *arr);
    printf("%d\n", *(arr + 4));
    return 0;
}
```

## Q&A

> 'sizeof' on array function parameter 'inOrderArr' will return size of 'int *'

因为数组作为参数传递给函数时，传递的是数组的地址，而不是整个数组空间，因而在函数中使用 `sizeof(arr)` 会报错，或者导致计算不准确。所以我们不要在函数内部使用 `sizeof(arr)` 计算数组长度，而是把数组的长度作为参数传递给函数。
