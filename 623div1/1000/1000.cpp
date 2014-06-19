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

class AliceAndFriends
{
public:
  double getMoney(vector <int> cards);
};
const int N = 1007;
double AliceAndFriends::getMoney(vector <int> cards)
{
  int n = cards.size();
  // sort( cards.begin(), cards.end() );
  int sum(0);
  for( int i = 0 ; i < n ; ++i )
    {
      vector<ppi> vc;
      int cnt(0);
      for( int j = 0 ; j < n; ++j )
	{
	  if( i != j )
	    {
	      if( cards[j] > cards[i] )
		{
		  cnt -= 4;
		  vc.push_back( make_pair( cards[j] - cards[i], 2) );
		  // vc.push_back( ppi( cards[j] - cards[i] + 1, 1 ) );
		}
	      else if( cards[j] == cards[i] )
		{
		  ;
		}
	      else
		{
		  // cards[j] < cards[i]
		  if( 2 * cards[j] < cards[i] )
		    {
		      cnt += 4;
		      vc.push_back( ppi( cards[i] - 2 * cards[j], -1 ) );
		      vc.push_back( ppi( cards[i] - 2 * cards[j] + 1, -1 ) );
		      vc.push_back( ppi( cards[i] - cards[j] + 1, -2 ) );
		    }
		  else if( 2 * cards[j] == cards[i] )
		    {
		      cnt += 2;
		      // vc.push_back( make_pair( 1, 1 ) );
		      vc.push_back( make_pair( cards[i] -cards[j] + 1, -2 ) );
		    }
		  else if( 2 * cards[j] > cards[i] )
		    {
		      if( cards[i] - cards[j] > 2 * cards[j] - cards[i] )
			{
			  vc.push_back( ppi( 2 * cards[j] - cards[i],
					     1 ) );
			  vc.push_back( ppi( 2 * cards[j] - cards[i] + 1,
					     1 ) );
			  vc.push_back( ppi( cards[i] - cards[j] + 1, -2 ) );
			}
		      else if( cards[i] - cards[j] == 2 * cards[j] - cards[i] )
			{
			  vc.push_back( ppi( cards[i] - cards[j], 1 ) );
			  vc.push_back( ppi( cards[i] - cards[j] + 1, -1 ) );
			}
		    }
		}
	    }
	}
      sort( vc.begin(), vc.end() );
      int mxCnt = cnt;
      for( int j = 0 ; j < vc.size();)
	{
	  if( vc[j].first > cards[i] )
	    {
	      break;
	    }
	  // else if( vc[j].first < 0 )
	  //   break;
	  int k = j;
	  for( ; k < vc.size() && vc[k].first == vc[j].first; ++k )
	    {
	      cnt += vc[k].second;
	    }
	  j = k;
	  mxCnt = max( mxCnt, cnt );
	}
      sum += mxCnt;
    }
  return (double)sum / ( n * 4 );
}
int main()
{
  AliceAndFriends a;
  // int c[] = { 1, 10 };
  // int c[] = { 9, 10 };
  // int c[] = { 1, 3 };
  // int c[] = { 1000000000, 1000000000 };
  int c[] = {42, 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812, 323, 334, 674, 665, 142, 712, 254, 869};
  vector<int> cc;
  for( int i = 0 ; i < sizeof(c) / sizeof(c[0]); ++i )
    cc.push_back( c[i] );
  // cout << cc.size() << endl;
  cout << a.getMoney(cc) << endl;
  return 0;
}
