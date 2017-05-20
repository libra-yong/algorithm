/*
˫������ 
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
	char data;
	int len;
	struct DNode *prior;
	struct DNode *next;
}DNode, *DList;

DList initDList(DList *L);
DList createFromTail(DList L);
DList searchAsNum(DList L);
DList searchAsContent(DList L);
DList insertDList(DList L);
DList delDList(DList L);
DList print(DList L);

//��ʼ��
DList initDList(DList *L){
	(*L) = (DList)malloc(sizeof(DNode));
	(*L)->len = 0;
	(*L)->prior = (*L);
	(*L)->next = (*L);
	return *L;
} 

//β�巨���� 
DList createFromTail(DList L){
	DNode *s, *r;
	int flag = 1;
	char data;
	r = L;
	printf("β�巨������,���������ݲ���'#'�������룺\n");
	while(flag){
		printf("��������: ");
		scanf("%c", &data);
		getchar();
		if(data == '#'){
			//������ # ���˳� 
			flag = 0;
		}else{
			s = (DList)malloc(sizeof(DNode));
			s->data = data;
			s->prior = r;
			s->next = L;
			r->next = s;
			r = s;
			L->prior = r;
			(L->len)++; 
			flag = 1;
		}
	}
	printf("��������...\n");
	print(L);
	return L;
}

//����Ų���
DList searchAsNum(DList L){
	int i, j;
	DNode *p;
	
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
	while((p->next != L) && (j < i)){
		p = p->next;
		j++;
	}
	
	if(j == i){
		//�ҵ���� 
		printf("����Ų��ҳɹ�, ��� %d �������� %c \n", i, p->data);
		return p;
	}else{
		//δ�ҵ� 
		printf("����Ų���ʧ�ܣ�δ�ڱ����ҵ����ݣ�\n");
		return NULL;
	}
}

//�����ݲ��� 
DList searchAsContent(DList L){
	DNode *p;
	char data;
	int i = 1; 
	
	p = L->next;
	printf("\n������������ݣ�");
	scanf("%c", &data);
	getchar();
	
	//���������δ�ҵ������˳�ѭ���� �ҵ�����ʱ�˳����� 
	while(p != L){
		if(p->data == data){
			printf("�����ݲ��ҳɹ����� %d ��λ�õ�����Ϊ %c\n", i, p->data);
			return p;
		}
		p = p->next;
		i++;
	}
	
	//δ�ҵ�����
	if(p == L){
		printf("�����ݲ���ʧ�ܣ�δ�ڱ����ҵ����ݣ�\n");
	}
}  

//����
DList insertDList(DList L){
	DNode *pre, *s;
	int k, i;
	char data;
	pre = L->next;
	k = 1;
	printf("\n��������Ҫ�����λ�ú�����(��ʽ: address content)��");
	scanf("%d %c", &i, &data);
	getchar();
	
	//����λ�ò�����Ϊ�� 
	if(i <= 0){
		printf("����ʧ�ܣ�����λ�ò��Ϸ�������λ�ò���Ϊ��\n");
		return NULL;
	}
	
	////���������δ�ҵ�����λ��(��ʱi���ڱ�ĳ���) �� �ҵ�����λ��ʱ�˳����� �˳�ѭ��
	while(pre != L && k < i - 1){
		pre = pre->next;
		k++;
	}
	
	if(pre == L){
		
		// δ�ҵ�����λ��(��ʱi���ڱ�ĳ���)
		printf("����ʧ�ܣ�����λ�ò��Ϸ�������λ�ó�����ĳ���\n");
		return NULL;
	}else{
		
		//�ҵ�����λ�ò��������� ,ע��:preָ�����λ�õ�ǰһ����� 
		s = (DNode*)malloc(sizeof(DNode));
		s->data = data;
		
		s->next = pre->next;
		pre->next->prior = s;
		s->prior = pre; 
		pre->next = s;
		
		L->len++;
		printf("����ɹ���");
		print(L);
		return L;
	}
}  

//ɾ�� 
DList delDList(DList L){
	DNode *p;
	int k = 1, i;
	p = L->next;
	printf("������ɾ�������ݵ�λ��(��ʽ��address)��");
	scanf("%d", &i); 
	getchar();
	
	//ɾ����λ�ñ���Ϸ� 
	if(i > L->len || i<= 0){
		printf("ɾ����λ�ó���������ĳ���!\n");
		return;
	}
	
	// �ҵ�ɾ��λ���˳�
	while(p != L && k < i){
		p = p->next;
		k++;
	}
	
	//ɾ������ 
	p->next->prior = p->prior;
	p->prior->next = p->next;
	//�����������Ի���˳�� 
	
	free(p);
	L->len--;
	printf("ɾ���ɹ���\n"); 
	print(L);
	return L;
} 

//�鿴�� 
DList print(DList L){
	DNode *p;
	int i = 0; 
	p = L->next;
	printf("�鿴��������Ϊ...\n");
	printf("���� %d ������(ע������Ǵ�ͷ���0��ʼ������һ���������Ϊ 1)\n", L->len);
	for(; i < L->len; i++){
		printf("%c ", p->data);
		p = p->next;
	} 
	printf("\n\n");
	return L;
}

int main(void){
	DNode *L;
	printf("===============================˫������=====================================\n");
	initDList(&L);
	createFromTail(L);
	searchAsNum(L);
	searchAsContent(L);
	insertDList(L);
	delDList(L);
	printf("===============================˫������=====================================\n");
	return 0;
}
