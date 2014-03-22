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
class TaroFriends
{
public:
  int getNumber(vector <int> coordinates, int X);
};
int TaroFriends:: getNumber(vector <int> coordinates, int X)
{
  int n = coordinates.size();
  sort( coordinates.begin(), coordinates.end() );
  int ans = coordinates[ n - 1 ] - coordinates[0];
  for( int chg = 1; chg < n; ++chg )
    {
      int left = min( coordinates[chg] - X, coordinates[0] + X );
      int right = max( coordinates[ chg - 1 ] + X, coordinates[ n - 1 ] - X );
      ans = min( right - left, ans );
    }
  return ans;
}
int main()
{

#ifdef LOCAL_DEFINE
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
