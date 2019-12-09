//제목 : 결혼식
//목적 : 친구 리스트를 읽고 이로부터 결혼식에 초대할 사람의 수를 구하는 프로그램
//조건 : 친구는 최대 500명, 리스트는 최대 10000줄

/*아이디어 : 그래프를 탐색하다가, 조건에 맞춰서 끊을 수 있는가...
(친구 관계를 일종의 인접행렬로 구할 수 있음)
2. 자신의 친구 = 인접행렬에서 자기한테 연결된 친구
3. 친구의 친구 = 한칸만 건너는 경우
*/

//느낀점 : 복잡한 탐색인줄 알았는데, 한 단계만 볼 거면 단순 2중 for문으로 탐색 가능

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool chingu[500][500];
bool checked[500];


int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		
		chingu[a-1][b-1] = true;
		chingu[b-1][a-1] = true;
	}

	//여기서부터 코딩 시작

	for (int i = 1; i < N; ++i) //친구의 친구를 탐색
	{
		if (chingu[0][i] == true)
		{
			checked[i] = true;
			for (int j = 1; j < N; ++j) {
				if (chingu[i][j] == true) checked[j] = true;
			}
		}
	}

	cout << count(checked, checked + N, true);

}