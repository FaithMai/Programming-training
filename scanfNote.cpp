/**
 * HDU1170
 */
#include<cstdio>
int main()
{
	int n, a, b;
	char c;
	scanf("%d", &n);
	while(n--)
	{
		scanf("\n%c%d %d", &c, &a, &b);
//		scanf("%c%d %d\n", &c, &a, &b);  //这样又会出错，原因是回车用于结束输入？
//        fflush(stdin);  或者用这句代码清空缓存区
//        getchar()；    或者用这句代码获取回车
		switch(c)
		{
			case '+':{printf("%d\n", a+b);break;}
			case '-':{printf("%d\n", a-b);break;}
			case '*':{printf("%d\n", a*b);break;}
			case '/':a%b == 0?printf("%d\n",a/b):printf("%0.2lf\n", (double)a/b);
		}
	}
	return 0;
}