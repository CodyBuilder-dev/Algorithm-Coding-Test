//제목 : 공
//목적 : 컵들을 이리저리 움직인 후, 최종적으로 공이 든 컵의 위치를 구하라
//조건 : 공의 위치는 고정되어 있으므로, 그냥 컵만 바꾸면 됨

/*아이디어 : 컵들은 어차피 1렬배열이고 공의 위치는 1번이므로,
배열 원소들 swap으로 자리바꾸기만 하면 됨
*/

/*구현
1. 배열에 컵 번호 넣기
2. 입력 받아서 컵 번호가 있는 배열 idx찾기
3. 해당 idx위치끼리 swap
*/

#include <iostream>

using namespace std;

int main()
{
	int cups[50];
	int M;
	cin >> M;

	for (int i = 1; i <= 50; ++i)
		cups[i - 1] = i;
	int a, b;
	for (int i = 0; i < M; ++i){
		cin >> a >> b;
		int idxA,idxB;
		for (int j = 0; j < 50; ++j){
			if (cups[j] == a)
				idxA = j;
			if (cups[j] == b)
				idxB = j;
		}
		swap(cups[idxA], cups[idxB]);
	}
	cout << cups[0];

}