
// Problem Statement: 	
// Implement A Star Algorithm for any game search problem. 
// Game search problem solved: 8 puzzle Problem


#include <bits/stdc++.h>
using namespace std;

int g=0;
vector<vector<int>>ans;

void displayPuzzle(int puzzle[])
{
	for(int i=0;i<9;i++)
	{
		if(i%3==0){
			cout<<endl;
		}
		if(puzzle[i]==-1)
		{
			cout<<"_"<<" ";
		}
		else
		{
			cout<<puzzle[i]<<" ";
		}
	}
	cout<<"\n\n";
}

void printAnswer()
{
	int n=ans.size();
    for(int i=0;i<n;i++)
    {
    	cout<<"\nState "<<i<<" of Puzzle: "<<endl;
    	for(int j=0;j<9;j++)
    	{
    		if(j%3==0)
    		{
    			cout<<endl;
    		}
    		if(ans[i][j]==-1)
    		{
    			cout<<"_"<<" ";
    		}
    		else{
    			cout<<ans[i][j]<<" ";
    		}
    	}
    	cout<<endl;
    }
}

void copyPuzzle(int temp[],int real[])
{
	for(int i=0;i<9;i++)
	{
		temp[i]=real[i];
	}
}

void moveLeft(int puzzle[], int pos)
{
	swap(puzzle[pos], puzzle[pos-1]);
}

void moveRight(int puzzle[], int pos)
{
	swap(puzzle[pos], puzzle[pos+1]);
}

void moveTop(int puzzle[],int pos)
{
	swap(puzzle[pos], puzzle[pos-3]);
}

void moveDown(int puzzle[],int pos)
{
	swap(puzzle[pos], puzzle[pos+3]);
}

int heuristic(int start[],int goal[])
{
	int h=0;

	for(int i=0;i<9;i++)
	{
		if(start[i]==-1 || start[i]==goal[i])continue;
		for(int j=0;j<9;j++)
		{
			if(start[i]==goal[j])
			{
				int row1,row2,col1,col2;
				row1=i/3;
				row2=j/3;
				col1=i%3;
				col2=j%3;
				h+=abs(row1-row2)+abs(col1-col2);
			}
		}
	}
	return h+g;
}

void moveTile(int start[], int goal[])
{
	int emptyAt=-1;
	for(int i=0;i<9;i++)
	{
		if(start[i]==-1)
		{
			emptyAt=i;
			break;
		}
	}

	int t1[9],t2[9],t3[9],t4[9],f1=INT_MAX,f2=INT_MAX, f3=INT_MAX,f4=INT_MAX;

	copyPuzzle(t1,start);
	copyPuzzle(t2,start);
	copyPuzzle(t3,start);
	copyPuzzle(t4,start);

	int row=emptyAt/3;
	int col=emptyAt%3;

	if(col-1>=0)
	{
		moveLeft(t1,emptyAt);
		f1=heuristic(t1,goal);
	}
	if(col+1<3)
	{
		moveRight(t2,emptyAt);
		f2=heuristic(t2,goal);
	}
	if(row-1>=0)
	{
		moveTop(t3,emptyAt);
		f3=heuristic(t3,goal);
	}
	if(row+1<3)
	{
		moveDown(t4,emptyAt);
		f4=heuristic(t4,goal);
	}


	if(f1<=f2 && f1<=f3 && f1<=f4)
	{
		moveLeft(start,emptyAt);
	}
	else if(f2<=f1 && f2<=f3 && f2<=f4)
	{
		moveRight(start,emptyAt);
	}
	else if(f3<=f1 && f3<=f2 && f3<=f4)
	{
		moveTop(start,emptyAt);
	}
	else
	{
		moveDown(start,emptyAt);
	}

//	displayPuzzle(start);
	vector<int>state(9);
	for(int i=0;i<9;i++)
	{
		state[i]=start[i];
	}
	ans.push_back(state);

}

void solvePuzzle(int start[],int goal[])
{
	g++;
	cout<<"\ng:"<<g;
	if(g>=31)
	{
		cout<<"Problem is not solvable";
		return;
	}
	moveTile(start,goal);
	int h=heuristic(start,goal);
	cout<<"\nHeuristic: "<<h;
	if(h==g)
	{
		cout<<"\n Solution found in "<<g<<" steps!!";
		printAnswer();
		return;
	}
	solvePuzzle(start,goal);
}

int main() {
	int start[9],goal[9];

	cout<<"Enter start state of puzzle: (Enter -1 at empty place)";
	for(int i=0;i<9;i++)
	{
		cin>>start[i];
	}

	cout<<"Enter goal state of puzzle: (Enter -1 at empty place)";
	for(int i=0;i<9;i++)
	{
		cin>>goal[i];
	}

//	displayPuzzle(start);

	vector<int>state(9);
	for(int i=0;i<9;i++)
	{
		state[i]=start[i];
	}
	ans.push_back(state);

	solvePuzzle(start,goal);


	return 0;
}
