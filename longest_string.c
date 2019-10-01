#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Lcss(char *str1,char *str2, int l1, int l2)
{       
	if(l1>l2)
	{
		int temp1 = l1;
		l1 = l2;
		l2 = temp1;
		char *temp2 = str1;
		str1 = str2;
		str2 = temp2;
	}
    int **dp = (int**) malloc (sizeof(int*)*l1);
    for (int i =0; i< l1; i++)
    {
        dp[i] = (int*) malloc (sizeof(int) * l2);
    }
    //对dp矩阵的第一列赋值
    for(int i=0;i<l1;i++)
    {
        if(str2[0]==str1[i])
            dp[i][0]=1;
        else 
            dp[i][0]=0;
    }
    //对dp矩阵的第一行赋值
    for(int j=0;j<l2;j++)
    {
        if(str1[0]==str2[j])
            dp[0][j]=1;
        else {
            dp[0][j]=0;
        }
    }
    for(int i=1;i<l1;i++)
        for(int j=1;j<l2;j++)
        {
            if(str1[i]==str2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=0;
            }
        }
    int max=dp[0][0];
    int start = 0;
    for(int i=0;i<l1;i++)
        for(int j=0;j<l2;j++)
        {
            if (max < dp[i][j])
            {
                max = dp[i][j];
                start = i + 1 - max;
                printf("%d\n",start);
            }

        }
    char *s = (char*) malloc(max+1);
    s = strncpy(s,str1+start,max);
 
    printf("%s\n",s);
}

int main()
{
    //char *s1 = "abcdefghijklmnop";
    //char *s2 = "abcsafjklmnopqrstuvw";
    //char *s1 = "yrtqyfxyrmbasfmkbuudetaahxxgvcpkfhlkfxtjvguizsmwbnwamftshffyzumqfzqvirxgjjuocobvhvgstvrynduavkvntvxgnravjyfjkycguqyrnbnwnoqvhh";
    //char *s2 = "xxzjrwyqtgzfgxyitvszmltcsdjweeycqgzsazahpqrvlgvwexcfwkusmuyltvtbjftkvwebmjctwbfcxfimoevbquznojlzkxygruhebhostshenguhymzjxhkjstiwzgyudtfeddgqlegxesngnlbubkhzfmspalfajiqsvohghxhswjiimnyazfmgqazdewfptldiilrwkhuntvseohykutjecuhg";
	char *s1 ="satgfqpleswalkvowbcjllbmtxdjqtxlxoyrobrnpuctrcowegmyjjmgkzibmbplpslbsfawrqmzeckiwctwizhpkthvqaukxmzhyqbhhjbihzoidheibsrfbzaruhlwoiwlexwoaicikadrhcvevcnwxwsskooedipgftdfcmdpdonvjtzsncuylrbfzstplfsnebivzdyhhbajfokqvscrzobdzgnfkeqfhzpugbekegaiidhervdsgc";
char *s2 = "kicndbvtazczllcipodvlrliqargjayiivkuymrusywvotxycdzscogyejpvfmrldueulwijytocrf";
    Lcss(s1,s2,strlen(s1),strlen(s2));
    return 0;
}

