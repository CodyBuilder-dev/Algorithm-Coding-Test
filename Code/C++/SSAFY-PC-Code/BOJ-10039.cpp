//제목 : 평균 점수
//목적 : 학생 5명의 평균점수를 구하라. 즉 C++에서 평균을 구할 줄 아는가

/*아이디어 : 그냥 배열+for문으로 구하면 재미없으니, 함수를 찾아보자
accumulate는 있으니, 이것과 vector size를 이용해서 구현
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> score;
	int temp;
	for (int i = 0; i < 5; ++i)
	{
		cin >> temp;
		if (temp < 40) temp = 40;
		score.push_back(temp);
	}

	
	int mean = accumulate(score.begin(), score.end(),0) / score.size();

	cout << mean;
}
