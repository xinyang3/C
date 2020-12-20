/*
 * @description: 栈的定义
 * @author: xinayng3
 * @date: Do not edit
 * @lastEditTime: Do not Edit
 */
#define MAXSIZE 10

typedef struct {
    Elemtype data[MAXSIZE];
    int top;
} Stack

void InitStack (Stack &S) {
    S.top = -1;
}

bool EmptyStack(Stack &S) {
    if (s.top == -1)
        return true;
    return false;
}

bool PushStack(Stack &S, Elemtype e) {
    if (S.top == MAXSIZE - 1)
        return false;
    S.top = S.top +1;
    S.data[S.top] = e;
    return false;
}

bool PopStack(Stack &S, Elemtype &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    S.top = S.top -1;
    return true;
}

bool GetTop (Stack &S, Elemtype &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    // S.top = S.top -1;
    return true;
}