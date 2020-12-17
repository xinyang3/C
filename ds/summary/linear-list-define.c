/*
 * @Author: xinyang3
 * @Date: 2020-12-17 18:49
 * @Descripttion: awesome description
 * @LastEditors: xinyang3
 * @LastEditTime: 2020-12-17 18:55
 */

void InitList(&L);
void DestroyList(&L);

void ListInsert(&L, int i, ElemType e);
void ListDelete(&L, int i);

void LocateElem(&L, ElemType e);
void GetElem(&L, ElemType e);

int Length(&L);
void PrintList(&L);
int Empty(&L);