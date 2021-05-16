// 静态链表：用数组的方式实现的链表，逻辑上相邻的元素也可以在物理上不相邻
// 优点：增删操作不需要移动大量的元素
// 缺点：不能随机存取，容量固定不变
// 适用场景：不支持指针的低级语言、数据元素数量固定不变的场景
// 静态链表 = 数据链表 + 备用链表
// https://mp.weixin.qq.com/s/j-QLf9w98GAktbGo2vnl0w
#include <stdio.h>
#include <stdlib.h>

// 备用链表的头结点占了一个位置
#define MaxSize 6
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    int cur;
} Node, StaticLinkList[MaxSize];

// 相当于
// struct Node {
//     int data;
//     int cur;
// };
// 重定义一个结构体数组类型
// typedef struct Node StaticLinkList[MaxSize];

// 判空
BOOL Empty (StaticLinkList arr);
// 判满
BOOL Full (StaticLinkList arr);
// 遍历（从 dataHead）开始遍历
void PrintStaticLinkList (StaticLinkList arr);
// 初始化（返回数据链表的头结点下标）
void InitStaticLinkList (StaticLinkList arr);
// 从备用链表中分配空间
int mallocFromList (StaticLinkList arr);
// 归还空间到备用链表
void freeToList (StaticLinkList arr, int i);
// 在指定位置插入元素
void InsertAt (StaticLinkList arr, int i, int data);
// 删除指定位置的元素
void DeleteAt (StaticLinkList arr, int i);

int main () {
    StaticLinkList arr;
    InitStaticLinkList(arr);
    InsertAt(arr, 1, 1);
    InsertAt(arr, 2, 2);
    InsertAt(arr, 3, 3);
    InsertAt(arr, 4, 4);
    InsertAt(arr, 5, 5);
    DeleteAt(arr, 5);
    PrintStaticLinkList(arr);
    return 0;
}

BOOL Empty (StaticLinkList arr) {
    // 备用链表的下一个空结点指向数据链表的第一个结点
    // 即数据链表为空，也就是静态链表为空
    if (arr[0].cur == 1) return TRUE;
    return FALSE;
}

BOOL Full (StaticLinkList arr) {
    // 备用链表的 cur 指向自己，说明满了
    if (arr[0].cur == 0) return TRUE;
    return FALSE;
}

void PrintStaticLinkList (StaticLinkList arr) {
    if (Empty(arr) == TRUE) {
        printf("StaticLinkList is Empty\n");
        return;
    }
    int index = 1;
    while (index) {
        printf("value is %d\n", arr[index].data);
        index = arr[index].cur;
    }
}

void InitStaticLinkList (StaticLinkList arr) {
    // 初始化，构建备用链表，每个结点的 cur 指针指向下一个空闲节点
    for (int i = 0; i < MaxSize; i++) {
        arr[i].data = 0;
        arr[i].cur = i + 1;
    }
    // 将表的最后一个结点的 cur 指向备用表的头结点
    arr[MaxSize - 1].cur = 0;
}

int mallocFromList (StaticLinkList arr) {
    int index = arr[0].cur;
    if (index) {
        arr[0].cur = arr[index].cur;
    }
    // 如果 index 为 0，说明表满了
    return index;
}

void freeToList (StaticLinkList arr, int i) {
    // 可以使用头插法，插入到备用链表的前面
    Node head = arr[0];
    Node node = arr[i];
    node.cur = head.cur;
    head.cur = i;
}

void InsertAt (StaticLinkList arr, int i, int data) {
    if (i < 1 || i > MaxSize) {
        printf("Position is invalide\n");
        return;
    }
    int space = mallocFromList(arr);
    if (space == 0) {
        printf("StaticLinkList is Full\n");
        return;
    }
    // 插入第一个元素
    if (i == 1) {
        arr[space].data = data;
        arr[space].cur = 0;
    } else {
        // 找到第 i - 1 个结点
        int j = 1, prevNodeIndex = 1;
        while (j < i - 1) {
            prevNodeIndex = arr[prevNodeIndex].cur;
            j++;
        }
        arr[space].data = data;
        arr[space].cur = arr[prevNodeIndex].cur;
        arr[prevNodeIndex].cur = space;
    }
}

void DeleteAt (StaticLinkList arr, int i) {
    if (i < 1 || i > MaxSize) {
        printf("Position is invalide\n");
        return;
    }
    int k = 1;
    for (int j = 1; j < i - 1; j++) {
        k = arr[k].cur;
    }
    Node node = arr[arr[k].cur];
    arr[k].cur = node.cur;
    freeToList(arr, i);
}
