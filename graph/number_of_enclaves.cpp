//question
/*
you are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking 
off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

//what it means
/*
->we are given an matrix of n*m
->where the cell with represent land and with 0 reprsent water
->move means we can walk off the boundary or move to another adjacent land cell
->question demand for number of land cell which we cannot walk off the boundary in any number of moves
->from the example of the question it meant we need to count number of land cell which are totally surrounded by water
*/

//thought process
/*
->first we ask from the user size of the matrix
->then ask from the inputs inside the matrix
->after geting the matirx we make a funtion which will give us the number of enclaves there we use two loop 
->to traverse the matrix and when we are at boundary and there is lank we call dfs funtion there
->in dfs function we mark that land as water because we are the boundary and then move to adjacnet cell to check if there are any land
->if found call dfs there
->and then after marking each lanc cell at the boundary as water
->in the number of enclaves funtion we agin traverse and count number of land cells then and just return it
*/



//code
#include<iostream>
#include<vector>
using namespace std;

void dfs(int i,int j,vector<vector<int>>&matrix,int &n,int &m){

    matrix[i][j]=0;

    vector<int>delrow={0,0,-1,1};
    vector<int>delcol={-1,1,0,0};

    for(int k=0;k<4;k++){
        int newrow=i+delrow[k];
        int newcol=j+delcol[k];

        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
            if(matrix[newrow][newcol]==1){
                dfs(newrow,newcol,matrix,n,m);
            }
        }
    }

}

int number_of_enclaves(int &n,int &m,vector<vector<int>>matrix){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(matrix[i][j]==1){
                    dfs(i,j,matrix,n,m);
                }
            }
        }
    }
     
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==1) cnt++;
        }
    }

    return cnt;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    
    int num=number_of_enclaves(n,m,matrix);
   cout<<num<<endl;

    return 0;
}