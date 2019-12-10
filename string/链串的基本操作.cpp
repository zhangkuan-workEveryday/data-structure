//串是特殊的线性表，串中的元素都是单个的字符，所以一个存储单元可以存储多个字符
//串有求子串，子串的替换，串的连接线性表所没有的操作
//用带头结点的单链表来存储串。
#include <iostream>
#include <stdlib.h>
using namespace std;

//————————————串的节点类型——————————————
typedef struct node {
    char data;
    struct node *next;
} LinkStrNode;

//————————————生成串——————————————————
void StrAssign(LinkStrNode *&s, char cstr[]) {
    LinkStrNode *r, *p;
    s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = s;
    for (int i = 0; cstr[i] != '\0'; i++) {
        p = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        p->data = cstr[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

//————————————串的复制————————————————
void StrCopy(LinkStrNode *&s, LinkStrNode *t) {
    LinkStrNode *p = t->next;
    LinkStrNode *q, *r;
    s = (LinkStrNode *)malloc(sizeof(LinkStrNode));
    r = s;
    while (p != NULL) {
        q = (LinkStrNode *)malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = NULL;
}

//————————————链串的连接——————————————
