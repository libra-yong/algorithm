#include <iostream>  
  
using namespace std;  
  
//三角板个数  
const int n=7;  
//邻接矩阵,用来判断是否相邻  
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
//每个三角板的颜色  
int color[n]= {0,0,0,0,0,0,0};  
  
static int total;  
void output()//输出涂色方案  
{  
    cout<<"serial number: ";  
    for(int i=0; i<n; i++)  
    {  
        cout<<color[i]<<" ";  
    }  
    total++;  
    cout<<endl;  
}  
int colorSame(int s)//判断与周围的三角板颜色是否相同  
{  
    int flag=0;  
    for(int i=0; i<s; i++)  
    {  
        //使用邻接矩阵判断是否相邻  
        //如果相邻判断颜色是否相同  
        if(data[i][s]==1 && color[i]==color[s])  
            flag=1;  
    }  
    return flag;  
}  


void tryFind(int s)  //给七巧板涂色
{  
    //s=0~6,如果s=7说明已经涂完  
    if(s==n)  
        output();  
    else  
    {  
        //1、2、3、4代表四种颜色  
        //只有与周围三角块的颜色不同时才会进入下一个三角板的涂色  
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
  
 
  

  






