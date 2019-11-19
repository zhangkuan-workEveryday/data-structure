//因为顺序表插入和删除的运行时间慢；且顺序表中，数组大小要提前已知；
//所以为了避免插入删除的时间开销；所以使用链表。
//链表分为：单链表，双链表，循环链表

//单链表操作：初始化、创建（头插和尾插）、销毁、插入，删除
//空表、长度、打印、查找（已知位置，已知数值）

#include <iostream>
#include <stdlib.h>
using namespace std;

//————————————链表节点定义——————————————
typedef int Elemtype;
typedef struct LinkNode {
  Elemtype data;
  LinkNode * next;
} LinkNode;

//————————————链表的初始化——————————————
void InitList(LinkNode *&L) {
  L = (LinkNode *)malloc(sizeof(LinkNode));
  L->next = NULL;
}

//————————————链表头插法创建————————————
void CreateListF(LinkNode *&L, Elemtype a[], int n) {
LinkNode *s;
L = (LinkNode *)malloc(sizeof(LinkNode));
L->next = NULL;
for (int i = 0; i < n; i++) {
  s = (LinkNode *)malloc(sizeof(LinkNode));
  s->data = a[i];
  s->next = L->next;
  L->next = s;
}
}

//————————————链表尾插法创建————————————
void CreatListR(LinkNode *&L, Elemtype a[], int n) {
  LinkNode *s;
  LinkNode *r;
  L = (LinkNode *)malloc(sizeof(LinkNode));
  r = L;
  for (int i = 0; i < n; i++) {
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = a[i];
    r->next = s;
    r = s;
  }
  r->next = NULL;
}

//————————————链表的销毁——————————————
void DestroyList(LinkNode *&L) {
  LinkNode *pre = L;
  LinkNode *p= pre->next;
  while (p!= NULL) {
    free (pre);
    pre = p;
    p = p->next;
  }
  free(pre);
}

//————————————链表元素插入（指定位置 插入）——————————————
bool InsertList(LinkNode *&L, int k, Elemtype e) {
  LinkNode *s;
  LinkNode *pre = L;
  int j = 0;
  if (k < 0)
    return false;
  while (pre!=NULL && j<k-1 ) {
    pre = pre->next;
    j++;
  }
  if (pre == NULL)
    return false;
  else {
    s = (LinkNode  *)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
  }
  return true;
}

//————————————链表元素的删除（指定位置元素删除）——————————————
bool DeleteList(LinkNode *&L, int i, Elemtype &e) {
  LinkNode *pre = L;
  LinkNode *p;
  int j = 0;
  if (i < 1)
    return false;
  while (j<i-1 && pre!=NULL) {
    pre = pre->next;
    j++;
  }
  if (pre == NULL)
  return false;
  else {
    p = pre->next;
    if (p == NULL)
      return false;
    e = p->data;
    pre->next = p->next;
    free(p);
  }
  return true;
}
//经过3次判断来寻找位置 i 是否合法；

//————————————元素值的查找（已知位置）—————————
bool GetElem(LinkNode *L, int k, Elemtype &e) {
  if (k < 1)
    return false;
  LinkNode *p = L;
  int j = 0;
  while (j < k && p!=NULL) {
    j++;
    p = p->next;
  }
  if (p == NULL)
    return false;
  else
    e = p->data;
  return true;
}

//————————————元素值的查找（已知元素大小）————————
int LocateElem(LinkNode *L, Elemtype x) {
  LinkNode *p = L->next;
  int i = 1;
  while (p->data != x && p!=NULL) {
    p = p->next;
    i++;
  }
  if (p == NULL)
    return 0;
  else
    return i;
}

//————————————链表是否为空表————————————————
bool EmptyList(LinkNode *L) {
  return (L->next == NULL);
}

//————————————链表的打印————————————————
void DisplayList(LinkNode *L) {
  LinkNode *p = L->next;
  while(p != NULL) {
    cout << p->data << "、";
    p = p->next;
  }
  cout << endl;
}
