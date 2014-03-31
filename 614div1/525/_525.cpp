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

class CycleColoring
{
public:
  int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K);
};
int CycleColoring::countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K)
{
  int p0, p1;
  p0 = 0, p1 = K;
  int n = vertexCount.size();
  for( int i = 0;i < n; ++i )
   {
     int v0, v1, tmp;
     int m = vertexCount[i];
     cal( v0, tmp, p0, 0, K, m - 1)
       {
       }
   }
}
