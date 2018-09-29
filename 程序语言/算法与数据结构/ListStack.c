#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;

typedef struct StackNode
{
    struct StackNode *next;
    ElemType data;
}StackNode, * StackNodePtr;

typedef struct
{
    int count;
    StackNodePtr top;
}LinkStack;

Status InitStack(LinkStack * S)
{
    S->top = NULL;
    S->count = 0;
    return OK;
}

Status ClearStack(LinkStack * S)
{
    StackNodePtr p, q;
    p = S->top;
    
    while(p){
        q = p;
        p = q->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

Status getTop(LinkStack S, ElemType * e)
{
    if (S.top == NULL)
    {
        return ERROR;
    }
    *e = S.top->data;
    return OK;
}

Status Pop(LinkStack * S, ElemType * e)
{
    if (S->top == NULL)
    {
        return ERROR;
    }
    StackNodePtr p;
    p = S->top;
    *e = p->data;
    S->top = p->next;
    free(p);
    S->count--;
    return OK;
    
}

Status Push(LinkStack * S, ElemType e)
{
    StackNodePtr p = (StackNodePtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return OK;
}

int getStackLength(LinkStack S)
{
    return S.count;
}
Status IsEmpty(LinkStack S)
{
    if(S.count == 0)
        return TRUE;
    else{
        return FALSE;
    }
}


int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        // printf("栈中元素依次为：");
        // StackTraverse(s);
        Pop(&s,&e);
        printf("top of stack e=%d\n",e);
        printf("is empty%d(1:yes 0:no)\n",IsEmpty(s));
        getTop(s,&e);
        printf("top element e=%d the length of stack%d\n",e,getStackLength(s));
        ClearStack(&s);
        printf("the stack is empty?:%d(1:yes 0:no)\n",IsEmpty(s));
        return 0;
}