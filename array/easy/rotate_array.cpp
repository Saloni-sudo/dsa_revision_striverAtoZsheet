// Rotate Array
//Given an integer array nums, 
//rotate the array to the right by k steps, 
//where k is non-negative.


#include<iostream>
#include<vector>
using namespace std;
vector<int>rotate(vector <int> arr,int k){
    k%=arr.size();
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
 
   return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr){
        cin>>x;
    }
    int k;
    cin>>k;
    vector<int>ans=rotate(arr,k);
    for(int x:ans){
        cout << x;
    }
    return 0;

}