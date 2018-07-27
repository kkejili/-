#include<stdio.h>
#include<string.h>
#define Max 200
typedef struct node
{
	int tail;
	int head;
	char a[200];
}queue;
void create(queue*q);
void enqueue(char ,queue*q);
char dequeue(queue*q);
int empty(queue);
int full(queue);
void change(char *);
double suan();
queue q;
char stack[200];
double Stack[200];
int top;
int main()
{
	char s[200];
	int n,sl;
	while(scanf("%s",&s)!=EOF) 
	{
		sl=strlen(s);
		s[sl]=';';
		s[sl+1]='\0';
		change(s);
		printf("%g\n",suan());
	}
	return 0;
}
void change(char *s)
{
	int sl,i,t;
	int privilege(char );
	sl=strlen(s);
	create(&q);
	top++;
	stack[top]='(';
	for(i=0;i<sl;i++)
	{
		switch(s[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9': enqueue(s[i],&q);break;
			case '(': top++;stack[top]=s[i];break;
			case ')':
			case ';':
			do{
			t=stack[top];
			top--;
			if(t!='(')
			enqueue(t,&q);
			}while(t!='('&&top!=-1); break;
			case '+':
			case '-':
			case '*':
			case '/':
			while(privilege(s[i])<=privilege(stack[top]))
			{
				t=stack[top];
				top--;
				enqueue(t,&q);
			}
			    top++;
			stack[top]=s[i]; break;
		}
	}
}
int privilege(char c)
{
	switch(c)
	{
	case '(':return 0;break;
	case '-':
	case '+':return 1;break;
	case '*':
	case '/':return 2;break;
	}
}
int full(queue q)
{
	if((q.tail+1)%Max==q.head)  return 1;
	else return 0;
}
int empty(queue q)
{
	if(q.head==q.tail)   return 1;
	else return 0;
}
char dequeue(queue &q)
{
	char c;
	if(empty(q))
	{
	printf("UNDERFLOW!\n");
	}
	c=q.a[q.head];
	q.head=(q.head+1)%Max;
	return c;
}
void enqueue(char c,queue &q)
{
	if(full(q)) 
	{
	printf("OVER FLOW!\n");
	return;
	}
	q.a[q.tail]=c;
	q.tail=(q.tail+1)%Max;
}
void create(queue q)
{
	q.head=q.tail=0;
}
double suan()
{
	char t;
	double x,y;
	int top=-1;
	while(!empty(q))
	{
		t=dequeue(q);
		if(t>='0'&&t<='9')
		{
			top++;
			Stack[top]=(int)t-'0';
		}
		else
		{
		y=Stack[top];
		top--;
		x=Stack[top];
		top--;
			switch(t)
			{
				case '+':top++;Stack[top]=x+y;break;
				case '*':top++;Stack[top]=x*y;break;
				case '/':top++;Stack[top]=x/y;break;
				case '-':top++;Stack[top]=x-y;break;
			}
		}
	}
	return Stack[top];
}
