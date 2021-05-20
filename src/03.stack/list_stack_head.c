// 带头结点的链栈
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkStack;

BOOL Empty (LinkStack s) {
    if (s == NULL || s->next == NULL) return TRUE;
    return FALSE;
}

LinkStack InitLinkStack (LinkStack s) {
    s = (Node *)malloc(sizeof(Node));
    s->next = NULL;
}

// 头删法
LinkStack DestoryLinkStack (LinkStack s) {
    if (s == NULL) return s;
    while (s->next != NULL) {
        Node *curr = s->next;
        s->next = curr->next;
        free(curr);
    }
    free(s);
    s = NULL;
    return s;
}

// 头插法
BOOL Push (LinkStack s, int data) {
    if (s == NULL) return FALSE;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = s->next;
    s->next = node;
    return TRUE;
}

// 头删法
BOOL Pop (LinkStack s, int *data) {
    if (Empty(s) == TRUE) return FALSE;
    Node *node = s->next;
    *data = node->data;
    s->next = node->next;
    free(node);
    return TRUE;
}

void PrintLinkStack (LinkStack s) {
    if (Empty(s) == TRUE) {
        printf("The Stack is Empty!\n");
        return;
    }
    Node *curr = s->next;
    while (curr != NULL) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

BOOL Peek (LinkStack s, int *data) {
    if (Empty(s) == TRUE) return FALSE;
    *data = s->next->data;
    return TRUE;
}

int main () {
    LinkStack s;
    s = InitLinkStack(s);
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    Push(s, 5);
    PrintLinkStack(s);
    int data = 0;
    Pop(s, &data);
    Pop(s, &data);
    PrintLinkStack(s);
    if (Peek(s, &data) == TRUE) {
        printf("value is %d\n", data);
    }
    s = DestoryLinkStack(s);
    printf("value is %p\n", s);
    PrintLinkStack(s);
    return 0;
}
