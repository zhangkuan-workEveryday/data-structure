//顺序表的基本操作：
//初始化、创建、销毁、插入、删除、是否为空、长度返回、打印、查找
#include <iostream>
#include <stdlib.h>
using namespace std;

//--------------------------------定义顺序表节点----------------------------
#define MaxSize 50
typedef int ElemType;
typedef struct SqList {
  ElemType data[MaxSize];
  int length;
} SqList;

//--------------------------------顺序表的初始化----------------------------
void InitList(SqList *&L) {
  L =  (SqList *)malloc(sizeof(SqList));
  L->length = 0;
}

//--------------------------------顺序表的建立-----------------------------
void CreatList(SqList *&L, ElemType a[], int n) {
  int i;
  L = (SqList *)malloc(sizeof(SqList));
  for (i = 0; i < n; i++) {
    L->data[i] = a[i];
  }
  L->length = n;
}

//--------------------------------顺序表的销毁-----------------------------
void DestroyList(SqList *&L) {
  free(L);
}

//-------------------------------顺序表的插入------------------------------
//注意物理位置和逻辑位置的转换
bool InsertList(SqList *&L, int k, ElemType e) {
  int i;
  if (k<1 || k>L->length)
    return false;
else
  k--;              //将逻辑位置换成物理存储位置
for (i = L->length; i > k; i--){
  L->data[i] = L->data[i-1];
}
L->length++;
return true;
}

//--------------------------------顺序表的删除-----------------------------
bool DelList(SqList *&L, ElemType x) {
  int i = 0;
  int j;
  while (L->data[i] != x && i<L->length) {
    i++;
  }
  if (i < L->length) {
    for (j = i; j < L->length-1; j++) {
      L->data[j] = L->data[j+1];
    }
  L->length--;
    return true;
  }
else
  return false;
}

//--------------------------------顺序表是否为空，长度判断，打印----
bool ListEmpty(SqList *L) {
  return (L->length == 0);
}

int ListLength(SqList *L) {
  return L->length;
}

void DisplayList(SqList *L) {
  for (int i = 0; i < L->length; i++) {
    cout << L->data[i] <<"  " ;
  }
  cout << endl;
}

//--------------------------------顺序表元素的查找---------------------------
//位置序号查找
bool LocateList(SqList *L, ElemType x, int &k) {
  int i = 0;
  while (i<L->length && L->data[i]!=x)
    i++;
  if (i < L->data[i]) {
    k = i+1;
    return true;
  }
  else
    return false;
}

//元素值查找
bool GetElem(SqList *L, ElemType &e, int k) {
  if (k < 1 || k>L->length)
  return false;
else
 e = L->data[k];
 return true;
}
