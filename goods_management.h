//GB2312
#include <stdbool.h>

//���洢��Ʒ����
#define MAX_GOODS_AMOUNT 100
//�ID����
#define MAX_ID_LEN 30
//����ֳ���
#define MAX_NAME_LEN 30
//��ۿ۳���
#define MAX_DISCOUNT_LEN 30
//��ȡ����Ʒ�ļ�
#define GOODS_FILE_NAME "goodsinfo.txt"

//��Ʒ��Ϣ
typedef struct 
{
char goods_id[MAX_ID_LEN];
char goods_name[MAX_NAME_LEN];
int goods_price;
char goods_discount[MAX_DISCOUNT_LEN];
int goods_amount;
int goods_remain;
} GoodsInfo;

//��Ʒ����
typedef struct node
{
GoodsInfo data;
struct node *next;
} GoodsList;

//��ʼ����Ʒ����
void init_list(GoodsList** L);
//������Ʒ��Ϣ
void output_all_items(GoodsList *L);
//�޸���Ʒ��Ϣ
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
//������Ʒ��Ϣ
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
//ɾ����Ʒ��Ϣ
bool delete_item(GoodsList *L, char* goods_id);
//������Ʒ��Ϣ
GoodsList* search_item(GoodsList *L, char* goods_id);
//������Ʒ�ļ�
bool save_to_file(GoodsList *L);
//������Ʒ����
bool destory_list(GoodsList** L);
//��Ʒ�۸�����
bool bubble_sort(GoodsList *L);

//��ȡ�ַ���(����ǰ��ո񼰻��з����Ի��з����ļ���βΪ������־)
int read_line(char str[], int n);
//��ȡ��Ʒ��Ϣ
GoodsInfo read_goods_info();
//��ʾһ����Ʒ����Ϣ
void output_one_item(GoodsList *L);

extern int CurrentCnt;