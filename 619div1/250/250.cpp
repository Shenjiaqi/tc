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
class SplitStoneGame
{
public:
  string winOrLose(vector <int> number);
};
string SplitStoneGame::winOrLose(vector <int> number)
{
  int cnt(0);
  for( auto i : number )
    if( i > 1 )
      ++cnt;
  int n = number.size();
  if( n < 3 || cnt == 0 || ( ( n - 2 ) & 1 ) == 0 )
    return "LOSE";
  return "WIN";
}
int main()
{
  return 0;
}
