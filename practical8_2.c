#include<stdio.h>
#include<string.h>
#define max 20
char stack[max];
int top=-1;
void push(char x)
{
	if(!isfull())
	{
		stack[++top]=x;
	}
	else
	{
		printf("stack is full:\n");
	}
}
char pop()
{
	if(!isempty())
	{
		return stack[top--];
	}
	else
	{
		printf("stack is empty\n");
		return 0;
	}
}
int isempty()
{
	if(top==-1)
	{
	   return 1;
    } 
	return 0;
}
int isfull()
{
	if(top=max-1)
	{
		return 1;
	}
	return 0;
}
int pre(char x)
{
	if(x=='+'|| x=='-')
	{
		return 0;
	}
	else if(x=='*' || x=='/')
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
void display(char a[])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
	}
}
void postfix(char a[])
{
	char post[max],symbol,next;
	int i,j=0;
	for(i=0;a[i]!='\0';i++)
	{
		symbol=a[i];
		switch(symbol)
		{
			case '(':
				push(symbol);
				break;
			case ')':
				while(next=pop()!='(')
				{
					post[j++]=next;
				}
				break;
			case '+':
			case '-':
		    case '/':
		    case '*':
		    case '^':
		    	while(!isempty() && pre(stack[top])>=pre(symbol))
		    	{
		    		post[j++]=pop();
				}
				push(symbol);
				break;
			default:
				post[j++]=symbol;
		}
	}
	while(!isempty())
	{
		post[j++]=pop();
	}
	post[j++]='\0';
	display(post);
}

void main()
{
	char a[]="((a*(b+c)*((d-a)/b))";
	
	printf("infix exp: ");
	display(a);
	postfix(a);
	printf("\npostfix exp: ");
}

