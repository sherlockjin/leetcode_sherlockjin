//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<iterator>
//#include<map>
//#include<vector>
//#include<stack>
//#include<queue>
//#include<string>
//using namespace std;
//
//
//const int K = 1005;
//int a[K][8];
//class cmp{
//	bool operator() (pair<int, int> pa, pair<int, int> pb){
//		long long va = 0, vb = 0, v;
//		v = 1;
//		for (int i = 0; i < 8; i++) {
//			va += v * a[pa.first][i];
//			v *= pa.second;
//		}
//		v = 1;
//		for (int i = 0; i<8; i++) {
//			vb += v * a[pb.first][i];
//			v *= pb.second;
//		}
//		return va > vb;
//	}
//};
//priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
//
//int main() {
//	int n, k;
//	cin >> k;
//	for (int i = 0; i < k; i++) {
//		for (int j = 7; j >= 0; j--)
//			cin >> a[i][j];
//	}
//	cin >> n;
//
//	for (int i = 0; i < k; i++) {
//		heap.push(make_pair(i, 1));
//	}
//
//	long long ans = 0;
//	pair<int, int> temp;
//	long long value, v;
//	while (n--) {
//		temp = heap.top();
//		heap.pop();
//		v = 1; 
//		value = 0;
//		for (int i = 0; i<8; i++) {
//			value += v * a[temp.first][i];
//			v *= temp.second;
//		}
//		ans = value;
//		heap.push(make_pair(temp.first, temp.second + 1));
//	}
//	printf("%lld\n", ans);
//
//	return 0;
//}
