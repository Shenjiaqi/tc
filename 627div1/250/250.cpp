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
class HappyLetterDiv1
{
public:
  string getHappyLetters(string letters);
};
int cnt['z' - 'a' + 1];
bool vis['z' - 'a' + 1];
string HappyLetterDiv1::getHappyLetters(string letters)
{
  for( auto i : letters )
    ++cnt[ i - 'a' ];
  int n = letters.length();
  string ans;
  for( int i = 0 ; i <= 'z' - 'a' ; ++ i )
    if( !vis[i] && cnt[i] > 0 )
      {
	vis[i] = true;
	int left = n - cnt[i];
	int maxV = 0;
	for( int j = 0 ; j <= 'z' - 'a' ; ++j )
	  if( j != i )
	    {
	      maxV = max( maxV, cnt[j] );
	    }
	int num = cnt[i];
	if( left & 1 )
	  ++left, --num;
	int need = maxV * 2 - left;
	if( num > 0 && need < num )
	  ans.push_back( 'a' + i );
      }
  sort( ans.begin(), ans.end() );
  return ans;
}
int main()
{
  string a = "zhzqhhhzhzzhzhqqz";
  HappyLetterDiv1 aa;
  cout << aa.getHappyLetters(a) << endl;
  return 0;
}
