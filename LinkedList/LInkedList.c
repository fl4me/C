#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024 
#define INSERT 1
#define MERGE 2
#define DELETE 3
#define PRINT 4

typedef struct stuInfo
{
	char strName[10];
	int age;
}ElemType;



struct Node
{
	ElemType data;
	struct Node *next;
};

typedef struct Node Lnode;
typedef struct Node *LinkedList;

//��Ϣ���� 
ElemType getInfo(void)
{	
	ElemType info;
	
	puts("������ѧ������:\t");
	scanf("%s",info.strName);
	puts("������ѧ������\t"); 
	scanf("%d",&(info.age));
	
	return  info;
}

//ͷ�巨�����ͷ���ĵ����� 
LinkedList LinkedListCtreate(int n)
{
	int i;
	LinkedList L,p;
	L=(Lnode*)malloc(sizeof(Lnode));
	if(L==NULL)
	{
		puts("����ռ�ʧ��");
		exit(0);
	}
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		if(p==NULL)
		{
			printf("����ռ�ʧ��");
			exit(0);
		}
		p->data=getInfo();
		p->next=L->next;
		L->next=p;
	}
	
	return L;
}


//��������

LinkedList LinkedListFind(ElemType in,LinkedList L)
{
	LinkedList p;
	p=L->next;
	while((p->data.strName != in.strName||p->data.age!=in.age) && p->next != NULL)
	{
		p=p->next;
	}
	if(p->next!=NULL)
	{
		return p;
	}
	else
	{
		puts("��ѧ��������");
		exit(0);
	}
} 

//����
 
void LinkedListInsert(LinkedList L)
{
	LinkedList pre=NULL, q=(Lnode *)malloc(sizeof(Lnode));
	ElemType p;
	if(q==NULL)
	{
		puts("����ռ�ʧ��");
		exit(0);
	}
	
	printf("���������λ�ã���λͬѧ֮ǰ��\n");
	
	p=getInfo();
	
	printf("�����������Ϣ\n");
	
	q->data=getInfo();
	pre=L;
	while((pre!=NULL)&&((pre->next->data.strName!=p.strName)&&(pre->next->data.age!=p.age)))
	{
		pre=pre->next;
	}
	
	q->next=pre->next;
	pre->next=q;
	
}
int main(void)
{	
	int i,len,cmd;
	LinkedList L=NULL,p;
	ElemType a[MAXSIZE];
	
	printf("�����������������ʼ������");
 	scanf("%d",&len);
 	
 		//�û�����ѧ����Ϣ ������������ 
/*	for(i=0;i<len;i++)
	{
		a[i]=getInfo();	
	}
	*/
	L=LinkedListCtreate(len);
 	
 	
	for(;;)
	{	puts("******************************************");
		printf("0-�˳�\n1-����\n2-�ϲ�\n3-ɾ��\n4-��ӡ����\n���������Լ���...\n");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case  INSERT : LinkedListInsert(L);
							len++;
							p=L->next;
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							
							continue;
			case MERGE :
			case DELETE :
			case PRINT :
			
							p=L->next;
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							continue;
			default :exit(0);
		}
		
	}

		//printf("%d\t%d",L->next->data.age,L->next->next->data.age);
	//�ϳ�����������Ϣ 

	
/*	LinkedListInsert(L);
		p=L->next;
	for(i=0;i<4;i++){
		printf("%s",(p->data).strName);
		p=p->next;
		
	}
	*/
		
	return 0;
}