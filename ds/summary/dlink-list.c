typedef Elemtype int;

typedef struct DNode
{
    Elemtype data;
    DNode * prior;
    DNode * next;
} DNode, DLinkList
;
bool InitList(DLinkList &L) {
    DNode * p =(DNode *)malloc(sizeof(DNode));
    if (p == NULL)
        return false; 
    p->prior = NULL;
    p->next = NULL;
    L = p;
    return true;
}

// p之后插入s
bool InsertNextDNode (LNode * p, LNode *s) {
    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;    
    p->next = s;
    s->prior = p;
    return true;
}
// 删除后一个节点
bool DeleteNextDNode (LNode *p) {
    LNode * q = p->next;
    if (q == NULL)
        return false;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}


