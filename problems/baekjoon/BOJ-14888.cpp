//제목 : 연산자 끼워넣기
/*목적 : N개 숫자 사이에 N-1개 연산자를 끼워넣은 후,  그 식의 결과를 계산하여 최대값 찾기
(중복 허용되고, 갯수 제한이 있는 연산자들을 N-1개 나열할 줄 아는가.)
*/
//조건 : N<=11, 연산결과, 중간결과의 최대최소는 +- 10억이므로 int 가능

/*아이디어
1. + - * /의 개수가 정해져 있다.
2. 즉 총합쳐서 N-1개를 잘 나열하는 경우의 수를 구하면 된다.
(같은 것이 있는 경우의 순열. N-1!/+!-!*!/!)
(갯수는 구하기 쉬운데 
3. 각 경우별로 연산수행 함수를 만들어 구현한다.
4. 최소값, 최대값과 비교해가며 계산한다.
*/

/*느낀 점 :
1.같은것이 있는 경우의 수는 next_permutation으로 가능
2.vector의 iterator을 쓰는 법을 익혀야 함
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> num;
	vector<char> operation;
	
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		num.push_back(temp);
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> temp;
		for (int j = 0;j<temp;++j)
			switch (i) {
			case 0: operation.push_back('+'); break;
			case 1: operation.push_back('-'); break;
			case 2: operation.push_back('*'); break;
			case 3: operation.push_back('/'); break;
			}
	}

	sort(operation.begin(), operation.end());

	/*연산자 잘 받았나 확인
	for (int i = 0; i < operation.size(); ++i)
		cout << operation[i];
	*/

	//여기서부터 본격적 코딩
	
	int total;
	int min = 1000000000;
	int max = -1000000000;
	do
	{
		int idx = 0; //이터레이터를 몰라서 idx씀
		total = num[idx];
		while (idx < N-1)
		{
			char op = operation[idx];
			switch (op) {
			case '+': total += num[idx + 1]; break;
			case '-': total -= num[idx + 1]; break;
			case '*': total *= num[idx + 1]; break;
			case '/': total /= num[idx + 1]; break;
			}
			idx++;
		}
		if (min > total) min = total;
		if (max < total) max = total;

	} while (next_permutation(operation.begin(), operation.end()));

	cout << max << '\n' << min;
	
	return  0;
}