#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node cell;
#define MAX 3006
struct node
{
	int v,w,m;	
};
cell edges[MAX];
int pre[MAX];
bool cmp(cell i,cell j)
{
	if(i.m<j.m)
	{
		return true;
	}
	return false;
}
int find(int x)
{
	if(pre[x]==x)
	{
		return x;
	}
	else
	{
		return pre[x]=find(pre[x]);
	} 
}
void reunion(int x,int y)
{
	int r1=find(x);
	int r2=find(y);
	if(pre[r1]!=pre[r2])
	{
		pre[r1]=r2;
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>edges[i].v>>edges[i].w>>edges[i].m;
	}
	sort(edges,edges+m,cmp);
	for(int i=1;i<=n;++i)
	{
		pre[i]=i;
	}
	int weight=0,num=0;
	for(int i=0;i<m;++i)
	{
		int x=edges[i].v,y=edges[i].w;
		if(find(x)!=find(y))
		{
			weight+=edges[i].m;
			num++;
			reunion(x,y);
		}
	}
	if(num!=n-1)
	{
		cout<<-1;
	}
	else
	{
		cout<<weight;
	}
	return 0;
} 
