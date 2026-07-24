/*
 Problem Statement: Given an array of integers arr[] and an integer target.

1st variant: Return YES if there exist two numbers such that their sum is equal to the target. 
Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. 
Otherwise, we will return {-1, -1}.


*/ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


bool ans(vector<int>arr,int target){
map<int,int>complementmap;
for(int i=0;i<arr.size();i++){
    int rem=target-arr[i];
    if(complementmap.find(rem)!=complementmap.end()){
        return true;
    }
    complementmap[arr[i]]++;
}
return false;
}
pair<int,int> indices(vector<int>arr,int target){
    map<int,int>complementmap_with_indices;
    for(int i=0;i<arr.size();i++){
        int rem=target-arr[i];
        if(complementmap_with_indices.find(rem)!=complementmap_with_indices.end()){
            return {complementmap_with_indices[rem],i};
        }
      complementmap_with_indices[arr[i]]=i;
    }
return {-1,-1};

}


int main(){
 int n;
 cin>>n;
 vector<int>arr(n);
 for(int & x:arr){
   cin>>x;
 }
int target;
cin>>target;
cout<<boolalpha<<ans(arr,target)<<endl;
pair<int, int> p = indices(arr, target);
cout << p.first << " " << p.second << endl;

return 0;
}