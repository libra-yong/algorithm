/*
ѡ����������� ֮ ѡ������
����ĿҪ������Ϊ�������ޣ������޷����д���������ȱ���ݴ���ƣ� 
*/

#include<stdio.h>
#include<stdlib.h> 

#define N 1000
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void adjHeap(int a[N],int i,int num);	//������ 
void BuildHeap(int a[N],int num);			//������
void heapSort(int a[N],int num); 			//������

//������
void adjHeap(int a[N],int i,int num)   
{
    int LChild = 2 * i;       //���ӽ����� 
    int RChild =2 * i + 1;     //�Һ��ӽ������ 
    int max = i;    
    
		//���i��Ҷ�ڵ�Ͳ��ý��е���        
    if(i <= num / 2)           
    {
        if(LChild <= num && a[LChild] > a[max])
        {
            max = LChild;
        }    
        if(RChild <= num && a[RChild] > a[max])
        {
            max = RChild;
        }
        if(max != i)
        {
            SWAP(a[i], a[max]);
            
            //���� 
            adjHeap(a, max, num);    
        }
    }        
}

//������ 
void BuildHeap(int a[N], int num)    
{
    int i;
    
    //��Ҷ�ڵ�������ֵΪnum/2 
    for(i = num / 2; i >= 1; i--)    
    {
        adjHeap(a, i, num);    
    }    
} 

//������ 
void heapSort(int a[N], int num)    
{
    int i;
    BuildHeap(a, num);
    for(i = num; i >= 1; i--)
    {
    	
    	//�����Ѷ������һ��Ԫ�أ���ÿ�ν�ʣ��Ԫ���е�����߷ŵ������
      SWAP(a[1], a[i]);            
      
      //���µ����Ѷ��ڵ��Ϊ�󶥶�
      adjHeap(a, 1, i - 1);      
    }
} 

int main(void)
{
    int a[N];
    int num, i;
    printf("��������Ҫ����ĸ�����"); 
    scanf("%d", &num);
    getchar();
    
    
    printf("������ %d ������������", num); 
    for(i = 1; i <= num; i++)
        scanf("%d", &a[i]);
        
    heapSort(a, num);
    
    printf("����������Ϊ��"); 
    for(i = 1;i <= num; i++)
        printf("%d ", a[i]);
    printf("\n\n");
  
    return 0;
}
