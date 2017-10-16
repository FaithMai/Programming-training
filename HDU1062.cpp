#include<iostream>
using namespace std;
int main()
{
	char a[1005], *pf, *pb, *temp, c;
	int i;
	cin>>i;
	cin.ignore(1);
	while(i--)
	{
		cin.getline(a,1005,'\n');
		pf = pb = a;
		// 如果已经是末尾了
		while(*pf != '\0')
		{
			// 如果指针不指向空格或者回车就向前
			while(!(*pf == ' ' || *pf == '\0'))
                pf++;
			// 交换字母
			temp = pf - 1;
			while(temp>pb)
			{
				c = *temp;
				*temp = *pb;
				*pb = c;
				pb++;
				temp--;
			}
			// 遇到连续空格就一直加
            while(*pf == ' ')
			pf++;
			pb=pf;
		}
        cout<<a<<endl;
	}
	return 0;
}
