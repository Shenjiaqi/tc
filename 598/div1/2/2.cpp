//     
// Class:
// FoxAndFencing
// Method:
// WhoCanWin
// Parameters:
// int, int, int, int, int
// Returns:
// string
// Method signature:
// string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class FoxAndFencing
{
public:
  string WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d);
};
string FoxAndFencing::WhoCanWin(int mov1, int mov2, int rng1, int rng2, int d)
{
  string r[]={"Draw","Ciel","Liss"};
  if(d<=mov1+rng1)
    return r[1];
  if(d+mov1<=mov2+rng2)
    return r[2];
  if(mov1>mov2)
    {
      if(mov1+rng1>mov2*2+rng2)
	return r[1];
      return r[0];
    }
  else if(mov1<mov2)
    {
      if(mov2+rng2>mov1*2+rng1)
	return r[2];
      return r[0];
    }
  return r[0];
}
int main()
{
  FoxAndFencing a;
  cout<<a.WhoCanWin(1,58,1,58,2)<<endl;
  cout<<a.WhoCanWin(2,1,1,100,50)<<endl;
  cout<<a.WhoCanWin(2,1,1,100,150)<<endl;
  cout<<a.WhoCanWin(100,100,100,100,100000000)<<endl;
  cout<<a.WhoCanWin(100,1,100,1,100000000)<<endl;
  cout<<a.WhoCanWin(100,1,100,250,100000000)<<endl;
  cout<<a.WhoCanWin(100,1,100,150,100000000)<<endl;
  cout<<a.WhoCanWin(100,50,100,1,100000000)<<endl;
  cout<<a.WhoCanWin(100,150,100,1,100000000)<<endl;
  return 0;
}
