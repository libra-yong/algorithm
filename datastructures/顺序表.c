/*
���Ա��˳��洢 
�������������ң����룬ɾ�� 
*/

#include<stdio.h>
#include<string.h>

#define MAXSIZE 100			 
#define OK 1
#define ERROR -1

typedef struct{
	char data[MAXSIZE];	
	int len;	//���ݳ��� 
}List;

List* initList(List *L);													//��ʼ�� 
int getAsNum(List L, int num);										//����Ų��� 
int getAsContent(List L, char content);						//�����ݲ���
int insertList(List *L, int i, char content);			//���룬��Ԫ��֮ǰ����		
int deleteList(List *L, int i, char *content);		//ɾ��
void print(List *L);															//��ӡ

//��ʼ��˳��� 
List* initList(List *L){
	int num, i;
	char ch;
	//����˳�����
	printf("������˳����ȣ�0<len<100): ");
	scanf("%d", &num);
	L->len = num;
	
	//�������� 
	for(i = 0; i < L->len; i++){
		getchar();
		printf("������� %d ������", i);
		scanf("%c", &ch);
		L->data[i] = ch;
	}
	return L;
}

//����Ų��� 
int getAsNum(List L, int num){
	if(num < 0 || num > L.len - 1){
		printf("����ʧ�ܣ�λ�� %d ���������ȣ�\n\n", num);
		return ERROR;
	}else{
		printf("����Ų��ҳɹ����� %d ��λ��Ԫ��Ϊ %c \n\n", num, L.data[num]);
		return num;
	}
}

//�����ݲ���
int getAsContent(List L, char content){
	unsigned int i = 0; 
	while(i >= 0 || i <= L.len - 1){
		//˳��ɨ����ҵ���ӦԪ�أ�����ɨ�������˳� 
		if(L.data[i] != content){
			i++;
		}else{ 
			break;
		}
	}
	if(i <= L.len - 1){
		//�ҵ��������������� 
		printf("�����ݲ��ҳɹ����� %d ��λ��Ԫ��Ϊ %c \n\n", i, L.data[i]);
		return i;
	}else{
		//δ�ҵ� 
		printf("����ʧ�ܣ�û�������ҵ�Ԫ�أ�\n\n");
		return ERROR; 
	}
}

//���룬��Ԫ��֮ǰ����
int insertList(List *L, int i, char content){
	int k;
	
	//�����λ�ò��ڱ�ķ�Χ 
	if(i < 0 || i >= L->len){
		printf("����λ�ò��Ϸ���\n\n");
		return ERROR;
	}
	
	//���Ǳ�������� 
	if(L->len == MAXSIZE){
		printf("���������޷����룡\n\n");
		return ERROR;
	}else if(i >= 0 && i <= L->len - 1){
		
		//����λ�ú��Ԫ������ƶ� 
		for(k = L->len - 1; k >= i; k--){
			L->data[k+1] = L->data[k];
		}
		L->data[i] = content;
		//���ȼ�һ 
		L->len++;
		printf("����ɹ���\n\n");
		print(L);
		return OK;
	}
} 

//ɾ�� 
int deleteList(List *L, int i, char *content){
	int k;
	
	//ɾ��λ�ò��Ϸ����Ƴ� 
	if(i < 0 || (i >= L->len)){
		printf("ɾ��λ�ò��Ϸ���\n\n");
		return ERROR;
	}
	
	//ɾ���ı��ѿ� 
	if(L->len == 0){
		printf("���ѿգ�\n\n");
		return ERROR;
	}else{
		*content = L->data[i];
		
		//ǰ�� 
		for(k = i; k <= L->len - 2; k++){
			L->data[k] = L->data[k+1];
		}
		
		//ɾ���ɹ�����ȼ�һ 
		L->len--;
		printf("ɾ���ɹ���\n\n");
		print(L);
		return OK;
	}
}

//��ӡ 
void print(List *L){
	int i; 
	printf("===================˳�������===================\n");
	printf("���� %d ������: ", L->len); 
	for(i = 0; i < L->len; i++){
		printf("%c ", L->data[i]);
	}
	printf("\n");
}

int main(void){
	List L;
	int i, num, length, flag = 1;
	char ch, cha; 
	
	//��ʼ�� 
	initList(&L); 
	print(&L);
	
	//����Ų��� 
	printf("��������Ҫ���ҵ�Ԫ����ţ�");
	scanf("%d", &num);
	getchar();
	getAsNum(L, num);
	
	//�����ݲ��� 
	printf("��������Ҫ���ҵ�Ԫ�ص����ݣ�");
	scanf("%c", &ch);
	getchar();
	getAsContent(L, ch);
	
	//����Ԫ�� 
	printf("��������Ҫ���������(��ʽ:addr_num data_char)��");
	scanf("%d %c", &num, &ch);
	getchar();
	insertList(&L, num, ch);
	
	//ɾ��Ԫ�� 
	printf("��������Ҫɾ����λ��(��ʽ:addr_num)��");
	scanf("%d", &num);
	getchar();
	deleteList(&L, num, &cha);	
	
	return 0;
} 
