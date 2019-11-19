//双链表的基本操作
//初始化、创建、插入、删除
//销毁、是否为空、长度、打印查找（和单链表操作一样）

#include <iostream>
#include <stdlib.h>
using namespace std;

//————————————双链表节点定义—————————————
typedef int ElemType;
typedef struct DLinkNode {
  ElemType data;
  DLinkNode *prior;
  DLinkNode *next;
} DLinkNode;

//————————————双链表的初始化—————————————
void InitList(DLinkNode *&L) {
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  L->prior = NULL;
  L->next = NULL;
}

//————————————双链表的头插法创建———————————
void CreateListF(DLinkNode *&L, ElemType a[],  int n) {
  DLinkNode *s;
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  L->prior = NULL;
  L->next = NULL;
  for (int i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s ->data = a[i];
    s->next = L->next;
    if (L->next != NULL) {
        L->next->prior = s;
    }
    s->prior = L;
    L->next = s;
  }
}

//————————————双链表的尾插法创建——————————-
void CreateListR(DLinkNode *&L, ElemType a[], int n) {
  DLinkNode *s;
  DLinkNode *r;
  L = (DLinkNode *)malloc(sizeof(DLinkNode));
  L->prior = NULL;
  r = L;
  for (int i = 0; i < n; i++) {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->data = a[i];
    r->next = s;
    r = s;
  }
  r->next = NULL;
}

//————————————双链表的销毁——————————————
void DestroyList(DLinkNode *&L) {
  DLinkNode *pre = L;
  DLinkNode *p = pre->next;
  while (pre != NULL) {
    free(pre);
    pre = p;
    p = p->next;
  }
}

//————————————双链表的插入——————————————
bool InsertList(DLinkNode *&L, int k, ElemType x) {
  DLinkNode *s;
  DLinkNode *pre = L;
  int i = 0;
  if (k < 1)
    return false;
  while (i < k-1 && pre!=NULL) {
    pre = pre->next;
  }
  if (pre == NULL)
    return false;
  else {
    s = (DLinkNode *)malloc(sizeof(DLinkNode));
    s->next = pre->next;
    if (pre->next != NULL)
      pre->next->prior = s;
    s->prior = pre;
    pre->next = s;
  }
  return true;
}

//————————————链表的删除（已知位置）————————-
bool DeleteDNode(DLinkNode *&L, int k) {
  DLinkNode *pre = L;
  DLinkNode *p;
  int i = 0;
  if (k < 1)
    return false;
  while (i < k-1  &&  pre != NULL) {
    pre = pre->next;
  }
  if (pre ==NULL)
    return false;
  else {
    p = pre->next;
    if (p == NULL)
      return false;
    free (p);
  }
  return true;
}

//————————————链表元素查找(已知位置)————————
bool GetElem(DLinkNode *L, int k, ElemType e) {
  DLinkNode *p = L;
  int i = 0;
  if (k < 1)
    return false;
  while (i < k  &&  p != NULL) {
    p = p->next;
  }
  if (p == NULL)
    return false;
  e = p->data;
  return true;
}


//————————————双链表元素查找（已知data）—————
int LocateElem(DLinkNode *L, ElemType x) {
  DLinkNode *p = L->next;
  int i = 1;
  while (p->data != x  &&  p != NULL) {
    p = p->next;
    i++;
  }
  if (p == NULL)
    return 0;
  else
  return i;
}

//————————————双链表的空判断—————————————
bool EmptyList(DLinkNode *L) {
  if (L->next == NULL)
    return true;
  else
    return false;
}

//————————————链表长度计算——————————————
int ListLength(DLinkNode *L) {
  DLinkNode *p = L;
  int i = 0;
  while (p != NULL) {
    p = p->next;
    i++;
  }
  return i;
}

//————————————双链表的打印——————————————
void DisplayList(DLinkNode *L) {
  DLinkNode *p = L->next;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
}
