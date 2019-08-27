#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j;
    double score[4][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12},
    };
    double (*ptr_score)[3] = score;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%.2lf\t",*(ptr_score[i]+j));
        }
        printf("\n");
    }
    return 0;
}
