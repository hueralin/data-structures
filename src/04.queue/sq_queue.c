// 队列的顺序实现
// 取模运算:
// 1. 将存储空间在逻辑上变成了环状（循环队列）
// 2. 将无限的整数域映射到有限的整数集合上
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

void InitSqQueue (SqQueue *q) {
    // front 指向第一个元素的下标
    // rear 指向下一个元素的下标
    q->front = q->rear = 0;
}

BOOL IsEmpty(SqQueue *q) {
    if (q->front == q->rear) return TRUE;
    else return FALSE;
}

BOOL IsFull (SqQueue *q) {
    // 如果队尾指针的下一个位置是队首指针，那么说明队列满了
    // 也就是说会有一个空间浪费掉
    if ((q->rear + 1) % MaxSize == q->front) return TRUE;
    else return FALSE;
}

BOOL EnQueue (SqQueue *q, int data) {
    if (IsFull(q) == TRUE) {
        printf("The Queue is Full!\n");
        return FALSE;
    }
    // 从队尾入队
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % MaxSize;
    return TRUE;
}

BOOL DeQueue (SqQueue *q, int *data) {
    if (IsEmpty(q) == TRUE) {
        printf("The Queue is Empty!\n");
        return FALSE;
    }
    *data = q->data[q->front];
    q->front = (q->front + 1) % MaxSize;
    return TRUE;
}

BOOL GetHead (SqQueue *q, int *data) {
    if (IsEmpty(q) == TRUE) {
        printf("The Queue is Empty!\n");
        return FALSE;
    }
    *data = q->data[q->front];
    return TRUE;
}

int Size (SqQueue *q) {
    return (q->rear + MaxSize - q->front) % MaxSize;
}

// 上面的实现方式，浪费了一个空间，所以我们还可以以一种更简便的方式实现顺序队列
// 那就是多加一个 size 变量，用于记录队列中的元素个数
// 入队时 + 1，出队时 - 1，size = 0 为空，size = MaxSize 为满
// 判空判满（虽然此时 font == rear）、获取长度都通过 size 仅从操作，比较方便

// 我们这里 rear 指向队尾元素的下一个位置，但有时要求 rear 指向队尾元素，那么：
// 1. 初始化时：front = 0; rear = MaxSize - 1;
// 2. 判空时：(rear + 1) % MaxSize == front;
// 3. 判满时：
//      3.1 牺牲一个存储单元 (rear + 2) % MaxSize == front;
//      3.2 增加辅助变量 size 或 tag
// 4. 入队时：q->rear = (q->rear + 1) & MaxSize; q->data[q->rear] = data;
// 5. 出队时：data = q->data[q->front]; q->front = (q->front + 1) % MaxSize;（没变）
// 6. 队列长度：(rear + MaxSize + 1 - front) % MaxSize;

int main () {

    return 0;
}
