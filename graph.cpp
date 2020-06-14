#include<iostream>
using namespace std;
#define max_v 1006
int n,m;
int find(int x,int pre[])
{
    if(pre[x]==x)
    {
        return x;
    }
    else
    {
        return pre[x]=find(pre[x],pre);
    }
}
void join(int v,int w,int pre[])
{
    int r1=find(v,pre);
    int r2=find(w,pre);
    if(pre[r1]!=pre[r2])
    {
        pre[r1]=r2;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int pre[max_v];
    int degree[max_v]={0};
    for(int i=1;i<=n;++i)
    {
        pre[i]=i;
    }
    for(int i=0;i<m;++i)
    {
        int v,w;
        cin>>v>>w;
        join(v,w,pre);
        degree[v]++;
        degree[w]++;
    }
    int count=0;
    int flag=0;
    for(int i=1;i<=n;++i)
    {
        if(pre[i]==i)
        {
            count++;
        }
        if(degree[i]%2)
        {
            flag=1;
        }
    }
    if(count==1&&flag==0)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
