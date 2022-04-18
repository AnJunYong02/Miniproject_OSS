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

void list_product(product *p[20], int count);
void one_product(product *p[20], int count);
int add_product(product *p[20], int count);
void update_product(product *p[20], int count);
void delete_product(product *p[20], int count);
