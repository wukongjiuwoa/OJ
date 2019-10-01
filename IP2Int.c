#include <stdio.h>
#define IP_RANGE_NUM 4
int main()
{
    unsigned short a[4]={0,0,0,0};
    int i = 0;
    char c;

    while((c = getc(stdin)) != '\n' )
    {
       if(c == '.')
       {
           //get IP num of each range
           i++;
           continue;
       } 
       a[i] = a[i]  * 10 + (c - '0');
    }
    //Format 4 unsigend short to one int
    unsigned int b =0;
    for(i=0; i<IP_RANGE_NUM; i++)
    {
        b = b + ( a[i] << ((IP_RANGE_NUM - i -1 )* 8)  );
    }
    printf("The INT value is %u\n", b);
    return 0;
}
