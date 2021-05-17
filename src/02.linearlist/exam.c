#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *SingleLinkList;

Node *GetElem (SingleLinkList head, int i);
SingleLinkList Insert (SingleLinkList head, int i, int data);
SingleLinkList InitSingleLinkListOnHead (SingleLinkList head, int num);
void deleteNode (SingleLinkList head, int data);
void PrintSingleLInkList (SingleLinkList head);
SingleLinkList Reverse (SingleLinkList head);
void DeleteMin (SingleLinkList head);
void ReverseNoExtra (SingleLinkList head);
void IncreaseSort (SingleLinkList head);
void DeleteRange (SingleLinkList head, int start, int end);
Node *FindCommonNode (SingleLinkList headA, SingleLinkList headB);

int main () {
    SingleLinkList head = NULL;
    head = InitSingleLinkListOnHead(head, 5);
    // Insert(head, 6, 3);
    // PrintSingleLInkList(head);
    // printf("\n");
    // deleteNode(head, 3);
    PrintSingleLInkList(head);
    printf("\n");
    // SingleLinkList newList = Reverse(head);
    // DeleteMin(head);
    // ReverseNoExtra(head);
    DeleteRange(head, 1, 4);
    PrintSingleLInkList(head);
    return 0;
}

Node *GetElem (SingleLinkList head, int i) {
    if (head == NULL) return NULL;
    if (i < 1) return NULL;
    // 创建用于遍历的指针，指向第一个结点
    Node *curr = head->next;
    int j = 1;
    // 找到第 i 个结点
    while (curr != NULL && j < i) {
        curr = curr->next;
        j++;
    }
    if (curr == NULL) return NULL;
    return curr;
}

SingleLinkList Insert (SingleLinkList head, int i, int data) {
    if (head == NULL) {
        printf("The SingleLinkList is NULL\n");
        return head;
    }
    if (i < 1) {
        printf("Range Error\n");
        return head;
    }
    // 先找到第 i - 1 个结点
    Node *p = GetElem(head, i - 1);
    if (p == NULL) {
        printf("Range Error\n");
        return head;
    }
    // 插入
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = p->next;
    p->next = node;
    return head;
}

SingleLinkList InitSingleLinkListOnHead (SingleLinkList head, int num) {
    // 创建头结点
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head = head;
    // 头插法构建单链表
    int i = 0;
    while (i < num) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = i + 1;
        node->next = head->next;
        head->next = node;
        i++;
    }
    return head;
}

void deleteNode (SingleLinkList head, int data) {
    if (head == NULL) return;
    Node *curr = head->next;
    Node *prev = head;
    Node *tmp = NULL;
    while (curr != NULL) {
        if (curr->data == data) {
            tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            free(tmp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void PrintSingleLInkList (SingleLinkList head) {
    if (head == NULL) {
        printf("SingleLinkList is Empty\n");
        return;
    }
    Node *curr = head->next;
    while (curr != NULL) {
        printf("value is %d\n", curr->data);
        curr = curr->next;
    }
}

SingleLinkList Reverse (SingleLinkList head) {
    if (head == NULL) return NULL;
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->next = NULL;
    Node *curr = head->next;
    while (curr != NULL) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = curr->data;
        node->next = newHead->next;
        newHead->next = node;
        curr = curr->next;
    }
    return newHead;
}

void DeleteMin (SingleLinkList head) {
    if (head == NULL || head->next == NULL) return;
    int min = 0;
    Node *prev = head;
    Node *prevMin = head;
    Node *curr = head->next;
    min = curr->data;
    while (curr != NULL) {
        if (curr->data < min) {
            min = curr->data;
            prevMin = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    // 顶部判断了，所以这里的 minNode 不可能为空
    Node *minNode = prevMin->next;
    prevMin->next = minNode->next;
    free(minNode);
}

void ReverseNoExtra (SingleLinkList head) {
    if (head == NULL || head->next == NULL) return;
    // 创建新的头结点，辅助空间复杂度为 O(1)
    Node *newHead = (Node *)malloc(sizeof(Node));
    newHead->next = NULL;
    Node *curr = head->next;
    Node *tmp = NULL;
    // 头插法
    while (curr != NULL) {
        tmp = curr->next;
        curr->next = newHead->next;
        newHead->next = curr;
        curr = tmp;
    }
    // 卸磨杀驴
    head->next = newHead->next;
    free(newHead);
}

void IncreaseSort (SingleLinkList head) {
    if (head == NULL || head->next == NULL) return;
    Node *prevNode = head;
    Node *currNode = head->next;
    Node *nextNode = currNode->next;
    while (currNode != NULL && nextNode != NULL) {
        if (currNode->data > nextNode->data) {
            prevNode->next = nextNode;
            // 注意下面的顺序
            currNode->next = nextNode->next;
            nextNode->next = currNode;
            prevNode = nextNode;
            // currNode 不用变
            nextNode = currNode->next;
        } else {
            // 前进
            prevNode = currNode;
            currNode = nextNode;
            nextNode = currNode->next;
        }
    }
}

void DeleteRange (SingleLinkList head, int start, int end) {
    if (head == NULL || head->next == NULL) return;
    Node *prev = head;
    Node *curr = head->next;
    Node *tmp = NULL;
    while (curr != NULL) {
        if (curr->data > start && curr->data < end) {
            tmp = curr->next;
            // 删除
            prev->next = curr->next;
            free(curr);
            curr = tmp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

Node *FindCommonNode (SingleLinkList headA, SingleLinkList headB) {
    if (headA == NULL || headB == NULL) return NULL;
    if (headA->next == NULL || headB->next == NULL) return NULL;
    // 计算 A、B 的长度
    int lenA = 0;
    int lenB = 0;
    Node *curr = headA->next;
    while (curr != NULL) {
        lenA++;
        curr = curr->next;
    }
    curr = headB->next;
    while (curr != NULL) {
        lenB++;
        curr = curr->next;
    }
    // 计算差
    int step = 0;
    if (lenA > lenB) {
        step = lenA - lenB;
    } else {
        step = lenB - lenA;
    }
    // 长的链表前进 step 步
    int i = 0;
    if (lenA > lenB) {
        curr = headA->next;
        while (i < step) {
            curr = curr->next;
            i++;
        }
    } else {
        curr = headB->next;
        while (i < step) {
            curr = curr->next;
            i++;
        }
    }
    // 边遍历、边比较
    Node *pA = NULL;
    Node *pB = NULL;
    if (lenA > lenB) {
        pA = curr;
    } else {
        pB = curr;
    }
    while (pA != NULL && pB != NULL && pA != pB) {
        pA = pA->next;
        pB = pB->next;
    }
    if (pA == NULL) return pA;
    if (pB == NULL) return pB;
    return pA;
}
