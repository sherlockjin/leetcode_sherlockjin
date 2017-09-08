#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;



const double epsi = 1e-8;
const double pi = acos(-1.0);
const int maxn = 50001;


struct PPoint{
	double x;
	double y;

	PPoint(double x = 0, double y = 0) :x(x), y(y){

	}

	PPoint operator - (const PPoint& op2) const{
		return PPoint(x - op2.x, y - op2.y);
	}

	double operator^(const PPoint &op2)const{
		return x*op2.y - y*op2.x;
	}
};


inline int sign(const double &x){
	if (x > epsi){
		return 1;
	}

	if (x < -epsi){
		return -1;
	}

	return 0;
}

inline double sqr(const double &x){
	return  x*x;
}


inline double mul(const PPoint& p0, const PPoint& p1, const PPoint& p2){
	return (p1 - p0) ^ (p2 - p0);
}


inline double dis2(const PPoint &p0, const PPoint &p1){
	return sqr(p0.x - p1.x) + sqr(p0.y - p1.y);
}

inline double dis(const PPoint& p0, const PPoint& p1){
	return sqrt(dis2(p0, p1));
}

int n;
PPoint p[maxn];
PPoint convex_hull_p0;


inline bool convex_hull_cmp(const PPoint& a, const PPoint& b){
	return sign(mul(convex_hull_p0, a, b)>0) || (sign(mul(convex_hull_p0, a, b)) == 0 && dis2(convex_hull_p0, a) < dis2(convex_hull_p0, b));
}

int convex_hull(PPoint* a, int n, PPoint* b){
	int i;
	for (i = 1; i < n; ++i){
		if (sign(a[i].x - a[0].x) < 0 || (sign(a[i].x - a[0].x) == 0 && sign(a[i].y - a[0].y) < 0)){
			swap(a[i], a[0]);
		}
	}

	convex_hull_p0 = a[0];
	sort(a, a + n, convex_hull_cmp);

	b[0] = a[0];
	b[1] = a[1];
	int newn = 2;
	for (i = 2; i < n; ++i){
		while (newn > 1 && sign(mul(b[newn - 1], b[newn - 2], a[i])) >= 0){
			newn--;
		}

		b[newn++] = a[i];
	}

	return newn;
}



double crossProd(PPoint A, PPoint B, PPoint C) {
	return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}


//int main(){
//	while (scanf("%d", &n) != EOF && n !=0 ){
//		int i;
//		for (i = 0; i < n; ++i){
//			scanf("%lf %lf", &p[i].x, &p[i].y);
//		}
//
//		n = convex_hull(p, n, p);
//		p[n] = p[0];
//		double max_ans = -1;
//		double min_ans = 1e10;
//		int j;
//		int k;
//		for (i = 0; i < n; ++i){
//			for (j = i + 1; j < n; ++j){
//				for (k = j + 1; k < n; ++k){
//					double ans = fabs(crossProd(p[i], p[j], p[k])) / 2;
//
//					if (max_ans < ans){
//						max_ans = ans;
//					}
//					
//					
//					if (min_ans > ans){
//						if (k == n&&ans == 0){
//						}
//						else{
//							min_ans = ans;
//						}
//					}
//					
//					
//				}
//			}
//		}
//
//		printf("%.1lf %.1lf\n",min_ans,max_ans);
//	}
//
//	return 0;
//}



//int dijkstra(int n, int s, int t)
//{
//	for (int i = 0; i<n; i++)
//		dist[i] = map[s][i];
//
//	memset(vis, 0, sizeof(vis));
//	vis[s] = 1;
//	for (int i = 1; i<n; i++)
//	{
//		int mi = INF, k = 0;
//		for (int j = 0; j<n; j++)
//			if (!vis[j])
//			{
//				int edis = dist[j] % (2 * Time[j])<Time[j] ? 0 : 2 * Time[j] - (dist[j] % (2 * Time[j]));
//				if (mi>dist[j] + edis)
//				{
//					mi = dist[j] + edis;
//					k = j;
//				}
//			}
//
//		int edis = dist[k] % (2 * Time[k])<Time[k] ? 0 : 2 * Time[k] - (dist[k] % (2 * Time[k]));
//		vis[k] = 1;
//		for (int j = 0; j<n; j++)
//			if (!vis[j] && dist[j]>dist[k] + edis + map[k][j])
//				dist[j] = dist[k] + edis + map[k][j];
//	}
//	return dist[t];
//}
//
//void init(int n)
//{
//	for (int i = 0; i<n; i++)
//		for (int j = 0; j <= i; j++)
//			if (i != j) map[i][j] = map[j][i] = INF;
//			else map[i][j] = 0;
//}
//
//int main()
//{
//	int n;
//	int m, x, y, dis, s, t;
//	while (cin >> n)
//	{
//		init(n);
//		for (int i = 0; i<n; i++)
//		{
//			scanf("%d,%d", &t, &Time[i]);
//			//cin>>t>>time[i];
//		}
//
//		cin >> m;
//		for (int i = 0; i<m; i++)
//		{
//			scanf("%d,%d,%d", &x, &y, &dis);
//			//cout<<"x:"<<x<<" y:"<<y<<" dis:"<<dis<<endl;
//			//cin>>x>>y>>dis;
//			map[x][y] = map[y][x] = dis;
//		}
//		scanf("%d,%d", &s, &t);
//		//cout<<"s:"<<s<<" t:"<<t<<endl;
//		cout << dijkstra(n, s, t) << endl;
//	}
//	return 0;
//}




