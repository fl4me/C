#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

//信息输入 
ElemType getInfo(void)
{	
	ElemType info;
	
	puts("请输入学生姓名:\t");
	scanf("%s",info.strName);
	puts("请输入学生年龄\t"); 
	scanf("%d",&(info.age));
	
	return  info;
}

//头插法创造带头结点的单链表 
LinkedList LinkedListCtreate(int n)
{
	int i;
	LinkedList L,p,bak,pre;
	L=(Lnode*)malloc(sizeof(Lnode));
	if(L==NULL)
	{
		puts("申请空间失败");
		exit(0);
	}
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		if(p==NULL)
		{
			printf("申请空间失败");
			exit(0);
		}
		p->data=getInfo();
		p->next=L->next;
		L->next=p;	
	}
	
	
	bak=L->next;
	while(bak!=NULL&&bak->next!=NULL)
	{
		pre=bak;
		p=bak->next;
		while(p!=NULL)
		{
			if(strcmp(bak->data.strName,p->data.strName)==0&&bak->data.age==p->data.age)
			{
				pre->next=p->next;
				p->next=NULL;
				free(p);
			 
			}
		pre=p;
		p=p->next; 
		}
		
		bak=bak->next;
	}

	return L;
}

void LinkedListInsert(LinkedList L)
{
	LinkedList pre=NULL, q=(Lnode *)malloc(sizeof(Lnode));
	ElemType p;
	if(q==NULL)
	{
		puts("申请空间失败");
		exit(0);
	}
	
	printf("请输入插入位置（哪位同学之前）\n\n");
	
	p=getInfo();
	
	printf("请输入插入信息\n\n");
	
	q->data=getInfo();
	pre=L;
	while((pre!=NULL)&&((pre->next->data.strName!=p.strName)&&(pre->next->data.age!=p.age)))
	{
		pre=pre->next;
	}
	if(pre==NULL)
	{
		puts("该同学不存在 ");
		exit(0);
	}
	q->next=pre->next;
	pre->next=q;
	
}
//保序合并 
LinkedList linkedListMerge(LinkedList La,LinkedList Lb )
{
	LinkedList Lc,pre,bak,p;
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
    
	bak=Lc->next;
	while(bak!=NULL&&bak->next!=NULL)
	{
		pre=bak;
		p=bak->next;
		while(p!=NULL)
		{
			if(strcmp(bak->data.strName,p->data.strName)==0&&bak->data.age==p->data.age)
			{
				pre->next=p->next;
				p->next=NULL;
				free(p);
			 
			}
		pre=p;
		p=p->next; 
		}
		bak=bak->next;
	}

    return Lc;
}

void LinkedListDelete(LinkedList L)
{
	LinkedList pre,Ltarget;
	puts("请输入删除个体信息");
	ElemType target=getInfo();
	pre=L;
	while((pre!=NULL)&&((pre->next->data.strName!=target.strName)&&(pre->next->data.age!=target.age)))
	{
		pre=pre->next;
	}
	Ltarget=pre->next;
	pre->next=Ltarget->next;
	Ltarget->next=NULL;
	free(Ltarget);
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
	int i,len,cmd,list;
	LinkedList L1,L2,p,Lc,L;
	int listNum=1;
	ElemType a[MAXSIZE];
	
	printf("创建单链表，请输入初始化长度\t");
 	scanf("%d",&len);

	L1=LinkedListCtreate(len);
	
	for(;;)
	{	puts("******************************************");
		printf("0-退出\n1-插入\n2-合并\n3-删除\n4-打印链表\n5-新建链表\n键入命令以继续...\n");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case  INSERT :  if(listNum==2)
							{
								puts("选择链表,输入1,2");
								scanf("%d",&list);
								if(list==1) L=L1;  
								else 		L=L2;
							}
							else L=L1;
							LinkedListInsert(L);
							len++;
							p=L->next;
							printf("姓名\t年龄\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							
							break;
			case MERGE :	
							if(listNum<2)
								break;
							Lc=linkedListMerge(L1,L2);
							listNum=0; 
							p=ListReverse(Lc )->next;
							puts("******************************************");
							printf("姓名\t年龄\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							break;
			case DELETE : 	
							if(listNum==2)
							{
								puts("选择链表,输入1,2");
								scanf("%d",&list);
								if(list==1) L=L1;  
								else 		L=L2;
							}
							else
							L=L1;
							LinkedListDelete(L);
							len--;
							goto A;
							
		A:	case PRINT :	if(listNum==0)
							{
								p=Lc->next;
								puts("L-merged");
								printf("姓名\t年龄\n");
								while(p!=NULL)
								{
									printf("%s\t%d\n",(p->data).strName,p->data.age);
									p=p->next;
		
								}
							puts("******************************************");
							break;
							}
							p=L1->next;
							puts("******************************************");
							puts("L1");
							printf("姓名\t年龄\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							if(listNum<2)
								break;
							p=L2->next;
							puts("L2");
							printf("姓名\t年龄\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							puts("******************************************");
							

							break;
			case NEW :
							listNum++;
							L2=LinkedListCtreate(len);
							p=L2->next;
							puts("******************************************");
							printf("姓名\t年龄\n");
							while(p!=NULL)
							{
								printf("%s\t%d\n",(p->data).strName,p->data.age);
								p=p->next;
		
							}
							break;
			default :		exit(0);
		}
		
	}
	return 0;
}
