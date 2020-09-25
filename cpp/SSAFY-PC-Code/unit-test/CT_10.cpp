#include <iostream>

using namespace std;

long permutation(int start, int end)
{
	int temp;
	long result=1;

	for (temp = start - end+1; temp <= start; temp++)
		result *= temp;
	return result;
}

long permutation_recur(int start, int end)
{
	int down = start - end;
	//permutaion의 재귀적 속성 이용

	if (start <= 1) return 1;
	if (down <= 0) return start*permutation_recur(start-1,end);
	return start * permutation_recur(start - 1, end) / down;

}
long permutation_brute(int start, int end)
{
	int cnt;
	int result[end];
	for 
}
int main()
{

	cout<<permutation(10,4)<<'\n';
	cout << permutation(10,5) << '\n';
	cout << permutation(10,6) << '\n';

	cout << permutation_recur(10, 4) << '\n';
	cout << permutation_recur(10, 5) << '\n';
	cout << permutation_recur(10, 6) << '\n';

}