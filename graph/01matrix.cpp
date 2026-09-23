//question
/*
->Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
*/

//what it meant
/*
->so,the question is aksing about nearest 0 for evry cell
->distance for adjacent cell is 1 is the clue it gave
*/


//thought process
/*
->okey first take user input m and n
->take input from the user about the cell to make the marix
->one thing is that if the cell value is 0 so,nearest distance for it will be 0
->i need to return a matirx also 
->to take count of which cell is marked we take visisted array
->to return the dirtance we will take another matrix
->and after that which cell has 0 value push them into queue and mark them vis and in distance matrix marks them as 0.
now move adjacent sid e of the matrix and if we got an unvisited one 
push them amrk them and give distnce value +1
->at last,return the distance matrix.
*/



//code
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> update_matrix(int&m,int &n,vector<vector<int>>&matrix)
{ 
    vector<vector<int>>dis(m,vector<int>(n,0));
    vector<vector<int>>vis(m,vector<int>(n,0));

    queue<pair<pair<int,int>,int>>q;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
            else if(matrix[i][j]==1){
                vis[i][j]=0;
            }
        }
    }

    vector<int> delrow={0,0,-1,1};
    vector<int>delcol={-1,1,0,0};

    while(!q.empty()){
        int istart=q.front().first.first;
        int jstart=q.front().first.second;
        int step=q.front().second;
        dis[istart][jstart]=step;
        q.pop();

        for(int i=0;i<4;i++){
            int newstart=istart+delrow[i];
            int newend=jstart+delcol[i];

            if(newstart>=0 && newstart<m && newend>=0 && newend<n && vis[newstart][newend]==0){
                
                vis[newstart][newend]=1;
                q.push({{newstart,newend},step+1});
                
            }

        }
    }
  return dis;
}
int main(){

    int m,n;
    cin>>m>>n;

    vector<vector<int>> matrix(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    vector<vector<int>> result=update_matrix(m,n,matrix);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }

    return 0;
}