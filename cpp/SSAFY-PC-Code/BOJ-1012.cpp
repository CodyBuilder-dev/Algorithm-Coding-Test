//제목 : 유기농 배추
//목적 : 단지 수 세기의 응용문제

/*조건
1. 여러가지 테케를 고려해야 한다
2. 배추가 배열로 주어지지 않고 갯수와 튜플로 주어진다.
*/

/*
아이디어 : DFS를 쓰면 매우 편하다.
*/

/*
디버깅 : 
1.컴파일은 되는데 런타임이뜬다? 메모리 확률 높음
2.시험에서는 프로그램 전체 구조를 고치려 하지 말고, 문제되는 부분만 살짝 꼼수로 바꿔도 괜찮음
3.2차원 배열은 제발 가로세로 확인 똑바로 할 것. 가로길이=/=세로길이 인 경우 for이나 if 똑바로 돌려야 함
4. 처음에 쓸때 조건문을 확실히 코드상에 주석으로 명시하고 코딩할 것
*/

#include <iostream>
#include <algorithm>

using namespace std;

int T;
int M, N, K;

int **farm;
int **visited;

int warm_cnt = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int dfs_check;

void DFS(int y, int x)
{
	/*종료조건
	1. 선 밖으로 나가면 무조건 에러
	2. farm == 1인데 이미 방문한 곳
	3. farm == 0인곳
	*/
	
	if ((x >= M) || (y >= N) || (x < 0) || (y < 0)) return;
	if (farm[y][x] != 1) return;
	if (visited[y][x] != 0) return;

	visited[y][x] = 1;

	for (int ii = 0; ii < 4; ++ii) {
		DFS(y + dy[ii],x + dx[ii]);
	}
	dfs_check = 1;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)//테케 스타트
	{
		cin >> M >> N >> K;


		farm = new int*[N]; //팜 배열 생성
		for (int j = 0; j < N; ++j)
			farm[j] = new int[M]();

		visited = new int*[N]; //방문체크 배열 생성
		for (int j = 0; j < N; ++j)
			visited[j] = new int[M]();

		int tempx, tempy; //농장 배열에 배추 심기
		for (int j = 1; j <= K; ++j) {
			cin >> tempx >> tempy;
				farm[tempy][tempx] = 1;
		}

		/*
		for (int j = 0; j < N; ++j) { //농장 배열 확인
			for (int k = 0; k < M; ++k)
				cout << farm[j][k];
			cout << '\n';
		}
		*/
		
			
				
		
		//여기부터 본격 코딩 시작

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if(farm[j][k] == 1 && visited[j][k]==0){ //조건 진입문이 뭔가 이상함. 조건대로 안 들어감
						DFS(j, k);
						//if(dfs_check == 1)
						warm_cnt += 1;
						dfs_check = 0;
					
				}
			}
		}

		/*
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < M; ++k)
				cout << visited[j][k];
			cout << '\n';
		}
		
		*/

		//여러 테게 돌리므로 메모리 초기화 해줘야 함
		
		for (int j = 0; j < N; ++j)
			delete[] farm[j];
		delete[] farm;

		for (int j = 0; j < N; ++j)
			delete[] visited[j];
		delete[] visited;

		//끝날때마다 벌레 마리수 초기화해줘야 함
		printf("%d\n", warm_cnt);
		warm_cnt = 0;
	}

	return 0;
}

