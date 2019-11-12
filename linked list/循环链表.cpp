//循环链表分为：单链表循环链表、双链表循环链表。
//循环链表尾指针的判断条件：p->next == L;
//单双链表的遍历
//链表是否对称
//两个循环链表合并成 一个链表

#include <iostream>
#include <stdlib.h>
using namespace std;

//————————————链表节点定义——————————————
typedef int ElemType;
typedef struct LinkNode {
  ElemType data;
  LinkNode * next;
} LinkNode;

typedef struct DLinkNode {
  ElemType data;
  DLinkNode *prior;
  DLinkNode *next;
} DLinkNode;

//——————————计算单链表中值为 x 节点的个数————————
int count(LinkNode *&L, ElemType x) {
  int i = 0;
  LinkNode *p = L->next;
  while (p !=  L) {
    if (p->data == x) {
      i++;
    }
      p = p->next;
  }
  return i;
}

//————————————删除双循环链表中第一个值为 x 的节点——————
bool delet(DLinkNode *&L, ElemType x) {
  DLinkNode *p = L->next;
  while (p->data != x  &&  p != L)
    p = p->next;
  if (p == L)
    return false;
  else {
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free (p);
  }
  return true;
}

//————————————判断双循环链表是否对称——————————
bool symm(DLinkNode *L) {
  bool same = true;
  DLinkNode *p = L->next;
  DLinkNode *q = L->prior;
  while (same) {                       //如何结束循环借鉴
    if (p->data != q->data)
      same = false;
    else if (p == q  ||  p->next ==q)
      break;
    else {
      p = p->next;
      q = q->next;
    }
  }
  return same;
}

//————————————将单循环链表合并————————————
void merge(LinkNode *&ha, LinkNode *&hb, LinkNode *&hc) {
  LinkNode *p = ha->next;
  hc = ha;
  while (p != ha)
    p = p->next;
  p->next = hb->next;
  while (p != hb)
    p = p->next;
  p->next = hc;
  free (hb);
}

//————————————将双链表有选则的合并————————————
void Merge(DLinkNode *&ha, DLinkNode *&hb, int i) {
  DLinkNode *p = ha->next;
  int length = 0;
  while (p != ha) {
    length++;
    p = p->next;
  }

  if (i == 0) {
    ha->next->prior = hb->prior;
    hb->prior->next = ha->next;
    ha->next = hb->next;
    hb->next->prior = ha;
  }
  else if (i < length){
    p = ha->next;
   for (int j = 0; j < i-1; j++)
    p = p->next;
  DLinkNode *post = p->next;
  p->next = hb->next;
  hb->next->prior = p;
  post->prior = hb->prior;
  hb->prior->next = post;
  }
  else {
    ha->prior->next = hb->next;
    hb->next->prior = ha->prior;
    hb->prior->next = ha;
    ha->prior = hb->prior;
  }
 }
