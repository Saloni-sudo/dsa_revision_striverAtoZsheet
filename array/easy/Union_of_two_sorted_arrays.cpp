//Union of two sorted arrays

//Given two sorted arrays nums1 and nums2,
//return an array that contains the union of these two arrays.
//The elements in the union must be in ascending order.


//The union of two arrays is an array 
//where all values are distinct and are present in either the first array,
// the second array, or both.



#include<iostream>
#include<vector>
using namespace std;

vector<int>union_of_array(vector<int>arr1,vector<int>arr2){
    int i=0; int j=0;
vector<int>ans;
  while(i<arr1.size() && j< arr2.size()){
          if(arr1[i]<arr2[j]){ ans.push_back(arr1[i]); i++;}
          else if(arr2[j]<arr1[i]){ ans.push_back(arr2[j]); j++;}
          else if(arr1[i]==arr2[j]){ans.push_back(arr1[i]); i++; j++;}
        }
    while(i<arr1.size()){
        ans.push_back(arr1[i]); i++;
    }
   while(j<arr2.size()){
            ans.push_back(arr2[j]); j++; }
        return ans;
    }

int main(){
 int n1,n2;
 cin>>n1>>n2;
 vector<int>arr1(n1);
 vector<int>arr2(n2);
 for(int &x: arr1){
    cin>>x;
 }
 for(int &x: arr2){
    cin>>x;
 }
 vector<int> ans=union_of_array(arr1,arr2);
for(int x:ans){
    cout<<x;
}
    return 0;
}