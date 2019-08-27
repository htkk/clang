#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hero {
    int id;
    char name[10];
    int hp;
};

int main(int argc, char **argv)
{

    struct hero lvbu;
    lvbu.id = 10;
    strcpy(lvbu.name,"吕布");
    lvbu.hp = 300;
    
    printf("%d\t%s\t%d\n",lvbu.id,lvbu.name,lvbu.hp);
    
    
    
    
//    char * str = "Hello!";
//    printf("%p\n",str);
//    str = "World!";
//    printf("%p\n",str);
    
    
//	char strings1[] = {'h','e','l','l','o','\0'};//字符串
//  char strings2[] = {'h','e','l','l','o'};//字符数组
	return 0;
}
