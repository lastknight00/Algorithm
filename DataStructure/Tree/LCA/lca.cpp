#include<cstdio>
#include<vector>
#define MAX 100001
int n,m,a,b,i,l[MAX][21],x[MAX];
std::vector<int> v[MAX];
void dfs(int p,int f){
	for(int i=0;i<v[p].size();i++){
		int c=v[p][i];
		if(c==f)continue;
		x[c]=x[p]+1;
		l[c][0]=p;
		for(int j=1;j<21;j++)l[c][j]=l[l[c][j-1]][j-1];
		dfs(c,p);
	}
}
int lca(int a,int b){
	if(x[a]>x[b])std::swap(a,b);
	for(int i=20;i>=0;i--){
		if((1<<i)<=x[b]-x[a])b=l[b][i];
	}
	if(a==b)return a;
	for(int i=20;i>=0;i--){
		if(l[a][i]!=l[b][i]){
			a=l[a][i],b=l[b][i];
		}
	}
	return l[a][0];
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1,0);
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&a,&b);
		printf("%d\n",lca(a,b));
	}
}
