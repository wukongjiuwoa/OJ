#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int Fibonacci(int n)
{
    if(n<=0)
        return n;
    int *Memo = (int*) malloc(n*sizeof(int));
    for(int i=0;i<=n;i++)
        Memo[i]=-1;
    return fib(n, Memo);
}
int fib(int n,int* Memo)
{

   if(Memo[n]!=-1)
   {
       printf("%d result is %d/n",n, Memo[n]);
        return Memo[n];
   }
    //如果已经求出了fib（n）的值直接返回，否则将求出的值保存在Memo备忘录中。
    if(n<=2)
        Memo[n]=1;
    else Memo[n]=fib( n-1,Memo)+fib(n-2,Memo);
        return Memo[n];
}
int main()
{

    printf("6 F is %d\n",Fibonacci(6));
    return 1;
    
    
}
