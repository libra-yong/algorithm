/*
Լɪ�� 
һ�Ѻ��Ӷ��б�ţ������1��2��3 ...m ,��Ⱥ���ӣ�n��������1-m��˳��Χ��һȦ���ӵ�1��ʼ����ÿ������m�����ú���
��Ҫ�뿪��Ȧ����������������ֱ��Ȧ��ֻʣ�����һֻ���ӣ���ú���Ϊ������������㷨��д�������Ϊ�����ĺ��ӵ�
��š�
*/
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	
	int count = 1;
	int i = 0, pos = -1;
	
	//��� 
	int alive = 0;
	int n, m;
	int man[1000] = {0};
	printf("��������Ӹ�����������ţ����磺50 4����"); 
	scanf("%d %d", &n, &m);
	getchar();
	
	/*
	��ʼ������˳�򣬵�����mʱ�˳�do-whileѭ�� ���������������������Ӧ������������� 
	*/
	while(count <= n){
		do{
			pos = (pos + 1) % n;
			if(man[pos] == 0){
				i++;
			}
			 
			if(i == m){
				i = 0;
				break;
			}
		}while(1);
		
		man[pos] = count;
		count++;
	}
	
	printf("����ԭ����˳��Ϊ��");
	for(i = 0; i < n; i++){
		printf("%3d ", i+1);
	} 
	
	printf("\n��Ӧ������˳��Ϊ: ");
	for( i = 0; i < n; i++){
		printf("%3d ", man[i]);
	}
	
	printf("\n�������λ�ñ�ţ�ԭ���б�ţ�Ϊ: ");
	for(i = 0; i < n; i++){
		if(man[i] > n-1){
			
			//ע����ѧ�е���Ŵ�1��ʼ�ͳ��������е���Ŵ�0��ʼ
			printf("%3d ", i+1); 
			continue; 
		}
		
	} 
	printf("\n");
	
	return 0;
}
