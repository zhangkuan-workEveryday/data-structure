//树的存储有两种：顺序存储、链式存储。
//树的链式存储又分为：双亲链式存储、孩子链式存储、孩子兄弟链式存储。

//二叉树的链式存储基本操作有：创建二叉树（已知括号表达式）、输出二叉树（按括号表达式输出）
//查找特定值的节点、查找节点的孩子节点、求高度、销毁二叉树。

//—————————————二叉树的节点————————————
#include <iostream>
#include<stdlib.h>
using namespace std;
#define ELemType int
#define MaxSize 20
typedef struct node {
    ELemType data ;
    struct node * lchild;
    struct node * rchild;
} BTNode;

//————————————二叉树的创建（已知括号表达式）——————
void  CreateBTree(BTNode *&b, char *str) {
    BTNode *St[MaxSize];
    int top = -1;
    int j = 0;
    int k;
    char ch;
    BTNode *p;
    b = NULL;
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode *)malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = NULL;
                p->rchild = NULL;
                if (b == NULL)
                    b = p;
                else {
                    switch (k)
                        case 1: St[top]->lchild = p;
                        case 2: St[top]->rchild = p;
                }
        }
        j++;
        ch = str[j];
    }
}

//————————————二叉树的销毁——————————————
void DestroyBTree(BTNode *&b) {
    if ( b!= NULL) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free (b);
    }
}

//————————————查找特定值的节点————————————
BTNode * FindNode(BTNode *b, ELemType x) {
    BTNode *p;
    if (b == NULL)
        return NULL;
    else if (b->data == x)
        return b;
    else {
        p = FindNode (b->lchild, x);
        if (p == NULL)
            return p;
        else
            return FindNode(b->rchild, x);
    }
}

//————————————找孩子节点———————————————
BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

//————————————求树的高度————————————————
int BTHeight(BTNode *b) {
    int lchildh, rchildh;
    if (b == NULL)
        return 0;
    else {
        lchildh = BTHeight(b->lchild);
        rchildh = BTHeight(b->rchild);
        return (lchildh > rchildh) ? lchildh : rchildh;
    }
}

//————————————树的输出————————————————
void DispBTree(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        if (b->lchild != NULL || b->rchild != NULL) {
            cout << '(';
            DispBTree(b->lchild);
            if (b->rchild != NULL)
                cout << ',';
            DispBTree(b->rchild);
            cout << ')';
        }
    }
}

//————————————二叉树的遍历——————————————
void PreOrder(BTNode *b) {
    if (b != NULL) {
        cout << b->data;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(BTNode *b) {
    if (b != NULL) {
        InOrder (b->lchild);
        cout << b->data;
        InOrder (b->rchild);
    }
}

void PostOrder(BTNode *b) {
    if (b != NULL) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        cout << b->data;
    }
}
