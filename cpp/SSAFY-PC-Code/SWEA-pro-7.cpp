#include <iostream>

using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

//�������� 2�� �ð�/�ݽð�
int ccw(Point p, Point q)
{
	return p.x*q.y - p.y*q.x;
}

//�����ε� �̿� 3�� �ð�/�ݽð�
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