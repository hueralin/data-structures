# C 语言的数据类型

## 1. 布尔型

C 语言并没有布尔类型，所以没有关键字 `bool`、`true`、`false`。

可以借助 C 语言的宏定义来定义布尔类型：

```c++
#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL flag = TRUE;
```
