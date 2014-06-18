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
//#include <unordered_set>
//#include <unordered_map>
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
class BuildingHeights
{
public:
  int minimum(vector <int> heights);
};
const int N = 4007;
const int L = 4007;
int p[N];
int BuildingHeights::minimum(vector <int> h)
{
  int n =  h.size();
  sort( h.begin(), h.end() );
  for( int i = 1; i <= n; ++i )
    p[i] = N * L;
  for( int i = 0; i < n; )
    {
      int j = i + 1;
      for( ; j < n && h[j] == h[i]; ++j )
	;
      int sum(0);
      for( int k = j - 1, num = 1; k >= 0; --k, ++num )
	{
	  sum += h[j - 1] - h[k] ;
	  p[num] = min( p[num], sum );
	}
      i = j;
    }
  int r(0);
  for( int i = 1; i <= n; ++i )
    r ^= p[i];
  return r;
}
int main()
{
  // int a[] = {1, 5, 4, 3, 8};
  int a[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
 2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
 929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
 1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
 1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
	     1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888};
  vector<int> aa;
  for( int i = 0 ; i < sizeof(a) / sizeof(a[0]); ++i )
    aa.push_back(a[i]);
  BuildingHeights aaa;
  
  cout << aaa.minimum(aa) << endl;
  
  return 0;
}
