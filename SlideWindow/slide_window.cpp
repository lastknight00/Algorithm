#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,d,i;
deque<pair<int,int> > dq;
int main(){
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&d);
		while(!dq.empty()&&dq.front().second<=i-m)dq.pop_front();
		while(!dq.empty()&&dq.back().first>d)dq.pop_back();
		dq.push_back(make_pair(d,i));
		printf("%d ",dq.front());
	}
}
