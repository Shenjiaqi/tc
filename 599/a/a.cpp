#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
class BigFatInteger
{
public:
  int minOperations(int A, int B);
};
int BigFatInteger::minOperations(int A, int B)
{
  vector<int> num;
  for(ll i=2;i*i<=A;++i)
    if((A%i)==0)
      {
	int c(0);
	for(;(A%i)==0;++c)
	  A/=i;
	num.push_back(c);
      }
  if(A>1)
    num.push_back(1);
  int m(0);
  for(int i=0;i<num.size();++i)
    num[i]*=B,
      m=max(m,num[i]);
  int fg=m;
  for(;fg!=(fg&(-fg));fg^=(fg&(-fg)))
    ;
  int ans=__builtin_ctz(fg)+num.size();
  if(m>fg)
    ++ans;
  return ans;
}

int main()
{
  BigFatInteger a;
  cout<<a.minOperations(6,1)<<" 2"<<endl;
  cout<<a.minOperations(162,1)<<" 4"<<endl;
  cout<<a.minOperations(999983,9)<<' '<<'5'<<endl;
  cout<<a.minOperations(360,8)<<" 8"<<endl;
  return 0;
}
