#include<iostream>
using namespace std;
#define MAX 106
int graph[MAX][MAX];
int cost[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i==j)
			{
				graph[i][j]=0;
			}
			else
			{
				graph[i][j]=MAX;
			}
		}
	}
	for(int i=0;i<m;++i)
	{
		int v,w,weight;
		cin>>v>>w>>weight;
		graph[v][w]=graph[w][v]=weight;
	}
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(graph[i][k]+graph[k][j]<graph[i][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		cost[i]=MAX;
	} 
	for(int i=1;i<=n;++i)
	{
		int flag=0,max=0;
		for(int j=1;j<=n;++j)
		{
			if(graph[i][j]==MAX)
			{
				flag=1;
			}
			if(max<graph[i][j])
			{
				max=graph[i][j];
			}
		}
		if(flag==0)
		{
			cost[i]=max;
		}
	}
	int min=MAX,index=1;
	for(int i=1;i<=n;++i)
	{
		if(min>cost[i])
		{
			min=cost[i];
			index=i;
		}
	}
	if(min==MAX)
	{
		cout<<0;
	}
	else
	{
		cout<<index<<' '<<min;
	}
	return 0;
} 
