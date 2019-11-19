//队列是操作受到限制的线性表：只能在一端插入，一端删除。
//顺序队：队空q->rear == q->front;  队满：q->rear == MaxSize-1
//对比顺序栈：栈空top == -1;  栈满：top == MaxSize - 1;

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 50
//————————————队结构的声明——————————————
typedef int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int front;
  int rear;
} SqQueue;

//————————————队列的初始化——————————————
void InitQueue(SqQueue *&q) {
  q = (SqQueue *) malloc (sizeof(SqQueue));
  q->front = -1;
  q->rear = -1;
}

//————————————队列的插入（入队）————————————
bool EnQueue(SqQueue *&q, ElemType e) {
  if (q->rear == MaxSize - 1)
    return false;
  else {
    q->rear++;
    q->data[q->rear] = e;
    return true;
  }
}


//————————————队列的删除（出队）————————————
bool DeQueue(SqQueue *&q, ElemType &e) {
  if (q->front == q->rear)
    return false;
  else {
    e = q->data[q->front];
    q->front++;
    return true;
  }
}

//————————————队列的销毁————————————————
void DestroyQueue(SqQueue *&q) {
  free (q);
}

//————————————判断队列是否为空——————————————
bool QueueEmpty(SqQueue *q) {
  return (q->front == q->rear);
}
