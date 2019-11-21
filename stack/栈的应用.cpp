//栈的应用：括号对称问题、其他对称问题
//栈的应用：中缀表达式转化成后缀表达式、后缀表达式的计算

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





//—————————————栈的应用——————————————————
//括号配对问题
bool match(char exp[], int n) {
  ElemType e;
  SqStack *st;
  InitStack(st);
  for (int i = 0; i < n; i++) {
    if (exp[i] == '(' )
      push(st, exp[i]);
    else if (exp[i] == ')' ) {
      if (StackEmpty(st)) {
        DestroyStack(st);
        return false;
      }
      pop(st, e);
    }
  }
  if (StackEmpty(st)) {
    DestroyStack(st);
    return true;
  }
  else {
    DestroyStack(st);
    return false;
  }
}


//——————————————左右对称问题——————————-
bool symmetry(char exp[]) {
  ElemType e;
  SqStack *st;
  InitStack(st);
  for (int i = 0; exp[i] != '\0'; i++) {
    push(st, exp[i]);
  }
  for (int i = 0; exp[i] != '\0'; i++) {
    pop(st, e);
    if (exp[i] != e ) {
      DestroyStack(st);
      return false;
    }
  }
  DestroyStack(st);
  return true;
}


//————————————将中缀表达式转化成后缀表达式——————
void trans(char *exp, char postexp[]) {
    int i = 0;
    ElemType e;
    SqStack *st;
    InitStack(st);
    while (*exp != '\0') {
        switch (*exp) {
        case ('+' ) :
        case ('-') :
            while (!StackEmpty(st)) {
                GetTop(st, e);
                if (e != '(') {
                    pop(st, e);
                    postexp[i++] = e;
               }
               else break;
            }
            push(st, *exp);
            break;
        case ('*' || '/') :
            while (!StackEmpty(st)) {
                GetTop(st, e);
                if (e == '*' || e == '/') {
                pop(st, e);
                postexp[i++] = e;
                }
                else break;
            }
            push(st, *exp);
            break;
        default :
            while (*exp >= '0' && *exp <= '9') {
            postexp[i++] = *exp;
            }
            postexp[i++] = '#';
        }
        exp++;
  }
  while (!StackEmpty(st)) {
    pop(st, e);
    postexp[i++] = e;
  }
  postexp[i] = '\0';
  DestroyStack(st);
}

//————————————后缀表达式求值——————————————
int  compvalue (char *postexp) {
    int a, b, c;
    int d;
    int f;
    ElemType e;
    SqStack *st;
    InitStack(st);
    while (*postexp != '\0') {
        switch (*postexp) {
        case ('+') :
              pop(st, e);
              a = e;
              pop(st, e);
              b = e;
              c = b + a;
              push (st, c);
              break;
        case ('-') :
              pop(st, e);
              a = e;
              pop(st, e);
              b = e;
              c = b - a;
              push(st, c);
              break;
          case ('*') :
                pop(st, e);
                a = e;
                pop(st, e);
                b = e;
                c = b * a;
                push(st, c);
                break;
        case ('/') :
                pop(st, e);
                a = e;
                if (a != '0'){
                pop(st, e);
                b = e;
                c = b / a;
                push(st, c);
                break;
              }
       default :
             d = 0;
             while (*postexp >= '0' && *postexp <= '9') {
               d = d*10 + *postexp;
               postexp++;
             }
             push (st, d);
    }
    postexp++;
  }
  pop(st, f);
  return f;
}
