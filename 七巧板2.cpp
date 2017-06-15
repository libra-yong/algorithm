#include <iostream>
#include <vector>
using namespace std;
//�ڽӾ����
const int data[7][7] = {{0,1,0,0,1,0,1},{1,0,0,1,0,1,0},{0,0,0,1,0,0,1},{0,1,1,0,0,1,1},
{1,0,0,0,0,0,1},{0,1,0,1,0,0,0},{1,0,1,1,1,0,0}};
vector<int> v;

//����i�����ɰ�ŵ�j����ɫ�Ƿ��ͻ
bool check(int i, int j)
{
    for (int k=0;k<i;++k)
    {
        //��i��͵�k�����ɰ��������ҵ�k����ɫΪ��j����ɫ
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
        //����߿��Ѿ���ɫ����������
        printSolution();
    }
    else
    {
        for (int j=1;j<=4;++j)
        {

            if (check(i,j))
            {
                //����i���ŵ�j����ɫ
                v.push_back(j);
                search(i+1);
                //����
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