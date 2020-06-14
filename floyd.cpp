#include<iostream>
using namespace std;
#define max_v 501
#define MAX 10000
int graph[max_v][max_v];
int cost[max_v][max_v];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,s,d;
	cin>>n>>m>>s>>d;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			graph[i][j]=MAX;
			cost[i][j]=MAX;
		}
	}
	for(int i=0;i<m;++i)
	{
		int v,w,dis,price;
		cin>>v>>w>>dis>>price;
		graph[v][w]=dis;
		graph[w][v]=dis;
		cost[v][w]=price;
		cost[w][v]=price;
	}
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(graph[i][k]+graph[k][j]<graph[i][j])
				{
					graph[i][j]=graph[i][k]+graph[k][j];
					cost[i][j]=cost[i][k]+cost[k][j];
				}
				else if(graph[i][k]+graph[k][j]==graph[i][j])
				{
					if(cost[i][k]+cost[k][j]<cost[i][j])
					{
						cost[i][j]=cost[i][k]+cost[k][j];
					}
				}
			}
		}
	}
	cout<<graph[s][d]<<' '<<cost[s][d];
	return 0;
} 
