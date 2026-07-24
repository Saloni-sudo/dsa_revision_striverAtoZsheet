/*
Given an array nums of n integers.



Return the length of the longest 
sequence of consecutive integers.
The integers in this sequence can appear in any order.


*/

#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_set>
using namespace std;


int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int &x:arr){
    cin>>x;
}
unordered_set<int> st;
 for(int i=0;i<n;i++){
    st.insert(arr[i]);
 }
 int longest=1;
 int x;
 int cnt=1;
 
 for(auto it : st){
  if(st.find(it-1)==st.end()){
    x=it;
  }
  while(st.find(x+1)!=st.end()){
    cnt++;
    x+=1;
  }
  longest=max(longest,cnt);
}

cout<<longest;
return 0;
}