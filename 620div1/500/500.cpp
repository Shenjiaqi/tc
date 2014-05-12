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
#include <unordered_set>
#include <unordered_map>
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
class CandidatesSelection
{
public:
  string possible(vector <string> score, vector <int> result);
};
string CandidatesSelection::possible(vector <string> score, vector <int> result)
{
  int n = result.size();
  int m = score[0].length();
  ll used = 0;
  ll seg = 0;
  for( ;; )
    {
      int i = 0;
      for( ; i < n - 1; ++i)
	{
	  for( ; i < n - 1 && ( ( 1LL << i ) & seg ) == 0; ++i )
	    if( result[i] > result[i + 1] )
	      break;
	  if( i < n - 1 && ( ( 1LL << i ) & seg ) == 0 )
	    break;
	}
      if( i >= n - 1 )
	return "Possible";
      vector<int> canUseLst;
      for( int i = 0; i < m; ++i )
	{
	  if( ( used & ( 1LL << i ) ) == 0 )
	    {
	      int j = 0;
	      for( ; j < n - 1; ++j )
		{
		  for( ; j < n - 1 && ( ( 1LL << j ) & seg ) == 0; ++j )
		    if( score[ result[j] ][i] > score[ result[j + 1] ][i] )
		      break;
		  if( ( ( 1LL << j ) & seg ) == 0 )
		    break;
		}
	      if( j >= n - 1 )
		canUseLst.push_back(i);
	    }
	}
      if( canUseLst.empty() )
	break;
      for( auto i : canUseLst)
	{
	  used |= 1LL << i;
	  for( int j = 0; j < n -1; ++j )
	    {
	      for( ; j < n - 1 && ( ( 1LL << j ) & seg ) == 0; ++j )
		if( score[ result[j] ][i] < score[ result[j + 1] ][i] )
		  seg |= 1LL << j;
	    }
	}
    }
  return "Impossible";
}

int main()
{
  return 0;
}
