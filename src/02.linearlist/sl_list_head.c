// 带头结点的单链表
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *SingleLinkList;

// 打印单链表
void PrintSingleLInkList (SingleLinkList L);
// 构建单链表（头插法）
SingleLinkList InitSingleLinkListOnHead (SingleLinkList L, int num);
// 构建单链表（尾插法）
SingleLinkList InitSingleLinkListOnTail (SingleLinkList L, int num);
// 按位获取
LNode *GetElem (SingleLinkList L, int i);
// 按值获取
LNode *LocateElem (SingleLinkList L, int data);
// 按位插入
SingleLinkList Insert (SingleLinkList L, int i, int data);
// 按位删除
BOOL Delete (SingleLinkList L, int i, int *res);

int main () {
    SingleLinkList L = NULL;
    // L = InitSingleLinkListOnHead(L, 5);
    L = InitSingleLinkListOnTail(L, 5);
    PrintSingleLInkList(L);
    LNode *node = GetElem(L, 3);
    if (node != NULL) {
        printf("GetElem(L, 3) value is %d\n", node->data);
    }
    node = LocateElem(L, 4);
    if (node != NULL) {
        printf("LocateElem(L, 4) value is %d\n", node->data);
    }
    L = Insert(L, 6, 6);
    PrintSingleLInkList(L);
    int res = 0;
    BOOL isDelete = Delete(L, 6, &res);
    if (isDelete == TRUE) {
        printf("delete success: \n", res);
        PrintSingleLInkList(L);
    }
    return 0;
}

void PrintSingleLInkList (SingleLinkList L) {
    if (L == NULL) {
        printf("SingleLinkList is Empty\n");
        return;
    }
    LNode *curr = L->next;
    while (curr != NULL) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

SingleLinkList InitSingleLinkListOnHead (SingleLinkList L, int num) {
    // 创建头结点
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    L = head;
    // 头插法构建单链表
    int i = 0;
    while (i < num) {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = i + 1;
        node->next = head->next;
        head->next = node;
        i++;
    }
    return L;
}

SingleLinkList InitSingleLinkListOnTail (SingleLinkList L, int num) {
    // 创建头结点
    LNode *head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    L = head;
    // 创建指向最后一个结点的指针
    LNode *tail = head;
    // 尾插法构建单链表
    int i = 0;
    while (i < num) {
        // 创建结点
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->data = i + 1;
        node->next = NULL;
        // 将 node 和前面连接起来
        tail->next = node;
        // tail 指向最后一个结点
        tail = node;
        i++;
    }
    return L;
}

LNode *GetElem (SingleLinkList L, int i) {
    if (L == NULL) return NULL;
    if (i < 1) return NULL;
    // 创建用于遍历的指针，指向第一个结点
    LNode *curr = L->next;
    int j = 1;
    // 找到第 i 个结点
    while (curr != NULL && j < i) {
        curr = curr->next;
        j++;
    }
    if (curr == NULL) return NULL;
    return curr;
}

LNode *LocateElem (SingleLinkList L, int data) {
    if (L == NULL) return NULL;
    // 创建用于遍历的指针
    LNode *curr = L->next;
    while (curr != NULL && curr->data != data) {
        curr = curr->next;
    }
    if (curr == NULL) return NULL;
    return curr;
}

SingleLinkList Insert (SingleLinkList L, int i, int data) {
    if (L == NULL) {
        printf("The SingleLinkList is NULL\n");
        return L;
    }
    if (i < 1) {
        printf("Range Error\n");
        return L;
    }
    // 先找到第 i - 1 个结点
    LNode *p = GetElem(L, i - 1);
    if (p == NULL) {
        printf("Range Error\n");
        return L;
    }
    // 插入
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = data;
    node->next = p->next;
    p->next = node;
    return L;
}

BOOL Delete (SingleLinkList L, int i, int *res) {
    if (L == NULL) return FALSE;
    // 查找第 i - 1 个元素
    LNode *p = GetElem(L, i - 1);
    if (p == NULL) return FALSE;
    // 删除
    LNode *node = p->next;
    *res = node->data;
    p->next = node->next;
    free(node);
    return TRUE;
}
