#include<cstdio>
#define INF 999999
struct {
	int f,t,c;
}e[5200];
int t,n,m,w,d[501],i,a,j;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&w);
		for(i=0;i<2*m;i+=2){
			scanf("%d %d %d",&e[i].f,&e[i].t,&e[i].c);
			e[i+1].t=e[i].f;
			e[i+1].f=e[i].t;
			e[i+1].c=e[i].c;
		}
		for(;i<m*2+w;i++){
			scanf("%d %d %d",&e[i].f,&e[i].t,&e[i].c);
			e[i].c*=-1;
		}
		for(i=2;i<=n;i++)d[i]=INF;
		a=1;
		for(i=0;i<n;i++){
			for(j=0;j<m*2+w;j++){
				int x=e[j].f;
				int y=e[j].t;
				int c=e[j].c;
				if(d[x]<INF&&d[y]>d[x]+c){
					d[y]=d[x]+c;
					if(i==n-1){
						a=0;
						break;
					}
				}
			}
		}
		printf("%s\n",a?"NO":"YES");
	}
}
