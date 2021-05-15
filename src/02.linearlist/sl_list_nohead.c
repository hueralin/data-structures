#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *SingleLinkList;

// 遍历单链表
void printList (SingleLinkList L);

// 获取第 i 个节点
LNode *GetELem (SingleLinkList L, int i);

// 向第 i 个位置上插入元素
SingleLinkList InsertNode (SingleLinkList L, int i, int data);

// 按值查找
LNode *LocateElem (SingleLinkList L, int data);

// 删除第 i 个节点
int DeleteNode (SingleLinkList L, int i);

// 构建单链表（头插法）
SingleLinkList InitSingleLinkListOnHead (SingleLinkList L, int num);
// 构建单链表（尾插法）
SingleLinkList InitSingleLinkListOnTail (SingleLinkList L, int num);

int main () {
	SingleLinkList L = NULL;
    L = InitSingleLinkListOnTail(L, 5);
	printList(L);
	return 0;
}

void printList (SingleLinkList L) {
	if (L == NULL) {
		printf("Empty");
		return;
	}
	LNode *curr = L;
	while (curr != NULL) {
		printf("value is %d\n", curr->data);
		curr = curr->next;
	}
}

LNode *GetElem (SingleLinkList L, int i) {
	if (i < 1) return NULL;
	if (L == NULL) return NULL;
	LNode *p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) return NULL;
	return p;
}

SingleLinkList InsertNode (SingleLinkList L, int i, int data) {
	if (i < 1) return L;
	// 如果是插入第一个位置，需要特殊处理下
	if (i == 1) {
		LNode *node = (LNode *)malloc(sizeof(LNode));
		node->data = data;
		node->next = L;
		L = node;
		return L;
	}
	// 否则，先找到第 i-1 节点
	LNode *p = GetElem(L, i - 1);
	if (p == NULL) return L;
	LNode *node = (LNode *)malloc(sizeof(LNode));
	node->data = data;
	node->next = p->next;
	p->next = node;
	return L;
}

LNode *LocateElem (SingleLinkList L, int data) {
	if (L == NULL) return NULL;
	LNode *p = L;
	while (p != NULL && p->data != data) {
		p = p->next;
	}
	return p;
}
int DeleteNode (SingleLinkList L, int i) {
	if (L == NULL) return -1;
	LNode *node = GetElem(L, i - 1);
	if (node == NULL) return -1;
	LNode *tmp = node->next;
	node->next = tmp->next;
	int res = tmp->data;
	free(tmp);
	return res;
}

SingleLinkList InitSingleLinkListOnHead (SingleLinkList L, int num) {
	int i = 0;
	while (i < num) {
		LNode *node = (LNode *)malloc(sizeof(LNode));
		node->data = i;
		node->next = L;
		L = node;
		i++;
	}
	return L;
}

SingleLinkList InitSingleLinkListOnTail (SingleLinkList L, int num) {
	// 指向最后一个结点的指针
	LNode *tail = L;
	int i = 0;
	while (i < num) {
		LNode *node = (LNode *)malloc(sizeof(LNode));
		node->data = i;
		node->next = NULL;
		if (i == 0) {
			L = node;
		} else {
			tail->next = node;
		}
		tail = node;
		i++;
	}
	return L;
}
