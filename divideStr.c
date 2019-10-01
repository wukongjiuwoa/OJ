#include <stdio.h>
#include <string.h>

void divide(char *s)
{
    int l = strlen(s);
    int n = l / 8;
    int m = l % 8;
    char t[9];
    t[8] = '\0';
    for(int i = 0; i < n; i++)
    {
        memcpy(t, s, 8);
        printf("%s\n",t);
        s += 8;
    }
    if(m > 0)
    {
        memcpy(t, s, m);
        for(int j = m; j < 8; j++)
            t[j] = '0';
        printf("%s\n", t);
    }
    return;
}

int main()
{
    char str1[101];
    char str2[101];
    gets(str1);
    gets(str2);
    divide(str1);
    divide(str2);
    return 0;
}
