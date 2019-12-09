//제목 : 체스판 다시 칠하기
//목적 : 이미 칠해져 있는 체스판을 맞게 수정하기
//조건 : 체스판의 최대 크기는 50x50 = 2500,

/*아이디어 : 브루트 포스
1. 어떻게 잘라야 할 지 인간은 알지만 컴퓨터는 모른다.
2. 즉, 모두 다 잘라보고 따지는 수밖에 없다
(8*8로 잘라낸다. 규칙에 맞게 칠해져있으면 pass, 규칙에 안 맞으면 고치기)
3. 고친 개수 세서 기억해둔다
4. 다르게 잘라본다
5/ 모든 경우의 수를 따져본후 최소를 찾는다
*/

/*경우의 수 : M*N이면 자르는 경우의 수는 (M-7)*(N-7)
자르고 나서 칠해보는 경우의 수는 2가지
칠할때 최악의 경우는 32번 칠해야 함
즉 경우의 수는 커봐야 2500*32*2 = 16만번. 해볼만 함
*/

/*구현
1. 체스판의 형태를 보니 2차원배열 쓰는게 맞다.
(자료의 삽입도 안 일어나고 값만 바꾸니까)
*/

/*느낀점 : 
1.scanf를 이용해 다닥다닥 붙어있는 캐릭터를 받으면, 
입력 끝에 지맘대로 줄바꿈 \n들어가 예상치 못한오류 생길 수 있음에 주의
2.정적배열한 배열을 동적 배열 포인터에 할당하는 방법?
->발견 못함
*/

#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
char baseboard[50][50]; //근본 판
char chessboard[8][8]; //잘라낸 판

int minima = 987654;

void input()
{
	cin >> M >> N;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			//scanf("%c", &baseboard[i][j]);  //여기가 문제임
			cin >> baseboard[i][j];
	}
}

int main()
{
	input();

	//baseboard 확인
	/*for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j)
			printf("%c", baseboard[i][j]);
	}*/
	
	//여기서부터 코드 작성

	for (int i = 0; i < M - 7; ++i) {
		for (int j = 0; j < N - 7; ++j){

			for (int k = 0; k < 8; ++k) //배열 베끼기
				for (int l = 0; l < 8; ++l)
					chessboard[k][l] = baseboard[i + k][j + l];
			//for (int k = 0; k < 8; ++k) { //베낀 배열 확인
			//	for (int l = 0; l < 8; ++l)
			//		cout << chessboard[k][l];
			//	cout << '\n';
			//}
				//왼쪽 위부터 B로 칠할때 경우의 수 저장
				int cnt = 0;
				for (int k = 0; k < 8; ++k) {
					for (int l = 0; l < 8; ++l) {
						if ((k + l) % 2 == 0 && chessboard[k][l] == 'W') //짝수인 경우 B로 칠하기
							cnt++;
						else if ((k + l) % 2 == 1 && chessboard[k][l] == 'B')
							cnt++;
					}
				}
				minima = (minima > cnt) ? cnt : minima;

				//왼쪽 위부터 W로 칠할 떄 경우의 수 저장
				cnt = 0;
				for (int k = 0; k < 8; ++k) {
					for (int l = 0; l < 8; ++l) {
						if ((k + l) % 2 == 0 && chessboard[k][l] == 'B') //짝수인 경우 B로 칠하기
							cnt++;
						else if ((k + l) % 2 == 1 && chessboard[k][l] == 'W')
							cnt++;
					}
				}
				minima = (minima > cnt) ? cnt : minima;
		}
	}
	cout << minima;
	
	return 0;

}
