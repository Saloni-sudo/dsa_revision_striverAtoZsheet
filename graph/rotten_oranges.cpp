//question
/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that 
is 4-directionally adjacent to a rotten
orange becomes rotten.

Return the minimum number of minutes that 
must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/


//what is mean by the question
/*
->we have given a matrix of n*m
->each cell in the matrix is atleast 2,1,0
->2 means that cell has a rotten oranges
->1 means a fresh orange
->0 means nothing
->the question says in the next minutes four adjacent side 
of a rotten oranges,if have a fresh orange will make it rotten.
->the question has asked about how many minutes will be needed to make every
fresh oranges rotten
->if we could not -1 will be returned.
*/

//thought process
/*
->first we take n and m as user input
->then after it we make a matrix
->fill the matrix
->then after this we will declare a queue which will store pair values
->then we traverse the whole matrix 
->push rotten oranges and count freshcount of oranges
->if there is no fresh oranges then return 0 directly because there is no oranges
to be rotten
->if there is fresh oranges present then we pass queus,fresh oranges, 0 as time 
in a function
->after that we count size of the queue
->we take each elemany from the queue there is new row fro the current row and column 
has a fresh oranges and it is not out bound
->then we make it rotten and bool rotten something would be then true 
and push thhat new row and column into the queue
after the loop we increase the min++
and at the end of the function we just return the minute
->and where we were calling the funtion there we count now if we still have frsh oranges
->if yes then -1 would be returned
->nope then minute wil be returned
*/

//code
#include <iostream>
#include <vector>
using namespace std;

int bfs(queue<pair<int,int>>&q,vector<vector<int>>&matrix,int time,int &fresh_count){
 vector<int> delrow={0,0,-1,1};
 vector<int> delcol={-1,1,0,0};
 int n=matrix.size();
 int m=matrix[0].size();
 

 while(!q.empty()){
     int sz=q.size();
     
     
     bool rottensomething=false;

     for(int i=0;i<sz;i++){
        int irow=q.front().first;
        int jcol=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newrow=irow+delrow[i];
            int newcol=jcol+delcol[i];

            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && matrix[newrow][newcol]==1){
                matrix[newrow][newcol]=2;
                rottensomething=true;
                fresh_count--;
                q.push({newrow,newcol});
            } 
         }
     }
      if(rottensomething) time++;

 }
 return time;   

};

int main(){
    int n,m;
    cin>>n>>m;
     vector<vector<int>>matrix(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
     }

     int fresh_count=0;
     queue<pair<int,int>>q;

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==2){
                q.push({i,j});
            }
            else if(matrix[i][j]==1){
                fresh_count++;
            }
        }
     }

     if(fresh_count==0){ cout<<0<<endl;
        return 0;}


     int time=bfs(q,matrix,0,fresh_count);

     if(fresh_count>0) {
        cout<<-1<<endl;
        return 0;
    }
    
    cout<<time<<endl;

    return 0;
}