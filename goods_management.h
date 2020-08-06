//GB2312
#include <stdbool.h>

//最大存储商品数量
#define MAX_GOODS_AMOUNT 100
//最长ID长度
#define MAX_ID_LEN 30
//最长名字长度
#define MAX_NAME_LEN 30
//最长折扣长度
#define MAX_DISCOUNT_LEN 30
//读取的商品文件
#define GOODS_FILE_NAME "goodsinfo.txt"

//商品信息
typedef struct 
{
char goods_id[MAX_ID_LEN];
char goods_name[MAX_NAME_LEN];
int goods_price;
char goods_discount[MAX_DISCOUNT_LEN];
int goods_amount;
int goods_remain;
} GoodsInfo;

//商品链表
typedef struct node
{
GoodsInfo data;
struct node *next;
} GoodsList;

//初始化商品链表
void init_list(GoodsList** L);
//所有商品信息
void output_all_items(GoodsList *L);
//修改商品信息
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
//插入商品信息
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
//删除商品信息
bool delete_item(GoodsList *L, char* goods_id);
//搜索商品信息
GoodsList* search_item(GoodsList *L, char* goods_id);
//保存商品文件
bool save_to_file(GoodsList *L);
//销毁商品链表
bool destory_list(GoodsList** L);
//商品价格排序
bool bubble_sort(GoodsList *L);

//读取字符串(忽略前面空格及换行符，以换行符或文件结尾为结束标志)
int read_line(char str[], int n);
//读取商品信息
GoodsInfo read_goods_info();
//显示一个商品的信息
void output_one_item(GoodsList *L);

extern int CurrentCnt;