//����һ������������ʽ������ + - * / �� ����������
//��N�����룬ÿ����һ������������ʽ��������10������ai�� 1 < = i < = 10 ����
//Ϊ�˼�㶨 0 < = ai < = 9
//��N�������ÿ��һ��������
//�������
//���Ⱦ��ǹ��ڷ������ȼ������⣬*��/�����ȼ��Ǵ���+��- ͬʱ�Ǵ����ҽ��еģ�
// ���ǽ���һ�����У��Ƚ�ȥ���ȳ����������㣬


#include<stdio.h>
//����ΪʲôҪ����һ���ṹ�壬��Ϊ�˽���һ������
//��������ô�жϷ��ŵ����ȼ����𣬽���һ��ջͨ��ջ�������Ƚ������ͨ���������� 
//��������Ӧ����ô�� �������齨���򵥣�
//��������
//��ն���
#define Max 200
typedef stuct node
{
		int head;
		int tail;
		char s[200];
}queue;
//��ʼ������
void create(queue *q)
{
	p->head = p->tail = 0;
}
//�ж϶����Ƿ��� 
int full(queue *q)
{
	if((q->tail+1)%Max==q->head)return 1;
	else return 0;
}
//�ж϶����Ƿ�Ϊ�� 
int empty(queue *q)
{
	if(q->tail==q->head)return 1;
	else return 0;
}
//����� 
void enqueue(char c,queue *q)
{
	//�����ж϶����Ƿ�������ֹ�������
	if(full(&q))
	{
		printf("QUEUE FAIL");
		return ;
	 } 
	 q->a[q->tail]=c;
	 q->tail=(q->tail+1)%Max;
}
//������ 
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
//����ջ�Ƚ���� 
//
//
// 
int main()
{
	
}
 

