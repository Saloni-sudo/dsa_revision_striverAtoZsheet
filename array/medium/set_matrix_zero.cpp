/*
Given an m x n integer matrix matrix, 
if an element is 0, set its entire row
and column to 0's.

You must do it in place.
*/


//there are three approache for this question
//1.brute force approach-in which whenever we encounter an elemant zero we change all elemant of 
//that row and column to be -1
//after traversing whole array
///we transform all the elemant which is -1 into zero
//time complexity of this question is O(n^3)
//space complexity would be O(1)


//2.would be a better solution which will not use tarversing the whole matrix 2 times what can we do
//can do generate two vector to store the column and row where zero is presnt and after traversing the 
//whole array.we can trvaerse the two vector and mark those elemant as 0
//time complexity of this question will be O(2*n)
//space somplexity would be O(something)



//but this question says to do this question in place
//means we have to solve this question without using any extra space

//it means we have to store the info in the array itself


#include<iostream>
#include<vector>
using namespace std;
void set_to_zeroes(vector<vector<int>> &matrix){
   int col1=1;
   int n=matrix.size();
   int m=matrix[0].size();
   for(int i=0;i<n;i++){//mark rows and colums which are zeroes in first rows and column
    for(int j=0;j<m;j++){
        if(matrix[i][j]==0){
            matrix[i][0]=0;
            if(j!=0){
                matrix[0][j]=0;
            }
            else{
                col1=0;
            }
        }
    }
   }
   for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){
        if(matrix[i][j]!=0){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
    }
   }
   if(matrix[0][0]==0){
    for(int i=0;i<m;i++){
        matrix[0][i]=0;
    }
   }
   if(col1==0){
    for(int j=0;j<n;j++){
        matrix[j][0]=0;
    }
   }
    
return;

}

int main(){
    int n;//number of rows
    cin>>n;
    int m;//number of columns
    cin>>m;
   vector<vector<int>> matrix(n,vector<int>(m));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
    }
   }
  set_to_zeroes(matrix);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
       cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}