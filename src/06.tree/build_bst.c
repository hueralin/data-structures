#include <stdio.h>
#include <stdlib.h>

typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *left, *right;
} BiTreeNode, *BiTree;

// “根节点” 的下标
int rootIndex = 0;
// 在中序序列中找到 val 的下标
int findRoot (int inOrderArr[], int inBegin, int inEnd, int val);
// 先序 + 中序 构建结点
BiTree buildBiTreeNodeWithPreIn (int preOrderArr[], int inOrderArr[], int inBegin, int inEnd);
// 先序 + 中序 组建二叉树
BiTree buildBiTreeWithPreIn (int preOrderArr[], int inOrderArr[], int inOrderArrLen);
// 先序遍历
void preOrder (BiTree root);
// 中序遍历
void inOrder (BiTree root);
// 后序遍历
void postOrder (BiTree root);

int main () {
    int preOrderArr[] = { 1, 2, 4, 5, 3 };
    int inOrderArr[] = { 4, 2, 5, 1 , 3 };
    int inOrderArrLen = sizeof(inOrderArr) / sizeof(inOrderArr[0]);
    BiTree root = buildBiTreeWithPreIn(preOrderArr, inOrderArr, inOrderArrLen);
    // 先序遍历
    preOrder(root);
    printf("\n");
    // 中序遍历
    inOrder(root);
    return 0;
}

int findRoot (int inOrderArr[], int inBegin, int inEnd, int val) {
    for (int i = inBegin; i <= inEnd; i++) {
        if (inOrderArr[i] == val) return i;
    }
    return -1;
}

// 分治法: 每一个结点都可以算作一棵二叉树中的根节点
// 在中序序列中找到根节点的位置，然后划分左右子树的边界
BiTree buildBiTreeNodeWithPreIn (int preOrderArr[], int inOrderArr[], int inBegin, int inEnd) {
    // 范围不合法，则退出
    if (inBegin > inEnd) return NULL;
    // 在中序序列中查找 “根节点” 的下标
    int index = findRoot(inOrderArr, inBegin, inEnd, preOrderArr[rootIndex]);
    // 若没找到，则退出
    if (index == -1) return NULL;
    // 若找到，则以 index 划分边界，分治构建
    BiTreeNode *root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    root->data = preOrderArr[rootIndex];
    rootIndex++;
    root->left = buildBiTreeNodeWithPreIn(preOrderArr, inOrderArr, inBegin, index - 1);
    root->right = buildBiTreeNodeWithPreIn(preOrderArr, inOrderArr, index + 1, inEnd);
    return root;
}

BiTree buildBiTreeWithPreIn (int preOrderArr[], int inOrderArr[], int inOrderArrLen) {
    if (preOrderArr == NULL || inOrderArr == NULL) return NULL;
    return buildBiTreeNodeWithPreIn(preOrderArr, inOrderArr, 0, inOrderArrLen - 1);
}

void preOrder (BiTree root) {
    if (root != NULL) {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder (BiTree root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d\n", root->data);
        inOrder(root->right);
    }
}

void postOrder (BiTree root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\n", root->data);
    }
}
