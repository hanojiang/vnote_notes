#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

Status ElemVisit(ElemType e)
{
    printf("%d\n", e);
    return OK;
}

Status InitStack(SqStack *s)
{
    // s->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    s->top = -1;
    return OK;
}

Status ClearStack(SqStack *s)
{
    s->top = -1;
    return OK;
}

Status IsEmpty(SqStack *s)
{
    if (s->top == -1)
        return TRUE;
    else
        return FALSE;
}

Status StackTop(SqStack s, ElemType *e)
{
    if (s.top == -1)
    {
        return ERROR;
    }
    *e = s.data[s.top];
    return OK;
}

Status StackPop(SqStack *s, ElemType *e)
{
    if (s->top == -1)
    {
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}

Status StackPush(SqStack *s, ElemType e)
{
    if (s->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    s->top++;
    s->data[s->top] = e;
    return OK;
}
int StackLength(SqStack s)
{
    return s.top + 1;
}

int main()
{
    printf("hello world");
    SqStack s;
    ElemType a = s.data[0];
    ElemVisit(a);
    printf("\n");
    SqStack *ss = (SqStack *)malloc(sizeof(s));
    ElemVisit(ss->data[0]);
    free(ss);
    printf("\n");

    SqStack s1;
    int t1;
    if(InitStack(&s1)==OK)
        for (int j = 0; j < 10; j++)
        {
            StackPush(&s1, j);
        }
    printf("length of s1 is %d\n", StackLength(s1));
    StackTop(s1, &t1);
    ElemVisit((ElemType)t1);
    int t2;
    StackPop(&s1, &t2);
    printf("length of s1 is %d\n", StackLength(s1));
    ClearStack(&s1);
    printf("after clear,length of s1 is %d\n", StackLength(s1));
    return 0;
}
