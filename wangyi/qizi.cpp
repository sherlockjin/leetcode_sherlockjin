#include"common.h"


class Cduiqizi{
public:
	int n;
	int x[50 + 5];
	int y[50 + 5];
	int dis[55];
	int res[55];
	int distance(int x1, int y1, int x2, int y2){
		return abs(x2 - x1) + abs(y2 - y1);
	}
	void qizi(){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> x[i];
		}
		for (int i = 0; i < n; i++){
			cin >> y[i];
		}
		for (int i = 0; i < n; i++){
			res[i] = INT_MAX;
		}
		res[0] = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				for (int k = 0; k < n; k++){
					dis[k] = distance(x[k], y[k], x[i], y[j]);
				}
				sort(dis, dis + n);
				/*for (int i = 0; i < n - 1; i++){
				cout << dis[i] << " ";
				}
				cout << dis[n - 1] << endl;*/
				int tmp = 0;
				for (int k = 0; k < n; k++){
					tmp += dis[k];
					res[k] = min(tmp, res[k]);
				}
			}
		}

		for (int i = 0; i < n - 1; i++){
			cout << res[i] << " ";
		}

		cout << res[n - 1] << endl;

	}

};



