#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
  ElemType data;
  struct LinkNode * next;
} LinkNode;

void InitQueue(LinkNode *&rear) {
  rear = NULL;
}

void EnQueue(LinkNode *&rear, ElemType x) {
  LinkNode *p;
  p = (LinkNode *) malloc (sizeof(LinkNode));
  p->data = x;
  if (rear == NULL) {
    p->next = p;
    rear = p;
  }
  else {
    p->next =rear->next;
    rear->next = p;
    rear = p;
  }
}


//注意  链队的删除  要考虑三种情况
bool DeQueue(LinkNode *&rear, ElemType &x) {
  LinkNode *t;
  if (rear == NULL)
    return false;
  else if (rear == rear->next ) {
    x = rear->data;
    free (rear);
    rear = NULL;
    return true;
  }
  else {
    t = rear->next;
    x= t->data;
    rear->next = t->next;
    free (t);
    return true;
  }
}

void DestroyQueue(LinkNode *&rear) {
  if (rear == NULL)
    cout <<"链队为空，不需要删除\n";
  LinkNode *pre = rear->next;
  LinkNode *p = pre->next;
  while (p != NULL) {
      free (pre);
      p = p->next;
  }
}

bool QueueEmpty(LinkNode *rear) {
  return (rear == NULL);
}
