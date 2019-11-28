//计算机内存按字编址，而一个字包含多个字节。一个字节可以存放一个字符。
//所以，一个字（一个地址）可以存放多个字符。
//串中的字符按照存放方式的不同，分为紧缩格式：节省空间，但是处理单个字符麻烦，运算效率低
//非紧缩格式：浪费空间，但是处理单个字符，连续字符方便，运算效率高。这里主要讨论非紧缩格式

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 50
//————————————顺序串的声明——————————————
typedef struct {
  char data[MaxSize];
  int length;
} SqString;

//————————————顺序串的生成——————————————
void StrAssign(SqString &s, char cstr[]) {
    int i;
    for (i = 0; cstr[i] != '\0'; i++)
        s.data[i] = cstr[i];
    s.length = i;
}

//————————————顺序串的复制——————————————
void StrCopy(SqString &s, SqString t) {
    for (int i = 0; i < t.length; i++)
        s.data[i] = t.data[i];
    s.length = t.length;
}

//————————————顺序串的连接——————————————
SqString concat(SqString s, SqString t) {
    SqString str;
    int i;
    str.length = s.length + t.length;
    for (i = 0; i < s.length; i++)
        str.data[i] = t.data[i];
    for (i = 0; i < t.length; i++)
        str.data[i+s.length] = t.data[i];
    return str;
}

//————————————顺序串的销毁——————————————
void DestroyStr(SqString &s) {

}
//因为顺序串是用本身表示，而不是用指针表示。所以顺序串的存储空间是有操作系统管理
//即由操作系统分配器存储空间，并在其超出作用域时候释放其存储空间。

//————————————求串长度—————————————————
int StrLength(SqString s) {
    return (s.length);
}

//————————————判断两个串是否相等————————————
bool StrEqual(SqString s, SqString t) {
    if (s.length != t.length)
        return false;
    else {
        for (int i = 0; i < s.length; i++) {
            if (s.data[i] != t.data[i])
                return false;
        }
        return true;
    }
}

//————————————串的输出————————————————
void displayStr(SqString s) {
    if (s.length > 0) {
        for (int i = 0; i < s.length; i++) {
                cout << s.data[i] << endl;
        }
    }
}

//————————————求子串————————————————
SqString SubStr(SqString s, int i, int j) {
    int k;
    SqString str;
    str.length = 0;
    if (i < 1 || i >s.length || i+j-1>s.length)
        return str;
    for (k = 0; k < j; k++)
        str.data[k] = s.data[k+i-1];
    return str;
}

//—————————————字串的插入————————————
SqString InsertStr(SqString s1, int i, SqString s2) {
    SqString str;
    str.length = 0;
    if (i<1 || i>str.length+1)
        return str;
    for (int k = 0; k < i-1; k++)
        str.data[k] = s1.data[k];
    for (int k = 0; k < s2.length; k++)
        str.data[k+i-1] = s2.data[k];
    for (int k = i-1; k < s1.length; k++)
        str.data[i+s2.length-1] = s1.data[k];
    return str;
}


//—————————————子串的删除————————————
SqString DeleteStr(SqString s, int i, int j) {
    SqString str;
    str.length = 0;
    if (i < 1 || i > s.length || i+j-1>s.length)
        return str;
    for (int k = 0; k < i-1; k++)
        str.data[k] = s.data[k];
    for (int k = i+j-2; k < s.length; k++)
        str.data[k-j] = str.data[k];
    return str;
}

//————————————子串的替换——————————————
SqString ReplyStr(SqString s, int i, int j, SqString t) {
    SqString str;
    str.length = 0;
    if (i<1 || i>s.length || i+j-1 >s.length )
        return str;
    for (int k = 0; k < i-1; k++)
        str.data[k] = s.data[k];
    for (int k = 0; k < t.length; k++)
        str.data[i+k] = t.data[k];
    for (int k = i-1; i < s.length; k++)
        str.data[k+j] = s.data[k];
    return str;
}
