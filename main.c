#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "manager.h"


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
	       	one_product(p);
	}
        else if( menu == 3) count = add_product(p, count);
        else if( menu == 4) update_product(p, count);
        else if( menu == 5) delete_product(p, count);
        else if( menu == 6) search_product_name(p, count);
        else if( menu == 7) search_product_price(p, count);
        else if( menu == 8) search_product_way(p, count);
        else if( menu == 9) savefile(p, count);
        else if( menu == 10)load_data();
    }
    printf("종료됨!!\n");
    return 0;
}
