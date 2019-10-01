//// huawei_test.cpp : 定义控制台应用程序的入口点。
////
#include<stdio.h>
#include<string.h>
#include<stdlib.h>javascript:void(0);
#include<stdbool.h>
#define N  50
int ConvertSubIPToInt(const char* sub_ip)
{
    if (sub_ip == NULL)
        return -1;
    int length = strlen(sub_ip);
    if (length < 1 || length>3)
        return -1;
    int sub_value = 0;
    for (int i = 0; i < length; i++)
    {
        if (sub_ip[i]<'0' || sub_ip[i]>'9')
            return -1;
        sub_value = 10 * sub_value + sub_ip[i] - '0';
    }
    //printf("%d\n",sub_value);
    return sub_value;
}
bool isIPAddressValid(const char* pszIPAddr, int *subIPValue)
{
    // 请在此处实现
    if (pszIPAddr == NULL || *pszIPAddr == '\0')
        return false;

    int szIPAddr_length = strlen(pszIPAddr);

    //int index_start = 0;
    //int index_end = szIPAddr_length - 1;

    //去除前边的空格
   // while (pszIPAddr[index_start] == ' ')
    //{
    //    ++index_start;
    //}
    //去除后边空格
    //while (pszIPAddr[index_end] == ' ')
    //{
    //    --index_end;
    //}
    //if (index_end <= index_start)
    //    return false;

    //int ip_length = index_end - index_start + 2;
    //int ip_length = index_end - index_start;
    char *temp_ip=(char*)malloc(szIPAddr_length + 1);
    strncpy(temp_ip, pszIPAddr, szIPAddr_length);
    temp_ip[szIPAddr_length] = '\0';
    char* sub_ip = strtok(temp_ip, ".");
    int sub_ip_count = 0;
    while (sub_ip != NULL)//ip分段，计数分段ip,并转换为0-255
    {
        sub_ip_count++;
        if (sub_ip_count > 4)
        {
            free(temp_ip);
            return false;
        }
        
        subIPValue[sub_ip_count - 1] = ConvertSubIPToInt(sub_ip);
        if (subIPValue[sub_ip_count - 1] < 0 || subIPValue[sub_ip_count - 1] > 255)
            {
                free(temp_ip);
                return false;
            }
        sub_ip = strtok(NULL, ".");
    }
    free(temp_ip);
    if (sub_ip_count != 4)
        return false;
    else
        return true;
}
bool isValidMask(int* mask_value)
{
    unsigned int mask_int32 = 0;
    for (int i = 0; i < 4; i++)
    {
        mask_int32 += ((unsigned int)mask_value[i]) << ((3 - i) * 8);
    }
    if (mask_int32 == 0xffffffff || mask_int32 == 0)
    {
        return false;
    }
    mask_int32 = ~mask_int32 + 1;
    if ((mask_int32 & (mask_int32 - 1)) == 0)//判断是否W为2^n次方
        return true;
    else
        return false;
}
bool isPrivateIP(int*ip_value)
{
    if (ip_value[0] == 10)
        return true;
    if (ip_value[0] == 172 && ip_value[1] >= 16 && ip_value[1] <= 31)
        return true;
    if (ip_value[0] == 192 && ip_value[1] == 168)
        return true;
    return false;
}
bool IPAnalyse(char* str, int* result)
{
    if (str == NULL)
        return false;
    char* p = strchr(str, '~');
    if (p == NULL)
        return  false;
    else
        *p = '\0';
    char* ip = str;
    char* mask = p + 1;

    int sub_IP_value[4];
    int sub_mask_value[4];
    if (!isIPAddressValid(ip, sub_IP_value) || !isIPAddressValid(mask, sub_mask_value))
    {
        result[5]++;
        return true;//ip无效
    }

    if (!isValidMask(sub_mask_value))
    {
        result[5]++;
        return true;//子掩码无效
    }
    if (isPrivateIP(sub_IP_value))
        result[6]++;
    if (sub_IP_value[0] >= 1 && sub_IP_value[0] <= 126)//A类
    {
        result[0]++;
        return true;
    }
    if (sub_IP_value[0] >= 128 && sub_IP_value[0] <= 191)//B类
    {
        result[1]++;
        return true;
    }
    if (sub_IP_value[0] >= 192 && sub_IP_value[0] <= 223)//C类
    {
        result[2]++;
        return true;
    }
    if (sub_IP_value[0] >= 224 && sub_IP_value[0] <= 239)//D类
    {
        result[3]++;
        return true;
    }
    if (sub_IP_value[0] >= 240)//E类
    {
        result[4]++;
        return true;
    }
    return false;

}
int main()
{
    char str[N];
    int statistic_info[7] = { 0 };
    while (scanf("%s",str) != EOF)
    {
        //if (strlen(str) < 2)
        //    break;
        //char* p = strrchr(str, '\n');
        //if (p != NULL)
        //    *p = '\0';
        //printf("%s\n", str);
        
        IPAnalyse(str, statistic_info);
        for(int i = 0; i < N; i++)
            str[i] = '\0';
    }
    for (size_t i = 0; i < 6; i++)
    {
        printf("%d ", statistic_info[i]);
    }
    printf("%d", statistic_info[6]);
    return 0;
}
