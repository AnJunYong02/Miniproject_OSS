#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[30];//제품이름
    char explain[100];//제품 설명
    char weight[30];// 제품 중량
    int price;//제품 가격
    int way;//제품 배송방법
} product;

int see_menu();
void list_product(product *p[20], int count);
void one_product(product *p[20]);
int add_product(product *p[20], int count);
void update_product(product *p[20], int count);
void delete_product(product *p[20], int count);
void search_product_name(product *p[20],int count);//이름으로 제품 검색하는 함수
void search_product_price(product *p[20],int count);//제품 가격으로 제품 검색하는 함수
void search_product_way(product *p[20],int count);//배송방법으로 제품 검색하는 함수
void savefile(product *p[20], int count);//제품들을 파일에 저장하는 함수
void load_data();//파일에 저장한 제품들을 불러오는 함수



