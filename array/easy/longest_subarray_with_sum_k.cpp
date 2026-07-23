// Given an array nums of size n and an integer k, 
//find the length of the longest sub-array that sums to k. 
//If no such sub-array exists, return 0.


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int>ans(n);
    for(int &x : ans){
       cin>>x;
    }
    int sum;
    cin>>sum;
 long long curr_sum = 0;
int left = 0, maxi_length = 0;

for (int right = 0; right < n; right++) {
    curr_sum += ans[right];

    while (curr_sum > sum) {
        curr_sum -= ans[left];
        left++;
    }

    if (curr_sum == sum) {
        maxi_length = max(maxi_length, right - left + 1);
    }
}
cout << maxi_length;
}