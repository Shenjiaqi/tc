#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;
class BinPacking
{
public:
  int minBins(vector <int> item);
};
int BinPacking::minBins(vector <int> item)
{
  sort(item.begin(),item.end());
  int ans(0);
  for(int i=item.size()-1;i>=0;)
    {
      if(item[i]<0)
	{
	  --i;
	  continue;
	}
      int j=i-1;
      for(;j>=0 && (item[j]<0 || item[j]+item[i]>300);--j)
	;
      if(j>=0)
	{
	  item[i]+=item[j],item[j]=-1;
	  if(item[i]>200)
	    --i,++ans;
	}
      else --i,++ans;
    }
  return ans;
}
//{{100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 189, 126, 158, 181, 132}}
int main()
{
  BinPacking a;
  int b[]={100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 189, 126, 158, 181, 132};
  vector<int> c(b,b+sizeof(b)/sizeof(b[0]));
  cout<<a.minBins(c)<<endl;
  return 0;
}
