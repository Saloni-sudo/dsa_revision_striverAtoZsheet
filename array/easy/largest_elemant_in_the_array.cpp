// Given an array, we have to find the largest element in the array.
//time complexity=
//space complexity=

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<*max_element(arr,arr+n);
    return 0;
}