# SeqList 顺序表

##### SeqList.h

```c
#include "Common.h"

typedef int ElemType;

typedef struct {
	ElemType* data;
	int length;		// 长度
	int capacity;	// 容量
}SeqList;

// 顺序表的初始化，cap 代表容量 O(1)
Status SeqListInit(SeqList* L, int cap);

// 在 Pos 位置插入元素 e O(n)
Status SeqListInsertByPos(SeqList* L, int Pos, ElemType e);

// 在 Pos 位置删除元素 O(n)
Status SeqListDeleteByPos(SeqList* L, int Pos);

// 在 Pos 位置查找元素，并将结果放到 Res 上 O(n)
Status SeqListFindByPos(SeqList* L, int Pos, ElemType* Res);

// 获取指定元素 e 在顺序表中的位置，找不到则返回 0 O(n)
int SeqListLocateElem(SeqList* L, ElemType e);

// 获取顺序表的长度 O(1)
int SeqListGetLength(SeqList* L);

// 判断线性表是否为空 O(1)
int SeqListIsEmpty(SeqList* L);

// 清空顺序表 O(1)
void SeqListClear(SeqList* L);

// 销毁顺序表（以后还得再申请空间）O(1)
void SeqListDestory(SeqList* L);
```

##### SeqList.c

```c
#include "Common.h"
#include "SeqList.h"
#include <stdlib.h>

// 顺序表的初始化
Status SeqListInit(SeqList* L, int Cap) {
	L->data = (ElemType*)malloc(sizeof(ElemType) * Cap);
	if (!L->data) exit(OVERFLOW); // 存储分配失败
	L->length = 0;
	return OK;
}

// 在 Pos 位置插入元素 e
Status SeqListInsertByPos(SeqList* L, int Pos, ElemType e) {
	// 检查 Pos 是否合法
	if (Pos < 1 || Pos > L->length + 1) return ERROR;
	// 检查是否还有剩余空间
	if (L->length == L->capacity) return ERROR;
	// 向后移动元素
	for (int i = Pos - 1; i < L->length; i++) {
		L->data[i + 1] = L->data[i];
	}
	// 插入元素
	L->data[Pos - 1] = e;
	L->length++;
	return OK;
}

// 在 Pos 位置删除元素
Status SeqListDeleteByPos(SeqList* L, int Pos) {
	// 检查 Pos 是否合法（顺便处理了顺序表为空的情况）
	if (Pos < 1 || Pos > L->length) return ERROR;
	// 向前移动元素
	for (int i = Pos; i < L->length; i++) {
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return OK;
}

// 在 Post 位置查找元素
Status SeqListFindByPos(SeqList* L, int Pos, ElemType* Res) {
	// 检查 Pos 是否合法
	if (Pos < 1 || Pos > L->length) return ERROR;
	*Res = L->data[Pos - 1];
	return OK;
}

// 获取指定元素 e 在顺序表中的位置
int SeqListLocateElem(SeqList* L, ElemType e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) i++;
	if (i == L->length) return 0;
	else return i + 1;
}

// 获取顺序表的长度
int SeqListGetLength(SeqList* L) {
	return L->length;
}

// 判断线性表是否为空
int SeqListIsEmpty(SeqList* L) {
	return L->length == 0 ? 1 : 0;
}

// 清空顺序表
void SeqListClear(SeqList* L) {
	L->length = 0;
}

// 销毁顺序表
void SeqListDestory(SeqList* L) {
	if (L->data) free(L->data); // 释放存储空间
}
```
