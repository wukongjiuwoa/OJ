#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d",&n);
    int *toBeSort = (int*) malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d",&toBeSort[i]);
        printf("%d\n",toBeSort[i]);
    }
    char bitmapSort[1000] = {0};
    for(int i = 0; i < n; ++i)
    {
        bitmapSort[toBeSort[i]] = 1;
    }
    fflush(stdout);
    for(int i = 0; i < 1000; i++)
    {
        if (bitmapSort[i] == 1)
            printf("%d\n",i);
    }
    return 0;
}
