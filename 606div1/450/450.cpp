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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
class EllysPairing
{
public:
  int getMax(int M, vector <int> count, vector <int> first, vector <int> mult, vector <int> add);
};
int EllysPairing::getMax(int m, vector <int> cnt,
			 vector <int> fir, vector <int> mul,
			 vector <int> add)
{
  map<int,int> mapp;
  for(int i=0;i<cnt.size();++i)
    {
      unsigned int val=fir[i];
      map<unsigned int,int> z;
      z[val]=1;
      int cir=10;
      for(int j=1;j<cnt[i];++j)
        {
	  val=((unsigned int)mul[i]*val+(unsigned int)add[i])&(unsigned int)(m-1);
	  if(z[val]!=0)
	    {
	      cir=j+1-z[val];
	      break;
	    }
	  z[val]=j+1;
	}
      if(cir<4)
	{
	  mapp[val]=0;
	  for(int j=1;j<cir;++j)
	    {
	      val=((unsigned int)mul[i]*val+(unsigned int)add[i])&(unsigned int)(m-1);
	      mapp[val]=0;
	    }
	}
      // cout<<z.size()<<endl;
    }
  int all=0;
  for(int i=0;i<cnt.size();++i)
  {
    all+=cnt[i];
    unsigned int val=fir[i];
    auto ite=mapp.find(val);
    if(ite!=mapp.end())
      ++(ite->SEC);
    for(int j=1;j<cnt[i];++j)
      { 
        val=((unsigned int)mul[i]*val+(unsigned int)add[i])&(m-1);
        ite=mapp.find(val);
        if(ite!=mapp.end())
        {
          ++(ite->SEC);
        }
      }
  }
  int ans=all/2;
  for(auto i:mapp)
  {
    if(i.SEC>ans)
    {
      ans=ans-(i.SEC-((all&1)?1:0)-ans);
      break;
    }
  }
  return ans;
}
int main()
{
  int m;
  int n=1;
  vector<int> arg[4];
  // m=134217728;
  // a[]={7463, 11941, 19994, 4709, 7081, 951, 7752, 16161, 9038, 12081, 17766, 14296, 19147, 18575, 6429, 3546, 13577, 14518, 17542, 7552, 16575, 141, 2401, 1342, 11750, 19479, 9647, 1345, 11509, 936, 19498, 6915, 16630, 8574, 13724, 17861, 8129, 153, 10327, 7876, 6127, 12629, 5548, 4056, 13881, 15422, 16934, 16673, 4810, 510888};
  // b[]={73231047, 119083464, 109181729, 100278224, 48793770, 101314280, 31325015, 125411053, 128903487, 48517677, 19707011, 129066211, 108429199, 124261860, 31807082, 38521161, 96100319, 24640963, 82712888, 31622509, 63940427, 82554566, 56830878, 29532843, 75383901, 82151424, 85035491, 125059529, 108920992, 89948285, 86369793, 62302025, 17249089, 78251534, 3112123, 78636230, 21476511, 82566444, 21432243, 115404619, 131843817, 91885001, 131692680, 118313639, 105572272, 79735084, 84350184, 57091533, 77116037, 53628428};
  // c[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22923461};
  // d[]={42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 42424242, 35994048};
  scanf("%d",&m);
  FOR(i,0,4)
    {
      arg[i].resize(n);
      FOR(j,0,n)
	assert(EOF!=scanf("%d",&arg[i][j]));
    }
  class  EllysPairing tmp;
  cout<<tmp.getMax(m,arg[0],arg[1],arg[2],arg[3])<<endl;
  return 0;
}
