/*
 * @Author: xinyang3
 * @Date: 2020-12-17 18:56
 * @Descripttion: awesome description
 * @LastEditors: xinyang3
 * @LastEditTime: 2020-12-17 19:54
 */

#define MAXSIZE 10
typedef struct {
  ElemType data[MAXSIZE];
  int length;  
} SeqList;

// 静态
void InitList(&L) {
  for(int i = 0; i <MAXSIZE; i++) {
    L.data[i] = 0;
  }
  L.length = 0;
}
// i位序
bool ListInsert(&L, int i, ElemType e) {
  if (i < 1 || i > L.length + 1) 
    return false;
  if (i > L.MAXSIZE) 
    return false;
  for(int k = L.length; k >= i; k --) {
    L.data[k] = L.data[k-1]; //
  }
  L.data[i-1] = e; // i-1
  L.length ++;
  return true;
}
// 删除
bool ListDelete(&L, int i, ElemType &e) {
  if (i < 1 || i > L.length) 
    return false;
  e = L.data[i-1];
  for(int k = i; k < L.length; k++) { // 前移动
    L.data[k-1] = L.data[k];
  }
  L.length --;
  return true;
}

bool GetElem (&L, int i, ElemType &e) {
  e = L.data[i-1];
}

int LocateElem(&L, ElemType e) {
  for(int i = 0; i < L.length; i ++) {
    if (L.data[i] == e) {
      return i+1;
    }
  }
  return 0;
}




// 动态
typedef struct {
  ElemType * data;
  int length;
  int MAXSIZE;  
} SeqList;

// 动态线性表初始化
void InitList(&L, int MAXSIZE) {
  L = (SeqList *) malloc(MAXSIZE*(sizeof(ElemType)));
  L.length = 0;
  L.MAXSIZE = MAXSIZE;
}
// 扩张
void increaseList(&L, int size) {
  ElemType * p = L.data;
  L.data = (ElemType *) malloc((L.MAXSIZE + size)*(sizeof(ElemType)));
  for(int i = 0; i < L.length; i ++) {
    L.data[i] = p.data[i];
  }
  L.MAXSIZE = L.length + size;
  free(p);
}

void main() {
  SeqList L;

}