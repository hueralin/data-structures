// 双向链表
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct DLNode {
    int data;
    struct DLNode *prev;
    struct DLNode *next;
} DLNode, *DLinkList;

// 遍历双链表
void PrintDLinkList (DLinkList L);
// 初始化双链表
DLinkList InitDLinkList ();
// 头插法建立双链表
DLinkList InitDLinkListOnHead (DLinkList L, int num);
// 尾插法建立双链表
DLinkList InitDLinkListOnTail (DLinkList L, int num);
// 基本操作（在某个结点后插入数据）
DLNode *InsertNext (DLNode *p, int data);
// 基本操作（删除某个结点之后的结点）
BOOL DeleteNext (DLNode *p, int *res);
// 按位查找
DLNode *GetELem (DLinkList L, int i);

int main () {
    DLinkList L = InitDLinkList();
    // L = InitDLinkListOnHead(L, 5);
    L = InitDLinkListOnTail(L, 5);
    PrintDLinkList(L);
    DLNode *res = GetELem(L, 3);
    if (res != NULL) {
        printf("GetELem(L, 3): %d\n", res->data);
    } else {
        printf("Not Found\n");
    }
    return 0;
}

void PrintDLinkList (DLinkList L) {
    if (L == NULL) {
        printf("DLinkList is Empty\n");
        return;
    }
    DLNode *curr = L->next;
    while (curr != NULL) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

DLinkList InitDLinkList () {
    // 创建头结点
    DLNode *head = (DLNode *)malloc(sizeof(DLNode));
    head->prev = NULL;
    head->next = NULL;
    return head;
}

DLinkList InitDLinkListOnHead (DLinkList L, int num) {
    if (L == NULL) return L;
    int i = 0;
    while (i < num) {
        InsertNext(L, i + 1);
        i++;
    }
    return L;
}

DLinkList InitDLinkListOnTail (DLinkList L, int num) {
    if (L == NULL) return L;
    DLNode *tail = L;
    int i = 0;
    while (i < num) {
        DLNode *node = InsertNext(tail, i + 1);
        tail = node;
        i++;
    }
    return L;
}

DLNode *InsertNext (DLNode *p, int data) {
    if (p == NULL) return NULL;
    DLNode *tmp = p->next;
    DLNode *node = (DLNode *)malloc(sizeof(DLNode));
    node->data = data;
    node->next = tmp;
    node->prev = p;
    if (tmp != NULL) {
        tmp->prev = node;
    }
    p->next = node;
    return node;
}

BOOL DeleteNext (DLNode *p, int *res) {
    if (p == NULL) return FALSE;
    DLNode *tmp = p->next;
    if (tmp == NULL) return FALSE;
    p->next = tmp->next;
    tmp->prev = p;
    *res = tmp->data;
    free(tmp);
    return TRUE;
}

DLNode *GetELem (DLinkList L, int i) {
    if (L == NULL) return NULL;
    if (i < 1) return NULL;
    DLNode *curr = L->next;
    int j = 1;
    while (curr != NULL && j < i) {
        curr = curr->next;
        j++;
    }
    if (curr == NULL) return NULL;
    return curr;
}
