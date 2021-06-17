#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *left, *right;
} BiTreeNode, *BiTree;

void PreOrder (BiTree t) {
    if (t != NULL) {
        printf("%d\n", t->data);
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder (BiTree t) {
    if (t != NULL) {
        PreOrder(t->left);
        printf("%d\n", t->data);
        PreOrder(t->right);
    }
}

void PostOrder (BiTree t) {
    if (t != NULL) {
        PreOrder(t->left);
        PreOrder(t->right);
        printf("%d\n", t->data);
    }
}

// 递归算法的控件复杂度是 O(h + 1)，即 O(h)，h 是二叉树的高度，1 是叶子结点的子结点也要处理
// 这三种遍历方式，每个结点都会被路过（访问）三次

// 应用：求树的高度（先求左右子树高度的较大者，然后再加一）
int treeDepth (BiTree t) {
    // 后序遍历
    if (t == NULL) return 0;
    int l = treeDepth(t->left);
    int r = treeDepth(t->right);
    return l > r ? l + 1 : r + 1;
}

int main () {

    return 0;
}