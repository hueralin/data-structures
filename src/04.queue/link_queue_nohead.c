// 队列的链式实现（不带头结点）
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
    // 初始化时，front 和 rear 都指向 NULL
    q->front = NULL;
    q->rear = NULL;
}

BOOL IsEmpty (LinkQueue *q) {
    if (q->front == NULL) return TRUE;
    else return FALSE;
}

void EnQueue (LinkQueue *q, int data) {
    // 尾插法
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    node->data = data;
    node->next = NULL;
    if (q->front == NULL) {
        // 插入第一个元素
        q->front = q->rear = node;
    } else {
        // 不是第一个元素
        q->rear->next = node;
        q->rear = node;
    }
}

void DeQueue (LinkQueue *q, int *data) {
    if (IsEmpty(q) == TRUE) {
        printf("The Queue is Empty!\n");
        return;
    }
    LinkNode *first = q->front;
    *data = first->data;
    q->front = first->next;
    if (q->rear = first) {
        // 出队的是最后一个结点
        // 这里 front 可以不用置空，因为上面已经设置了
        // 但是 rear 一定要置空
        q->front = NULL;
        q->rear = NULL;
    }
    free(first);
}

int size (LinkQueue *q) {
    if (IsEmpty(q) == TRUE) return 0;
    int size = 0;
    LinkNode *curr = q->front;
    while (curr != NULL) {
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
