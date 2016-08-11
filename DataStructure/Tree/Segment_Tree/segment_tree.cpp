#include<cstdio>
#include<algorithm>
using namespace std;
int s[400002],d[100000],n,i;
void init(int node, int start, int end){
	if(start==end)s[node]=start;
	else{
		init(node*2,start,(start+end)/2);
		init(node*2+1,(start+end)/2+1,end);
		s[node]=(d[s[node*2]]>d[s[node*2+1]])?s[node*2+1]:s[node*2];
	}
}
int query(int node, int start, int end, int i, int j){
	if(start>j||end<i) return -1;
	if(start>=i&&end<=j)return s[node];
	int t1 = query(node*2,start,(start+end)/2,i,j);
	int t2 = query(node*2+1,(start+end)/2+1,end,i,j);
	if(t1<0)return t2;
	if(t2<0)return t1;
	return (d[t1]>d[t2])?t2:t1;
}
int rec(int x, int y){
	if(x==y) return d[x];
	int p = query(1,0,n-1,x,y);
	int a=d[p]*(y-x+1);
	if(p>x)a=max(a,rec(x,p-1));
	if(p<y)a=max(a,rec(p+1,y));
	return a;
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",d+i);
	init(1,0,n-1);
	printf("%d\n",rec(0,n-1));
}
