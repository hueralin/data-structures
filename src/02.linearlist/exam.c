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
SingleLinkList separateList (SingleLinkList head);
SingleLinkList separateList2 (SingleLinkList A);
int GetLen (SingleLinkList head);

int main () {
    SingleLinkList head = NULL;
    head = InitSingleLinkListOnHead(head, 6);
    // Insert(head, 6, 3);
    // PrintSingleLInkList(head);
    // printf("\n");
    // deleteNode(head, 3);
    // PrintSingleLInkList(head);
    // printf("\n");
    // SingleLinkList newList = Reverse(head);
    // DeleteMin(head);
    // ReverseNoExtra(head);
    // DeleteRange(head, 1, 4);
    SingleLinkList B = separateList2(head);
    PrintSingleLInkList(head);
    printf("\n");
    PrintSingleLInkList(B);
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
    int lenA = GetLen(headA);
    int lenB = GetLen(headB);
    int step = 0;
    Node *longList, *shortList;
    if (lenA > lenB) {
        step = lenA - lenB;
        longList = headA->next;
        shortList = headB->next;
    } else {
        step = lenB - lenA;
        longList = headB->next;
        shortList = headA->next;
    }
    while (step > 0) {
        longList = longList->next;
        step--;
    }
    while (longList != NULL) {
        if (longList == shortList) {
            return longList;
        } else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

int GetLen (SingleLinkList head) {
    if(head == NULL || head->next == NULL) return 0;
    int len = 0;
    Node *curr = head->next;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

SingleLinkList separateList (SingleLinkList A) {
    if (A == NULL || A->next == NULL) return NULL;
    int i = 0;
    // 新的头结点
    Node *B = (Node *)malloc(sizeof(Node));
    B->next = NULL;
    // 工作指针，用于遍历 A
    Node *curr = A->next;
    // 尾插法，用尾结点
    Node *rearA = A;
    Node *rearB = B;
    // 遍历 A，将奇数序号结点尾插入 A，偶数序号结点尾插入 B
    while (curr != NULL) {
        printf("xx\n");
        i++;
        if (i % 2 != 0) {
            rearA->next = curr;
            rearA = curr;
        } else {
            rearB->next = curr;
            rearB = curr;
        }
        curr = curr->next;
    }
    // 记得将 A、B 的尾指针的 next 置空
    // 否则还会和之前的链表有关联
    // 如：
    // A：5->3->1->null
    // B：4->2->1->NULL（按理说 B 应该只有 4->2，但是 2 还保留着之前的链接关系）
    rearA->next = NULL;
    rearB->next = NULL;
    return B;
}

SingleLinkList separateList2 (SingleLinkList A) {
    if (A == NULL || A->next == NULL) return NULL;
    int i = 0;
    // 偶数头插
    Node *B = (Node *)malloc(sizeof(Node));
    B->next = NULL;
    // 奇数尾插
    Node *rearA = A;
    Node *curr = A->next;
    Node *tmp = NULL;
    while (curr != NULL) {
        i++;
        // 注意缓存下 curr->next
        tmp = curr->next;
        if (i % 2 != 0) {
            rearA->next = curr;
            rearA = curr;
        } else {
            curr->next = B->next;
            B->next = curr;
        }
        curr = tmp;
    }
    // 摘链尾插时，尾结点记得清空以前的链接关系
    rearA->next = NULL;
    return B;
}
