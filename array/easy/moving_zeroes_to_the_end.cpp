//Move Zeroes

//Given an integer array nums, 
//move all 0's to the end of it 
//while maintaining the relative order of the non-zero elements.

//Note that you must do this in-place without making a copy of the array.


#include<iostream>
#include<vector>
using namespace std;

vector<int> movezeroes( vector<int>arr){
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    return arr;
}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &x:arr){
        cin>>x;

    }
    vector<int> ans=movezeroes(arr);
   for(int x:ans){
     cout<<x;
   }

    return 0;
}
