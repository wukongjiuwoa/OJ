#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
using namespace std;
 
vector<string> split(string str, char sep){
    stringstream stream(str);
    string temp;
    vector<string> res;
    while(getline(stream, temp, sep)){
        res.push_back(temp);
    }
    return res;
}
 
//判断IP是否合法:0-不合法  1-合法
bool ipIsValid(vector<string> svec)
{
    if(svec.size()!=4)
        return false;
    return true;
}
 
//判断子网掩码是否合法
bool maskIsValid(vector<string> svec)
{
    bool zero = false;
    if(svec.size()!=4)
        return false;
    for(int i = 0; i < 4; i++)
    {
        if(zero == false)
        {
            if(atoi(svec[i].c_str()) != 255)
            {
                if(atoi(svec[i].c_str())!=0&&
                   atoi(svec[i].c_str())!=128&&
                   atoi(svec[i].c_str())!=192&&
                   atoi(svec[i].c_str())!=224&&
                   atoi(svec[i].c_str())!=240&&
                   atoi(svec[i].c_str())!=248&&
                   atoi(svec[i].c_str())!=252&&
                   atoi(svec[i].c_str())!=254)
                        return false;
                else
                    zero=true;
            }
        }
        else
        {
            if(atoi(svec[i].c_str()) != 0)
                return false;
        }
    }
    if(atoi(svec[3].c_str()) == 255){
            return false;
    }
        return true;
}
 
//分类IP：返回0不合法IP或MaskCode，返回1~5表示;A B C D E 五类IP，返回6合法但不属于五大类。
//第二个参数为1：私有IP, 0:非私有IP
int classifyIp(string str,int &privateFlag)
{
    vector<string > ip_mask;
    ip_mask=split(str,'~');
    string ip=ip_mask[0];
    string maskCode=ip_mask[1];
 
    vector<string > ip_substrs;
    ip_substrs=split(ip,'.');
    vector<string > mask_substrs;
    mask_substrs=split(maskCode,'.');
 
    int ipType=0;
        //先判断IP和maskCode是否合法
    if(ipIsValid(ip_substrs)==false||maskIsValid(mask_substrs)==false)
        return ipType;
   //再判断IP类型
    long temp1=strtol(ip_substrs[0].c_str(),NULL,10);//第1部分
    long temp2=strtol(ip_substrs[1].c_str(),NULL,10);//第2部分
    long temp3=strtol(ip_substrs[2].c_str(),NULL,10);//第3部分
    long temp4=strtol(ip_substrs[3].c_str(),NULL,10);//第4部分
    if(temp1>=1&&temp1<=126)
        ipType=1;//A
    else if(temp1>=128&&temp1<=191)
        ipType=2;//B
    else if(temp1>=192&&temp1<=223)
        ipType=3;//C
    else if(temp1>=224&&temp1<=239)
        ipType=4;//D
    else if(temp1>=240&&temp1<=255)
        ipType=5;//E
    else if(temp1==0||temp1==127)
        ipType=6;//合法但不属于五大类
    //最后判断是否为私有IP
    if(ipType)
    {
        if(temp1==10)
            privateFlag=1;
        else if(temp1==172&&(temp2>=16&&temp2<=31))
            privateFlag=1;
        else if(temp1==192&&temp2==168)
            privateFlag=1;
        else
            privateFlag=0;
    }
    return ipType;
}
 
 int main()
{
    string inStr;
    vector<string > ip_mask;
    int cnt[7]={0};
    while(getline(cin,inStr))
    {
        int privateFlag=0;
        int res=0;
        res=classifyIp(inStr,privateFlag);
        cout << res << endl;
         if(res==0)
            cnt[5]+=1;//Ip 或 子网掩码不合法
         else if(res==1)
            cnt[0]+=1;//A类
        else if(res==2)
            cnt[1]+=1;//B类
        else if(res==3)
            cnt[2]+=1;//C类
        else if(res==4)
            cnt[3]+=1;//D类
        else if(res==5)
            cnt[4]+=1;//E类
 
        if(privateFlag)
            cnt[6]+=1;
    }
    //打印结果
    for(int i=0;i<6;i++){
        cout<<cnt[i]<<" ";
        
    }
     cout<<cnt[6];
}

