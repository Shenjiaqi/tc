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
class BlockTheBlockPuzzle
{
public:
  int minimumHoles(vector <string> board);
};
const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { 0, -1 }, { -1, 0 } };
const int N = 52;
const int M = N * N + N;
int p[N][N], pi;
int s[M * 2];
int c[ M * 2];
int rd[ M * 30 ][3], rdi;
int lev[ M * 2 ];
int S, T;
void add( int f, int t)
{
  ++rdi;
  rd[rdi][0] = t, rd[rdi][1] = 1, rd[rdi][2] = s[f], s[f] = rdi;
  ++rdi;
  rd[rdi][0] = f, rd[rdi][1] = 0, rd[rdi][2] = s[t], s[t] = rdi;
}
bool bfs()
{
  memcpy( c, s, sizeof(c) );
  memset( lev, 0, sizeof(lev) );
  queue<int> que;
  que.push(S);
  lev[S] = 1;
  for( ; !que.empty(); )
    {
      int v = que.front();
      que.pop();
      for( int i = c[v]; i; i = rd[i][2] )
	{
	  if( rd[i][1] > 0 )
	    {
	      int to = rd[i][0];
	      if( 0 == lev[to] )
		{
		  lev[to] = lev[v] + 1;
		  que.push(to);
		}
	    }
	}
    }
  return lev[T];
}
int dfs( int v, int f )
{
  if( v == T )
    return f;
  int r = f;
  int i = c[v];
  for( ; i; i = rd[i][2] )
    {
      if( rd[i][1] > 0 )
	{
	  int to = rd[i][0];
	  if( lev[v] + 1 == lev[to] )
	    {
	      int tmp = dfs( to, min( f, rd[i][1] ) );
	      rd[i][1] -= tmp;
	      rd[ i + ( ( i & 1 ) ? 1 : -1 ) ][1] += tmp;
	      f -= tmp;
	      if( f == 0 )
		break;
	    }
	}
    }
  c[v] = i;
  return r - f;
}
// void pt( int v )
// {
//   for( int i = s[v]; i; i = rd[i][2] )
//     cout << ( rd[i][0] > M ? rd[i][0] - M : rd[i][0] ) << ' ';cout << endl;
// }
// void gpos( int v )
// {
//   for( int i = 0 ; i < N; ++i )
//     for( int j = 0 ; j < N ; ++j )
//       if( v == p[i][j] )
// 	{
// 	  cout << i << ' ' << j << endl;
// 	  return ;
// 	}
// }
int mf( )
{
  // pt(1);
  // gpos(28);
  // cout << "!" << endl;
  // pt(29);
  int r(0);
  for( ; bfs() ; )
    {
      // cout << lev[T] << endl;
      for( ; ; )
	{
	  int tmp = dfs( S, 10);
	  // cout << tmp << endl;
	  if( tmp == 0 )
	    break;
	  r += tmp;
	  // cout << tmp << "!" << endl;
	}
    }
  // cout << r << endl;
  return r;
}
bool cnt( int x, int y, vector<string> & b, int n, int k )
{
  int xx = x + dir[k][0] * 3;
  int yy = y + dir[k][1] * 3;
  if( xx >= 0 && yy >= 0 && xx < n && yy < n && b[xx][yy] != 'H' )
    {
      bool ept = false;
      for( int i = 1; i <= 2; ++i )
	{
	  xx = x + dir[k][0] * i;
	  yy = y + dir[k][1] * i;
	  if( b[xx][yy] != 'H' )
	    ept = true;
	}
      if( ept )
	{
	  return true;
	}
    }
  return false;
}
int BlockTheBlockPuzzle::minimumHoles(vector <string> board)
{
  int n = board.size();
  S = ++pi;
  T = ++pi;
  int ans(0);
  for( int i = 0 ; i < n ; ++i )
    for( int j = 0 ; j < n ; ++j )
      if( board[i][j] == '$' )
	{
	  for( int a = i % 3 ; a < n ; a += 3 )
	    {
	      for( int b = j % 3 ; b < n ; b += 3 )
		{
		  // cout << board[a][b];
		  if( board[a][b] != 'H' )
		    p[a][b] = ++pi;
		}
	      // cout << endl;
	    }
	  // cout << p[0][3] << endl;
	  for( int a = i % 3 ; a < n ; a += 3 )
	    for( int b = j % 3 ; b < n ; b += 3 )
	      if( board[a][b] != 'H' )
		{
		  add( p[a][b] + M, p[a][b] );
		  if( board[a][b] == '$' )
		    {
		      for( int k = 0 ; k < 2; ++k )
			{
			  if( cnt( a, b, board, n, k ) )
			    {
			      int x = a + dir[k][0] * 3;
			      int y = b + dir[k][1] * 3;
			      if( board[x][y] == 'b' )
				{
				  bool ept = true;
				  for( int l = 1; l <= 2; ++l )
				    {
				      int xx = a + dir[k][0] * l;
				      int yy = b + dir[k][1] * l;
				      if( board[xx][yy] == 'b' )
					ept = false;
				      else if( board[xx][yy] == '.' )
					++ans;
				    }
				  if( !ept )
				    return -1;
				}
			      else
				add( S, p[x][y] + M );
			    }
			}
		    }
		  else if( board[a][b] == '.' )
		    {
		      for( int k = 0 ; k < 2; ++k )
			{
			  if( cnt( a, b, board, n, k ) )
			    {
			      int x = a + dir[k][0] * 3;
			      int y = b + dir[k][1] * 3;
			      if( board[x][y] == 'b' )
				{
				  add( p[a][b], T );
				}
			      else if( board[x][y] == '$' )
				add( S, p[a][b] + M );
			      else 
				{
				  add( p[a][b], p[x][y] + M ); // '.'
				  add( p[x][y], p[a][b] + M );
				}
			    }
			}
		    }
		  else
		    {
		      for( int k = 0; k < 2; ++k )
			if( cnt( a, b, board, n, k ) )
			  {
			    int xx = a + dir[k][0] * 3;
			    int yy = b + dir[k][1] * 3;
			    // if( a == 0 && b == n - 1 )
			    //   cout << xx << ' ' << yy << endl;
			    if( board[xx][yy] == '$' )
			      {
				bool ept = true;
				for( int l = 1; l < 3; ++l )
				  {
				    int x = a + dir[k][0] * l;
				    int y = b + dir[k][1] * l;
				    if( board[x][y] == 'b' )
				      ept = false;
				    else if( board[x][y] == '.' )
				      ++ans;
				  }
				if( !ept )
				  return -1;
			      }
			    else if( board[xx][yy] == '.' )
			      {
				add( p[xx][yy], T );
			      }
			  }
		    }
		}
	  return mf() + ans;
	}
  return 0;
}
map<int,int> sett;
int sti;
void ddfs( int v )
{
  if( v == T )
    {
      cout << "!" << sti << endl;
      ++sti;
    }
  for( int i = s[v]; i; i = rd[i][2] )
    {
      int t = rd[i][0];
      if( rd[i][1] == 0 )
	{
	  sett.insert( ppi( t > M ? t - M : t, sti ) );
	  printf( " %d ", t > M ? t - M : t );
	  ddfs( t );
	}
    }
}
int main()
{
  BlockTheBlockPuzzle a;
  // string aa[] = {"............H..",
  // 		 "...............",
  // 		 "...............",
  // 		 "HHH$HHH........",
  // 		 "HHHHHHH........",
  // 		 "HHHHHHHH.......",
  // 		 "......b..H.....",
  // 		 "...............",
  // 		 "...............",
  // 		 "...H..H..H.....",
  // 		 "...............",
  // 		 "...............",
  // 		 "...............",
  // 		 "...............",
  // 		 "..............."};
  // string aa[] = {"............H..",
  // 		 "...............",
  // 		 "...............",
  // 		 "HHH$HHH.....H..",
  // 		 "HHHHHHH........",
  // 		 "HHHHHHHH.......",
  // 		 "......b..H.....",
  // 		 "...............",
  // 		 "...............",
  // 		 "...H..H..H.....",
  // 		 "...............",
  // 		 "...............",
  // 		 "...............",
  // 		 "...............",
  // 		 "..............."};

// string aa[] = {"b..$...",
// 	       "...H...",
// 	       ".......",
// 	       "b..b..b",
// 	       "...H...",
// 	       ".......",
// 	       "b..b..b"};
 // string aa[] = {"b..b..b",
 // 		"..b..b.",
 // 		".......",
 // 		"b..$bbb",
 // 		".b.....",
 // 		"....b..",
 // 		"b..b..b"};
  string aa[] = {"....HH.......H.............H........b......H..",
		 "........H.................H...H...........H...",
		 "...H....H....H........b..H.........HH.........",
		 "...H..........H..H.......H...........H.....H.b",
		 "................................b..H....H....H",
		 "...............H..................H...........",
		 "....H............H.......H..........b.........",
		 "...............H...........b...H.........H....",
		 "..H............H.b.H................H..H$.....",
		 "......H..........H....H....................H..",
		 "..............b..........................H....",
		 "..........H..H.....b......H.........H..H.HH...",
		 ".....H.......H..........H.......H.......H.H...",
		 "............b......H................bH....H...",
		 "....H......H.........H......bH................",
		 "H......H...H.HH...............H...H........b..", "...................H......H..H............H...", "...H.....................b..H.............H...", "..H.Hb..H............H....H......H....H....H..", "..............H.b.H......HH.H....b..b.........", "...H...H..H............H.H....bH..H..bH.......", ".......H............H............H...........H", "..H...b........b..b..H.H.H.....H.....bH.H.....", "..........H............H..........H.....H...H.", ".............H....H...........b...H...H.H.....", "...H..................bH......................", "..H...H.b.....Hb.........H.............H......", ".........b...H......H......H........H.H....H..", ".H...................H........H....H........H.", "H......b.......H.....H...................H....", "....H...H...........H.H...............H.......", "..............H...............H...H......H..H.", "..H...H......H.H.........H.H...H..........H...", "...........Hb..........H.......H..............", "...........H....H..............H........H.....", ".......................b.........H.H...H......", "......H.............H....b..................H.", "b....H....................H........H....H.....", "...H..............H......H...............H..H.", "...................H.........H..H............H", ".........H.......H...........H.H.....H......HH", "H.....H.............H..................HH...H.", "..........H..H........................HH.....H", "....H.................H..........H.H......H...", "H.............................H.....b...HH...H", ".......H.H...............H...................."};
  vector<string> aaa;
  for( int i = 0 ; i < sizeof( aa ) / sizeof( aa[0] ); ++i )
    aaa.push_back( aa[i] );
  // cout << aaa.size() << endl;
  cout << a.minimumHoles(aaa) << endl;
  // for( int i = 0 ; i < 50 ; ++i )
  //   for( int j = 0 ; j < 50 ; ++j )
  //     if( aa[i][j] == '$' )
  // 	cout << i << '!' << j << ' ' << p[i][j] << endl;
  // ddfs(S);
  // // for( int i = 0 ; i < aaa.size(); ++i )
  // //   {
  // //     for( int j = 0 ; j < aaa.size() ; ++j )
  // // 	{
  // // 	  if( aa[i][j] == '$' )
  // // 	    {
  // for( int x = 0;  x < aaa.size(); ++x )
  // 		{
  // 		  for( int y = 0; y < aaa.size(); ++y )
  // 		  {
  // 		    if( sett.find( p[x][y] ) != sett.end() )
  // 		      {
  // 			cout << sett[ p[x][y] ];
  // 		      }
  // 		    else cout << aa[x][y];
  //   		  }
  //   	      cout << endl;
  //   	    }
    // 	    }
    // 	}
    // }
  return 0;
}
