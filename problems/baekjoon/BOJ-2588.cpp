//제목 : 곱셈
//목적 : 세자리수의 곱셈을 자리별로 수행하라

/*아이디어 : 숫자를 한자리씩 받아서 배열에 저장
(입출력을 얼마나 자유자재로 받을 줄 아느냐)
10의 승수를 사용
*/

#include <iostream>
#include <cmath>
using namespace std;

int first[3];
int second[3];
int mult[3];
int main()
{
	scanf("%1d%1d%1d", &first[2], &first[1], &first[0]);

	scanf("%1d%1d%1d", &second[2], &second[1], &second[0]);

	
	for (int j = 0; j < 3; ++j) {//second 번지수
		for (int k = 0; k < 3; ++k) //first 번지수
			mult[j] += first[k] * pow(10, k) * second[j];

		cout << mult[j] << '\n';
	}
	int sum = 0;

	for (int i = 2; i >= 0; --i) {//총 자릿수	
		sum += mult[i] * pow(10, i);
	}
	cout << sum;
}
