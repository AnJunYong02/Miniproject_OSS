#include <stdio.h>
#include "manager.h"

int see_menu(){
    int menu;
    printf("1. 제품 전체 리스트\n");
    printf("2. 제품 한개에 대한 자세한 정보\n");
    printf("3. 제품 추가\n");
    printf("4, 제품 수정\n");
    printf("5. 제품 삭제하기\n");
    printf("6. 제품 검색하기 (제품 이름으로 검색하기)\n");
    printf("7. 제품 검색하기 (제품 가격대로 검색하기)\n");
    printf("8. 제품 검색하기 (제품 배송 방법으로 검색하기)\n");
    printf("9. 파일 저장하기\n");
    printf("10. 파일 불러오기\n");
    printf("0. 종료\n");
    printf("=> 실행하고 싶은 번호를 선택하세요.");
    scanf("%d",&menu);
    return menu;
}

int main(){
    int menu;
    product *p[20];
    int count =0;//리스트 출력하기
#ifdef DEBUG
    	printf("==> DEBUG MODE\n");

#endif
    while(1){
        menu = see_menu();
        if(menu == 0) break;
        else if( menu == 1) list_product(p, count);
        else if( menu == 2){
		list_product(p,count);
	       	one_product(p, count);
	}
        else if( menu == 3) count = add_product(p, count);
        else if( menu == 4) update_product(p, count);
        else if( menu == 5) delete_product(p, count);
    }
    printf("종료됨!\n");
    return 0;
}
