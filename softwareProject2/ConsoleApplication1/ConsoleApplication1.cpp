// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "math.h"
#define M 3;
struct point {
	int x;
	int y;
	int n;
	double r;
}point[M],points[M];
double dist(int point1, int point2)
{
	return sqrt((point[point1].x - point[point2].x)*(point[point1].x - point[point2].x) + (point[point1].y - point[point2].y)*(point[point1].y - point[point2].y));
}
bool boardtest(int i) {
	if (point[i].x < point[i].r || point[i].x + point[i].r>10 || point[i].y < point[i].r || point[i].y + point[i].r>10)
		return false;
	return true;
}
bool disttest(int i, int j) {
	if (dist(i, j) < point[i].r + point[j].r)
		return false;
	return true;

	int main() {
		//设置block坐标为5,5
		point[3].x = 5;
		point[3].y = 5;
		point[3].r = 0;
		for (int i = 0; i < 3; i++) {
			point[i].n = 0;
			point[i].r = 0;
		}
		double s = 0;
		for (point[0].n = 1; point[0].n < 100; point[0].n++) {
			point[0].x = point[0].n % 10;
			point[0].y = (int)point[0].n / 10;
			if (point[0].y == 0)
				point[0].y++;
			if (point[0].n == 50)//不与block重合
				point[0].n++;
			for (point[1].n = point[0].n + 1; point[1].n < 100; point[1].n++) {
				point[1].x = point[1].n % 10;
				point[1].y = (int)point[1].n / 10;
				if (point[1].y == 0)
					point[1].y++;
				if (point[1].n == 50)//不与block重合
					point[1].n++;
				for (point[2].n = point[1].n + 1; point[2].n < 100; point[2].n++) {
					point[2].x = point[2].n % 10;
					point[2].y = (int)point[2].n / 10;
					if (point[2].n == 50)//不与block重合
						point[2].n++;
					printf("%d    %d   %d\n", point[0].n, point[1].n, point[2].n);
					for (point[0].r = 0; boardtest(0); point[0].r += 0.1)
						for (point[1].r = 0; boardtest(1) && disttest(0, 1) && disttest(3, 1); point[1].r += 0.1)
							for (point[2].r = 0; boardtest(2) && disttest(0, 2) && disttest(1, 2) && disttest(2, 3); point[2].r += 0.1)
								if (S() > s) {
									s = S();
									Record();//记录位置
								}
				}

			}
		}
		printf("%lf\n", s);
		printf("点1的位置%d,%d   半径%lf\n", points[0].x, points[0].y, points[0].r);
		printf("点2的位置%d,%d   半径%lf\n", points[1].x, points[1].y, points[1].r);
		printf("点3的位置%d,%d   半径%lf\n", points[2].x, points[2].y, points[2].r);
		getchar();
	}


