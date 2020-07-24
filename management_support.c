#include <stdio.h>
#include <ctype.h>

#include "goods_management.h"

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ( isspace(ch = getchar()) );

    while (ch != '\n' && ch != EOF)
    {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }

    str[i] = '\0';
    return i;
}

GoodsInfo read_goods_info()
{
    GoodsInfo goodsInfo;

    printf("输入你要插入的商品信息：\n");
    printf("商品ID：");
    read_line(goodsInfo.goods_id, MAX_ID_LEN);
    printf("商品名称：");
    read_line(goodsInfo.goods_name, MAX_NAME_LEN);
    printf("商品价格：");
    scanf("%d", &goodsInfo.goods_price);
    printf("商品折扣：");
    read_line(goodsInfo.goods_discount, MAX_DISCOUNT_LEN);
    printf("商品数量：");
    scanf("%d", &goodsInfo.goods_amount);
    printf("商品剩余：");
    scanf("%d", &goodsInfo.goods_remain);

    return goodsInfo;
}

void output_one_item(GoodsList *L)
{
    if (L != NULL)
    {
        printf("%s\t", L->data.goods_id);
        printf("%s\t", L->data.goods_name);
        printf("%d\t", L->data.goods_price);
        printf("%s\t", L->data.goods_discount);
        printf("%d\t", L->data.goods_amount);
        printf("%d\n", L->data.goods_remain);
    }
    else
        printf("商品信息不存在。\n");
}