#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF=1<<30;

class SegmentTree{
  int size;
  int data[1200005];
  
  int MIN_rec(int a,int b,int left,int right,int node){
    if(a<=left&&right<=b){
      return(data[node]);
    }
    if(right<a||b<left){
      return(INF);
    }

    int vleft=MIN_rec(a,b,left,(left+right)/2,node*2);
    int vright=MIN_rec(a,b,(left+right)/2+1,right,node*2+1);
    return(min(vleft,vright));
  }

public:
  SegmentTree(vector<int>vec){
    size=1;
    while(size<vec.size()){
      size*=2;
    }

    for(int i=0;i<vec.size();i++){
      data[size+i]=vec[i];
    }
    for(int i=vec.size();i<size;i++){
      data[size+i]=INF;
    }

    for(int i=size-1;i>0;i--){
      data[i]=min(data[i*2],data[i*2+1]);
    }
  }

  void update(int index,int x){
    index+=size-1;
    data[index]=x;
    while(index>1){
      index/=2;
      data[index]=min(data[index*2],data[index*2+1]);
    }
    return;
  }

  int MIN(int left,int right){
    return(MIN_rec(left,right,1,size,1));
  }
};
  
int main(){
  vector<int>vec;
  SegmentTree seg();
  return(0);
}
