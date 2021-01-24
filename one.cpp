#include <bits/stdc++.h>
using namespace std;
# define N 1000
vector<int> gr[N];
vector<int> gr_copy[N];

// Function to add edge
void Add_edge(int x, int y)
{
	gr[x].push_back(y);
	gr_copy[y].push_back(x);
}


void dfs1(int node,int visited[],vector<int> &v)
{	
visited[node]=1;
for(auto x: gr[node])
{
	if(visited[x]==0)
	{
		dfs1(x,visited,v);
	}
}
	v.push_back(node);
}

void dfs2(int node,int visited[])
{
visited[node]=1;
for(auto x: gr_copy[node])
{
	if(visited[x]==0)
	{
		dfs2(x,visited);
	}
}
}

// Driver code
int main()
{
	// Number of vertices
	int n = 5;
vector<int> v;
	// Add edges
	Add_edge(0, 2);
	Add_edge(1, 0);
	Add_edge(0, 3);
	Add_edge(2,1);
	Add_edge(3,4);

	 int visited[n];
	 fill(visited,visited+n,0);


	 for(int i=0;i<n;i++)
	 {
		 if(visited[i]==0)
			dfs1(i,visited,v);
	 }


	fill(visited,visited+n,0);

	int counting=0;
	 for(int i=v.size()-1;i>=0;i--)
	 {
		 int node=v[i];
		 if(visited[node]==0)
			{
				dfs2(node,visited);
				counting++;
			}
	 }
cout<<counting;
	return 0;
}
