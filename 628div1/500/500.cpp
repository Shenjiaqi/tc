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
class CircuitsConstruction
{
public:
  int maximizeResistance(string circuit, vector <int> conductors);
};
int pos;
int dfs( string &s )
{
  char c = s[pos];
  ++pos;
  if( c == 'X' )
    {
      return 1;
    }
  else if( c == 'A' )
    {
      return dfs(s) + dfs(s);
    }
  // 'B'
  return max( dfs(s), dfs(s) );
}
int CircuitsConstruction::maximizeResistance(string circuit,
					    vector <int> conductors)
{
  int num = dfs( circuit );
  sort( conductors.begin(), conductors.end(), greater<int>() );
  int r(0);
  for( int i = 0 ; i < num ; ++i )
    r += conductors[i];
  return r;
}
int main()
{
  CircuitsConstruction a;
  // string cir = "BXBXX";
  // int c[] = {8, 2, 3};
  // string cir = "AAXXAXAXX";
  // int c[] = {1, 1, 2, 8, 10};
  // string cir = "AXBXX";
  // int c[] = {8, 2, 3};
  string cir = "BAAXBXXBXAXXBBAXXBXXAAXXX";
  int c[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
  vector<int> con;
  for( int i = 0 ; i < sizeof(c) /  sizeof(c[0]); ++i )
    con.push_back( c[i] );
  cout << a.maximizeResistance( cir, con ) << endl;
  return 0;
}
