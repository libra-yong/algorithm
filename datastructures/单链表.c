/*
���Ա����ʽ�洢 
�������������ң����룬ɾ��
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
	char ch;
	int len;	//���� 
	struct Node *next;
}Node, *linkList;



void initList(linkList *L);							//��ʼ������ 
linkList cteateFromeHead(linkList L);		//ͷ�巨������
linkList createFromTail(linkList L);		//β�巨������ 
linkList getAsNum(linkList L);					//����Ų��� 
linkList getAsContent(linkList L);			//�����ݲ���
linkList insertList(linkList L);				//����
linkList delList(linkList L);								//ɾ��
linkList print(linkList L);							//�鿴����
 
//��ʼ������ 
void initList(linkList *L){
	(*L) = (linkList)malloc(sizeof(Node));
	(*L)->len = 0;
	(*L)->next = NULL;
}

//ͷ�巨������ 
linkList cteateFromeHead(linkList L){
	Node *s;
	char ch;
	int flag = 1;
	printf("ͷ�巨������,���������ݲ���'#'�������룺\n"); 
	while(flag){
		printf("��������: ");
		scanf("%c", &ch);
		getchar();
		if(ch == '#'){
			//������ # ���˳� 
			flag = 0;
		}else{
			s = (linkList)malloc(sizeof(Node));	
			s->ch = ch; 
			s->next = L->next;
			L->next = s;
			(L->len)++; 
			flag = 1;
		}
	}
	print(L);
	return L;
}

//β�巨������ 
linkList createFromTail(linkList L){
	Node *s, *r;	//rָ��ʼ��ָ������β�� 
	char ch;
	int flag = 1;
	r = L;
	printf("β�巨������,���������ݲ���'#'�������룺\n");
	while(flag){
		printf("��������: ");
		scanf("%c", &ch);
		getchar();
		if(ch == '#'){
			//������ # ���˳� 
			flag = 0;
			r->next = NULL;
		}else{
			s = (linkList)malloc(sizeof(Node));
			s->ch = ch;
			r->next = s;
			r = s;
			(L->len)++; 
			flag = 1;
		}
	} 
	print(L);
	return L;
} 

//����Ų��� 
linkList getAsNum(linkList L){
	int i, j;
	Node *p;
	
	p = L; 
	j = 0; 
	printf("\n��������ҵ����: ");
	scanf("%d", &i);
	getchar();
	
	//���ҵ���Ų�����Ϊ�� 
	if(i <= 0){
		printf("���벻�Ϸ�! \n");
		return NULL;
	}
	
	//�˳���������֣���������û���ҵ����� �� pָ��ָ��Ŀ���� 
	while((p->next != NULL) && (j < i)){
		p = p->next;
		j++;
	}
	
	if(j == i){
		//�ҵ���� 
		printf("����Ų��ҳɹ�, ��� %d �������� %c \n", i, p->ch);
		return p;
	}else{
		//δ�ҵ� 
		printf("����Ų���ʧ�ܣ�δ�ڱ����ҵ����ݣ�\n");
		return NULL;
	}
}

//�����ݲ���
linkList getAsContent(linkList L){
	Node *p;
	char ch;
	int i = 1; 
	
	p = L->next;
	printf("\n������������ݣ�");
	scanf("%c", &ch);
	getchar();
	
	//���������δ�ҵ������˳�ѭ���� �ҵ�����ʱ�˳����� 
	while(p != NULL){
		if(p->ch == ch){
			printf("�����ݲ��ҳɹ����� %d ��λ�õ�����Ϊ %c\n", i, p->ch);
			return p;
		}
		p = p->next;
		i++;
	}
	
	//δ�ҵ�����
	if(p == NULL){
		printf("�����ݲ���ʧ�ܣ�δ�ڱ����ҵ����ݣ�\n");
	}
} 

//����
linkList insertList(linkList L){
	Node *pre, *s;
	int k, i;
	char ch;
	pre = L;
	k = 0;
	printf("\n��������Ҫ�����λ�ú�����(��ʽ: address content)��");
	scanf("%d %c", &i, &ch);
	getchar();
	
	//����λ�ò�����Ϊ�� 
	if(i <= 0){
		printf("����ʧ�ܣ�����λ�ò��Ϸ�������λ�ò���Ϊ��\n");
		return NULL;
	}
	
	////���������δ�ҵ�����λ��(��ʱi���ڱ�ĳ���) �� �ҵ�����λ��ʱ�˳����� �˳�ѭ��
	while(pre != NULL && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	if(pre == NULL){
		
		// δ�ҵ�����λ��(��ʱi���ڱ�ĳ���)
		printf("����ʧ�ܣ�����λ�ò��Ϸ�������λ�ó�����ĳ���\n");
		return NULL;
	}else{
		
		//�ҵ�����λ�ò��������� 
		s = (linkList)malloc(sizeof(Node));
		s->ch = ch;
		s->next = pre->next;
		pre->next = s;
		L->len++;
		printf("����ɹ���");
		print(L);
		return L;
	}
} 

//ɾ��
linkList delList(linkList L){
	Node *pre, *r;
	int k = 0, i;
	char *ch;
	pre = L;
	printf("������ɾ�������ݵ�λ��(��ʽ��address)��");
	scanf("%d", &i); 
	getchar();
	
	//ɾ����λ�ñ���Ϸ� 
	if(i > L->len || i<= 0){
		printf("ɾ����λ�ó���������ĳ���!\n");
		return;
	}
	
	// �ҵ�ɾ��λ���˳�
	while(pre->next != NULL && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	//ɾ������ 
	r = pre->next;
	pre->next = r->next;
	free(r);
	L->len--;
	printf("ɾ���ɹ���\n"); 
	print(L);
	return L;
} 

//�鿴���� 
linkList print(linkList L){
	Node *p;
	int i = 0; 
	p = L->next;
	printf("==============�鿴��������Ϊ==============\n");
	printf("���� %d ������(ע������Ǵ�ͷ���0��ʼ������һ���������Ϊ 1)\n", L->len);
	for(; i < L->len; i++){
		printf("%c ", p->ch);
		p = p->next;
	} 
	printf("\n\n");
	return L;
}

int main(void){
	Node *L;
	initList(&L);
	
	//ͷ�巨 
//	cteateFromeHead(L);

	//β�巨 
	createFromTail(L);		 
	getAsNum(L);					 
	getAsContent(L);			
	insertList(L);				
	delList(L);		
	return 0;
} 
