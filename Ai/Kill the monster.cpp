#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;
int a,b;
int mm;
int vis[10];
struct p{
	int h;
	int bb;
}s[10];
void dfs(int c,int b)
{if(b<=0)
	{mm=min(mm,c);
		return ;
	}
	for(int i=0;i<a;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(s[i].bb>=b)
			dfs(c+1,b-2* s[i].h);
			else
			dfs(c+1,b-s[i].h);
			vis[i]=0;
		}
	}
}
int main()
{while(cin>>a>>b)
	{mm=inf;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<a;i++)
		{int h1,h2;
        cin>>h1>>h2;
        s[i].h=h1;
        s[i].bb=h2;
		}
		dfs(0,b);
		if(mm!=inf)
		cout<<mm<<endl;
		else
		cout<<-1<<endl;
	}
	return 0;
}
