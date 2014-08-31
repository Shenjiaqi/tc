#include <bits/stdc++>
class SuffixArrayDiv1
{
public:
  int minimalCharacters(vector <int> SA);
};
int SuffixArrayDiv1::minimalCharacters(vector <int> sa)
{
  int numSa = sa.size();
  vector<int> posSa;
  posSa.resize( sa.size() );
  for( int i = 0 ; i < numSa ; ++i )
    posSa[ sa[i] ] = i;
  posSa.push_back( -1 );
  int ans = numSa;
  for( int idx = numSa - 1; idx > 0 ; --idx )
    {
      int preIdx = idx - 1;
      int nxtPosPreIdx = posSa[ sa[preIdx] + 1];
      int nxtPosNowIdx = posSa[ sa[idx] + 1 ];
      if( nxtPosNowIdx > nxtPosPreIdx )
	{
	  --ans;
	}
    }
  return ans;
}
