//交换两个元素位置
//双链表的逆置
//双链表中的元素排序
//增加一个评率调用函数
 #include <iostream>
 #include <stdlib.h>
 using namespace std;
//————————————双链表的节点定义————————————
 typedef int ElemType;
 typedef struct DLinkNode {
   ElemType data;
  DLinkNode *next;
  DLinkNode *prior;
} DLinkNode;

//————————————双链表的元素位置的交换(前提：互换两元素位置已知，删除后面的元素)——————————
void swap(DLinkNode *&L, DLinkNode *p) {
  DLinkNode *pre;
  pre = p->prior;
  if (pre != NULL) {
    pre->next = p->next;
    if (p->next != NULL)
      p->next->prior = pre;
  }
  pre->prior->next = p;
  p->prior = pre;
  p->next = pre;
  pre->prior = p;
}

//————————————双链表的排序——————————————
void sort(DLinkNode *&L) {
  DLinkNode *p = L->next->next;
  DLinkNode *q;
  DLinkNode *s = L->next;
  L->next->next = NULL;
  while (p != NULL) {
    q = p->next;
    while (p->data > s->data  &&  s != NULL)
      s = s->next;
    if (s == NULL) {
      s->prior->next = p; //先
      p->prior = s->next;
      p->next = s; //后，防止 s 前一个节点位置丢失
      s->prior = p;
    }
    p = q;
  }
}

//————————————双链表元素的逆置————————————
void reserve(DLinkNode *&L) {
  DLinkNode *q;
  DLinkNode *p = L->next;
  L->next = NULL;
  while (p != NULL) {
    q = p->next;
    p->next = L->next;
    if (L->next != NULL)
      L->next->prior = p;
    L->next = p;
    p->prior = L;
    p = q;
  }
}

//补充：将一个链表中的第一个x找出，按照“频率”排序
typedef int ElemType;
typedef struct LinkNode {
  ElemType data;
 LinkNode *next;
 LinkNode *prior;
 int freq;
} LinkNode;

bool Located(LinkNode *&H, ElemType x) {  //找，准备，交换+更新pre
  LinkNode *p = H->next;
  LinkNode *pre;
  while (p->data != x  && p != NULL) {
    p = p->next;
  }
  if (p == NULL)
    return false;
  else {
    p->freq++;       //将数据更新
    pre = p->prior;  //增加前指针
    while (p->prior >= pre->prior  &&  pre != NULL) {   //交换两元素（前提：不为头结点，最后更新pre）
      p->prior = pre->prior;    //将pre提取出来
      pre->prior->next = p;

      p->next->prior = pre;   //将pre插入
      pre->next = p->next;
      p->next = pre;
      pre->prior = p;

      pre = p->prior;       //更新pre
    }
  }
  return true;
}


//交换要两个指针，删前删后都一样。
//循环里面可以更新
