#include<iostream>
using namespace std;
#define max_v 1001
int graph[max_v][max_v];
int visit[max_v];
int n,m,s,d=1;
void dfs(int v)
{
	static int flag=0;
	if(flag)	cout<<' ';
	flag++;
	cout<<v;
	for(int w=1;w<=n;++w)
	{
		if(!visit[w]&&graph[v][w])
		{
			visit[w]=1;
			dfs(w);
			d++;
			cout<<' '<<v;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<m;++i)
	{
		int v,w;
		cin>>v>>w;
		graph[v][w]=graph[w][v]=1;
	}
	visit[s]=1;
	dfs(s);
	if(d<n)
	{
		cout<<' '<<0;
	}
	return 0;
}
