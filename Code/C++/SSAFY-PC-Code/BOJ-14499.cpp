//제목 : 주사위 굴리기
//목적 : 주사위의 전개도가 주어졌을 때, 주사위 굴려보기
//조건 : 지도의 크기는 최대 20x20 명령 최대 1000개

/*아이디어 : 우선 주사위를 구현하고, 주사위 이동을 구현하고, 이동후 값 판단 및 변경을 구현한다.
1. 주사위 구현 : 그냥 1차원 배열 or 벡터
2. 이동 구현 : 상하좌우 4방향이므로, 각 방향별 주사위 면 변화 구현
->배열을 직접 swap하기
->배열을 직접 움직이지 말고, 바닥면 포인터를 이동시키자
3. 값 판단 : 윗면/아랫면 관계 파악및 구현
->바닥면 포인터에 따른 현재 바닥면 값과 지도 값 관계
*/

//느낀점 : 주사위의 규칙을 '하드코딩' 해야할 필요도 있을수 있음

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, y, x, K;
int board[20][20];
int dice[6];
int* bottomPointer;

//동 서 북 남 순
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
//주사위 움직임 함수
//모든 경우의수를 다 따져보는 수밖에 없음
// 0 1 2 3 4 5
// 1 3 5 6 4 2라고 두고 dice[0]이 윗면, dice[1]이 동쪽, dice[2]가 남쪽으로 하자
//동쪽으로 가면, 현재 윗면은 동쪽이 되고, +1이 바닥면이 되고 +1+3이 윗면이 된다.
//즉 0->1 1->3 3->4 4->0  
//서쪽 = 현재 윗면은 서쪽, +1이 윗면, +4가 바닥면
// 즉 0->4 4->3 3->1 1->0  

//북쪽 = 현재 윗면은 북, 현재 남쪽은 윗
//즉 0->5 5->3 3->2 2->0 

//남쪽 = 현재 윗면은 남, 현재 북쪽은 윗
// 0->2 2->3 3->5 5->0 

//결국 순차 swap 통해 구현
/*
3번의 swap으로 해결가능

0 2 3 5
2 0 3 5(02)
3 0 2 5(03)
5 0 2 3(05)

*/

void dice_move(int dir)
{
	switch (dir)
	{
	case 1: //동
		swap(dice[0], dice[1]);
		swap(dice[0], dice[3]);
		swap(dice[0], dice[4]);
		return;
	case 2: //서
		swap(dice[0], dice[4]);
		swap(dice[0], dice[3]);
		swap(dice[0], dice[1]);
		return;
	case 3: //북
		swap(dice[0], dice[5]);
		swap(dice[0], dice[3]);
		swap(dice[0], dice[2]);
		return;
	case 4: //남
		swap(dice[0], dice[2]);
		swap(dice[0], dice[3]);
		swap(dice[0], dice[5]);
		return;
	}
}

/*새로 만든 주사위 이동 함수
주사위의 1을 0번, 3을 1번, 5를 2번이라 하면 6은 3번, 4는 4번 2는 5번
0 1 2 3 4 5
처음 포인터는 3번
동쪽으로 굴리면 윗면의 오른쪽이 바닥이 되므로 -3+1
서쪽으로 굴리면 윗면의 왼쪽이 바닥이 되므로 -3+4
남쪽으로 굴리면 윗면의 남쪽이 바닥이 되므로 -3+2
북쪽으로 굴리면 윗면의 -3+5
서쪽으로 굴리면 
*/
//void dice_move(int dir)
//{
//	switch (dir)
//	{
//	case 1: //동쪽
//
//	case 2: //
//	case 3:
//	case 4:
//
//	}
//}

//면 체크 함수
//dice[3]이 아랫면이므로 그 부분 파악해서 비교 및 대입
void dice_write(int y, int x)
{
	if (board[y][x] == 0)//비교
		board[y][x] = dice[3];
	else{
		dice[3] = board[y][x];
		board[y][x] = 0;
	}
}

int main()
{

	cin >> N >> M >> y >> x >> K;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	for (int i = 0; i < K; ++i)
	{
		int dir;
		cin >> dir;
		int ny = y + dy[dir - 1];
		int nx = x + dx[dir - 1];
		if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
			y = ny; x = nx;
			dice_move(dir);
			dice_write(ny,nx);
			cout << dice[0] << '\n';
		}
	}


	//주사위 구현
	//주사위는 각 마주보는 면이 2칸씩 뛰도록
	//주사위는 맨 아랫면을 i로 하고, i>=3이면 -2, i<3이면 +2가 반대면

}