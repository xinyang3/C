2.2.3

AABDA CCCCBD

error 3

```c
// 1
bool deleteMin(SeqList &L, Elemtype &e) {
    if (L.length == 0)
        return false;
    int index = 0;
    Elemtype p = L.data[0];
    for(int i = 1; i < L.length; i ++) { // 找出最小值
        if (L.data[i] < p) {
            p = L.data[i];
            index = i;
        }
    }
    e = L.data[index];
    L.data[index] = L.data[L.length -1];
    L.length --;
    return true;
}
// 2
void SeqListRevert(SeqList &L) {
    Elemtype p;
    for(int i = 0; i < L.length/2; i ++) {
        p = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = p;
    }
}
// 3
void deleteAllValueX(SeqList &L) {
    int i = 0, k = 0;
    while(i < L.length) {
        if (L.data[i] == x) {
            k ++;
        } else {
            L.data[i-k] = L.data[i]; // 向前移k个
        }
    }
    L.length = L.length - k;
}
// 4 与3类似
bool deleteAllValueST (SqList &L, Elemtype s, Elemtype t){
  	if(L.length == 0)
        return false;
    if (s >= t)
        return false;
    int i = 0, k = 0;
    while(i < L.length) {
        if (l.data[i] > s && L.data[i] < t) {
            k ++;
        } else {
            L.data[i - k] = L.data[i];
        }
    }
 	L.length = L.length - k;
}
// 7
SqList * listMerge(SqList &L, SqList &M) {
    SqList r = (SqList *)malloc(sizeof(SqList));;
    int i = 0, j = 0, k = 0;
    while(i < L.length && j < M.length) {
        if(L.data[i] < L.data[j]) {
            r->data[k++] = L.data[i];
            i ++;
        } else {
            r->data[k++] = L.data[j];
        	j ++;
        }
    }
    while(i < L.length) {
        r->data[k++] = L.data[i];
    }
    while(j < L.length) {
        r->data[k++] = L.data[j];
    }
    r->length = k;
}
// 8
void moveList(SqList &L) {
    Elemtype temp[m];
    temp[1..m] = L[1...m]; // 数组存到临时变量temp
    for (i = m; i < m + n; i ++) {
        L.data[i - m] = L.data[i]; // m - m+n前移
    }
    int k = 0;
    for(i = n; i < m + n; i ++) {
        L.data[i] = temp[k ++];
    }
}
```

4、5、6 一类
11-13 12 题意不明确，12、13 计数排序法
重点 9-13

2.3.7

BBCDA <u>DCDC C</u>

BCDAD BDDCC

CCDCB

error: 6 7- 10 11 19 24 25
