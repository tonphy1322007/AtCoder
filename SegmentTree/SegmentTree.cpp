#include<iostream>
#include<vector>
#include<functional>
using namespace std;

class SegmentTree{
private:
  int size;
  int element;
  int data[1200005];
  function<int(int, int)> opr;

  int query_rec(int a, int b, int left, int right, int node){
    if(a <= left && right <= b){
      return(data[node]);
    }
    if(right < a || b < left){
      return(element);
    }

    int vleft = query_rec(a, b, left, (left + right) / 2, node * 2);
    int vright = query_rec(a, b, (left + right) / 2 + 1, right, node * 2 + 1);
    return(opr(vleft, vright));
  }

public:
  SegmentTree(int n, int e, function<int(int, int)> o) : size(1), element(e), opr(o) {
    while(size < n){
      size *= 2;
    }

    for(int i = 1; i < size * 2; i++){
      data[i] = element;
    }
  }

  SegmentTree(vector<int> vec, int e, function<int(int, int)> o) : size(1), element(e), opr(o) {
    while(size < vec.size()){
      size *= 2;
    }

    for(int i = 0; i < vec.size(); i++){
      data[size + i] = vec[i];
    }
    for(int i = vec.size(); i < size; i++){
      data[size + i] = element;
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

  int query(int left, int right){
    return(query_rec(left, right, 1, size, 1));
  }
};

int add(int a,int b){
  return(a+b);
}

int main(){
  SegmentTree seg(10,0,add);
  return(0);
}
