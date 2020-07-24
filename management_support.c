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

    printf("������Ҫ�������Ʒ��Ϣ��\n");
    printf("��ƷID��");
    read_line(goodsInfo.goods_id, MAX_ID_LEN);
    printf("��Ʒ���ƣ�");
    read_line(goodsInfo.goods_name, MAX_NAME_LEN);
    printf("��Ʒ�۸�");
    scanf("%d", &goodsInfo.goods_price);
    printf("��Ʒ�ۿۣ�");
    read_line(goodsInfo.goods_discount, MAX_DISCOUNT_LEN);
    printf("��Ʒ������");
    scanf("%d", &goodsInfo.goods_amount);
    printf("��Ʒʣ�ࣺ");
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
        printf("��Ʒ��Ϣ�����ڡ�\n");
}