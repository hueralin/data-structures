# 链表需要注意的代码问题

前提：链表带头结点

- 如何判空
    - 单链表：`head->next == NULL;`
    - 双链表：`head->next == NULL;`
    - 循环单链表：`head->next == head;`
    - 循环双链表：`head->next = head; head->prev = head;`
- 如何判断一个结点 p 是表头还是表尾结点
    - 单链表：`p == head;` `p->next == NULL;`
    - 双链表：`p == head;` `p->next == NULL;`
    - 循环单链表：`p == head;` `p->next == head;`
    - 循环双链表：`p == head;` `p->next == head;`
- 如何在表头、表中、表尾 插入/删除 一个结点
    - 单链表：
        - 插入：`node->next = p->next; p->next = node;`
        - 删除：`p->next = node->next; free(node);`
    - 双链表：
        - 插入：
            ```c++
                node->next = p->next;
                node->prev = p;
                // 需要考虑待插入位置的下一个结点是否为 NULL
                if (p->next != NULL) {
                    p->next->prev = node;
                }
                p->next = node;
            ```
        - 删除：
            ```c++
                p->next = node->next;
                // 需要考虑待删除结点的下一个结点是否为 NULL
                if (node->next != NULL) {
                    node->next->prev = p;
                }
                free(node);
            ```
    - 双链表要考虑待操作结点的下一个结点是否为 NULL 的情况
    - 循环双链表，因为是个环，所以没有 next 为 NULL 的结点，所以不需要考虑待作结点的下一个结点是否为 NULL
