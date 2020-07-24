#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "goods_management.h"

void init_list(GoodsList **L)
{
    *L = (GoodsList *)malloc(sizeof(GoodsList));

    GoodsInfo goodsInfo;
    GoodsList *temp = *L;

    FILE *fp = fopen(GOODS_FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("提示：无法读取商品文件\n");
        fclose(fp);
        return;
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s", goodsInfo.goods_id);
            fscanf(fp, "%s", goodsInfo.goods_name);
            fscanf(fp, "%d", &goodsInfo.goods_price);
            fscanf(fp, "%s", goodsInfo.goods_discount);
            fscanf(fp, "%d", &goodsInfo.goods_amount);
            fscanf(fp, "%d\n", &goodsInfo.goods_remain);

            GoodsList *node = (GoodsList *)malloc(sizeof(GoodsList));
            node->data = goodsInfo;
            temp->next = node;
            temp = node;

            CurrentCnt++;
        }
    }
    fclose(fp);
    temp->next = NULL;

    printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}

void output_all_items(GoodsList *L)
{
    L = L->next;

    while (L != NULL)
    {
        output_one_item(L);
        L = L->next;
    }
}

bool change_item(GoodsList *L, char *goods_id, GoodsInfo new_info)
{
    GoodsList *t = search_item(L, goods_id);
    if (t != NULL)
    {
        t->data = new_info;
        return true;
    }
    else
    {
        printf("插入失败\n");
        return false;
    }
}

bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice)
{
    if (CurrentCnt >= MAX_GOODS_AMOUNT)
    {
        printf("信息库已满，要插入请先删除部分商品数据!\n");
        return false;
    }
    else if(choice == 0 || choice > CurrentCnt + 1)
    {
        printf("插入位置不合法。\n");
        return false;
    }
    else if(choice < 0)
        choice = CurrentCnt + 2 + choice;
    
    GoodsList *q, *p , *temp;

    q= L;
    p = L->next;
            
    for(int i = 1; i < choice && p != NULL; i++)
    {
        q = p;
        p = p->next;
    }
    temp = (GoodsList *)malloc(sizeof(GoodsList));
    temp->data = goodsInfo;
    temp->next = p;
    q->next = temp;
    CurrentCnt++;

    return true;
}

bool delete_item(GoodsList *L, char *goods_id)
{
    GoodsList *q, *p = L;
    while (strcmp(p->data.goods_id, goods_id) != 0 && p != NULL)
    {
        q = p;
        p = p->next;
    }

    if (p != NULL)
    {
        q->next = p->next;
        free(p);
        CurrentCnt = CurrentCnt - 1;

        return true;
    }
    else
        return false;
}

GoodsList *search_item(GoodsList *L, char *goods_id)
{
    GoodsList *p = L->next;

    while (p != NULL)
    {
        if (strcmp(p->data.goods_id, goods_id) == 0)
            return p;
        else
            p = p->next;
    }

    return NULL;
}

bool save_to_file(GoodsList *L)
{
    if (L == NULL)
    {
        printf("链表不存在。\n");
        return false;
    }

    FILE *fp;
    if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
    {
        printf("无法打开商品文件\n");
        return false;
    }

    GoodsList *p = L->next;
    while (p != NULL)
    {
        fprintf(fp, "%s\t", p->data.goods_id);
        fprintf(fp, "%s\t", p->data.goods_name);
        fprintf(fp, "%d\t", p->data.goods_price);
        fprintf(fp, "%s\t", p->data.goods_discount);
        fprintf(fp, "%d\t", p->data.goods_amount);
        fprintf(fp, "%d\n", p->data.goods_remain);
        p = p->next;
    }
    fclose(fp);
}

bool bubble_sort(GoodsList *L)
{
    if (L == NULL)
    {
        printf("链表不存在。\n");
        return false;
    }
    else if (L->next == NULL)
    {
        printf("当前链表中没有商品\n");
        return false;
    }

    GoodsList *p;   
    GoodsInfo temp;
    for (int i = 0; i < CurrentCnt - 1; ++i)
    {
        p = L->next;
        for (int j = 0; j < CurrentCnt - 1 - i; ++j)
        {
            if (p->data.goods_price > p->next->data.goods_price)
            {
                temp = p->next->data;
                p->next->data = p->data;
                p->data = temp;
            }
            p = p->next;
        }
    }
    return true;
}

bool destory_list(GoodsList **L)
{
    if (L == NULL || *L == NULL)
    {
        printf("链表不存在。\n");
        return false;
    }

    GoodsList *p = *L, *t;
    while (p != NULL)
    {
        t = p->next;
        free(p);
        p = t;
    }

    *L = NULL;
    CurrentCnt = 0;
    return true;
}
