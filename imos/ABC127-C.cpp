#include<iostream>
using namespace std;
int main(){
  int n,m;
  int gate[100005]={0};
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int left,right;
    cin>>left>>right;
    gate[left]++;
    gate[right+1]--;
  }

  int cnt=0;
  for(int i=1;i<=n;i++){
    gate[i]+=gate[i-1];
    if(gate[i]==m){
      cnt++;
    }
  }
  
  cout<<cnt<<endl;
  return(0);
}
