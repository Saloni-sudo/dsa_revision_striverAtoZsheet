//question
/*
 Implement a stack (LIFO) with push(x), pop(), top(),
 size() and empty(), using a fixed-size array. All operations
 must run in O(1). Handle overflow (push on a full stack) and
 underflow (pop/top on an empty stack).
 */


//thought process
/*
Idea: keep an array and an index `top` that points at the last
pushed element. push -> top++, pop -> top--. Everything is O(1).
*/




#include<iostream>
#include<stack>
#include<queue>
using namespace std;


class Arraystack{
    int *arr;
    int capacity;
    int topidx; //all are private

public:

  Arraystack(int cap=100)//constructor
   : capacity(cap), topidx(-1)//assigned list
  {
    arr=new int[cap];//arr is poit to first slot of the array
  }

  ~Arraystack() //destructors
  {
    delete[] arr;
  }

  // all are methods

  void push(int x){
    if(topidx==capacity-1){
        cout<<"stack overflow";
    }
    else{
        arr[++topidx]=x;
    }
  }

  void pop(){
    if(topidx==-1){
        cout<<"stack underflow";
    }
    else{
        topidx--;
    }
  }

  int top(){
    if(topidx==-1){
        cout<<"stack underflow";
        return -1;
    }
     return arr[topidx];
    }

   bool  empty(){
  return topidx==-1;
  }

  int size(){
    return topidx+1;
 }

};




int main(){
    Arraystack s(3);//making an object and 3 is capcity if we did not had passed 3,it would be then 100 as capacity (default)
    s.push(3);
    s.push(5);
    s.push(4);
    s.pop();
    cout<<"top: "<<s.top()<<endl;      
    cout<<"size: "<<s.size()<<endl;     
    cout<<"empty: "<<s.empty()<<endl;
    s.pop();
    s.pop();
    cout<<"empty: "<<s.empty()<<endl;   

    cout<<"size: "<<s.size()<<endl; 

    return 0;
}

////*note endl is used with cout or cin not with return only