#include <stdio.h>
#include "hotel.h"

extern char hotelNames[4][20];
int main(int argc, char **argv)
{
	int choice,days;
    double price;
    choice = Menu();
    switch(choice){
        case 1:
            price = HOTEL1;
            printf("您选择的酒店是：%s，单价为%.2lf。\n", *(hotelNames + (choice - 1)), HOTEL1); 
            break;
        case 2:
            price = HOTEL2;
            printf("您选择的酒店是：%s，单价为%.2lf。\n", *(hotelNames + (choice - 1)), HOTEL2); 
            break;
        case 3:
            price = HOTEL3;
            printf("您选择的酒店是：%s，单价为%.2lf。\n", *(hotelNames + (choice - 1)), HOTEL3); 
            break;
        case 4:
            price = HOTEL4;
            printf("您选择的酒店是：%s，单价为%.2lf。\n", *(hotelNames + (choice - 1)), HOTEL4); 
            break;
    }
    days = GetNights();
    ShowPrice(days,price);
    printf("系统运行结束。\n");
	return 0;
}
