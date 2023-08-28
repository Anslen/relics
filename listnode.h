#ifndef LN_INCLUDED
#define LN_INCLUDED 1
#include <stdlib.h>

typedef struct node
{
    double value;
    struct node *next;//后一个节点
    struct node *prev;//前一个节点
} node;

typedef struct listnode
{
    node *start;
    node *end;
    int len;
} listnode;

listnode* ln_new(void)
{
    //新建一个链表
    listnode* ln = malloc(sizeof(listnode));
    ln->start = NULL;
    ln->end = NULL;
    ln->len = 0;
    return ln;
}

void ln_delall(listnode* ln)
{
    //删除一个链表
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
    //在链表中搜索一个数字，返回第一个匹配的索引
    //没有搜索到时返回-1
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
    //在一个节点后添加一个节点
    //添加第一个节点时可在obj传入NULL
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
    //在链表中删除一个节点
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
    //在链表中索引一个节点
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
