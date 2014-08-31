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
class DrivingPlans
{
public:
  int count(int N, vector <int> A, vector <int> B, vector <int> C);
};
const int N = 20007;
const int mod = 1e9 + 9;
int fa[N];
vector<int> lst[N];
int que( int v )
{
  return v == fa[v] ? v : fa[v] = que( fa[v] );
}
void join( int a, int b )
{
  a = que(a);
  b = que(b);
  fa[b] = a;
}
vector<ppi> rd[N];
int ct[N];
void add( int f, int t , int c )
{
  rd[f].push_back( make_pair( t, c ) );
  rd[t].push_back( make_pair( f, c ) );
}
const int inf = 2e9 + 7;
int dis[N];
int dist[N];
int cnt[N];
bool in[N];
void cal( int from, int n )
{
  for( int i = 1 ; i <= n; ++i )
    dis[i] = inf;
  dis[que(from)] = 0;
  in[que(from)] = true;
  queue<int> quee;
  quee.push(que(from));
  for( ; !quee.empty(); )
    {
      int v = quee.front();
      quee.pop();
      in[v] = false;
      int d = dis[v];
      for( auto i : lst[v] )
	for( auto j : rd[i] )
	  {
	    int t = que(j.first);
	    int tmp = d + j.second;
	    if( dis[t] > tmp )
	      {
		dis[t] = tmp;
		if( !in[t] )
		  {
		    quee.push(t);
		    in[t] = true;
		  }
	      }
	  }
    }
}
int DrivingPlans::count(int n, vector <int> a, vector <int> b, vector <int> c)
{
  int num = a.size();
  for( int i = 1 ; i <= n; ++i )
    fa[i] = i;
  for( int i = 0 ; i < num; ++i )
    if( c[i] > 0 )
      {
	add( a[i], b[i], c[i]);
      }
    else join( a[i], b[i] );
  for( int i = 1; i <= n; ++i )
    lst[ que(i) ].push_back(i);
  if( que( 1 ) == que( n ) )
    return -1;
  cal( n, n );
  memcpy( dist, dis, sizeof(dist) );
  cal( 1, n);
  for( int i = 1; i <= n; ++i )
    ++ct[ que(i) ];
  multimap<int,int> mapp;
  for( int i = 1; i <= n; ++i )
    if( dis[que(i)] + dist[que(i)] == dis[que(n)] )
      {
	if( ct[ que(i) ] > 1 )
	  return -1;
	mapp.insert( make_pair( dis[que(i)], que(i) ) );
      }
  cnt[que(1)] = 1;
  for( auto i : mapp )
    {
      int v = i.second;
      for( auto j : rd[v] )
	{
	  int t = j.first;
	  if( dis[t] == dis[v] + j.second &&
	      dis[t] + dist[t] == dis[n])
	    {
	      cnt[t] = ( cnt[t] + cnt[v] ) % mod;
	    }
	}
    }
  cout << dis[n] << endl;
  return cnt[n];
}
int main()
{ 
  int a[] =  {371, 1684, 845, 641, 261, 1244, 459, 1911, 1936, 1168, 1679, 1942, 1757, 108, 1215, 688, 1758, 987, 886, 1737, 1041, 1701, 1387, 823, 1035, 1854, 1650, 486, 599, 1002, 906, 1207, 1081, 530, 331, 1040, 841, 1719, 484, 1011, 1390, 1032, 887, 1211, 121, 1078, 994, 1733, 1466, 402, 1496, 1682, 1506, 503, 1142, 216, 1412, 1888, 1552, 1250, 1364, 660, 1006, 1178, 160, 1254, 873, 1482, 139, 1859, 1861, 901, 1146, 102, 1817, 1197, 142, 626, 474, 1902, 747, 2000, 1264, 327, 1176, 660, 1339, 1192, 1807, 1896, 351, 372, 1176, 1672, 1031, 555, 793, 1177, 1671, 37, 1647, 1796, 1576, 1278, 928, 1688, 1022, 1069, 583, 1196, 616, 1430, 481, 1611, 1259, 1187, 1180, 1720, 265, 1031, 1444, 244, 1146, 1922, 586, 524, 660, 5, 786, 597, 843, 1697, 849, 1780, 1887, 473, 228, 216, 664, 1750, 846, 110, 1209, 975, 1226, 1241, 418, 576, 901, 866, 1084, 1781, 1858, 235, 864, 458, 1050, 184, 1487, 1368, 1781, 77, 103, 1410, 388, 129, 485, 701, 404, 1259, 1652, 945, 442, 1231, 1744, 1640, 1098, 362, 486, 78, 1924, 1993, 566, 424, 1922, 883, 655, 1522, 4, 1305, 703, 854, 313, 154, 22, 547, 1655, 24, 1954, 951, 1076, 322, 1457, 449, 99, 1963, 1405, 680, 854, 1590, 1650, 1217, 241, 1700, 119, 456, 295, 9, 656, 1323, 744, 993, 719, 847, 1445, 1885, 1146, 1446, 1143, 1972, 1294, 406, 85, 929, 73, 1657, 368, 229, 1727, 439, 306, 436, 1933, 276, 729, 533, 695, 920, 1341, 1045, 886, 559, 1635, 1716, 1317, 731, 1658, 291, 1671, 991, 288, 1052, 860, 374, 771, 418, 279, 1053, 878, 1506, 1076, 754, 1381, 1884, 1124, 1957, 480, 1210, 94, 58, 1921, 1763, 1860, 1349, 1900, 1602, 29, 240, 1679, 1465, 557, 355, 1501, 353, 19, 120, 165, 1171, 1142, 835, 1670, 1563, 1362, 1352, 1207, 1498, 1360, 767, 261, 304, 1805, 1767, 35, 1612, 135, 1450, 763, 997, 1427, 28, 1669, 1904, 795, 214, 1587, 100, 1284, 570, 78, 1074, 1770, 1053, 948, 854, 610, 1010, 1809, 1973, 338, 1157, 1088, 278, 559, 1193, 1522, 424, 246, 418, 494, 1067, 729, 1092, 561, 1432, 1847, 343, 1640, 1695, 496, 1787, 751, 605, 1669, 1802, 42, 340, 820, 981, 668, 1776, 1892, 1054, 161, 365, 1915, 615, 1531, 1864, 266, 652, 1395, 218, 1168, 685, 1936, 1420, 1311, 867, 70, 578, 957, 1087, 1445, 765, 1976, 1496, 1332, 1970, 87, 1210, 1763, 1026, 1316, 1024, 672, 1498, 696, 1330, 466, 1797, 1385, 1506, 1431, 1312, 1914, 648, 1045, 847, 1720, 508, 1170, 267, 1515, 1816, 50, 772, 571, 326, 1948, 195, 1383, 1044, 1135, 1144, 1947, 1809, 1964, 920, 1345, 1457, 1316, 454, 364, 1555, 1044, 439, 335, 34, 1961, 197, 453, 998, 669, 293, 549, 1522, 516, 1650, 391, 1479, 981, 702, 1306, 954, 805, 654, 1413, 1016, 1936, 1538, 1253, 1582, 1940, 487, 1590, 1337, 271, 1385, 465, 131, 47, 1109, 583, 284, 1221, 1852, 589, 1625, 623, 1845, 1897, 1868, 882, 1851, 1844, 510, 1969, 466, 820, 828, 101, 485, 234, 987, 1513, 1444, 867, 164, 1734, 172, 372, 26, 184, 238, 1508, 1844, 951, 738, 1261, 1991, 243, 709, 1532, 298, 578, 331, 376, 487, 117, 413, 1254, 1281, 242, 772, 679, 1540, 558, 1028, 1748, 915, 1356, 1596, 771, 465, 1703, 1751, 476, 219, 1473, 40, 1228, 1925, 923, 1454, 499, 1874, 922, 1227, 1744, 267, 758, 1098, 1823, 840, 977, 636, 1453, 946, 1158, 596, 193, 660, 667, 1679, 1625, 1081, 586, 288, 1702, 1940, 179, 1378, 164, 524, 1922, 1293, 258, 475, 1335, 953, 1772, 1079, 1245, 108, 1877, 487, 717, 1842, 228, 964, 792, 1001, 427, 618, 126, 1871, 1598, 875, 533, 380, 1779, 1891, 296, 811, 1650, 616, 1060, 614, 672, 1144, 858, 1401, 711, 741, 784, 1004, 1148, 1510, 1640, 1269, 486, 381, 1073, 64, 380, 456, 247, 148, 1132, 1556, 784, 1397, 1613, 176, 752, 1197, 1144, 703, 1408, 543, 283, 1374, 1799, 470, 1632, 537, 1234, 52, 1108, 814, 269, 1507, 315, 39, 1267, 1276, 161, 1845, 1319, 1006, 1463, 529, 1139, 606, 712, 1715, 1425, 364, 735, 1212, 1335, 486, 988, 1818, 1662, 981, 615, 1771, 1600, 270, 1782, 1500, 771, 1165, 9, 961, 399, 723, 1103, 411, 101, 201, 681, 193, 1198, 1516, 792, 618, 1306, 366, 1723, 170, 564, 195, 90, 595, 1209, 210, 1576, 1521, 1906, 185, 1435, 1006, 1373, 43, 410, 1308, 1938, 807, 1000, 940, 761, 1801, 874, 298, 1430, 1269, 358, 1047, 335, 652, 1790, 1015, 1385, 413, 738, 1788, 1519, 1574, 47, 225, 974, 401, 1305, 67, 1666, 1052, 342, 1570, 1374, 783, 682, 1861, 309, 1774, 151, 983, 1590, 860, 521, 1229, 1478, 1274, 627, 1703, 619, 76, 1719, 1583, 1906, 1598, 192, 1666, 113, 40, 1926, 1034, 711, 519, 572, 1315, 394, 1866, 506, 567, 641, 1312, 206, 176, 1759, 395, 1501, 799, 1450, 1481, 140, 1472, 1637, 441, 447, 1405, 1115, 85, 1884, 500, 1020, 724, 559, 1296, 1868, 658, 113, 908, 381, 1989, 1070, 1811, 556, 583, 1953, 61, 1096, 621, 803, 211, 466, 178, 1901, 851, 685, 975, 179, 27, 1428, 423, 1564, 1294, 232, 1568, 77, 256, 1732, 1192, 622, 527, 879, 1196, 1938, 169, 115, 215, 954, 1121, 1406, 1670, 1682, 765, 1846, 38, 1233, 1036, 963, 936, 1955, 79, 587, 669, 1067, 1141, 1081, 459, 352, 826, 1103, 1204, 1134, 1842, 1177, 169, 1725, 1537, 521, 1537, 1372, 1037, 1998, 1455, 857, 1078, 591, 628, 1468, 74, 1676, 585, 1173, 1458, 349, 1536, 1855, 1287, 973, 283, 89, 1450, 1265, 205, 739, 1906, 297, 1667, 1089, 583, 1952, 1037, 200, 974, 71, 128, 1357, 1870, 697, 268, 553, 140, 1565, 1638, 532, 680, 1088, 1048, 216, 1937, 781, 1320, 1516, 1701, 1332, 401, 487, 470, 1406, 294, 1066, 1262, 258, 1660, 1379, 323, 703, 1634, 1821, 143, 1560, 1867, 1918, 23, 1509, 818, 324, 1816, 462, 1666, 172, 1789, 977, 498, 1524, 1031, 882, 1444, 1042, 1232, 1346, 597, 1276, 1721, 500, 845, 1461, 116, 616, 667, 1422, 29, 1993, 1703, 1667, 578, 1749, 1129, 1218, 1773, 619, 198, 1885, 1354, 1262, 110, 1278, 830, 972, 428, 755, 1503, 316, 695, 957, 627, 1728, 848, 602, 1574, 1649, 562, 141, 1769, 914, 692, 1060, 211, 534, 665, 885, 1003, 949, 1746, 214, 128, 1800, 1900, 693, 1214, 308, 447, 1882, 828, 369, 1340, 1455, 941, 1121, 235, 1339, 653, 701, 1817, 1187, 1909, 68, 1048, 543, 1374, 1471, 1907, 397, 163, 370, 318, 1332, 1239, 103, 422, 35, 1228, 890, 941, 174, 489, 1895, 11, 1696, 1497, 1900, 1095, 695, 179, 1786, 44, 1640, 648, 1502, 469, 1685, 260, 464, 1336, 1869, 1485, 1369, 1226, 543, 1107, 1715, 761, 811, 730, 1242, 1170, 539, 1988, 1893, 864, 1224, 1153, 1599, 1624, 1857, 1566, 1784, 1352, 1218, 799, 389, 1682, 442, 1480, 960, 751, 1607, 1957, 262, 70, 380, 458, 1547, 1741, 1404, 1995, 10, 435, 681, 1372, 1074, 137, 1571, 346, 381, 1712, 631, 1056, 260, 310, 19, 1785, 1807, 1364, 1348, 229, 1538, 308, 1578, 469, 1529, 1033, 328, 504, 1613, 591, 1125, 869, 1482, 396, 1778, 714, 1935, 1918, 504, 983, 92, 975, 1968, 1490, 1990, 1387, 1344, 205, 84, 1738, 1845, 1449, 1075, 70, 887, 1259, 579, 13, 63, 1402, 327, 422, 1166, 898, 1633, 1593, 1464, 1067, 1178, 839, 1394, 1677, 223, 1570, 1333, 478, 207, 868, 1382, 687, 1840, 1083, 1575, 758, 1739, 1835, 481, 1156, 140, 743, 1219, 378, 56, 1972, 455, 1996, 1583, 975, 1937, 343, 1698, 932, 1952, 1401, 1623, 1867, 56, 456, 638, 868, 1831, 1141, 221, 1579, 1947, 1729, 1190, 900, 376, 987, 1159, 1678, 1669, 1687, 1302, 1067, 560, 1365, 285, 569, 1414, 1541, 1657, 986, 1950, 251, 1290, 79, 1447, 137, 1844, 1199, 1130, 1704, 1010, 522, 350, 453, 1200, 1227, 1307, 1478, 903, 1795, 734, 1075, 563, 1274, 708, 865, 605, 1941, 198, 50, 1736, 1684, 1658, 1310, 1260, 1080, 647, 686, 629, 1133, 389, 730, 1774, 1556, 1518, 471, 426, 1221, 1656, 1752, 1916, 482, 579, 842, 1101, 1650, 1895, 1232, 1823, 1101, 1502, 165, 1231, 47, 1102, 1031, 759, 1188, 314, 309, 1853, 526, 438, 242, 1959, 654, 440, 490, 485, 1300, 1417, 987, 60, 1555, 724, 1946, 1233, 1342, 1160, 936, 1773, 160, 916, 865, 1836, 275, 1049, 1155, 1551, 655, 1239, 1722, 1611, 1938, 36, 1780, 1437, 743, 1021, 318, 865, 1325, 1958, 1234, 1272, 455, 106, 654, 386, 1201, 1792, 1924, 733, 828, 1235, 189, 1902, 1713, 1629, 983, 682, 832, 1924, 48, 1663, 167, 1884, 1333, 510, 188, 141, 1488, 1412, 837, 1066, 1065, 891, 1947, 1404, 955, 505, 510, 188, 1982, 984, 663, 922, 368, 1711, 1857, 640, 943, 244, 649, 220, 528, 1964, 996, 831, 1730, 1136, 1091, 1470, 1999, 18, 947, 766, 1445, 533, 47, 1367, 1523, 853, 222, 1925, 574, 850, 615, 1630, 474, 227, 1954, 1470, 1143, 1099, 1574, 312, 1029, 311, 1473, 144, 793, 8, 43, 1550, 1965, 120, 1185, 252, 1001, 614, 1995, 1586, 1538, 628, 930, 422, 1981, 1225, 1595, 650, 483, 432, 1282, 1882, 828, 448, 1806, 1892, 153, 502, 762, 1375, 1638, 1673, 417, 1558, 1493, 1164, 1344, 147, 1710, 90, 88, 999, 1874, 608, 52, 967, 1587, 1651, 415, 1682, 357, 1094, 1360, 1161, 613, 1339, 921, 473, 332, 921, 671, 1506, 845, 630, 1814, 865, 1273, 1287, 60, 97, 270, 1813, 1111, 456, 662, 98, 118, 1810, 1489, 222, 1335, 1008, 150, 1949, 414, 994, 1753, 775, 541, 1931, 209, 756, 1485, 491, 1512, 1717, 664, 1392, 926, 1486, 1743, 1019, 958, 603, 1086, 273, 1841, 221, 471, 155, 1346, 1953, 1289, 331, 1677, 489, 1206, 1178, 1491, 968, 638, 960, 1194, 658, 927, 1426, 1727, 336, 1077, 152, 360, 112, 998, 164, 1892, 1878, 312, 1143, 575, 1518, 1559, 1628, 1880, 377, 885, 1994, 391, 1956, 723, 1076, 95, 405, 997, 1347, 1740, 66, 1727, 240, 981, 1257, 1338, 415, 1137, 348, 938, 375, 1773, 331, 179, 1572, 1023, 1560, 1705, 1897, 1984, 316, 751, 1590, 1583, 1527, 624, 1005, 536, 1156, 1826, 191, 1224, 1949, 1689, 971, 1828, 571, 1409, 255, 295, 99, 236, 566, 1105, 537, 1360, 1163, 1359, 330, 196, 124, 583, 1175, 1940, 555, 664, 1465, 479, 244, 445, 1936, 54, 1189, 1733, 1170, 1417, 214, 113, 764, 1257, 845, 739, 705, 1693, 598, 1409, 1303, 721, 616, 604, 83, 1258, 1834, 1785, 1923, 1124, 1172, 1940, 1059, 246, 609, 1118, 1973, 1630, 1833, 1641, 1893, 368, 345, 733, 635, 1735, 1809, 198, 131, 1584, 559, 409, 819, 1494, 694, 72, 1631, 1660, 1473, 657, 1825, 852, 1054, 1230, 742, 50, 1213, 812, 149, 1884, 1166, 203, 1309, 1867, 1888, 908, 1967, 632, 1755, 1114, 41, 1887, 1721, 1294, 1980, 1366, 735, 1985, 676, 829, 224, 1243, 817, 586, 241, 1375, 1969, 53, 140, 1156, 1248, 988, 51, 1236, 552, 1, 1708, 1963, 1820, 1246, 59, 1864, 1402, 1424, 1471, 1898, 1519, 1355, 202, 1544, 97, 565, 1058, 1084, 245, 1443, 517, 1683, 1831, 175, 48, 1973, 689, 612, 796, 1668, 1151, 123, 884, 467, 706, 1823, 1416, 691, 263, 794, 254, 269, 1481, 1543, 704, 1109, 1015, 412, 727, 472, 815, 1837, 833, 1530, 1126, 1581, 457, 340, 15, 391, 606, 1577, 1477, 1051, 1127, 1985, 722, 81, 1180, 1391, 639, 775, 1476, 975, 1635, 1271, 466, 1469, 1585, 227, 841, 1506, 327, 253, 520, 1448, 1139, 384, 952, 1145, 1944, 1757, 1328, 94, 948, 403, 1574, 951, 1321, 21, 96, 1697, 1203, 1240, 180, 1384, 433, 1586, 1400, 132, 515, 629, 1434, 341, 740, 1528, 194, 731, 385, 985, 1222, 217, 551, 126, 1849, 1476, 32, 798, 904, 1014, 1186, 1982, 1597, 970, 1881, 696, 1639, 1263, 217, 1397, 479, 582, 1164, 1876, 1389, 1482, 173, 1539, 743, 1551, 58, 1150, 1680, 641, 157, 181, 1782, 834, 134, 633, 1848, 652, 737, 1329, 168, 381, 405, 1554, 1080, 274, 1726, 46, 982, 684, 1883, 1128, 1770, 800, 888, 257, 335, 774, 1345, 1092, 1361, 226, 930, 784, 1451, 1742, 1958, 2, 776, 1952, 1299, 171, 1859, 1167, 1930, 1624, 930, 1162, 1622, 170, 1110};
  int b[] = {1602, 461, 1663, 1559, 680, 1965, 731, 575, 1012, 1674, 992, 881, 1631, 1638, 394, 1476, 1648, 1589, 1682, 127, 9, 2000, 296, 110, 1647, 1397, 118, 1594, 1705, 674, 1663, 298, 42, 478, 981, 1025, 496, 325, 1109, 942, 1724, 773, 1122, 1418, 1010, 1852, 1380, 408, 1611, 1579, 511, 1922, 790, 1998, 1593, 1979, 288, 1154, 838, 1759, 1182, 1386, 1534, 1845, 444, 1503, 104, 1712, 1148, 761, 972, 1517, 1348, 1817, 1665, 1941, 583, 554, 999, 1877, 928, 1408, 442, 505, 1632, 1459, 179, 1724, 771, 525, 411, 213, 1158, 1836, 773, 289, 180, 1943, 1996, 1983, 1763, 1801, 1868, 1764, 1610, 1419, 789, 1700, 877, 544, 500, 1598, 959, 1326, 1108, 1191, 34, 1322, 1234, 691, 288, 667, 590, 1855, 57, 1515, 1618, 1040, 1661, 343, 157, 492, 941, 1159, 776, 889, 498, 197, 600, 111, 1194, 402, 1649, 589, 1485, 1885, 961, 1945, 1557, 1669, 689, 705, 149, 1319, 1174, 900, 1385, 450, 958, 1165, 897, 1275, 1977, 785, 190, 620, 1940, 758, 1678, 1767, 1173, 1607, 476, 1690, 434, 65, 172, 1609, 1575, 1367, 204, 1567, 94, 1273, 1035, 1233, 411, 1627, 1538, 769, 291, 635, 1365, 874, 328, 1034, 1317, 1090, 1136, 641, 174, 1412, 344, 25, 36, 62, 1050, 1334, 723, 1258, 38, 961, 944, 300, 906, 1744, 151, 1316, 392, 28, 1339, 1651, 1972, 395, 1807, 162, 1553, 1439, 603, 774, 920, 441, 1722, 1746, 714, 1694, 190, 1843, 105, 1618, 524, 1137, 947, 675, 707, 777, 1938, 513, 611, 1936, 771, 589, 678, 531, 1119, 1768, 1159, 78, 1335, 234, 281, 1938, 85, 772, 969, 773, 266, 130, 1099, 1525, 1875, 1410, 392, 682, 1850, 1304, 1623, 918, 1393, 856, 820, 1403, 74, 666, 1220, 702, 801, 1692, 1183, 1439, 1821, 255, 1244, 768, 719, 1064, 35, 1664, 264, 731, 33, 299, 56, 452, 897, 698, 68, 656, 1960, 567, 990, 925, 1859, 1652, 1407, 1986, 1625, 573, 1384, 1609, 1296, 897, 190, 127, 59, 1913, 1519, 347, 823, 1377, 1882, 1718, 906, 1346, 1282, 97, 1093, 1186, 1132, 1911, 1097, 400, 638, 625, 1052, 1567, 1559, 785, 1582, 1625, 1379, 959, 1301, 1316, 16, 1347, 1431, 288, 1182, 1806, 937, 1694, 690, 807, 977, 1840, 588, 259, 1200, 459, 1019, 670, 750, 13, 264, 854, 1040, 1620, 282, 1076, 846, 1525, 1407, 1492, 1500, 576, 419, 1993, 1433, 1132, 674, 1508, 1184, 1064, 619, 647, 117, 634, 1945, 215, 1770, 219, 318, 750, 382, 1862, 1537, 1842, 64, 1069, 1085, 1927, 243, 1860, 87, 862, 1884, 94, 1334, 533, 1430, 939, 654, 1268, 195, 1703, 38, 1955, 1254, 1501, 1842, 1594, 1350, 584, 1080, 545, 668, 1192, 369, 636, 1615, 1280, 1709, 1449, 1715, 600, 1877, 1048, 1642, 441, 807, 276, 790, 1618, 1, 1211, 389, 1266, 1399, 1193, 929, 1748, 1440, 211, 1150, 1080, 627, 133, 720, 1593, 581, 1663, 669, 683, 1644, 831, 1159, 24, 1135, 487, 337, 1346, 390, 930, 1171, 1397, 1498, 783, 1573, 1688, 69, 134, 1408, 801, 1324, 1055, 389, 685, 370, 1791, 1533, 1064, 958, 989, 211, 609, 1546, 519, 1528, 926, 1331, 1930, 192, 608, 12, 271, 20, 1407, 1657, 687, 452, 1301, 1937, 71, 1669, 1313, 1011, 493, 1943, 1296, 1163, 1774, 1859, 182, 1179, 1580, 896, 450, 1401, 1828, 1670, 812, 1254, 510, 961, 1349, 1533, 638, 1426, 1734, 75, 365, 1504, 1607, 1394, 1195, 1917, 1548, 1935, 642, 302, 420, 1564, 1187, 1757, 761, 232, 972, 966, 477, 77, 1412, 122, 973, 553, 1040, 1488, 679, 1062, 1531, 125, 905, 759, 909, 1249, 1629, 66, 1209, 30, 1171, 1449, 1540, 966, 765, 1674, 725, 1603, 1365, 1796, 1866, 6, 1061, 1174, 1498, 1618, 19, 1425, 1574, 1133, 731, 224, 1863, 1359, 139, 1588, 502, 692, 1793, 1663, 1390, 1609, 589, 1784, 44, 1298, 1735, 705, 1840, 1598, 609, 307, 7, 1783, 1027, 321, 1038, 139, 604, 869, 220, 623, 596, 445, 1493, 858, 709, 1851, 870, 231, 1109, 1138, 161, 455, 421, 499, 1658, 1537, 802, 1982, 1351, 1557, 1005, 374, 74, 1926, 1678, 264, 1242, 1063, 307, 926, 879, 1496, 1661, 1343, 759, 333, 978, 1133, 359, 623, 900, 183, 372, 1778, 1038, 1068, 392, 711, 490, 638, 79, 39, 1580, 1421, 1945, 887, 879, 1290, 561, 1563, 438, 1512, 1457, 276, 844, 1818, 1041, 1591, 1620, 1971, 769, 1516, 576, 1482, 22, 393, 1765, 1648, 86, 1414, 1445, 1399, 1965, 1706, 905, 821, 1738, 1072, 444, 1074, 1196, 184, 822, 1829, 1590, 1968, 352, 429, 669, 383, 693, 1757, 1838, 1715, 1465, 1971, 1873, 900, 1917, 1452, 24, 1159, 1579, 1899, 1277, 1868, 419, 736, 1418, 1749, 1493, 1651, 1009, 1320, 1248, 1376, 1574, 1272, 943, 67, 930, 294, 1903, 369, 824, 1125, 1843, 473, 1886, 131, 1393, 1618, 1983, 917, 729, 827, 1176, 1930, 108, 820, 1576, 731, 1458, 1800, 20, 1520, 139, 1422, 1092, 754, 358, 797, 1997, 116, 468, 1113, 68, 1331, 520, 1759, 1165, 11, 617, 1333, 1585, 1519, 177, 1838, 1148, 1100, 890, 620, 540, 285, 1332, 1193, 1352, 830, 988, 1870, 656, 1036, 1330, 198, 1048, 70, 1078, 832, 1212, 599, 926, 476, 1133, 880, 764, 1552, 1840, 1178, 1024, 1209, 1787, 1703, 157, 564, 1694, 184, 935, 1552, 1295, 551, 78, 674, 1855, 1592, 430, 1030, 1936, 1224, 1842, 1202, 117, 672, 1176, 587, 1856, 935, 1838, 868, 1096, 1974, 1231, 1601, 74, 1745, 1252, 1045, 956, 518, 296, 1841, 936, 1617, 589, 1899, 1889, 584, 116, 1108, 713, 578, 927, 1391, 598, 565, 277, 1183, 866, 1129, 1801, 304, 1462, 1356, 523, 233, 1184, 1722, 1177, 1087, 104, 340, 1077, 195, 564, 262, 600, 851, 1838, 1794, 880, 1087, 1153, 1648, 1822, 651, 851, 356, 91, 1016, 1116, 822, 1383, 1015, 117, 808, 500, 609, 28, 1517, 1281, 1539, 1843, 1714, 223, 1331, 1786, 1138, 1889, 1595, 92, 204, 1245, 968, 485, 380, 685, 838, 619, 532, 1775, 1045, 683, 307, 235, 1271, 877, 610, 266, 487, 1146, 1387, 1855, 601, 1505, 1613, 1179, 1756, 1055, 49, 1722, 961, 1959, 1423, 1533, 1762, 305, 1670, 600, 623, 159, 700, 280, 628, 1576, 1398, 1878, 1227, 702, 618, 1198, 617, 1233, 1275, 1376, 470, 899, 838, 1470, 1387, 1969, 991, 484, 1215, 1830, 154, 883, 1358, 1184, 763, 615, 1562, 640, 731, 1862, 1267, 1220, 767, 73, 354, 752, 894, 753, 398, 1436, 1968, 104, 1549, 506, 1191, 441, 437, 1177, 1900, 855, 141, 395, 1129, 529, 122, 1717, 250, 1670, 85, 1962, 869, 1250, 1704, 825, 974, 1784, 157, 172, 1884, 816, 1440, 1039, 1803, 307, 1017, 806, 1377, 277, 254, 145, 532, 648, 1565, 1147, 1108, 158, 990, 779, 1978, 1251, 73, 1942, 1769, 663, 395, 1475, 1762, 1079, 396, 410, 836, 1095, 1088, 17, 230, 1633, 295, 1283, 435, 163, 1678, 1679, 1556, 1509, 45, 645, 410, 1575, 1317, 559, 400, 1609, 165, 709, 1784, 780, 1444, 373, 1642, 979, 696, 260, 555, 1082, 129, 1618, 276, 526, 1778, 74, 864, 1895, 1742, 1100, 655, 883, 831, 264, 1357, 1399, 35, 1535, 1739, 1070, 1115, 1767, 90, 788, 1219, 211, 1546, 813, 644, 405, 156, 732, 89, 663, 1857, 1762, 148, 1363, 1666, 1832, 709, 318, 984, 1062, 1514, 161, 896, 714, 249, 530, 352, 1313, 592, 1286, 189, 1429, 18, 783, 746, 1401, 1578, 537, 172, 1798, 1707, 1264, 1592, 1344, 634, 58, 766, 951, 746, 1533, 1188, 1411, 1920, 1407, 1795, 1429, 1231, 335, 347, 121, 871, 579, 787, 1921, 927, 1894, 76, 4, 1132, 1861, 710, 947, 482, 146, 560, 1252, 268, 1174, 1314, 1579, 1348, 290, 788, 568, 150, 1123, 1370, 789, 1630, 647, 588, 1088, 588, 1851, 405, 681, 366, 127, 356, 1095, 463, 1352, 391, 580, 856, 1725, 440, 1207, 1150, 910, 1181, 662, 275, 1037, 715, 496, 1485, 258, 913, 1502, 415, 205, 519, 1708, 1560, 1270, 519, 229, 519, 928, 1743, 660, 628, 83, 810, 79, 282, 1865, 246, 296, 1614, 388, 1107, 808, 336, 977, 864, 642, 1349, 1989, 1312, 1621, 1223, 1030, 1929, 1697, 1351, 659, 391, 1372, 1887, 1600, 498, 801, 477, 905, 30, 1839, 1327, 1611, 67, 1341, 1932, 4, 1145, 338, 1813, 1091, 1135, 1921, 567, 539, 1237, 1600, 710, 22, 643, 453, 1120, 782, 626, 1799, 155, 300, 1709, 1456, 1490, 167, 136, 605, 1573, 1928, 366, 736, 1514, 1383, 152, 647, 1368, 74, 907, 1149, 1033, 360, 874, 1205, 1698, 1398, 161, 130, 1454, 791, 1872, 1982, 787, 962, 1656, 451, 1303, 1896, 332, 1269, 536, 1787, 1596, 1541, 1229, 614, 1071, 926, 445, 1975, 310, 282, 1373, 1260, 542, 1604, 911, 1304, 1932, 1937, 1788, 26, 431, 484, 1085, 1602, 848, 814, 1638, 848, 1124, 1160, 661, 261, 1552, 1042, 1747, 1853, 1908, 237, 1912, 812, 407, 1896, 1388, 868, 1240, 439, 424, 560, 1777, 770, 1745, 188, 195, 1360, 1212, 1526, 1540, 489, 594, 54, 1653, 44, 895, 1251, 423, 483, 1764, 577, 29, 1763, 931, 891, 1678, 167, 910, 1713, 822, 717, 84, 431, 1313, 1576, 1885, 716, 876, 933, 1108, 703, 543, 1371, 361, 1283, 289, 1799, 614, 1301, 1897, 687, 1053, 1104, 1002, 1636, 923, 876, 301, 1837, 1343, 600, 1947, 1367, 156, 1156, 1473, 75, 1268, 109, 538, 634, 964, 1244, 892, 1501, 1282, 1237, 1979, 406, 441, 1184, 1292, 454, 220, 284, 429, 166, 1609, 1000, 107, 539, 1808, 400, 31, 42, 1140, 1737, 144, 625, 1286, 14, 121, 966, 995, 622, 672, 559, 473, 1087, 1624, 1826, 192, 382, 1781, 818, 1546, 183, 353, 227, 1337, 1377, 809, 1454, 36, 1449, 1671, 1586, 140, 1645, 1652, 656, 1685, 1288, 1226, 336, 1659, 1794, 965, 733, 3, 303, 240, 508, 1146, 1474, 1203, 1102, 1569, 757, 1535, 976, 1542, 1882, 1103, 794, 1879, 1320, 981, 859, 290, 1637, 1545, 1878, 862, 893, 150, 86, 1057, 237, 1967, 145, 593, 1752, 1804, 1643, 40, 1506, 530, 1769, 1214, 80, 1505, 248, 1901, 1794, 1635, 763, 514, 1278, 1013, 728, 863, 1754, 507, 1763, 1386, 1880, 1694, 808, 870, 363, 809, 934, 88, 1586, 1279, 740, 1234, 1018, 1318, 1621, 938, 1934, 1055, 914, 1259, 1348, 203, 1646, 1928, 132, 221, 3, 211, 443, 1214, 41, 1323, 1291, 1802, 438, 1653, 1098, 550, 82, 1441, 748, 1984, 1396, 1604, 3, 1484, 1783, 646, 1863, 1819, 1654, 1247, 760, 1619, 635, 55, 542, 1699, 935, 1415, 1910, 691, 1832, 915, 286, 1483, 555, 1353, 1528, 858, 742, 1206, 446, 1750, 1731, 811, 1106, 1260, 1761, 920, 187, 1083, 1460, 1668, 713, 962, 1216, 406, 1140, 1253, 387, 972, 1467, 1990, 126, 1523, 1484, 75, 1839, 301, 446, 88, 667, 449, 6, 1606, 1992, 1691, 363, 495, 1245, 1380, 503, 1199, 1939, 1855, 1812, 898, 694, 88, 563, 1643, 924, 465, 1307, 546, 1342, 1141, 549, 334, 1696, 1511, 884, 352, 311, 495, 602, 1769, 1138, 1693, 548, 1415, 1126, 1064, 460, 833, 1367, 1185, 1189, 872, 425, 1182, 140, 1743, 150, 402, 383, 923, 1076, 1127, 1007, 677, 1022, 535, 1193, 330, 198, 1641, 1691, 1608, 1298, 1423, 1996, 772, 1834, 168, 973, 1169, 1552, 1760, 319, 1824, 1385, 142, 699, 706, 166, 1675, 575, 1098, 196, 241, 16, 319, 212, 1043, 1297, 774, 711, 844, 1890, 745, 416, 1003, 172, 159, 1987, 1566, 1157, 114, 413, 1603, 1616, 44, 1919, 1972, 1568, 934, 264, 1766, 1442, 523, 449, 509, 1545, 1026, 1716, 1741, 1827, 607, 548, 329, 1223, 210, 512, 950, 673, 339, 864, 718, 756, 1495, 1628, 1836, 1238, 730, 1686, 1783, 1285, 93, 1573, 1152, 497, 1503, 1538, 165, 1256, 778, 186, 902, 23, 1931, 1905, 192, 980, 1945, 1438, 455, 212, 412, 1112, 1082, 1117, 1315, 1325, 1199, 292, 723, 637, 829, 1139, 743, 159, 789, 281, 919, 317, 1240, 1806, 255, 1815, 976, 173, 97, 1966, 1717, 1234, 369, 1994, 154, 1255, 1022, 287, 199, 662, 861, 1208, 1525, 1626, 1499, 1691, 272, 837, 488, 1543, 657, 1913, 1971, 1319, 546, 501, 1561, 1307, 912, 1779, 748, 1938, 1015, 551, 139, 632, 1711, 1105, 828, 1339, 1131, 1046, 749, 726, 1264, 1388, 1681, 379, 189, 1544, 367, 1452, 138, 1605, 347, 1957, 208, 1521, 1951, 804, 239, 73, 1325, 320, 424};
  int c[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0};
  vector<int> aa, bb, cc;
  for( int i = 0 ; i < sizeof(a) / sizeof(a[0] ); ++i )
    {
      aa.push_back(a[i] );
      bb.push_back(b[i] );
      cc.push_back(c[i] );
    }
  DrivingPlans aaa;
  cout << aaa.count( 2000, aa, bb, cc);
 return 0;
}