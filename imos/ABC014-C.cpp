#include<iostream>
#include<algorithm>
using namespace std;

int color[1000005]={0};

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    color[a]++;
    color[b+1]--;
  }

  int maxim=0;
  for(int i=0;i<=1000000;i++){
    color[i+1]+=color[i];
    maxim=max(maxim,color[i]);
  }

  cout<<maxim<<endl;
  return(0);
}


