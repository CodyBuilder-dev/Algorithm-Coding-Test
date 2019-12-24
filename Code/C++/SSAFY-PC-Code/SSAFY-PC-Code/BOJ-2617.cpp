//제목 : 구슬 찾기
//목적 : 중간이 될 수 없는 구슬의 개수

/* 아이디어 :
순서는 내가보기에 절대 못구함
2차원 배열을 그리고, 큰거 작은거 구하기
i 보다 작으면 -1, 1보다 크면 1, 모르면 0
1의 개수가 -1이랑 똑같으면 중간 아닐까
1의 개수가 -1보다 크면 앞(정확히는  1의 개수가 (n-1)/2)
-1의 개수가 1보다 크면 뒤...
(매우 어렵고 복잡함)
*/

/* 아이디어2 :트리로 만들면 개 껌인데 ㄹㅇ
1. 트리로 어떻게 갖다 붙이는가?
2. 갖다붙힌후 경우의수 탐색
*/

#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int **graph;
	graph = new int*[N+1];
	for (int i = 0; i < N+1; ++i)
		graph[i] = new int[N+1]();

	int heavy, light;
	for (int i = 1; i <= M; ++i)
	{
		cin >> heavy >> light;
		graph[heavy][light] = 1;
		graph[light][heavy] = -1;
	}
	//아 이거 설마 완전탐색인가
	//빈공간을 1,-1로 채워나가면서 찾는거임 ㅋㅋ
	//그럴때 절대 중간에 있지 않는 것들 빼면 되잖아
	int *middle;
	middle = new int[N + 1];

	int cnt=0, sum_heavy,sum_light;
	for (int i = 0; i < N+1; ++i){
		sum_heavy= sum_light = 0;
		for (int j = 0; j < N + 1; ++j) {
			if (graph[i][j] == 1) sum_heavy++;
			else if (graph[i][j] == -1) sum_light++;
		}
		if (sum_heavy > (N-1)/2 || sum_light > (N-1)/2 ) cnt++;

	}
	cout << cnt;

}