/*
选择排序堆排序 之 选择排序
（题目要求数据为正不受限，此题无法进行大数排序，且缺少容错机制） 
*/

#include<stdio.h>
#include<stdlib.h> 

#define N 1000
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

void adjHeap(int a[N],int i,int num);	//调整堆 
void BuildHeap(int a[N],int num);			//建立堆
void heapSort(int a[N],int num); 			//堆排序

//调整堆
void adjHeap(int a[N],int i,int num)   
{
    int LChild = 2 * i;       //左孩子结点序号 
    int RChild =2 * i + 1;     //右孩子结点点序号 
    int max = i;    
    
		//如果i是叶节点就不用进行调整        
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
            
            //调整 
            adjHeap(a, max, num);    
        }
    }        
}

//建立堆 
void BuildHeap(int a[N], int num)    
{
    int i;
    
    //非叶节点最大序号值为num/2 
    for(i = num / 2; i >= 1; i--)    
    {
        adjHeap(a, i, num);    
    }    
} 

//堆排序 
void heapSort(int a[N], int num)    
{
    int i;
    BuildHeap(a, num);
    for(i = num; i >= 1; i--)
    {
    	
    	//交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
      SWAP(a[1], a[i]);            
      
      //重新调整堆顶节点成为大顶堆
      adjHeap(a, 1, i - 1);      
    }
} 

int main(void)
{
    int a[N];
    int num, i;
    printf("请输入你要输入的个数；"); 
    scanf("%d", &num);
    getchar();
    
    
    printf("请输入 %d 个待排序数：", num); 
    for(i = 1; i <= num; i++)
        scanf("%d", &a[i]);
        
    heapSort(a, num);
    
    printf("堆排序后的数为："); 
    for(i = 1;i <= num; i++)
        printf("%d ", a[i]);
    printf("\n\n");
  
    return 0;
}
