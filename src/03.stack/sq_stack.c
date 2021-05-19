// 顺序栈
#include <stdio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int top;
} SqStack;

void InitSqStack (SqStack *s) {
    s->top = -1;
}

void DestorySqStack (SqStack *s) {
    s->top = -1;
    // 数组会程序结束后自动被系统回收
}

BOOL Empty (SqStack *s) {
    if (s->top == -1) return TRUE;
    return FALSE;
}

BOOL Full (SqStack *s) {
    if (s->top == MaxSize - 1) return TRUE;
    return FALSE;
}

BOOL Push (SqStack *s, int data) {
    if (Full(s) == TRUE) return FALSE;
    s->data[++s->top] = data;
    return TRUE;
}

BOOL Pop (SqStack *s, int *data) {
    if (Empty(s) == TRUE) return FALSE;
    *data = s->data[s->top--];
    return TRUE;
}

BOOL Peek (SqStack *s, int *data) {
    if (Empty(s) == TRUE) return FALSE;
    *data = s->data[s->top];
    return TRUE;
}

void PrintSqStack (SqStack s) {
    if (Empty(&s) == TRUE) {
        printf("The SqStack is Empty!\n");
        return;
    }
    int index = s.top;
    while (index > -1) {
        printf("value is %d\n", s.data[index--]);
    }
}

int main () {
    SqStack s;
    InitSqStack(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 5);
    PrintSqStack(s);
    int data = 0;
    if (Pop(&s, &data) == TRUE) {
        printf("Delete success: %d\n", data);
    }
    if (Peek(&s, &data)) {
        printf("Peek: %d\n", data);
    }
    PrintSqStack(s);
    return 0;
}
