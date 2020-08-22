#include<iostream>
using namespace std;
int main(){
  int n,q;
  int othello[200005]={0};
  cin>>n>>q;
  for(int i=0;i<q;i++){
    int left,right;
    cin>>left>>right;
    othello[left]++;
    othello[right+1]--;
  }

  for(int i=1;i<=n;i++){
    othello[i]+=othello[i-1];
    cout<<othello[i]%2;
  }
  cout<<endl;
  return(0);
}
