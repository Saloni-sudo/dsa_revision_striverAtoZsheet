//Given an integer array of size n containing distinct values
// in the range from 0 to n (inclusive),
// return the only number missing from the array within this range.





#include<iostream>
#include<algorithm>
using namespace std;

int main(){
 int n;
    cin>>n;
    vector<int>ans(n);
    for(int &x:ans){
        cin>>x;
    }
    int k=ans.size();
    int total_sum=k*(k+1)/2;
    int sum=0;
    for(int i=0;i<ans.size();i++){
        sum+=ans[i];
    }
    int missing_number=total_sum-sum;
    cout<<missing_number;
    return 0;
}