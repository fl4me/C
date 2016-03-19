#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024 
#define INSERT 1
#define MERGE 2
#define DELETE 3
#define PRINT 4
#define NEW 5

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
//����ϲ� 
LinkedList linkedListMerge(LinkedList La,LinkedList Lb )
{
	LinkedList Lc;
    Lnode *pa=La->next;
    Lnode *pb=Lb->next;
    Lc=La;

    Lnode *pc=Lc;

    while(pa !=NULL && pb!=NULL)
    {
         if(pa->data.age <= pb->data.age)
         {
             pc->next=pa;
             pc=pa;
             pa=pa->next;
         }
         else
         {
              pc->next=pb;
              pc=pb;
              pb=pb->next;
         }
    //printf("%d\t",pc->data);
    }
    if(pa!=NULL)
    {
         pc->next=pa;
    }
    else if(pb!=NULL)
    {
        pc->next=pb;
    }
    return Lc;
}

LinkedList ListReverse(LinkedList L)
{
    LinkedList current, p;

    if (L == NULL)
    {
        return NULL;
    }
    current = L->next;
    while (current->next != NULL)
    {
        p = current->next;
        current->next = p->next;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

int main(void)
{	
	int i,len,cmd;
	LinkedList L1,L2,p,Lc;
	int listNum=1;
	ElemType a[MAXSIZE];
	
	printf("�����������������ʼ������\t");
 	scanf("%d",&len);
 	
 		//�û�����ѧ����Ϣ ������������ 
/*	for(i=0;i<len;i++)
	{
		a[i]=getInfo();	
	}
	*/
	L1=LinkedListCtreate(len);
 	
 	
	for(;;)
	{	puts("******************************************");
		printf("0-�˳�\n1-����\n2-�ϲ�\n3-ɾ��\n4-��ӡ����\n5-�½�����\n���������Լ���...\n");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case  INSERT : LinkedListInsert(L1);
							len++;
							p=L1->next;
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							
							continue;
			case MERGE :	
							if(listNum<2)
								continue;
							Lc=linkedListMerge(L1,L2);
							
							p=ListReverse(Lc )->next;
							puts("******************************************");
							printf("����\t����\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							continue;
			case DELETE : 
			case PRINT :
							p=L1->next;
							puts("******************************************");
							puts("L1");
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							if(listNum<2)
								continue;
							p=L2->next;
							puts("L2");
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							if(listNum<3)
								continue;
							
							p=Lc->next;
							puts("L-merged");
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							continue;
			case NEW :
							listNum++;
							L2=LinkedListCtreate(len);
							p=L2->next;
							puts("******************************************");
							printf("����\t����\n");
							for(i=0;i<len;i++)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							continue;
			default :		exit(0);
		}
		
	}
	return 0;
}
