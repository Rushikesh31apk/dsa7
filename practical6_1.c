#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int exp;
	struct node*next;
};
struct node*insert(struct node*head,int x,int y)
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->coef=x;
	temp->exp=y;
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else{
		struct node*p=head;
		while(p->next!= NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=NULL;
	}
	return head;
}
struct node*create(struct node*head)
{
	int i,n,x,y;
	printf("\nlenth of polynomial:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter coef of %d: ",i+1);
		scanf("%d",&x);
		printf("enter exp of %d: ",i+1);
		scanf("%d",&y);
		head=insert(head,x,y);	
	}
	return head;	
}

void print(struct node*head)
{
	struct node*temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%dX^%d ",temp->coef,temp->exp);
		temp=temp->next;
		if(temp==NULL)
		{
			printf("\n");
    	}
    	else
    	{
    		printf("+");
		}
	}
}
void main()
{
	printf("polynomial representation:\n");
	struct node*head=NULL;
	head=create(head);
	print(head);
}
