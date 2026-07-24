//Given an array nums of size n and an integer k, 
//find the length of the longest sub-array that sums to k. 
//If no such sub-array exists, return 0.


#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main(){
 int n;
 cin>>n;
 vector<int>arr(n);
 for(int & x: arr){
    cin>>x;
 }
 int target;
 cin>>target;
 map<long long,int>presummap;
 long long sum=0;
 int maxLength=0;
 for(int i=0;i<arr.size();i++){
    sum+=arr[i];
    if(sum==target){
        maxLength=max( maxLength,i+1);
    }
    long long rem=sum-target;
    if(presummap.find(rem)!=presummap.end()){
        int length=i-presummap[rem];
        maxLength=max(maxLength,length);
    }

   if(presummap.find(sum)==presummap.end()){
    presummap[sum]=i;
 }}
  cout<<maxLength;
 

}