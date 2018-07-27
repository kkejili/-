#include<stdio.h>
#include<string.h>
#define Max 200
typedef struct node
{
	int tail;
	int head;
	char a[200];
}queue;
void create(queue*);//相当于初始化队列 
void enqueue(char ,queue*);//入队列 
char dequeue(queue*);//出队列 
int empty(queue*q);//判断队列是否是空的 
int full(queue*q);//判断队列是否是满的 
void change(char *);//
double suan();//这个函数是进行最后的运算。 
queue q;//通过结构体定义队列。 
char stack[200];//为什么这里定义了char型的和double的、 
double Stack[200];
int top;
int main()
{
	char s[200];
	int n,sl;
	while(scanf("%s",&s)!=EOF) //EOF (End Of File)判断是否输入结束 使程序进入循环状态， 
	{
		sl=strlen(s);
		s[sl]=';';//为什么这里要在加上一个; 
		s[sl+1]='\0';
		change(s);//对其进行改变，加入优先级规则 
		printf("%g\n",suan());
	}
	return 0;
}
void change(char *s)
{
	int sl,i,t;
	int privilege(char );//符号的优先级函数， 
	sl=strlen(s);//将s1赋值为s的最大值， 
	create(&q);//初始化队列 
	top++;//这里top为什么要加加 
	stack[top]='(';//这里通过数组来定义栈 堆，队列优先,先进先出（FIFO—first in first out） [1]  。栈，先进后出(FILO—First-In/Last-Out)。
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
		case '9': enqueue(s[i],&q);break;//将数字如队列 
		case '(': top++;stack[top]=s[i];break;//这里为什么top要加加， 
		case ')':
		case ';'://如果到达;说明到达了末尾 
		do{
		t=stack[top];//先入栈，栈的特性为先入后出，而队列的特性是先入先出这里让数字先入后出之后在如栈，那么我想问不应该是从左向右吗 
		top--;//答，他读是从右往左进行读的，故先入栈，通过先进后出的特性让左边的先出来，之后进入队列。 
		if(t!='(')//和上文的{对应 
		enqueue(t,&q);//将数字如队列 
		}while(t!='('&&top!=-1); break;//这里将所有数字从栈中送入队列 
		case '+':
		case '-':
		case '*':
		case '/':
		while(privilege(s[i])<=privilege(stack[top]))//通过栈来进行符号优先级的判别 
		{//
		t=stack[top];//通过栈，如果比栈顶的优先级低， 就入队列 
		top--;
		enqueue(t,&q);
		}
		    top++;//比栈顶的优先级高，如栈 
		stack[top]=s[i]; break;
		}
	}
}
int privilege(char c)//符号的优先级函数 
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
void enqueue(char c,queue *q)//入队列 
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
	while(!empty(&q))//当队列不为空时进行运算 
	{
			t=dequeue(&q);//释放队列里的每一个值 
			if(t>='0'&&t<='9')
			{
			top++;
			Stack[top]=(int)t-'0';//注意这里的S是大写的， 
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
