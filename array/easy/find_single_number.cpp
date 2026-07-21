//Single Number

//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//You must implement a solution with a linear runtime complexity and use only constant extra space.



#include<iostream>
#include<algorithm>
using namespace std;
 

int single_number(vector<int>arr){
    int Xor=0;
    for(int i=0;i<arr.size();i++){
        Xor=Xor^arr[i];

    }
    return Xor;
}

int main(){
 int n;
 cin>>n;
vector<int>arr(n);
for(int &x: arr){
    cin>>x;
}
int x=single_number(arr);
cout<<x;


    return 0;
}
