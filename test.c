/*
#include<stdio.h>
int main()
{
	int n=0,t=0,s=0,m=0;
	scanf("%d",&n);
	m=n;
	while(1)
	{
		t=m%10;
		s+=t;
		if(m-t==0)break;
		m=n/10;
	}
	if(n%s==0)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}
*/
//����������һ������Ϊn���ַ���S0S1S2...Sn-2Sn-1�����ǿ��԰�����ַ�������ѭ������һλ�õ��µ��ַ�����Sn-1S0S1S2...Sn-2��
//����������������ͬ���ַ���S��T����S�ܲ���ͨ�����ɴ�ѭ�����Ʊ���ַ���T��
//��Ŀ�������ȱ����ַ������飬ͨ��strlen�ҵ��ַ������ȣ����жϳ��ȣ�
//���ҵ���ͬ��ĸ��֮����������Ƿ����

#include<stdio.h>
#include<string.h>
int main()
{
	
	char a[100],b[100];
	int i=0;
	int	h=0;
	int l=0;
	scanf("%s",&a);
	scanf("%s",&b);
	if(strlen(a)!=strlen(b))printf("No");
	for(h=0;h<strlen(a);h++)
	{
		if(a[0]==b[h])
		{
			for(i=h;i<strlen(a);i++)
			{
				if(b[i]!=a[l++])
				{
					printf("No");
					break;
				}
			}
			for(i=0;i<h;i++)
			{
				if(a[l++]!=b[i])
				{
					printf("No");
					break;
				}
			}
			printf("Yes");
		}
	}
	
	return 0;
}


/*
������һ�����г��ִ�����������

���ڸ���һ������Ϊn������a[]������Ҫ���a[]�е��������ĸ����֡����ж�����ֳ��ֵĴ����������ģ���ô���������С�����֡�
*/
//��Ŀ����
//������һ��������������ĳ��ȣ�����һ��intָ�룬ָ��malloc������ڴ棬֮��Ѱ���Ǹ������ֵĴ�����࣬�����������飬��һ����¼���ִ����Ĵ�С��
//	�ҵ�m���������������ҵ�s����С����
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *s;
	int *m;
	int i=0,j=0;
	s = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	m = (int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(s[i]==s[j])
			{
				m[i]++;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(m[i]>)
	}
	free(s);
	*s =NULL;
	free(m);
	*m=NULL;
	return 0;
}
*/

/*
��ĿD
�������
T��1-5���ͨ��switch���������ѡ���С�Ѷȣ�Ӧ�ö���Ϊlong long int�����ݣ���ͨ��switch�����ѡ��Ҫ�����T�Ĵ�С��֮��ͨ��ȡǰ��λ���жϳ�������Ϣ����������Ϣ����
��һ�����������жϣ��ں�����Ҳ��ͨ��switch������ѡ��֮��ͨ����������������������
����Ӧ����һ������Ϊ18���������������룬������㣬ֱ���ڸ���case֮��������֤��Ϣ��
�ȶ���һ���ṹ�壬����ṹ������
*/
//ͨ�������������жϳ�������Ϣ��������Ϣ��ֱ�����û�з���ֵͨ���鿴��Ŀ��Ϣ����ֻ��ǰ������һ������ֻ��Ҫ�ж�ǰ�������֣�
/*

#include<stdio.h>

void xinxi(char z[18])
{
	switch(z[0])
	{
	case '1':
		{
			printf("He/She is from Beijing,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	case '2':
		{
			printf("He/She is from Liaoning,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	case '3':
		{
			if(z[1]=='1')
			printf("He/She is from Shanghai,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			if(z[1]=='3')
			printf("He/She is from Zhejiang,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	case '5':
		{
			printf("He/She is from Tibet,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	case '7':
		{
			printf("He/She is from Taiwan,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	case '8':
		{
			if(z[1]=='1')
			printf("He/She is from Hong Kong,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			if(z[1]=='2')
			printf("He/She is from Macao,and his/her birthday is on %c%c,%c%c,%c%c%c%c based on the table.\n",z[13],z[12],z[11],z[10],z[9],z[8],z[7],z[6]);
			return ;
		}
	}
}
int main()
{
	int T;
	int i;
	scanf("%d",&T);
		switch(T)
		{
			case 1:
				{
					char a[18];
					for(i=0;i<18;i++)scanf("%c",&a);
					xinxi(a);
					return ;
				}
			case 2:
				{
					char b[18],c[18];
					for(i=0;i<18;i++)scanf("%c",&b);
					xinxi(b);
					for(i=0;i<18;i++)scanf("%c",&c);
					xinxi(c);
					return ;
				}
			case 3:
				{
					char d[18],e[18],f[18];
					for(i=0;i<18;i++)scanf("%c",&d);
					xinxi(d);
					for(i=0;i<18;i++)scanf("%c",&e);
					xinxi(e);
					for(i=0;i<18;i++)scanf("%c",&f);
					xinxi(f);
					return ;
				}
			case 4:
				{
					char g[18],h[18],k[18],l[18],m[18];
					for(i=0;i<18;i++)scanf("%c",&g);
					xinxi(g);
					for(i=0;i<18;i++)scanf("%c",&h);
					xinxi(h);
					for(i=0;i<18;i++)scanf("%c",&k);
					xinxi(k);
					for(i=0;i<18;i++)scanf("%c",&l);
					xinxi(l);
					for(i=0;i<18;i++)scanf("%c",&m);
					xinxi(m);
					return ;
				}
			case 5:
				{
					char n[18],o[18],p[18],q[18],r[18],s[18];
					for(i=0;i<18;i++)scanf("%c",&n);
					xinxi(n);
					for(i=0;i<18;i++)scanf("%c",&o);
					xinxi(o);
					for(i=0;i<18;i++)scanf("%c",&p);
					xinxi(p);
					for(i=0;i<18;i++)scanf("%c",&q);
					xinxi(q);
					for(i=0;i<18;i++)scanf("%c",&r);
					xinxi(r);
					for(i=0;i<18;i++)scanf("%c",&s);
					xinxi(s);
					return ;
				}
		}
	return 0;
}
*/
/*
��ĿE
��Ŀ����
mȡģa1����mȡģa2����mȡģa3
����ȽϿӵ����Ҳ�֪��ȡģ����ȡ��
*/

