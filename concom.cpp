/*
ID:gateaux1
PROG: concom
LANG: C++
*/

#include<iostream>
#include<string.h>
#include<fstream>
#include<stdio.h>
using namespace std;
int tri[101][101],n,m=0,c[101];
bool con[101];
void dfs(int x)
{
	con[x]=true;
	for(int i=1;i<=n;i++) c[i]+=tri[x][i];
	for(int i=1;i<=n;i++) if(c[i]>=50 && !con[i]) dfs(i);
}
int main()
{
	ifstream fin ("concom.in");
	ofstream fout ("concom.out");

	memset(tri,0,sizeof(tri));

	fin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;

		fin>>a>>b;
		if(a>m) m=a;
		if(b>m) m=b;
		fin>>tri[a][b];
	}
	n=m;
	for(int i=1;i<=n;i++)
	{
		memset(con,false,sizeof(con));
		memset(c,0,sizeof(c));
		dfs(i);
		for(int j=1;j<=n;j++)
			if(j!=i && con[j]) fout<<i<<" "<<j<<endl;
	}

	return 0;
}
