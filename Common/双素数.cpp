#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<string>

using namespace std;

const int N = 1e6 + 10;

bool visul[N];
int priori[N], cnt, tag[N];
void getPrime(){
	int i, j;
	memset(visul, 0, sizeof(visul));
	memset(tag, 0, sizeof(tag));
	cnt = 0;
	visul[0] = visul[1] = 1;
	for (i = 2; i<N; i++){
		if (!visul[i]) {   
			priori[cnt++] = i;
			tag[i] = true;
		}
		for (j = 0; j<cnt && i*priori[j]<N; j++){
			visul[i*priori[j]] = true;
			if (i%priori[j] == 0) {
				break;
			}
		}
	}
	return;
}


bool check(int x){
	char s[11];
	sprintf(s, "%d", x);
	int len = strlen(s), t;
	for (int i = 0; i<len / 2; i++) {
		swap(s[i], s[len - 1 - i]);
	}
	sscanf(s, "%d", &t);
	if (x != t && tag[t]) return true;
	return false;
}



//int main() {
//
//	cnt = 0;
//	getPrime();
//	int k;
//	cin >> k;
//	int ans = -1, idx = 0;
//	for (int i = 0; i<cnt; i++) {
//		int p = priori[i];
//		if (p>1000000) break;
//		if (check(p)) {
//			idx++;
//		}
//		if (idx == k) {
//			ans = p;
//			break;
//		}
//	}
//	cout << ans << endl;
//
//	return 0;
//}
