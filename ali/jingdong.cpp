#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int res = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= n; l++){
					if (fabs(pow(i, j) - pow(k, l))<1e-5)
					{
						res = (res + 1) % 1000000007;
					}
				}
			}
		}
	}
	cout << res << endl;
	return 0;

}