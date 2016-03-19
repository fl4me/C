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
	LinkedList L,p;
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
	
	return L;
}


//遍历查找

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
		puts("该学生不存在");
		exit(0);
	}
} 

//插入
 
void LinkedListInsert(LinkedList L)
{
	LinkedList pre=NULL, q=(Lnode *)malloc(sizeof(Lnode));
	ElemType p;
	if(q==NULL)
	{
		puts("申请空间失败");
		exit(0);
	}
	
	printf("请输入插入位置（哪位同学之前）\n");
	
	p=getInfo();
	
	printf("请输入插入信息\n");
	
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
	
	printf("创建单链表，请输入初始化长度");
 	scanf("%d",&len);
 	
 		//用户输入学生信息 ，创建单链表 
/*	for(i=0;i<len;i++)
	{
		a[i]=getInfo();	
	}
	*/
	L=LinkedListCtreate(len);
 	
 	
	for(;;)
	{	puts("******************************************");
		printf("0-退出\n1-插入\n2-合并\n3-删除\n4-打印链表\n键入命令以继续...\n");
		scanf("%d",&cmd);
		switch(cmd)
		{
			case  INSERT : LinkedListInsert(L);
							len++;
							p=L->next;
							printf("姓名\t年龄\n");
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
							printf("姓名\t年龄\n");
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
	//合成链表后，输出信息 

	
/*	LinkedListInsert(L);
		p=L->next;
	for(i=0;i<4;i++){
		printf("%s",(p->data).strName);
		p=p->next;
		
	}
	*/
		
	return 0;
}