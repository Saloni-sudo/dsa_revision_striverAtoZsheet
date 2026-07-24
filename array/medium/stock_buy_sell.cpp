/*
You are given an array prices where prices[i]
 is the price of a given stock on the ith day.

You want to maximize your profit by choosing a 
single day to buy one stock and choosing a different
 day in the future to sell that stock.

Return the maximum profit you can achieve from 
this transaction. If you cannot achieve any profit,

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int &x:arr){
  cin>>x;
  }
  int minprice=INT_MAX;
  int maxprofit=0;
  for(int price:arr){
    minprice=min(minprice,price);
    maxprofit=max(maxprofit,price-minprice);
  }
  cout<<maxprofit<<endl;
  return 0;
}
