//->Given an array of integers nums, return the second-largest element in the array. 
//If the second-largest element does not exist,
 //return -1.


 // time complexity=0(n)
 // space complexity=0(1)

 #include<iostream>
 #include<vector>
 using namespace std;

int second(vector<int> &arr){
    int largest=-1;
    int second=-1;
    for(int x:arr){
        if(x>largest){
            second=largest;
            largest=x;
        }
        else if(x>second && x!=largest){
            second=x;
        }
    }
 return second;
}
 int main(){
    int n;
    cin>>n;
    vector <int>arr(n);
    for(int &x:arr){
        cin>>x;
    }
    cout<<second(arr);
  return 0;
}