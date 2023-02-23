#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[6][4][4], i, j, k;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; i++)
        {
            for (k = 0; k < 4; k++)
            {
                a[i][j][k] = i + 1;
            }
            
        }
        
    }
    
    for(i=0; i < 4; i++){
        for (j = 0; j < 4; j++)
        {
            a[4][i][j] = a[0][i][j] + a[1][i][j] + a[2][i][j] + a[3][i][j];
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; i++)
        {
            for (k = 0; k < 4; k++)
            {
                printf("%d", a[i][j][k]);
            }
            
        }
        
    }
    return 0;
}
