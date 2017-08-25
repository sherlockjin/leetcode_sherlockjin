#include"common.h"

const int MAX_N = 10 + 5;
const int MAX_K = 1e5+5;
const int MOD = 1e9+7;


class Xiaoyilike{
public:
	int n, k;
	int dp[MAX_N][MAX_K];
	void like(){
		cin >> n >> k;
		for (int i = 1; i <= k; i++){
			dp[1][i] = 1;
		}
		for (int i = 1; i <= n; i++){
			dp[i][1] = 1;
		}
		for (int i = 2; i <= n; i++){
			int sum = 0;
			for (int t = 1; t <= k; t++){
				sum = (sum + dp[i - 1][t]) % MOD;
			}
			for (int j = 2; j <= k; j++){
				int invalid = 0;
				for (int t = 2 * j; t <= k; t = t + j){
					invalid = (invalid + dp[i - 1][t]) % MOD;
				}
				dp[i][j] = (sum - invalid + MOD) % (MOD);
			}
		}
		int res = 0;
		for (int i = 1; i <= k; i++){
			res = (res + dp[n][i]) % MOD;
		}
		cout << res << endl;
	}
};


//int main(){
//	Xiaoyilike x;
//	x.like();
//	return 0;
//}