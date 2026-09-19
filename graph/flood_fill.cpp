//question
/*
You are given an image represented by an m x n grid of integers
image, where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. Your task is
to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent
 (pixels that share a side with the original pixel, either horizontally 
 or vertically) and shares the same color as the starting pixel.

Keep repeating this process by checking neighboring pixels of the updated pixels
 and modifying their color if it matches the original color of the starting pixel.

The process stops when there are no more adjacent pixels of the original color to 
update.

Return the modified image after performing the flood fill.
*/



//what is means
/*
->we are given matrix of n*m
->we have a cell called as sr,sc and also a color
->we have to mark sr,sc cell with the given color
->and aslo all the neighbours of sr,sc which is of the original color when sr,sc was not colored
and then return the colored matrix.
*/


//thought process
/*
->first we take n and m from the user
->then take cell infor from the user
->then take sr,sc from the user and after that color from the user
->after everything given in the question is provided to us by the user
->we make a copy of the matrix which we will return as an answer
->we first store the intial color of sr,sc cell beacuse we have to compare it with the other cells
->then we colored that cell in the answer cell and push those pointer in the queue
->then we do bfs traversal on those check for boundary condition and if neighbous are not of the same color and not 
colored in the ans matrix
then we color them in the answer one and push them in the matrix
->we can aslo do this question using dfs without using queue
*/


//code
#include <iostream>
#include <vector>
using namespace std;
void bfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&ans,int inticolor,int color,queue<pair<int,int>>&q,int n,int m){
    vector<int>delrow={-1,1,0,0};
    vector<int>delcol={0,0,-1,1};

    while(!q.empty()){
        int intirow=q.front().first;
        int inticol=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int newrow=intirow+delrow[i];
            int newcol=inticol+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && image[newrow][newcol]==inticolor && ans[newrow][newcol]!=color){
                ans[newrow][newcol]=color;
                q.push({newrow,newcol});
             }
         }
    }
}

vector<vector<int>> floodfill(vector<vector<int>>&image,int sr,int sc,int color,int n,int m){
    queue<pair<int,int>> q;
    int inticolor=image[sr][sc];
    vector<vector<int>>ans=image;
    ans[sr][sc]=color;
    q.push({sr,sc});
    bfs(sr,sc,image,ans,inticolor,color,q,n,m);
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> image(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>image[i][j];
        }
    }

    int sr,sc;
    cin>>sr>>sc;

    int color;
    cin>>color;
    
    vector<vector<int>>ans=floodfill(image,sr,sc,color,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
     
    return 0;

}