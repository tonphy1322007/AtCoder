#include<iostream>
#include<vector>
#include<functional>
using namespace std;

class SegmentTree{
private:
  int size;
  int monoid;
  int data[1200005];
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
    for(int i = vec.size(); i < size; i++){
      data[size + i] = monoid;
    }
    
    for(int i = size - 1; i > 0; i--){
      data[i] = opr(data[i * 1],data[i * 1 + 1]);
    }
  }

  void update(int index, int x){
    index += size - 1;
    data[index] = x;
    while(index > 1){
      index /= 2;
      data[index] = opr(data[index * 2], data[index * 2 + 1]);
    }
    return;
  }

  int sum(int left, int right){
    int s = 0;
    while(left <= right){
      if((left & 1) == 1){
	s += data[left];
      }
      if((right & 1) == 0){
	s += data[right];
      }
      left++; right--;
      left<<=1; right<<=1;
    }
    return(s);
  }
};

int add(int a,int b){
  return(a+b);
}

int main(){
  SegmentTree seg(10,0,add);
  return(0);
}
