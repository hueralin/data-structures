// 不带头结点的链栈
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkStack;

// 头删法
LinkStack DestoryLinkStack (LinkStack s) {
    while (s != NULL) {
        Node *curr = s;
        s = s->next;
        free(curr);
    }
    return s;
}

/* 因为没有头结点的链栈的 push、pop 操作都会改变头指针指向，所以需要返回 LinkStack */

// 头插法
LinkStack Push (LinkStack s, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = s;
    s = node;
    return s;
}

// 头删法
LinkStack Pop (LinkStack s, int *data) {
    *data = s->data;
    Node *p = s;
    s = s->next;
    free(p);
    return s;
}

void PrintLinkStack (LinkStack s) {
    if (s == NULL) {
        printf("The Stack is Empty!\n");
        return;
    }
    Node *curr = s;
    while (curr != NULL) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

BOOL Peek (LinkStack s, int *data) {
    if (s == NULL) return FALSE;
    *data = s->data;
    return TRUE;
}

int main () {
    LinkStack s = NULL;
    s = Push(s, 1);
    s = Push(s, 2);
    s = Push(s, 3);
    s = Push(s, 4);
    s = Push(s, 5);
    s = Push(s, 6);
    PrintLinkStack(s);
    int data = 0;
    s = Pop(s, &data);
    s = Pop(s, &data);
    PrintLinkStack(s);
    if (Peek(s, &data) == TRUE) {
        printf("value is %d\n", data);
    }
    s = DestoryLinkStack(s);
    printf("value is %p\n", s);
    PrintLinkStack(s);
    return 0;
}
