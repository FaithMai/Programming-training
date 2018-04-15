#include<cstdio>
#include<malloc.h>
#include<vector>
#include<queue>
using namespace std;
#define Type int
typedef struct tree{
	Type data;
	struct tree *l, *r;
}BTree;
void build(BTree* &tree, vector<int> a, vector<int> b){
	if(a.size()==0)
		return;
	int p = 0;
	vector<int> al, ar, bl, br;
	tree = (BTree*)malloc(sizeof(BTree));
	tree->l = tree->r = NULL;
	// 找到根节点
	for(int i = 0; i < a.size(); ++i){
		if(a[i] == b[0]){
			p = i;
			break;
		}
	}
	for(int i = 0; i < p; ++i)
		al.push_back(a[i]);
	for(int i = p+1; i < a.size(); ++i)
		ar.push_back(a[i]);
	for(int i = 1; i <= p; ++i)
		bl.push_back(b[i]);
	for(int i = p+1; i < a.size(); ++i)
		br.push_back(b[i]);
	tree->data = a[p];
	// 递归建树
    build(tree->l, ar, br);
    build(tree->r, al, bl);


}
// dfs层次遍历
void dfs(BTree *r){
	queue<BTree*> q;
	BTree *root = r;
	q.push(root);
	int f = 0;
	while(!q.empty()){
		if(f++)
			putchar(' ');
		root = q.front();
		printf("%d", root->data);
		q.pop();
		if(root->l != NULL)
			q.push(root->l);
		if(root->r != NULL)
			q.push(root->r);
	}
	printf("\n");
}

int main()
{
	int n, x;
	vector<int> a, b;
	BTree *tree = NULL;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&x);
		a.push_back(x);
	}
	for(int j = 0; j < n; ++j){
		scanf("%d",&x);
		b.push_back(x);
	}
	//printf("%d,%d",a.size(), b.size());
	build(tree, a, b);
	//printf("%p",tree);
	dfs(tree);
	return 0;
}
