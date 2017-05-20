/*
ѭ�������� 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cNode{
	char data;
	int len;	//�� 
	struct cNode *next;
}Node, *cNode;

cNode initCNode(cNode *L);				//��ʼ�� 
cNode createFromTail(cNode L);		//β�巨������
cNode searchAsNum(cNode L);				//����Ų���
cNode searchAsContent(cNode L);		//�����ݲ���
cNode insertCNode(cNode L);				//����
cNode delList(cNode L);						//ɾ�� 
cNode print(cNode L);							//�鿴����

//��ʼ�� 
cNode initCNode(cNode *L){
	(*L) = (cNode)malloc(sizeof(Node));
	(*L)->len = 0;
	(*L)->next = (*L);
	return (*L);
}

//β�巨������ 
cNode createFromTail(cNode L){
	Node *s, *r;
	int i = 0, flag = 1;
	char data;
	
	r = L;
	printf("β�巨������,���������ݲ���'#'�������룺\n");
	while(flag){
		printf("��������: ");
		scanf("%c", &data);
		getchar();
		if(data != '#'){
			s = (cNode)malloc(sizeof(Node));
			s->data = data;
			s->next = r->next;
			r->next = s;
			r = s;
			L->len++;
		}else{
			printf("��������...\n");
			flag = 0;
		}
	}
	r->next = L;
	print(L);
	return L;
}

//����Ų���
cNode searchAsNum(cNode L){
	int i, j;
	Node *p;
	
	p = L->next; 
	j = 1; 
	printf("\n��������ҵ����: ");
	scanf("%d", &i);
	getchar();
	
	//���ҵ���Ų�����Ϊ�� 
	if(i <= 0){
		printf("���벻�Ϸ�! \n");
		return NULL;
	}
	
	//��ѭ������ĵ���β���ж������� p != L 
	while((p != L) && (j < i)){
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
cNode searchAsContent(cNode L){
	Node *p;
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
cNode insertCNode(cNode L){
	Node *pre, *s;	
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
		
		//�ҵ�����λ�ò��������� 	��ע��:preָ�����λ�õ�ǰһ�����  
		s = (cNode)malloc(sizeof(Node));
		s->data = data;
		s->next = pre->next;
		pre->next = s;
		L->len++; 
		printf("����ɹ���");
		print(L);
		return L;
	}
} 

//ɾ�� 
cNode delList(cNode L){
	Node *pre, *r;
	int k = 0, i;
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
	while(pre->next != L && k < i - 1){
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
cNode print(cNode L){
	Node *p;
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
	Node *L;
	printf("===============================ѭ��������=====================================\n");
	initCNode(&L);
	createFromTail(L);
	searchAsNum(L);
	searchAsContent(L);
	insertCNode(L);
	delList(L);
	printf("===============================ѭ��������=====================================\n");
	return 0;
} 
