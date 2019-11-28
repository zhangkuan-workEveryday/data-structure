//按照字典顺序比较两个串的大小
//求一个顺序串中的第一个最长的连续相同字符构成的子串

#include <iostream>
using namespace std;
#define MaxSize 50

typedef struct {
    char data[MaxSize];
    int length;
} SqString;

int StrCom(SqString s, SqString t) {
    int comlen;
    if (s.length < t.length)
        comlen = s.length;
    else
        comlen = t.length;
    for (int i = 0; i < comlen; i++) {
        if (s.data[i] < t.data[i])
            return -1;
        else if (s.data[i] > t.data[i])
            return 1;
    }
    if (s.length == t.length)
        return 0;
    else if (s.length < t.length)
        return -1;
    else
        return 1;
}


void LongestString(SqString s, int &index, int maxlen) {
    int length, i =1, start;
    index = 0;
    maxlen = 1;
    while (i < s.length) {
        start = i -1;
        length = 1;
        while (i < s.length && s.data[i] == s.data[i-1]) {
            i++;
            length++;
        }
        if (length > maxlen) {
            index = start;
            maxlen = length;
        }
        i++;
    }
}
