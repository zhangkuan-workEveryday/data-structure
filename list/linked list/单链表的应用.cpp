//单链表头插法尾插法拆分
//单链表中最大节点删除
//单链表递增（递减）排序
//单链表中间位置寻找

#include <iostream>
#include <stdlib.h>
using namespace std;
//————————————单链表节点定义————————————
typedef int Elemtype;
typedef struct LinkNode {
  Elemtype data;
  LinkNode *next;
} LinkNode;

//————————————单链表拆分——————————————
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2) {
  LinkNode *p = L->next;
  L->next = NULL;
  L1 = L;
  LinkNode *r1= L1;
  L2 = (LinkNode *)malloc(sizeof(LinkNode));
  L2->next = NULL;
  LinkNode *q;
  while (p !=NULL) {
    r1->next = p;
    r1 = p;
    p = p->next;
    q = p->next;
    p->next = L2->next;
    L2->next = p;
    p = q;
  }
  r1->next = NULL;
}

//————————————单链表的删除——————————————
void DeleteList(LinkNode *&L) {
  LinkNode *pre = L;
  LinkNode *p = L->next;
  LinkNode *maxpre = pre;
  LinkNode *maxp = p;
  while (p != NULL) {
    if (maxp->data < p->data) {
      maxp = p;
      maxpre = pre;
    }
    p = p->next;
  }
  maxpre->next = maxp->next;
  free (maxp);
}

//————————————单链表递增排序——————————————
void sort(LinkNode *&L) {
  LinkNode *p = L->next->next;
  LinkNode *q;
  LinkNode *pre = L;
  L->next->next = NULL;
  while (p !=NULL) {
    while (p->data > pre->next->data) {
      pre = pre->next;
    }
    q = p->next;
    p->next = pre->next;
    pre->next = p;
    p = q;
  }
}

//————————————单链表中间位置的元素——————————
Elemtype MidNode(LinkNode *&L) {
  LinkNode *p = L->next;
  LinkNode *q = L->next;
  while (q->next->next != NULL) {
    q = q->next->next;
    p = p->next;
  }
  return p->data;
}
