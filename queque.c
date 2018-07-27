//给定一个四则运算表达式，包括 + - * / （ ），计算结果
//有N行输入，每行有一个四则运算表达式，不超过10个数字ai（ 1 < = i < = 10 ）。
//为了简便定 0 < = ai < = 9
//有N行输出，每行一个运算结果
//问题分析
//首先就是关于符号优先级的问题，*，/的优先级是大于+和- 同时是从左到右进行的，
// 就是建立一个队列，先进去的先出来进行运算，


#include<stdio.h>
//这里为什么要建立一个结构体，答，为了建立一个队列
//这里是怎么判断符号的优先级，答，建立一个栈通过栈的特性先进后出，通过返回数字 
//建立队列应该怎么建 是用数组建，简单，
//创建队列
//清空队列
#define Max 200
typedef stuct node
{
		int head;
		int tail;
		char s[200];
}queue;
//初始化队列
void create(queue *q)
{
	p->head = p->tail = 0;
}
//判断队列是否满 
int full(queue *q)
{
	if((q->tail+1)%Max==q->head)return 1;
	else return 0;
}
//判断队列是否为空 
int empty(queue *q)
{
	if(q->tail==q->head)return 1;
	else return 0;
}
//入队列 
void enqueue(char c,queue *q)
{
	//首先判断队列是否满，防止队列溢出
	if(full(&q))
	{
		printf("QUEUE FAIL");
		return ;
	 } 
	 q->a[q->tail]=c;
	 q->tail=(q->tail+1)%Max;
}
//出队列 
char dequeue(queue *q)
{
	char c;
	if(empty(&q))
	{
		printf("QUEUE EMPTY");
		return ;
	}
	c=q->a[q->head];
	q->head=(q->head+1)%Max;
	return c;
}
//符号栈先进后出 
//
//
// 
int main()
{
	
}
 

