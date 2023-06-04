// Problem Statements:	
// Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and Backtracking for n-queens problem



#include <bits/stdc++.h>
using namespace std;

int n;

bool isSafe(int row, int col,vector<bool>&rows,vector<bool>&ld, vector<bool>&rd)
{
	if(rows[row]==true || ld[row+col]==true || rd[row-col+n-1]==true)
		return false;
	return true;
}

bool solve(vector<vector<int>>&board, int col,vector<bool>&rows,vector<bool>&ld, vector<bool>&rd)
{
	if(col==n)return true;

	for(int i=0;i<n;i++)
	{
		if(isSafe(i,col,rows,ld,rd)==true)
		{
			rows[i]=true;
			ld[i+col]=true;
			rd[i-col+n-1]=true;
			board[i][col]=1;

			bool ans=solve(board,col+1,rows,ld,rd);
			if(ans==true)return true;

			rows[i]=false;
			ld[i+col]=false;
			rd[i-col+n-1]=false;
			board[i][col]=0;

		}
	}

	return false;

}

int main()
{
	cout<<"Enter rows of chess board: ";
	cin>>n;

	vector<vector<int>>board(n,vector<int>(n,0));

	vector<bool>rows(n,false);
	vector<bool>ld(2*n-1,false);
	vector<bool>rd(2*n-1,false);

	bool ans= solve(board, 0, rows, ld, rd);

	if(ans==false)
		cout<<"Not possible"<<endl;
	else
	{
		cout<<"Possible"<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	return 0;
}
