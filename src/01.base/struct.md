## 结构体

### 结构体的概念和基本操作

结构体用于表示一条记录，里面允许存储多个不同类型的数据，来描述现实生活中的一个事物。

#### 结构体的声明

```c++
// 1. 声明一个名为 Book 的结构体，没有声明结构体变量
struct Book {
    // 拥有 3 个成员
    int book_id;
    char title[50];
    char author[50];
};

// 2. 声明一个名为 Book 的结构体，并声明了 book1、book2 两个结构体变量
struct Book {
    int book_id;
    char title[50];
    char author[50];
} book1, book2;

// 3. 声明一个名为 Book 的结构体，没有声明结构体变量，等需要时再声明
struct Book {
    int book_id;
    char title[50];
    char author[50];
};

struct Book book1, book2;

// 4. 声明一个没有名字的结构体，并声明了 s1 结构体变量
struct {
    int a;
    char b;
    double c;
} s1;

// 5. 使用 typedef 创建新类型 Book
typedef struct {
    int book_id;
    char title[50];
    char author[50];
} Book;

// 以后用 Book 类型声明变量，前面不用加 struct
Book book1, book2;
```

#### 结构体的初始化与访问

和其它类型变量一样，对结构体变量可以在定义时指定初始值，访问结构体变量的成员时需要使用 `.` 操作符。

```c++
#include <stdio.h>
#include <string.h>

struct Book {
   int   book_id;
   char  title[50];
   char  author[50];
} book = { 123456, "C 语言", "hueralin" };

typedef struct {
    char name[50];
    int age;
} Student;

int main () {
    printf("book_id: %d\ntitle : %s\nauthor: %s\n", book.book_id, book.title, book.author);
    // 定义时直接初始化
    Student stu1 = { "hueralin", 18 };
    printf("stu1 name: %s\nstu1 age : %d\n", stu1.name, stu1.age);
    // 先定义，然后再初始化
    Student stu2;
    // stu2 = { "hueralin", 18 };  // 不行，会报错
    // 应该手动给各个成员赋值
    strcpy(stu2.name, "hueralin");
    stu2.age = 18;
    printf("stu2 name: %s\nstu2 age : %d\n", stu2.name, stu2.age);
    return 0;
}

// 输出：
// book_id: 123456
// title : C 语言
// author: hueralin

// stu1 name: hueralin
// stu1 age : 18

// stu2 name: hueralin
// stu2 age : 18
```

### 结构体作为函数参数

可以把结构体作为函数参数，传参方式与其他类型的变量或指针类似。

```c++
#include <stdio.h>

typedef struct {
    int id;
    int age;
} IDCard;

void printIDCard (IDCard idc);

// 如果是使用 struct 声明的结构体，则函数形参前面应该加上 struct
// void printIDCard (struct IDCard idc);

int main () {
    IDCard idc = { 10086, 18 };
    printIDCard(idc);
    return 0;
}

void printIDCard (IDCard idc) {
    printf("id: %d\nage: %d\n", idc.id, idc.age);
}

// 输出：
// id: 10086
// age: 18
```

### 指向结构体的指针

定义指向结构体的指针，方式与定义指向其他类型变量的指针相似。

```c++
#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

int main () {
    struct Person person = { "hueralin", 18 };
    struct Person *ptr = &person;
    // 注意访问成员的方式变了：指针变量->成员
    printf("name: %s\n", ptr->name);
    printf("age: %d\n", ptr->age);
    return 0;
}

// 输出：
// name: hueralin
// age: 18
```
