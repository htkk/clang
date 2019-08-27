#include <stdio.h>

//int list[15],num=0,i; 
void con(){
    static int num = 0;
    num++;
    printf("函数被调用的次数%d\n",num);
}

int main(int argc, char **argv)
{
    
    register int i;
    int val;
    printf("请输入数字：");
    while(scanf("%d",&val) == 1 && val > 0){
        for(i = val;i >= 0;i--){
            con();
        }
        printf("请输入数字：");
    }
//    int * aa = list;
//    
//	for(i=0;i<10;i++){
//        list[i]=num+=5;
//        }
//    printf("%d\n",sizeof(list));
//    for(i=0;i<10;i++){
//        printf("%d\n",list[i]);
//        }
    
    
	return 0;
}
