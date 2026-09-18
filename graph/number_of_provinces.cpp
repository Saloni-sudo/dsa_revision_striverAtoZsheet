//question

/*There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected
 directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and 
no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1
 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/


//what this question meant to ask
/*
an matrix is given of n*n
if[i][j]=1,means there is an edge between i and j 
if not then 0.
we need to return number of provinces which indirectly meant to say 
connected component.
*/

//thought process
/*
->take n as user input
->then define an n*n matrix 
->take input from the user about the edges between the vertex
this is what the question provided to us.now,on that we have to calculate the connected components
->first we find value of n
->after that we define a visited array of size n(to track which node has been already visited)
->after that we start traversing the rows and check each value in the rows if visited or not and call dfs
->increase count there
->in dfs we traverse to it neighbouring ones and check if they have edge and they are not yet marked and call dfs on them

*/

//code
#include<iostream>
#include<vector>
using namespace std;

void dfs(int node,vector<vector<int>>&isconnected,vector<int>&vis,int &n){
    vis[node]=1;//mark the node as visited
    for(int k=0;k<n;k++){//check for the neighbiurs node which has edge  and it is unvisited
        if(isconnected[node][k]==1 && vis[k]==0){
            dfs(k,isconnected,vis,n);//do dfs traversal on that node
        }
    }
}

int number_of_provines(int &n,vector<vector<int>>&isconnected){
    vector<int> vis(n,0);//making the visited array
    int cnt=0;//keeping count
    
    for(int i=0;i<n;i++){//traversing the nodes
        if(vis[i]==0){//if the node is unvisited
            cnt++;//increase it count
            dfs(i,isconnected,vis,n);//traversal dfs
        }
    }
  return cnt;//return the count
}

int main(){
    int n;
    cin>>n;// asking for the size of matrix
    vector<vector<int>>isconnected(n+1,vector<int>(n+1,0));//matrix

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cin>>isconnected[i][j]; //input of edges
            
        }
    }
    int mini=number_of_provines(n,isconnected);//calling the function
    cout<<mini<<endl;//returning the answer

    return 0;
}
