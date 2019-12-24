#include <iostream>

using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

//원점기준 2점 시계/반시계
int ccw(Point p, Point q)
{
	return p.x*q.y - p.y*q.x;
}

//오버로딩 이용 3점 시계/반시계
int ccw(Point r, Point p, Point q)
{
	return ccw(p - r, q - r);
}


int main()
{
	Point p = { 1,2 };
	Point q = { 4,8 };

	cout << ccw(p, q);
}