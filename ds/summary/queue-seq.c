/*
 * @description: 队列的操作
 * @author: xinayng3
 * @date: Do not edit
 * @lastEditTime: Do not Edit
 */
#define MAXSIZE 10
typedef struct SqQueue {
    Elemtype data[MAXSIZE];
    int front;
    int rear;
} SqQueue

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool EmptyQueue(SqQueue, &Q) {
    if (Q.front == Q.rear) {
        return true;
    }
    return false;
}

bool EnQueue(SqQueue &Q, Elemtype &e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear +1) % MAXSIZE;
    return true;
}
bool DeQueue(SqQueue &Q, Elemtype &e) {
    if (Q.front = Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}
bool GetHead (SqQueue &Q, Elemtype &e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
}