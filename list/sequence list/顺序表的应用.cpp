//删除顺序表中值为  x 的元素
//将顺序表中的元素分为两类
#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct SqList {
  ElemType data[MaxSize];
  int length;
} SqList;

//--------------------------------删除顺序表中值为 X 的元素---------------------
void DeleteList_1(SqList *&L, ElemType x) {
  int i;
  int j = 0;
  for (i = 0; i < L->length; i++) {
    if (L->data[i] != x) {
      L->data[j] = L->data[i];
      j++;
    }
  }
}

void DeleteList_2(SqList *&L, ElemType x) {
  int k = 0;
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] == x)
      k++;
    L->data[i-k] = L->data[i];
  }
}


//--------------------------------顺序表中分两类---------------------------------
void part_1(SqList *&L) {
  int i = 0;
  int j = L->length - 1;
  while (i < j) {
    while (L->data[j]>0 && i<j)
      j--;
    while (L->data[i]<=0 && i<j)
      i++;
    if (i < j)
      swap(L->data[i], L->data[j]);
  }
}

void part_2(SqList *&L) {
  int i = 0;
  int j = L->length;
  ElemType x = L->data[0];
  while (i < j) {
    while (L->data[j]>0 && i<j)
      j--;
    if (i < j)
      swap(L->data[i],  L->data[j]);

    while (L->data[i]>=0 && i<j)
      i++;
    if(i < j)
      swap(L->data[j],  L->data[i]);
  }
  L->data[i] = x;
}

void part_3(SqList *&L) {
  int k = -1;
  for (int i = 0; i < L->length; i++) {
    if (L->data[i] <=0) {
      k++;
    swap(L->data[k], L->data[i]);
    }
  }
}
