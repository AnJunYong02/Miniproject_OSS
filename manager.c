#include "manager.h"

void list_product(product *p[20], int count){//제품 전체 리스트
    printf("\n\n");
    for(int i=0; i<count; i++){
        if(p[i]-> price == -1) continue;
        else{
            printf("%d. " ,i+1);
            printf("제품이름 : %s   제품설명: %s    제품 가격: %d     \n\n",p[i]->name,p[i]->explain, p[i]->price);
        }
    }
}


void one_product(product *p[20], int count){//제품 한개에 대한 자세한 정보
    int num;
    printf("\n\n알고 싶은 제품의 번호는?");
    scanf("%d",&num);
    printf("\n제품 이름: %s", p[num-1]->name);
    printf("제품 설명: %s",p[num-1]->explain);
    printf("제품 가격: %d\n",p[num-1]-> price);
    printf("제품 판매단위: %s",p[num-1]->weight);
    if(p[num-1]->way == 12)//새벽배송 /택배배송이라면 
        printf("배송방법    새벽배송/택배배송\n");
    else if(p[num-1] -> way == 1)// 새벽배송이라면
        printf("배송방법: 새벽배송\n");
    else printf("배송방법: 택배배송\n");//택배배송일때
} 

int add_product(product *p[20], int count){//제품 추가
    p[count] = (product *)malloc(sizeof(product));
    getchar();
    printf("\n추가할 제품 이름은? ");
    fgets(p[count]->name, 30, stdin);
    // getchar();
    printf("제품 설명은? ");
    fgets(p[count]->explain, 100, stdin);
    // getchar();
    printf("제품 가격은? ");
    scanf("%d",&p[count]->price);
    getchar();
    printf("제품의 판매단위는? ex) 300kg, 10개입 >> ");
    fgets(p[count]-> weight, 50, stdin);
    // getchar();
    printf("제품 배송방법은?(1:새벽배송 2: 택배배송) ");
    scanf("%d",&p[count] -> way);
    getchar();
    printf("==> 추가됨!\n");
    count++;
    return count;
}


void update_product(product *p[20],int count){//제품 수정
    int index;
    list_product(p, count);
    printf("수정할 제품 번호는? ");
    scanf("%d",&index);
    getchar();
    printf("수정할 제품 이름은? ");
    fgets(p[index-1]->name, 30, stdin);
    printf("제품 설명은? ");
    fgets(p[index-1]->explain, 100, stdin);
    printf("제품 가격은? ");
    scanf("%d",&p[index-1]->price);
    getchar();
    printf("제품의 판매단위는? ");
    fgets(p[index-1]-> weight, 50, stdin);
    printf("제품 배송방법은? ");
    scanf("%d",&p[index-1] -> way);
    getchar();
    printf("=> 수정됨!!\n");
}



void delete_product(product *p[20],int count){//제품 삭제
    int delete_index;
    int flag;
    list_product(p,count);
    printf("삭제할 제품 번호는? ");
    scanf("%d",&delete_index);
    printf("정말로 삭제하시겠습니까?(삭제:1)");
    scanf("%d",&flag);
    if(flag == 1){
        printf("=>삭제됨!\n");
        p[delete_index-1] -> price = -1;
    }
}


void search_product_name(product *p[20], int count){{//이름으로 제품 검색하는 함수
    char search_name[30];
    int flag = 0;
    printf("검색할 제품의 이름을 입력하세요.");
    fgets(search_name,30,stdin);
    for(int i=0; i<count; i++){
        if(p[i]->price == -1) continue;
        if(strstr(p[i]->name, search_name)){//제품 검색
            printf("%d. " ,i+1);
            printf("%s\n",p[i]->name);
            printf("%s\n",p[i]->explain);
            printf("\n%d\n\n\n",p[i]->price);
            flag++;
        }
    }
    if(flag == 0) printf("No search!!\n");
}


void search_product_price(product *p[20], int count){//가격으로 제품 검색
    int search_price;
    int flag = 0;
    printf("검색할 제품의 가격을 입력하세요.");
    scanf("%d",&search_price);
    for(int i=0; i<count; i++){
        if(p[i]->price == -1) continue;
        if( p[i]->price == search_price){//제품 검색
            printf("%d. " ,i+1);
            printf("%s\n",p[i]->name);
            printf("%s\n",p[i]->explain);
            printf("\n%d\n\n\n",p[i]->price);
            flag++;
        }
    }
    if(flag == 0) printf("No search!!\n");
}


void search_product_way(product *p[20], int count){//배송 방법으로 제품 검색
    int search_way;
    int flag = 0;
    printf("검색할 제품의 배송방법을 입력하세요.(1:새벽배송 2: 택배배송)");
    scanf("%d", &search_way);
    for(int i=0; i<count; i++){
        if(p[i]->price == -1) continue;
        if( p[i]->way == search_way){//제품 검색
            printf("%d. " ,i+1);
            printf("%s\n",p[i]->name);
            printf("%s\n",p[i]->explain);
            printf("\n%d\n\n\n",p[i]->price); 
            flag++;
        }
    }
    if(flag == 0) printf("No search!!\n");
}

void savefile(product *p[20],int count){
    FILE *file;
    file = fopen("Product.txt", "w");
    for(int i=0; i<count; i++){
        if(p[i]->price == -1) continue;
        else{
            fprintf(file, "%d. " ,i+1);
            fprintf(file, "%s\n",p[i]->name);
            fprintf(file, "%s\n",p[i]->explain);
            fprintf(file,"\n%d\n\n\n",p[i]->price);
        }
    }
    printf("=> 저장됨!\n");
    fclose(file);
}


int load_data(product *p[20]){
    FILE *file;
    int i=0;
    file = fopen("Product.txt","r");
    while(!feof(file)){
        fscanf(file,"%s",p[i]->name);
        fscanf(file,"%s",p[i]->explain);
        fscanf(file,"%s",p[i]->weight);
        fscanf(file,"%d",p[i]->price);
        fscanf(file,"%d",p[i]->way);
        i++;
    }
    return i;
}



void read_product(product *p[20], int count){
    FILE* file;
    file = fopen("Product.txt","r");
    for(int i= 0; i<count; i++){
        printf("%d. " ,i+1);
        printf("%s\n",p[i]->name);
        printf("%s\n",p[i]->explain);
        printf("\n%d\n\n\n",p[i]->price);
    }
    fclose(file);
}

