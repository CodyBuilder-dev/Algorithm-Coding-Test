//제목 : 과제 안 내신 분..?
//목적 : 30명 중 과제를 안 낸 2명의 번호를 찾아내기

/*아이디어 : 그냥 하면 너무 쉬우니 좀 멋있게 구현하기?
1. 에라토스테네스의 체 비슷하게 하기
*/

/*느낀점 : 
1.배열의 맨 끝에 원소 추가하는거 구현하면 좋음
2.만약 B형 공부를 시작한다면, 기존에 라이브러리로 풀었던 이런 문제들 라이브러리 안 쓰고 푸는것부터 다시 해야할 듯
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int numArray[30] = { 0 };
	std::vector<int> notSubmit;
	
	int temp;
	for (int i = 0; i < 28; ++i) {
		std::cin >> temp;
		numArray[temp - 1] = 1;
	}
	
	//배열 맨 끝에 추가하기
	for (int i = 0; i < 30; ++i)
		if (numArray[i] == 0)
			notSubmit.push_back(i + 1);

	std::sort(notSubmit.begin(), notSubmit.end());
	std::cout << notSubmit[0] <<' '<< notSubmit[1];	
}