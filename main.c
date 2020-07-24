#include <stdio.h>
#include "goods_management.h"

int CurrentCnt = 0;

int main()
{
    GoodsList* goodsList;
    init_list(&goodsList);
    
    int choice, pos;
    char id[MAX_ID_LEN];
    GoodsInfo goodsinfo;
    GoodsList* goodsNode;
    
    while (1)
    {
        printf("\n商品管理系统\n");
        printf("********************************************\n");
        printf("1.显示所有商品的信息:\n");
        printf("2.修改某个商品的信息:\n");
        printf("3.插入某个商品的信息:\n");
        printf("4.删除某个商品的信息:\n");
        printf("5.查找某个商品的信息:\n");
        printf("6.依商品价格进行排序:\n");
        printf("7.保存文件并退出系统:\n");
        printf("8.不保存文件并退出系统:\n");
        printf("9.(慎用)清空所有内容-文件和链表:\n");
        printf("********************************************\n");
        printf("输入您的选择: ");

        loop: scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            output_all_items(goodsList);
            break;
        case 2:
            printf("输入要修改记录的 ID：");
            read_line(id, MAX_ID_LEN);
            goodsinfo = read_goods_info();
            if(change_item(goodsList, id, goodsinfo))
                printf("修改成功。\n");
            else
                printf("修改失败。\n");
            
            break;
        case 3:
            goodsinfo = read_goods_info();
            printf("输入您要插入的位置(1:链表头部 -1:链表尾部)：");
            scanf("%d",&pos);
            if(insert_item(goodsList, goodsinfo, pos))
                printf("插入成功。\n");
            else
                printf("插入失败。\n");
            break;
        case 4:
            printf("输入要删除记录的 ID：");
            read_line(id, MAX_ID_LEN);
            if(delete_item(goodsList, id))
                printf("删除成功。\n");
            else
                printf("删除失败。\n");
            break;
        case 5:
            printf("输入要查找商品的 ID：");
            read_line(id, MAX_ID_LEN);
            goodsNode = search_item(goodsList, id);
            if(goodsNode != NULL)
                output_one_item(goodsNode);
            else
                printf("查找失败。\n");
            
            break;
        case 6:
            if(bubble_sort(goodsList))
                printf("排序成功。\n");
            else
                printf("排序失败。\n");
            break;
        case 7:
            if(save_to_file(goodsList) && destory_list(&goodsList))
            {
                printf("您已经保存文件并退出系统。\n");
                return 0;
            }

        case 8:
            if(destory_list(&goodsList))
                printf("您已经退出商品管理系统。\n");
            return 0;

        case 9:
            if(destory_list(&goodsList) && remove(GOODS_FILE_NAME) == 0)
                printf("您已经清空所有内容。\n");
            break;

        default:
            printf("请输入正确的选项：");
            goto loop;
        }
    }
}