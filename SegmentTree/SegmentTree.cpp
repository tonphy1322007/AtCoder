#include<iostream>
#include<vector>
#include<functional>
using namespace std;

class SegmentTree{
private:
  int size;
  int monoid;
  int data[200005];
  int lazy[200005];
  function<int(int, int)> opr;

public:
  SegmentTree(int n, int m, function<int(int, int)> o) : size(1), monoid(m), opr(o) {
    while(size < n){
      size *= 2;
    }

    for(int i = 1; i < size * 2; i++){
      data[i] = monoid;
    }
  }

  SegmentTree(vector<int> vec, int m, function<int(int, int)> o) : size(1), monoid(m), opr(o) {
    while(size < vec.size()){
      size *= 2;
    }

    for(int i = 0; i < vec.size(); i++){
      data[size + i] = vec[i];
    }
    for(int i = size - 1; i > 0; i--){
      data[i] = opr(data[i * 1],data[i * 1 + 1]);
    }
  }

};

int add(int a,int b){
  return(a+b);
}

int main(){
  SegmentTree seg(10,0,add);
  return(0);
}
