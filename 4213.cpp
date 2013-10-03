#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int k;
int longestCommonSubsequence( string a,  string b) {
  int A = a.size(), B = b.size();
  int L[A+1][B + 1];
  memset(L,0,sizeof L);
  for(int i = k; i < A; i++) {
    for(int j = k; j < B; j++) {
      L[i][j]=max(L[i-1][j],L[i][j-1]);
      for(int h=0; h <= i; h++){
        if(h >= k)L[i][j]=max(L[i][j],L[i-h][j-h]+h);     
     }
   }
 }
 return L[A-1][B-1];
}

int main() {
  //freopen("4213.in","r",stdin);
  string a, b;
  while(scanf("%d",&k) and k!=0){
    cin >> a >> b;
    cout << longestCommonSubsequence("#"+a, "#"+b)<<endl;
    //cout<<"***************"<<endl;
  }
}
