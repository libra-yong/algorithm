#include <iostream>  
  
using namespace std;  
  
//���ǰ����  
const int n=7;  
//�ڽӾ���,�����ж��Ƿ�����  
const int data[n][n] =  
{  
    {0,1,0,0,1,0,1},  
    {1,0,0,1,0,1,0},  
    {0,0,0,0,1,0,1},  
    {0,1,1,0,0,1,1},  
    {1,0,0,0,0,0,1},  
    {0,1,0,1,0,0,0},  
    {1,0,1,1,1,0,0}  
};  
//ÿ�����ǰ����ɫ  
int color[n]= {0,0,0,0,0,0,0};  
  
static int total;  
void output()//���Ϳɫ����  
{  
    cout<<"serial number: ";  
    for(int i=0; i<n; i++)  
    {  
        cout<<color[i]<<" ";  
    }  
    total++;  
    cout<<endl;  
}  
int colorSame(int s)//�ж�����Χ�����ǰ���ɫ�Ƿ���ͬ  
{  
    int flag=0;  
    for(int i=0; i<s; i++)  
    {  
        //ʹ���ڽӾ����ж��Ƿ�����  
        //��������ж���ɫ�Ƿ���ͬ  
        if(data[i][s]==1 && color[i]==color[s])  
            flag=1;  
    }  
    return flag;  
}  


void tryFind(int s)  //�����ɰ�Ϳɫ
{  
    //s=0~6,���s=7˵���Ѿ�Ϳ��  
    if(s==n)  
        output();  
    else  
    {  
        //1��2��3��4����������ɫ  
        //ֻ������Χ���ǿ����ɫ��ͬʱ�Ż������һ�����ǰ��Ϳɫ  
        for(int i=1; i<=4; i++)  
        {  
            color[s]=i;  
            if(colorSame(s)==0)  
                tryFind(s+1);  
        }  
    }  
} 

  
int main()  
{  
    total=0;  
    tryFind(0);  
    cout<<"Total= "<<total<<endl;  
    return 0;  
}  
  
 
  

  






