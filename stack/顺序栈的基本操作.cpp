//栈属于线性结构，是只能在一端进行插入和删除的线性表。
// * 栈的初始化、入栈、出栈、栈的销毁、栈是否为空、取栈顶元素

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 50

//————————————声明栈的类型———————————————
typedef  int ElemType;
typedef struct {
  ElemType data[MaxSize];
  int top;
}SqStack;

//————————————栈的初始化————————————————
void InitStack(SqStack *&s) {
  s = (SqStack *) malloc (sizeof(SqStack));
  s->top = -1;
}

//—————————————进栈——————————————————
bool push(SqStack *&s, ElemType e) {
  if (s->top == MaxSize - 1)
    return false;
  else {
    s->top++;
    s->data[s->top] = e;
  }
  return true;
}

//————————————出栈——————————————————
bool pop(SqStack *&s, ElemType &e) {
  if (s->top == -1)
    return false;
  else {
    e = s->data[s->top];
    s->top--;
  }
  return true;
}

//————————————栈的销毁————————————————
void DestroyStack(SqStack *&s) {
  free (s);
}

//————————————栈是否为空————————————————
bool StackEmpty(SqStack *s) {
  return (s->top == -1);
}

//—————————————取栈顶元素——————————————
bool GetTop(SqStack *s, ElemType &e) {
  if (s->top == -1)
    return false;
  else {
    e = s->data[s->top];
    return true;
  }
}
