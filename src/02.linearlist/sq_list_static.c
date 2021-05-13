// 顺序表的实现 - 静态分配
#include <stdio.h>

#define MaxSize 10
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct {
    int data[MaxSize];
    int length;
} SqList;

// 初始化顺序表
void InitList (SqList *list);
// 打印顺序表
void ListPrint (SqList *list);
// 向顺序表的某个位置插入元素
BOOL ListInsert (SqList *list, int i, int e);
// 从顺序表的某个位置删除元素（被删除的元素存放在地址 e 中）
BOOL ListDelete (SqList *list, int i, int *e);
// 按位查找
BOOL GetElem (SqList *list, int i, int *e);
// 按值查找（返回位序）
int LocateElem (SqList *list, int e);


int main () {
    SqList list;
    InitList(&list);
    ListInsert(&list, 1, 1);
    ListInsert(&list, 2, 2);
    ListInsert(&list, 3, 3);
    int res = 0;
    // 删除第三个元素
    BOOL isDelete = ListDelete(&list, 3, &res);
    if (isDelete == TRUE) {
        printf("delete pos 3: %d\n", res);
    }
    BOOL isFound = GetElem(&list, 2, &res);
    if (isFound == TRUE) {
        printf("find pos 2: %d\n", res);
    }
    printf("find value equals 1, pos is %d\n", LocateElem(&list, 1));
    ListPrint(&list);
    return 0;
}

void InitList (SqList *list) {
    for (int i = 0; i < MaxSize; i++) {
        list->data[i] = 0;
    }
    list->length = 0;
}

void ListPrint (SqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("data[%d]'s value is %d\n", i, list->data[i]);
    }
}

BOOL ListInsert (SqList *list, int i, int e) {
    // 位序合法性校验
    if (i < 1 || i > list->length + 1) {
        return FALSE;
    }
    // 表已经满了
    if (list->length >= MaxSize) {
        return FALSE;
    }
    for (int j = list->length; j >= i; j--) {
        list->data[j] = list->data[j - 1];
    }
    list->data[i - 1] = e;
    list->length++;
    return TRUE;
}

// ListInsert 的时间复杂度分析（最好、最坏、平均）
// 最好：插入在表的末尾，执行 0 次循环，即 O(1)
// 最坏：插入在表的开头，执行 n 次循环，即 O(n)
// 平均：假设插入在每个位置的概率是相等的，总共有 n + 1 个位置，所以概率 p = 1 / (n + 1)
// 即平均执行次数 = np + (n-1)p + (n-2)p + ... + 1p = n(n+1)/2 * 1/(n+1) = n/2
// 所以时间复杂度为 O(n)

BOOL ListDelete (SqList *list, int i, int *e) {
    // 位序合法性校验（即使是空表，在这里也排除出去了）
    if (i < 1 || i > list->length) {
        return FALSE;
    }
    *e = list->data[i - 1];
    for (int j = i; j < list->length; j++) {
        list->data[j - 1] = list->data[j];
    }
    list->length--;
    return TRUE;
}

// ListDelete 的时间复杂度（最好、最坏、平均）
// 最好，删除最后一个，执行 0 次循环，即 O(1)
// 最坏，删除第一个，执行 n - 1 次循环，即 O(n)
// 平均：假设删除在每个位置的元素的概率是相等的，共有 n 个位置，即 p = 1 / n
// 平均执行次数 = (n-1)p + (n-2)p + ... + 1p = n(n-1)/2 * 1/n = (n-1)/2
// 所以时间复杂度为 O(n)

// 顺序表要求物理上相邻的元素在逻辑上也相邻，所以在插入或删除时才会有移动其他元素的操作

BOOL GetElem (SqList *list, int i, int *e) {
    if (i < 1 || i > list->length) {
        return FALSE;
    }
    *e = list->data[i - 1];
    return TRUE;
}

// GetElem 时间复杂度为 O(1)

int LocateElem (SqList *list, int e) {
    for (int i = 0; i < list->length; i++) {
        if (list->data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

// LocateElem 时间复杂度（最好、最坏、平均）
// 最好，要找的值在第一个位置，执行 1 次 循环
// 最坏，要找的值在最后一个位置或不存在，执行 n 次循环
// 平均，假设要找的值在每个位置上的概率相等，即 p = 1 / n
// 平均执行次数 = np + (n-1)p + (n-2)p + ... + 1p = n(n+1)/2 * 1/n = (n+1)/2
// 所以时间复杂度 O(n)

// 因为顺序表中的元素可能是无序的，所以 LocateElem 采用了遍历的方法
