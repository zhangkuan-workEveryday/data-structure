//顺序循环队列：新的元素会覆盖原来的元素。
//  ****双端队列***：两端都可以进出元素

//前进操作：rear = (rear + 1) % MaxSize;   front = (front + 1) % MaxSize
//队满判断：(rear + 1) % MaxSize == front
//个数计算：(rear - front + MaxSize ) % MaxSize

#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct{
  ElemType data[MaxSize];
  int front;
  int rear;
} SqQueue;

void IntiQueue(SqQueue *&qu) {
  qu = (SqQueue *) malloc (sizeof(SqQueue));
  qu->front = 0;
  qu->rear = 0;
}

bool EnQueue(SqQueue *&qu, ElemType e) {
  if ((qu->rear+1) % MaxSize  ==  qu->front)
    return false;
  else {
    qu->rear = (qu->rear +1) % MaxSize;
    qu->data[qu->rear] = e;
    return true;
  }
}

bool DeQueue(SqQueue *&qu,  ElemType &e) {
  if (qu->rear == qu->front )
    return false;
  else {
    qu->front = (qu->front +1) % MaxSize;
    e = qu->data[qu->front];
    return true;
  }
}

void DestroyQueue(SqQueue *&qu) {
  free (qu);
}

bool QueueEmpty(SqQueue *qu) {
  return (qu->front == qu->rear);
}
