#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cut(int *p,int n)
{
    if(n==0)
       return 0;
    int q=0;
    for(int i=1;i<=n;i++)
    {
        
        int temp = p[i-1]+cut(p, n-i);
        printf("i:%d, n: %d,  cur: %d\n", i,n,temp);
        if(q < temp)
            q = temp;
        printf("q: %d\n", q);

    }
    return q;
}


int cutDynMemo(int *p,int n,int *r);
int cutMemo(int *p, int n)
{
    int *r= (int*) malloc(sizeof(int)*n);
    for(int i=0;i<=10;i++)
        r[i]=-1;
    return cutDynMemo(p, n, r);
}
int cutDynMemo(int *p,int n,int *r)
{
    int q=-1;
    if(r[n]>=0)
        return r[n];
    if(n==0)
        q=0;
    else 
    {
        for(int i=1;i<=n;i++)
        {
            int temp =  cutDynMemo(p, n-i,r)+p[i-1];
            if(q < temp)
                q = temp;
        }
    }
    r[n]=q;

    return q;
}
int bottom_up_cut(int *p,int n)
{
    int *r = (int*) malloc(sizeof(int) * (1 + n));
    r[0] =  0;
    for(int i=1;i<=n;i++)
    {
        int q=-1;
        for(int j=1;j<=i;j++)
        {
            int temp =  p[j-1]+r[i-j];
            if(q < temp)
                q = temp;
        }
        r[i]=q;
    }
    return r[n];
}
int main()
{
    int price[10] = {1,5,8,9,10,17,17,20,24,30};
//    printf("%d\n", cut(price,4));
//    printf("%d\n", cutMemo(price,4));
    printf("%d\n", bottom_up_cut(price,4));
    printf("%d\n", bottom_up_cut(price,3));
    printf("%d\n", bottom_up_cut(price,2));
    return 1;
    
    
}
