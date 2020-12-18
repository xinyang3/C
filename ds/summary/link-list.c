typedef Elemtype int;
typedef struct {
  Elemtype data;
  LNode * next;
} LNode, * LinkList

bool InitList (LinkList &L) {
  L = NULL;
  return true;
}

bool InitList(LinkList &L) {
  LNode * node = (LNode *)malloc(sizeof(LNode));
  if (!node)
    return false;
  node.next = NULL;
  L = node;
  return true;
}

// 带头结点，L指向空节点
bool ListInsert (LinkList &L, int i, Elemtype e) {
  if(i < 1)
    return false;
  
  LinkList p = L;
  int j = 0;
  // 指向最后或i-1
  while (p != NULL && j < i -1) {
    p = p->next;
    j++;
  }
  LNode * node = (LNode *)malloc(sizeof(LNode));
  if (node == NULL)
    return false;
  node->data = e;
  node->next = p->next;
  p->next = node;
  return true;
}
// 带头节点
bool ListDelete(LinkList &L, int i, Elemtype &e) {
  if (i < 1) 
    return false;
  LNode * p = L;
  int j = 0;
  while(p != NULL && i < i -1) {
    p = p->next;
    j ++;
  }
  LNode * q = p->next;
  p->next = p->next->next;
  e = q->data;
  free(q);
}

LNode GetElem(LinkList &L, int i) {
  if (i == 0)
    return L;
  if (i < 0)
    return NULL;
  
  LNode * p = (LNode *)malloc(sizeof(LNode));
  int j = 0;
  p = L;
  while(p && j < i) {
    p = p->next;
    j ++;
  }
  return p;
}

LNode LocateElem (LinkList &L, Elemtype e) {
  int i = 0;
  LNode * p = L;
  while(p && p->data != e) {
    p = p->next;
    i ++;
  }
  return p;
}
int Length (LinkList &L) {
  LNode * p = p->next;
  if (!p) {
    return 0;
  }
  int length = 1;
  while(p) {
    p = p->next;
    length ++;
  }
  return length;
}

// 不带头
bool ListInsert (LinkList &L, i, Elemtype e) {
  if(i < 1)
    return false;
  if (i == 1) {
    LNode * q = (LNode *)malloc(sizeof(LNode));
    L = q;
    return true;
  }

  LinkList p = L;
  int j = 1;
  // 指向最后或i-1
  while (p != NULL && j < i -1) {
    p = p->next;
    j++;
  }
  LNode * node = (LNode *)malloc(sizeof(LNode));
  if (node == NULL)
    return false;
  node->data = e;
  node->next = p->next;
  p->next = node;
  return true;
}