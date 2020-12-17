/*
 * @Author: xinyang3
 * @Date: 2020-12-17 18:56
 * @Descripttion: awesome description
 * @LastEditors: xinyang3
 * @LastEditTime: 2020-12-17 19:17
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