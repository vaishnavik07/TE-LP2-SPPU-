// Problem Statement: 	
// Implement depth first search algorithm and breadth First Search algorithm. Use an undirected graph and develop a recursive algorithm for 
// searching all the vertices of a graph or tree data structure. 


#include <bits/stdc++.h>
using namespace std;

class Graph{

public:
	vector<int>* adj;
	int size;
	int* visited1,*visited2;

	Graph(int size)
	{
		visited1=new int(size);
		visited2=new int(size);
		for(int i=0;i<size;i++)
		{
			visited1[i]=0;
			visited2[i]=0;
		}
		adj= new vector<int>[size];
		this->size=size;
	}

	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void printAdjList()
	{
		for(int i=0;i<size;i++)
		{
			cout<<i;
			for(int j=0;j<adj[i].size();j++)
			{
				cout<<"-->"<<adj[i][j];
			}
			cout<<endl;
		}
	}


	void dfs(int v)
	{
		visited1[v]=1;
		cout<<v<<" ";
		for(int it:adj[v])
		{
			if(!visited1[it])
				dfs(it);
		}
	}

	void dfsStart(int v)    //function is reuired if there are multiple connected components
	{
		for(int i=0;i<size;i++)
		{
			visited1[i]=0;
		}
		dfs(v);
		for(int i=0;i<size;i++)
		{
			if(!visited1[i])
				dfs(i);
		}
	}


	void bfs(int v)
	{
		queue<int>q;
		q.push(v);
		visited2[v]=1;
		while(!q.empty())
		{
			int node=q.front();
			q.pop();
			cout<<node<<" ";

			for(int it: adj[node])
			{
				if(!visited2[it])
				{
					q.push(it);
					visited2[it]=1;
				}
			}
		}
	}

	void bfsStart(int v)   //function to check if multiple connected components
	{
		for(int i=0;i<size;i++)
		{
			visited2[i]=0;
		}
		bfs(v);
		for(int i=0;i<size;i++)
		{
			if(!visited2[i])
			   bfs(i);
		}
	}

};

int main() {
	
	int n,e;
	cout<<"Enter number of vertices: "<<endl;
	cin>>n;
	Graph g(n);
	cout<<"Enter number of edges: "<<endl;
	cin>>e;
	int u,v;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter edge "<<i+1<<": "<<endl;
		cin>>u>>v;
		g.addEdge(u,v);
	}

	 while(true){
	        int ch;
	        cout<<"enter your choice"<<endl;
	        cout<<"1.Adjacency List\n2.DFS\n3.BFS\n4.Quit"<<endl;
	        cin>>ch;
	        if(ch==1){
	            g.printAdjList();
	        }
	        else if(ch==2){
	        	int startVertex;
	            cout<<"Enter starting vertex: "<<endl;
	            cin>>startVertex;
	            g.dfsStart(startVertex);
	        }
	        else if(ch==3){

	        	int startVertex;
				cout<<"Enter starting vertex: "<<endl;
				cin>>startVertex;
				g.bfsStart(startVertex);
	        }
	        else{
	            break;
	        }
	        cout<<endl;
	    }

	return 0;
}
