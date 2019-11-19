 //顺序表的并归
 //单链表的并归
 //有序表并归的应用
 //集合的交、并、差运算


 #include <iostream>
 #include <stdlib.h>
 using namespace std;

 //--------------------------------定义顺序、链表节点----------------------------
 #define MaxSize 50
 typedef int ElemType;
 typedef struct SqList {
   ElemType data[MaxSize];
   int length;
 } SqList;

 typedef struct LinkNode {
   ElemType data;
   LinkNode * next;
 } LinkNode;
//————————————顺序表的二路并归(不破坏原表)————————————
void  UnionList (SqList *LA, SqList *LB, SqList *&LC) {
  int i = 0;
  int j = 0;
  int k = 0;
  LC = (SqList *)malloc(sizeof(SqList));
  while (i < LA->length  ||  j < LB->length) {
    if (i < LA->length  &&  j < LB->length  &&  LA->data[i] < LB->data[j] ) {
      LC->data[k] = LA->data[i];
      i++;
    }
    else if (i < LA->length  &&  j < LB->length  &&  LB->data[i] < LA->data[j] ) {
      LC->data[k] = LB->data[j];
      j++;
    }
    else if (i >= LA->length) {
      LC->data[k] = LB->data[j];
      j++;
    }
    else {
      LC->data[k] = LA->data[i];
      i++;
    }
 }
}

//————————————链表的二路并归（不破坏原来的表格）——————————
void Un (LinkNode *LA, LinkNode  *LB, LinkNode *&LC) {
  LC = (LinkNode *)malloc (sizeof(LinkNode));
  LinkNode *r = LC;
  LinkNode *s;
  LinkNode *p = LA->next;
  LinkNode *q = LB->next;
  while (p != NULL || q != NULL){
    if (p != NULL  &&  q != NULL  && p->data < q->data) {
      s = (LinkNode *)malloc (sizeof(LinkNode));
      s->data = p->data;
      r->next = s;
      r = s;
      p = p->next;
    }
    else if (p != NULL  &&  q != NULL  && q->data < p->data) {
      s = (LinkNode *)malloc (sizeof(LinkNode));
      s->data = q->data;
      r->next = s;
      r = s;
      q = q->next;
    }
    else if (p == NULL) {
      s = (LinkNode *)malloc (sizeof(LinkNode));
      s->data = q->data;
      r->next = s;
      r = s;
      q = q->next;
    }
    else {
      s = (LinkNode *)malloc (sizeof(LinkNode));
      s->data = p->data;
      r->next = s;
      r = s;
      p = p->next;
    }
 }
 r->next = NULL;
}

//————————————两个集合求并集，含有相同的元素——————————
void Union (LinkNode *LA, LinkNode *LB, LinkNode *&LC) {
  LC = (LinkNode *) malloc (sizeof(LinkNode));
  LinkNode *p = LA->next;
  LinkNode *q = LB->next;
  LinkNode *r = LC;
  LinkNode *s;
  while (p != NULL  &&  q!= NULL) {
    if (p->data < q->data) {
      s = (LinkNode *) malloc (sizeof(LinkNode));
      s->data = p->data;
      r->next = s;
      r = s;
      p = p->next;
    }
    else if (q->data < p->data) {
      s = (LinkNode *) malloc (sizeof(LinkNode));
      s->data = q->data;
      r->next = s;
      r = s;
      q = q->next;
    }
    else {
      s = (LinkNode *) malloc (sizeof(LinkNode));
      s->data = p->data;
      r->next = s;
      r = s;
      p = p->next;
      q= q->next;
    }
  }
  if (q != NULL)
    p = q;
  while (p != NULL) {
    s = (LinkNode *) malloc (sizeof(LinkNode));
    s->data = p->data;
    r->next = s;
    r = s;
    p = p->next;
  }
  r->next = NULL;
}

//————————————三个集合求交集（充分利用空间）——————
void UN(LinkNode *&LA, LinkNode *LB, LinkNode *LC) {
  LinkNode *pa = LA->next;
  LinkNode *pb = LB->next;
  LinkNode *pc = LC->next;
  LinkNode *r = LC;
  LinkNode *q;
  while (pa != NULL) {
    while (pb->data < pa->data  && pb != NULL) {
      pb = pb->next;
    }
    while (pc->data < pa->data  && pc != NULL) {
      pc = pc->next;
    }
    if (pb != NULL  &&  pc != NULL  &&  pb->data == pa->data  && pc->data == pa->data) {
      r->next = pa;
      r = pa;
      pa = pa->next;
   }
   else {
     q = pa->next;
     free (pa);
     pa = q;
   }
 }
 r->next = NULL;
}

//————————————删除有序单链表中相同的元素———————————
void deleteNode (LinkNode *&LA) {
  LinkNode *p = LA->next;
  LinkNode *q;
  while (p != NULL) {
  if (p->data == p->next->data) {
    q = p->next;
    p->next = q->next;
    free (q);
  }
  else
    p = p->next;
}
}

//————————————两个集合求差（充分利用）——————————
void sub(LinkNode *&LA, LinkNode *&LB, LinkNode *&LC) {
  LinkNode *pa = LA->next;
  LinkNode *pb = LB->next;
  LC = LA;
  LinkNode *r;
  r = LC;
  while (pa != NULL  &&  pb != NULL) {
    if (pa->data < pb->data) {
      r->next = pa;
      pa = pa->next;
    }
    else if (pa->data > pb->data) {
      pb = pb->next;
    }
    else  {
      pa = pa->next;
      pb = pb->next;
    }
  }
  if (pb == NULL) {
    while (pa != NULL) {
      r->next = pa;
      pa = pa->next;
    }
  }
  r->next = NULL;
}
