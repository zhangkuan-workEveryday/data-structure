//顺序队列：采用单链表，将头结点稍作修改
#include <iostream>
#include <stdlib.h>
using namespace std;

//————————————定义修改后的头结点、其他节点———————
typedef int ElemType;
typedef struct DataNode {
  ElemType data;
  struct DataNode * next;
} DataNode;

typedef struct {
  DataNode *front;
  DataNode *rear;
} LinkQuNode;

//————————————链队的初始化——————————————
void InitQueue(LinkQuNode *&q) {
  q = (LinkQuNode *) malloc (sizeof(LinkQuNode));
  q->rear = NULL;
  q->front = NULL;
}

//————————————链队的插入——————————————
void EnQueue(LinkQuNode *&q, ElemType x) {
  DataNode *p;
  p = (DataNode *) malloc (sizeof(DataNode));
  p->next = NULL;
  if (q->front == NULL) {
    q->front = NULL;
    q->rear = NULL;
  }
  else {
    p->next = q->rear->next;
    q->rear->next = p;

  }
}
