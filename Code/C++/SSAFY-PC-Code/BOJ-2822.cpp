//제목 : 점수 계산
//목적 : 여러개의 정수가 들어올 때, 가장 높은 수 5개를 뽑아 더해라(즉, 정렬을 쓸줄 아는가)

/*아이디어 : 그냥 정렬 쓰면 재미없으니, 무식하게 풀어보자
1. 5개짜리 배열 생성
2. 값이 들어오면 최소값이랑 비교해서 배열에서 최소값 빼고 넣기
3. 마지막에 배열 출력
*/

//느낀점 : 정렬을 직접 구현하긴 어렵다. 
typedef struct {
	int score;
	int num;
}QUEST;

#include <iostream>
//#include <algorithm>
using namespace std;

int main()
{
	QUEST maximum[5] = { 0 };
	QUEST sorted[5] = { 0 };

	int minimum = 0;
	int minidx = 0;

	QUEST temp;
	for (int i = 0; i < 8; ++i) {
		cin >> temp.score;
		temp.num = i+1;
		
		if (temp.score > minimum) maximum[minidx] = temp;

		minimum = maximum[0].score;
		for (int j = 0; j < 5; ++j)
			if (minimum > maximum[j].score) {minimum = maximum[j].score; minidx = j;}

	}

	for (int i = 0; i < 4; ++i)
		if (maximum[i].score > maximum[i + 1].score)
			for (int j = i + 1; j > 0; --j)
				while (maximum[j].score < maximum[j - 1].score) swap(maximum[j], maximum[j - 1]);
	
	int sum = 0;
	for (int i = 0; i < 5; ++i)
		sum += maximum[i].score;
	cout << sum << '\n';
	for (int i = 0; i < 5; ++i)
		cout << maximum[i].num << ' ';
}