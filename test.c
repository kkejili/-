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
//假设现在有一个长度为n的字符串S0S1S2...Sn-2Sn-1，我们可以把这个字符串向右循环右移一位得到新的字符串：Sn-1S0S1S2...Sn-2。
//现在有两个长度相同的字符串S和T，问S能不能通过若干次循环右移变成字符串T。
//题目分析，先遍历字符串数组，通过strlen找到字符串长度，先判断长度，
//先找到相同字母，之后遍历发现是否相等

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
众数是一组数中出现次数最多的数。

现在给你一个长度为n的数组a[]，你需要输出a[]中的众数是哪个数字。若有多个数字出现的次数都是最多的，那么输出其中最小的数字。
*/
//题目分析
//先输入一个数，定义数组的长度，定义一个int指针，指向malloc分配的内存，之后寻找那个数出现的次数最多，定义两个数组，另一个记录出现次数的大小，
//	找到m中最大的数，并且找到s中最小的数
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
题目D
问题分析
T在1-5间故通过switch语句来进行选择减小难度，应该定义为long long int型数据，先通过switch语句来选择要输入的T的大小，之后，通过取前六位来判断出生地信息，出生地信息可以
用一个函数，来判断，在函数中也是通过switch来进行选择，之后通过输出函数，来进行输出，
本题应该用一个长度为18的数组来进行输入，那样简便，直接在各个case之后输出身份证信息，
先定义一个结构体，这个结构体中有
*/
//通过给予数字来判断出生地信息和生日信息，直接输出没有返回值通过查看题目信息发现只有前两个不一样，故只需要判断前两个数字，
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
题目E
题目分析
m取模a1加上m取模a2加上m取模a3
这题比较坑的是我不知道取模就是取余
*/

