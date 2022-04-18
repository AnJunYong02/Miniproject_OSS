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

void list_product(product *p[20], int count);//제품 전체 리스트 출력 함수
void one_product(product *p[20],int count);//제품 한개에 대한 정보 출력 함수
int add_product(product *p[20], int count);//제품 추가하는 함수
void update_product(product *p[20], int count);//제품 수정하는 함수
void delete_product(product *p[20], int count);//제품 삭제하는 함수
