#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10005;
double dp[maxn];
int cost[maxn];
double p[maxn];

int main()
{

	int n, m;
	while(scanf("%d%d",&n, &m)==2){
		if(n==0&&m==0)
			break;
		for(int i = 1; i <= m; ++i){
			scanf("%d%lf",&cost[i], &p[i]);
			p[i] = 1 - p[i];
		}
		// 初始化dp
		for(int i = 0; i <= n; ++i)
			dp[i] = 1.0;
		// 遍历从开始到结束每一个大学
		for(int i = 1; i <= m; ++i){
			for(int j = n; j >= cost[i]; --j){
				// 有j数目的钱，不被选的概率
				// 之所以从上往下dp，是因为同一所大学只能在一遍中选择一次
				dp[j] = min(dp[j], dp[j-cost[i]]*p[i]);
			}
		}
		printf("%.1lf%%\n", (100.0-dp[n]*100));
	}
	return 0;
}
