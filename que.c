#include<stdio.h>
#include<string.h>
#define Max 200
typedef struct node
{
	int tail;
	int head;
	char a[200];
}queue;
void create(queue*);//�൱�ڳ�ʼ������ 
void enqueue(char ,queue*);//����� 
char dequeue(queue*);//������ 
int empty(queue*q);//�ж϶����Ƿ��ǿյ� 
int full(queue*q);//�ж϶����Ƿ������� 
void change(char *);//
double suan();//��������ǽ����������㡣 
queue q;//ͨ���ṹ�嶨����С� 
char stack[200];//Ϊʲô���ﶨ����char�͵ĺ�double�ġ� 
double Stack[200];
int top;
int main()
{
	char s[200];
	int n,sl;
	while(scanf("%s",&s)!=EOF) //EOF (End Of File)�ж��Ƿ�������� ʹ�������ѭ��״̬�� 
	{
		sl=strlen(s);
		s[sl]=';';//Ϊʲô����Ҫ�ڼ���һ��; 
		s[sl+1]='\0';
		change(s);//������иı䣬�������ȼ����� 
		printf("%g\n",suan());
	}
	return 0;
}
void change(char *s)
{
	int sl,i,t;
	int privilege(char );//���ŵ����ȼ������� 
	sl=strlen(s);//��s1��ֵΪs�����ֵ�� 
	create(&q);//��ʼ������ 
	top++;//����topΪʲôҪ�Ӽ� 
	stack[top]='(';//����ͨ������������ջ �ѣ���������,�Ƚ��ȳ���FIFO��first in first out�� [1]  ��ջ���Ƚ����(FILO��First-In/Last-Out)��
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
		case '9': enqueue(s[i],&q);break;//����������� 
		case '(': top++;stack[top]=s[i];break;//����ΪʲôtopҪ�Ӽӣ� 
		case ')':
		case ';'://�������;˵��������ĩβ 
		do{
		t=stack[top];//����ջ��ջ������Ϊ�������������е������������ȳ�����������������֮������ջ����ô�����ʲ�Ӧ���Ǵ��������� 
		top--;//�������Ǵ���������ж��ģ�������ջ��ͨ���Ƚ��������������ߵ��ȳ�����֮�������С� 
		if(t!='(')//�����ĵ�{��Ӧ 
		enqueue(t,&q);//����������� 
		}while(t!='('&&top!=-1); break;//���ｫ�������ִ�ջ��������� 
		case '+':
		case '-':
		case '*':
		case '/':
		while(privilege(s[i])<=privilege(stack[top]))//ͨ��ջ�����з������ȼ����б� 
		{//
		t=stack[top];//ͨ��ջ�������ջ�������ȼ��ͣ� ������� 
		top--;
		enqueue(t,&q);
		}
		    top++;//��ջ�������ȼ��ߣ���ջ 
		stack[top]=s[i]; break;
		}
	}
}
int privilege(char c)//���ŵ����ȼ����� 
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
int full(queue *q)
{
	if((q->tail+1)%Max==q->head)  return 1;
	else return 0;
}
int empty(queue *q)
{
	if(q->head==q->tail)   return 1;
	else return 0;
}
char dequeue(queue *q)
{
	char c;
	if(empty(q))
	{
	printf("UNDERFLOW!\n");
	}
	c=q->a[q->head];
	q->head=(q->head+1)%Max;
	return c;
}
void enqueue(char c,queue *q)//����� 
{
	if(full(q)) 
	{
		printf("OVER FLOW!\n");
		return;
	}
	q->a[q->tail]=c;
	q->tail=(q->tail+1)%Max;
}
void create(queue *q)
{
	q->head=q->tail=0;
}
double suan()
{
	char t;
	double x,y;
	int top=-1;
	while(!empty(&q))//�����в�Ϊ��ʱ�������� 
	{
			t=dequeue(&q);//�ͷŶ������ÿһ��ֵ 
			if(t>='0'&&t<='9')
			{
			top++;
			Stack[top]=(int)t-'0';//ע�������S�Ǵ�д�ģ� 
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
