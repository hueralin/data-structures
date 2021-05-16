// 带头结点的循环单链表
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
} Node, *CLinkList;

// 判空
BOOL Empty (CLinkList head);
// 打印循环单链表
void PrintCLinkLIst (CLinkList head);
// 初始换循环单链表
CLinkList InitCLinkList ();
// 在某个结点后插入结点
Node *InsertNext (Node *node, int data);
// 在某个结点后删除结点
BOOL DeleteNext (Node *node, int *res);

int main () {
    CLinkList head = InitCLinkList();
    InsertNext(head, 1);
    InsertNext(head, 2);
    InsertNext(head, 3);
    InsertNext(head, 4);
    InsertNext(head, 5);
    PrintCLinkLIst(head);
    int res = 0;
    if (DeleteNext(head, &res) == TRUE) {
        printf("delete %d\n", res);
        PrintCLinkLIst(head);
    }
    return 0;
}

BOOL Empty (CLinkList head) {
    if (head == NULL || head->next == head) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void PrintCLinkLIst (CLinkList head) {
    if (Empty(head) == TRUE) {
        printf("CLinkList is Empty\n");
        return;
    }
    Node *curr = head->next;
    // 注意结束条件的变化
    while (curr != head) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

CLinkList InitCLinkList () {
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;
    return head;
}

Node *InsertNext (Node *node, int data) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = node->next;
    node->next = p;
    return p;
}

BOOL DeleteNext (Node *node, int *res) {
    if (node == NULL) return FALSE;
    Node *tmp = node->next;
    if (tmp == NULL) return FALSE;
    *res = tmp->data;
    node->next = tmp->next;
    free(tmp);
    return TRUE;
}