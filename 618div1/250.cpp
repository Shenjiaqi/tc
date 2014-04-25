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
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
class Family
{
public:
  string isFamily(vector <int> parent1, vector <int> parent2);
};
const int N = 1007;
vector<int> p[N];
int fe[N] = {0};
bool dfs( int v, int id )
{
  if( fe[v] == 0 )
    {
      fe[v] = id;
      for( auto i : p[v] )
	if( !dfs( i, id == 1 ? 2 : 1 ) )
	  return false;
    }
  return id == fe[v];
}
string Family::isFamily(vector <int> parent1, vector <int> parent2)
{
  int n = parent1.size();
  for( int i = 0; i < n; ++i )
    if( parent1[i] >= 0 )
      {
	int a = parent1[i], b= parent2[i];
	p[a].push_back(b);
	p[b].push_back(a);
      }
  for( int i = 0; i < n; ++i )
    if( fe[i] == 0 && !dfs( i, 1 ) )
      return "Impossible";
  return "Possible";
}
int main()
{
  return 0;
}
