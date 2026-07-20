//Given a binary array nums,
// return the maximum number of consecutive 1's in the array.


//time complexity=
//space complexity=


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int &x : nums){
    cin>>x;
  }
   int maxi=0;
   int cnt;
   for(int i=0;i<nums.size();i++){
     if(nums[i]!=0){
        cnt++;
    }
    else{
        maxi=max(cnt,maxi);
        cnt=0;
    }
   }
  int s=max(maxi,cnt);
  cout<<s;
         return 0;
}