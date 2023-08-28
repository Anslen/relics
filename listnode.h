#ifndef LN_INCLUDED
#define LN_INCLUDED 1
#include <stdlib.h>

typedef struct node
{
    double value;
    struct node *next;//��һ���ڵ�
    struct node *prev;//ǰһ���ڵ�
} node;

typedef struct listnode
{
    node *start;
    node *end;
    int len;
} listnode;

listnode* ln_new(void)
{
    //�½�һ������
    listnode* ln = malloc(sizeof(listnode));
    ln->start = NULL;
    ln->end = NULL;
    ln->len = 0;
    return ln;
}

void ln_delall(listnode* ln)
{
    //ɾ��һ������
    node* ptr = ln->start;
    node* next;
    while(ptr != NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(ln);
}

int ln_search(listnode* ln,double num)
{
    //������������һ�����֣����ص�һ��ƥ�������
    //û��������ʱ����-1
    int index = 0;
    node* ptr = ln->start;
    while(ptr != NULL)
    {
        if(ptr->value == num)
        {
            return index;
        }
        ptr = ptr->next;
        index++;
    }
    return -1;
}

void ln_add(listnode *ln,node *obj,double num)
{
    //��һ���ڵ�����һ���ڵ�
    //��ӵ�һ���ڵ�ʱ����obj����NULL
    node *add = malloc(sizeof(node));
    add->value = num;
    if(ln->start = NULL)
    {
        add->prev = NULL;
        add->next = NULL;
        ln->start = add;
        ln->end = add;
    }
    else if(obj->next = NULL)
    {
        obj->next = add;
        add->prev = obj;
        add->next = NULL;
        ln->end = add;
    }else
    {
        add->next = obj->next;
        add->next->prev = add;
        obj->next = add;
        add->prev = obj;
    }
    ln->len++;
}

void ln_delnode(listnode *ln,node *obj)
{
    //��������ɾ��һ���ڵ�
    if(obj == ln->start)
    {
        ln->start = obj->next;
        obj->next->prev = NULL;
        free(obj);
    }else if(obj == ln->end)
    {
        ln->end = obj->prev;
        obj->prev->next = NULL;
        free(obj);
    }else
    {
        obj->prev->next = obj->next;
        obj->next->prev = obj->prev;
        free(obj);
    }
    ln->len--;
}

node* ln_index(listnode *ln,int index)
{
    //������������һ���ڵ�
    if(index >= ln->len)
    {
        return NULL;
    }
    node *out = ln->start;
    int n = 0;
    while(n < index)
    {
        out = out->next;
        n++;
    }
    return out;
}

#endif
