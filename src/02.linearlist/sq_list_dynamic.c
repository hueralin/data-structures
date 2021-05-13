// 顺序表的实现 - 动态扩容
#include <stdio.h>

#define InitSize 10 // 默认的最大长度

typedef struct {
    int *data;      // 指示动态分配数组的指针
    int MaxSize;    // 顺序表的最大容量
    int length;     // 顺序表的当前长度
} SqList;

void InitList (SqList *list);
void IncreaseSize (SqList *list, int len);

int main () {
    SqList l1;
    InitList(&l1);
    printf("before: %d\n", l1.MaxSize);
    IncreaseSize(&l1, 10);
    printf("after: %d\n", l1.MaxSize);
    return 0;
}

void InitList (SqList *list) {
    list->data = (int *)malloc(sizeof(int) * InitSize);
    list->length = 0;
    list->MaxSize = InitSize;
}

void IncreaseSize (SqList *list, int len) {
    // 保存对原有数组的地址引用
    int *tmp = list->data;
    // 开辟新地址空间
    list->data = (int *)malloc(sizeof(int) * (list->MaxSize + len));
    // 将原地址空间中的数据复制过去
    for (int i = 0; i < list->length; i++) {
        list->data[i] = tmp[i];
    }
    // 增加表的最大容量
    list->MaxSize += len;
    // 释放掉原来的地址空间
    free(tmp);
}

// before: 10
// after: 20
