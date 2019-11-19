//栈的链式存储结构——链栈
//链栈：只在链首进行插入和删除操作.

#include <iostream>
#include <stdlib.h>
typedef int ElemType;
//————————————定义链栈节点——————————————
typedef struct LinkStNode {
  ElemType data;
  struct LinkStNode * next;
} LinkStNode;

//————————————链栈的初始化——————————————
void InitStack(LinkStNode *&s) {
  s = (LinkStNode *) malloc ( sizeof(LinkStNode) );
  s->next = NULL;
}

//————————————链栈的插入（入栈）————————————
void push(LinkStNode *s, ElemType e) {
  LinkStNode *p = (LinkStNode *) malloc ( sizeof(LinkStNode) );
  p->data = e;
  p->next = s->next;
  s->next = p;
}

//————————————链栈的删除（退栈）————————————
bool pop(LinkStNode *s, ElemType &e) {
  LinkStNode *p;
  if (s->next == NULL)
    return false;
  p = s->next;
  s->next = p->next;
  e = p->data;
  free (p);
  return true;
}

//————————————判断栈是否为空——————————————
bool StackEmpty(LinkStNode *s) {
  return (s->next == NULL);
}

//————————————取栈顶元素————————————————
bool GetTop(LinkStNode *s, ElemType &e) {
  if (s->next == NULL)
    return false;
  e = s->next->data;
  return true;
}
