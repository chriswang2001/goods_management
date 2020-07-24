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
        printf("\n��Ʒ����ϵͳ\n");
        printf("********************************************\n");
        printf("1.��ʾ������Ʒ����Ϣ:\n");
        printf("2.�޸�ĳ����Ʒ����Ϣ:\n");
        printf("3.����ĳ����Ʒ����Ϣ:\n");
        printf("4.ɾ��ĳ����Ʒ����Ϣ:\n");
        printf("5.����ĳ����Ʒ����Ϣ:\n");
        printf("6.����Ʒ�۸��������:\n");
        printf("7.�����ļ����˳�ϵͳ:\n");
        printf("8.�������ļ����˳�ϵͳ:\n");
        printf("9.(����)�����������-�ļ�������:\n");
        printf("********************************************\n");
        printf("��������ѡ��: ");

        loop: scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            output_all_items(goodsList);
            break;
        case 2:
            printf("����Ҫ�޸ļ�¼�� ID��");
            read_line(id, MAX_ID_LEN);
            goodsinfo = read_goods_info();
            if(change_item(goodsList, id, goodsinfo))
                printf("�޸ĳɹ���\n");
            else
                printf("�޸�ʧ�ܡ�\n");
            
            break;
        case 3:
            goodsinfo = read_goods_info();
            printf("������Ҫ�����λ��(1:����ͷ�� -1:����β��)��");
            scanf("%d",&pos);
            if(insert_item(goodsList, goodsinfo, pos))
                printf("����ɹ���\n");
            else
                printf("����ʧ�ܡ�\n");
            break;
        case 4:
            printf("����Ҫɾ����¼�� ID��");
            read_line(id, MAX_ID_LEN);
            if(delete_item(goodsList, id))
                printf("ɾ���ɹ���\n");
            else
                printf("ɾ��ʧ�ܡ�\n");
            break;
        case 5:
            printf("����Ҫ������Ʒ�� ID��");
            read_line(id, MAX_ID_LEN);
            goodsNode = search_item(goodsList, id);
            if(goodsNode != NULL)
                output_one_item(goodsNode);
            else
                printf("����ʧ�ܡ�\n");
            
            break;
        case 6:
            if(bubble_sort(goodsList))
                printf("����ɹ���\n");
            else
                printf("����ʧ�ܡ�\n");
            break;
        case 7:
            if(save_to_file(goodsList) && destory_list(&goodsList))
            {
                printf("���Ѿ������ļ����˳�ϵͳ��\n");
                return 0;
            }

        case 8:
            if(destory_list(&goodsList))
                printf("���Ѿ��˳���Ʒ����ϵͳ��\n");
            return 0;

        case 9:
            if(destory_list(&goodsList) && remove(GOODS_FILE_NAME) == 0)
                printf("���Ѿ�����������ݡ�\n");
            break;

        default:
            printf("��������ȷ��ѡ�");
            goto loop;
        }
    }
}