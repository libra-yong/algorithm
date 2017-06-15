#include <iostream>
#include <vector>
using namespace std;
//邻接矩阵表
const int data[7][7] = {{0,1,0,0,1,0,1},{1,0,0,1,0,1,0},{0,0,0,1,0,0,1},{0,1,1,0,0,1,1},
{1,0,0,0,0,0,1},{0,1,0,1,0,0,0},{1,0,1,1,1,0,0}};
vector<int> v;

//检查第i块七巧板放第j种颜色是否冲突
bool check(int i, int j)
{
    for (int k=0;k<i;++k)
    {
        //第i块和第k块七巧板相连，且第k块颜色为第j种颜色
        if (1 == data[i][k] && v[k] == j)
        {
            return false;
        }
    }
    return true;
}

void printSolution()
{
    for (vector<int>::iterator it = v.begin();it != v.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void search(int i)
{
    if ( 7 == i)
    {
        //如果七块已经着色，则输出结果
        printSolution();
    }
    else
    {
        for (int j=1;j<=4;++j)
        {

            if (check(i,j))
            {
                //给第i块着第j种颜色
                v.push_back(j);
                search(i+1);
                //回溯
                v.pop_back();
            }

        }
    }
}

int main()
{
    search(0);
    return 0;
}