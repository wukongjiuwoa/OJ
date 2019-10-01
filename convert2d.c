#include <stdio.h>
#include <stdbool.h>


void convert2d(char *s)
{
    int i = 0;
    bool pre = false;
    for(; *s != '\0'; s++)
    {
       if((pre == false && *s == '0') || *s == 'x' )
       {
           pre = true;
           continue;
       }
       int j = (int) (*s >= 'A') ? (*s - 'A' + 10) : (*s - '0');
       //printf("%d\n", j);
       i = i * 16 + j;
        //printf("%d\n", i);
    }
    printf("%d\n", i);
    return;
}

int main()
{
    char s[10];
    while(scanf("%s", s) != EOF)
    {
        //printf("%s\n", s);
        convert2d(s);
    }
    return 0;
}
