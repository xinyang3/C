/*
 * @description:队列定义
 * @author: xinayng3
 * @date: Do not edit
 * @lastEditTime: Do not Edit
 */
typedef int Elemtype;
typedef struct SeQueue {
    Elemtype data;

} SqQueue;

void InitQueue(&Q);
void DestroyQueue(&Q);
EnQueue(&Q);
DeQueue(&Q);
GetHead(&Q);
QueueEmpty(&Q);