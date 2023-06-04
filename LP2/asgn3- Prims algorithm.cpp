// Problem Statements:
// Greedy algorithms: 1)selection_sort  2)Prims algorithm


#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min_idx=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min_idx])
				min_idx=j;
		}
		if(min_idx!=i)
		{
			swap(arr[i],arr[min_idx]);
		}
	}
}


//Prims Algorithm
void mst(vector<vector<int>>adj[],int n)
{
	int sum=0;
	vector<int>vis(n,0);
	priority_queue<pair<int,pair<int,int>>, 
	vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
	// wt & node
	pq.push({0,{0,-1}});
	while(!pq.empty())
	{
		auto it=pq.top();
		pq.pop();
		int node=it.second.first;
		int parent=it.second.second;
		int wt=it.first;
		if(vis[node]==1)continue;
		cout<<node<<" "<<parent<<" "<<wt<<endl;
		vis[node]=1;
		sum+=wt;
		for(auto it:adj[node])
		{
			if(!vis[it[0]])
			{
				pq.push({it[1],{it[0],node}});
			}
		}
	}
	cout<<"MST"<<sum;
}


int main()
{
	int n,e;
	cout<<"\nEnter number of vertices: ";
	cin>>n;
	vector<vector<int>>adj[n];
	int u,v,wt;
	cout<<"\nEnter number of edges: ";
	cin>>e;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>wt;
		vector<int>tmp(2);
		tmp[0]=v;
		tmp[1]=wt;
		adj[u].push_back(tmp);
		tmp[0]=u;
		adj[v].push_back(tmp);
	}
	mst(adj,n);
	// int n;
	// cout<<"\n Enter number of elements to be sorted: ";
	// cin>>n;
	//
	// int arr[n];
	//
	// cout<<"\nEnter elements of array: ";
	// for(int i=0;i<n;i++)
	// {
	// cin>>arr[i];
	// }
	// selection_sort(arr,n);
	//
	// cout<<"\n Array after sortng: ";
	// for(int i=0;i<n;i++)
	// {
	// cout<<arr[i]<<" ";
	// }
	return 0;
}