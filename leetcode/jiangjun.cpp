#include <iostream>  
#include <vector>  
#include <numeric>  
#include <limits> 
#include <math.h>

using namespace std;

class Jiangjun{
	struct Point {      // 定义点类型  
		double x, y;
		Point(double x1 = 0, double y1 = 0) :x(x1), y(y1) {}
	};
	
	Point castleHelp(Point p1, Point p2, Point p3) {    // 输入3点,输出位置和夹角  
		Point ret;
		p2.x -= p1.x;
		p2.y -= p1.y;
		p3.x -= p1.x;
		p3.y -= p1.y;
		ret.x = p2.x * p3.y - p3.x * p2.y;
		ret.y = acos((p2.x * p3.x + p2.y * p3.y) / sqrt((p2.x * p2.x + p2.y * p2.y) * (p3.x * p3.x + p3.y * p3.y)));
		return ret;
	}

	int castle(vector<Point> points) {
		int ret(0), vl(points.size());
		if (vl < 4) return 0;
		for (int k1(0); k1 < vl; ++k1)
		for (int k2(0); k2 < vl; ++k2) {
			if (k1 == k2) continue;
			int n1(0), n2(0), n0(2);
			double theta1(0), theta2(0);
			for (int k3(0); k3 < vl; ++k3) {
				if (k3 == k2 || k3 == k1) continue;
				auto p(castleHelp(points[k1], points[k2], points[k3]));
				if (p.y < 1e-9) ++n0;            // 在射线AB上  
				else {
					if (p.x > 0) ++n1, theta1 = theta1 < p.y ? p.y : theta1;      // 在直线一侧  
					else if (0 < p.x) ++n2, theta2 = theta2 < p.y ? p.y : theta2;  // 在直线另一侧  
				}
			}
			if (acos(-1) < theta1 + theta2) {                    // 判断是否则为凸焦点  
				n1 = n1 < n2 ? n2 + n0 : n1 + n0;
				ret = ret < n1 ? n1 : ret;
			}
		}
		return ret;
	}

	int test() {
		int points_size(0);
		//cout << "请输入点的个数:";
		cin >> points_size;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		vector<Point> points;
		Point points_item;
		//cout << "请依次输入点的坐标: x y" << endl;
		for (int points_i(0); points_i < points_size / 2; ++points_i) {
			cin >> points_item.x >> points_item.y;
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			points.push_back(points_item);
		}
		cout << castle(points) << endl;

		return 0;

	}
};
 //测试用例
/**
10
1
1
-1
1
-1
-1
1
-1
0
0
*/