//
//#include <iostream>
//#include <cstring>
//#include <cstdio>
//#include <algorithm>
////#include"cainiaocangku.cpp"
////#define INF 1000000000
//using namespace std;
////const int MAX_NUM = 1100;
////int map[MAX_NUM][MAX_NUM], Time[MAX_NUM];
////int dist[MAX_NUM], vis[MAX_NUM];
//
//

//
//
//}
//
//
//
//
//
////int dijkstra(int n, int s, int t)
////{
////	for (int i = 0; i<n; i++)
////		dist[i] = map[s][i];
////
////	memset(vis, 0, sizeof(vis));
////	vis[s] = 1;
////	for (int i = 1; i<n; i++)
////	{
////		int mi = INF, k = 0;
////		for (int j = 0; j<n; j++)
////			if (!vis[j])
////			{
////				int edis = dist[j] % (2 * Time[j])<Time[j] ? 0 : 2 * Time[j] - (dist[j] % (2 * Time[j]));
////				if (mi>dist[j] + edis)
////				{
////					mi = dist[j] + edis;
////					k = j;
////				}
////			}
////
////		int edis = dist[k] % (2 * Time[k])<Time[k] ? 0 : 2 * Time[k] - (dist[k] % (2 * Time[k]));
////		vis[k] = 1;
////		for (int j = 0; j<n; j++)
////			if (!vis[j] && dist[j]>dist[k] + edis + map[k][j])
////				dist[j] = dist[k] + edis + map[k][j];
////	}
////	return dist[t];
////}
////
////void init(int n)
////{
////	for (int i = 0; i<n; i++)
////		for (int j = 0; j <= i; j++)
////			if (i != j) map[i][j] = map[j][i] = INF;
////			else map[i][j] = 0;
////}
////
////int main()
////{
////	int n;
////	int m, x, y, dis, s, t;
////	while (cin >> n)
////	{
////		init(n);
////		for (int i = 0; i<n; i++)
////		{
////			scanf("%d,%d", &t, &Time[i]);
////			//cin>>t>>time[i];
////		}
////
////		cin >> m;
////		for (int i = 0; i<m; i++)
////		{
////			scanf("%d,%d,%d", &x, &y, &dis);
////			//cout<<"x:"<<x<<" y:"<<y<<" dis:"<<dis<<endl;
////			//cin>>x>>y>>dis;
////			map[x][y] = map[y][x] = dis;
////		}
////		scanf("%d,%d", &s, &t);
////		//cout<<"s:"<<s<<" t:"<<t<<endl;
////		cout << dijkstra(n, s, t) << endl;
////	}
////	return 0;
////}
//
//
//

