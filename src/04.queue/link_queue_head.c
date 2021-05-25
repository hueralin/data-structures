// 队列的链式实现（带头结点）
#include <stdio.h>
#include <stdlib.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitLinkQueue (LinkQueue *q) {
    // 初始化时，front 和 rear 都指向头结点
    q->front = q->rear = (LinkNode *)malloc(sizeof(LinkNode));
    q->front = NULL;
}

BOOL IsEmpty (LinkQueue *q) {
    if (q->front == q->rear) return TRUE;
    else return FALSE;
}

void EnQueue (LinkQueue *q, int data) {
    // 尾插法
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->data = data;
    node->next = NULL;
    q->rear->next = node;
    q->rear = node;
}

void DeQueue (LinkQueue *q, int *data) {
    if (IsEmpty(q) == TRUE) {
        printf("The Queue is Empty!\n");
        return;
    }
    LinkNode *first = q->front->next;
    *data = first->data;
    q->front->next = first->next;
    if (q->rear = first) {
        // 出队的是最后一个结点，则修改 rear 指针
        q->rear = q->front;
    }
    free(first);
}

int size (LinkQueue *q) {
    if (IsEmpty(q) == TRUE) return 0;
    int size = 0;
    LinkNode *curr = q->front;
    while (curr->next != NULL) {
        curr = curr->next;
        size++;
    }
    return size;
}

int main () {
    LinkQueue q;
    InitLinkQueue(&q);
    return 0;
}
