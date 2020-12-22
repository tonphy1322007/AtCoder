#include<iostream>
#include<vector>
#include<functional>
using namespace std;

const int UNSET = -(1<<30);

class SegmentTree{
private:
  int size;
  int monoid;
  int data[1200005];
  int lazy[1200005];
  function<int(int, int)> opr;

  void eval(int node){
    if(lazy[node] == UNSET){
      return;
    }
    
    data[node] = lazy[node];
    if(node < size){
      lazy[node * 2] = lazy[node] / 2;
      lazy[node * 2 + 1] = lazy[node] / 2;
    }

    lazy[node] = UNSET;
    return;
  }

  int sum_rec(int a, int b, int left, int right, int node){
    eval(node);
    
    if(a <= left && right <= b){
      return(data[node]);
    }
    if(right < a || b < left){
      return(monoid);
    }

    int vleft = sum_rec(a, b, left, (left + right) / 2, node * 2);
    int vright = sum_rec(a, b, (left + right) / 2 + 1, right, node * 2 + 1);
    return(vleft + vright);
  }

  void update_rec(int a, int b, int left, int right, int node, int x){
    eval(node);

    if(a <= left && right <= b){
      lazy[node] = x * (right - left + 1);
    }
    if(right < b || a < left){
      return;
    }

    update_rec(a, b, left, (left + right) / 2, node * 2, x);
    update_rec(a, b, (left + right) / 2 + 1, right, node * 2 + 1, x);
    return;
  }

public:
  SegmentTree(int n, int m, function<int(int, int)> o) : size(1), monoid(m), opr(o) {
    while(size < n){
      size *= 2;
    }

    for(int i = 1; i < size * 2; i++){
      data[i] = monoid;
      lazy[i] = UNSET;
    }
  }

  SegmentTree(vector<int> vec, int m, function<int(int, int)> o) : size(1), monoid(m), opr(o) {
    while(size < vec.size()){
      size *= 2;
    }

    for(int i = 0; i < vec.size(); i++){
      data[size + i] = vec[i];
      lazy[size + i] = UNSET;
    }
    for(int i = vec.size(); i < size; i++){
      data[size + i] = monoid;
      lazy[size + i] = UNSET;
    }
    
    for(int i = size - 1; i > 0; i--){
      data[i] = opr(data[i * 1],data[i * 1 + 1]);
      lazy[i] = UNSET;
    }
  }

  void update(int index, int x){
    update_rec(index, index, 1, size, 1, x);
  }

  void update(int left, int right, int x){
    update_rec(left, right, 1, size, 1, x);
  }

  int sum(int left, int right){
    return(sum_rec(left, right, 1, size, 1));
  }
};

int add(int a,int b){
  return(a+b);
}

int main(){
  SegmentTree seg(10,0,add);
  return(0);
}
