// 顺序表的实现 - 静态分配
#include <stdio.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

// 初始化顺序表
void InitList (SqList *list);

int main () {
    SqList list;
    InitList(&list);
    for (int i = 0; i < MaxSize; i++) {
        printf("list.data[%d]'s value is %d\n", i, list.data[i]);
    }
    return 0;
}

void InitList (SqList *list) {
    for (int i = 0; i < MaxSize; i++) {
        list->data[i] = 0;
    }
    list->length = 0;
}

// list.data[0]'s value is 0
// list.data[1]'s value is 0
// list.data[2]'s value is 0
// list.data[3]'s value is 0
// list.data[4]'s value is 0
// list.data[5]'s value is 0
// list.data[6]'s value is 0
// list.data[7]'s value is 0
// list.data[8]'s value is 0
// list.data[9]'s value is 0
