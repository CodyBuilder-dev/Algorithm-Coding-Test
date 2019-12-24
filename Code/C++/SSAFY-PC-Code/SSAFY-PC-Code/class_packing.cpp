#include <iostream>

using namespace std;

int pack(char a, char b, char c. char d)
{
	int p = a;
	p = (p << 8 | b);
	p = (p << 8 | c);
	p = (p << 8 | d);
	return p;

}

char unpack(int p, int k)
{
	int n = k * 8;
	unsigned mask = 255;
	mask <<= n;
	return ((p&mask) >> n);

}

int main() {
		
}