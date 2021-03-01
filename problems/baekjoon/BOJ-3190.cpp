//제목 : 뱀
//목적 : 시뮬레이션 문제를 해결할 수 있는가?

/*아이디어 : N이 100까지이므로, 칸은 10000칸. 좀 큰데
브루트 포스로 완전탐색 해도 되나?
방향 변환 횟수가 100인데, 그럼 4^100이므로 경우가 너무 많으므로
브루트포스는 안된다. 백트래킹?

아 이게 굳이 처음부터 모든 경우의 수를 할 필요가 없이
그냥 명령을 그때 그때 받으면서 진행하면 되네
*/

/*자료구조
판 : 2차원 배열 0
사과 : 2차원배열 원소 1
뱀 신체와 벽  : -1
명령 : 한번에 큐에 받아서 하나씩 빼거나, 그냥 그때그때 변수에 받거나
*/

/*알고리즘 
for
	cin >> 2개 받기
	해당 경로 진행가능 여부 판단
	진행가능시 사과 여부 판단.
	최종적으로 모든 결과를 포함한 배열 반환
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, K, L; //초기 조건
	
	cin >> N;
	
	//사과 위치 받기

	int apl_x[100] = { 0 };
	int apl_y[100] = { 0 };

	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		cin >> apl_x[i] >> apl_y[i];
		
	}
	
	/*
	for (int i = 0; i < K; ++i)
	{
		cout << apl_x[i] <<','<< apl_y[i];

	}
	*/

	int time = 0; //게임 시간
	int X; //명령 초
	char C; //명령 방향
	int dir = 1; //동1 남2 서3 북4
	
	//이건 뱀 객체를 따로 만들어야겠네
	//뱀 몸통 객체, index는 뱀 몸통 위치, 값은 xy좌표값
	//0이 머리, length-1는 꼬리
	int snake_x[100] = { 0 };
	int snake_y[100] = { 0 };
	int length = 1;
		
	//머리 처음 위치는 1행 1열
	snake_x[length-1] = 1; snake_y[length-1] = 1;
	
	//이동 횟수 받기. 큐에 넣는게 나을수도 있네
	cin >> L;

	for (int i = 1; i <= L; ++i)
	{
		cin >> X >> C;
		while(time<X)
		{
			time++;
			switch (dir)
			{
			case 1: //동쪽인 경우
				if (snake_x[0] >= N) goto endgame; //벽 충돌

				for (int k = 0; k < length; ++k) //자기몸 충돌
					if ((snake_x[0] + 1 == snake_x[k])
						&& (snake_y[0] == snake_y[k])) goto endgame;

				for (int k = 0; k < K; ++k) {
					if (snake_x[0] + 1 == apl_x[k] //사과 먹기
						&& snake_y[0] == apl_y[k]) {

						length++;

					}
				}

				for (int k = length-1; k > 0 ; --k) {
					snake_x[k] = snake_x[k - 1];
					snake_y[k] = snake_y[k - 1];
				}
					snake_x[0]++;
		
				break;
			case 2: //남쪽인 경우
				if(snake_y[0] >= N) goto endgame; //벽 충돌

				for (int k = 0; k < length; ++k) //자기몸 충돌
					if (snake_x[0] == snake_x[k]
						&& snake_y[0]+1 == snake_y[k]) goto endgame;
				
				for (int k = 0; k < K; ++k) {
					if (snake_x[0]  == apl_x[k] //사과 먹기
						&& snake_y[0] + 1 == apl_y[k]) {
						length++;

					}
				}
		
					for (int k = length - 1; k > 0; --k) {
						snake_x[k] = snake_x[k - 1];
						snake_y[k] = snake_y[k - 1];
					}
					snake_y[0]++;
			
				break;
			case 3: //서쪽인 경우
				if (snake_x[0] <= 1) goto endgame; //벽 충돌

				for (int k = 0; k < length; ++k) //자기몸 충돌
					if ((snake_x[0]-1 == snake_x[k])
						&& (snake_y[0] == snake_y[k])) goto endgame;
				for (int k = 0; k < K; ++k) {
					if (snake_x[0] - 1 == apl_x[k] //사과 먹기
						&& snake_y[0] == apl_y[k]) {
	
						length++;
	
					}
				}
			
					for (int k = length - 1; k > 0; --k) {
						snake_x[k] = snake_x[k - 1];
						snake_y[k] = snake_y[k - 1];
					}
					snake_x[0]--;
	
				break;
			case 4: //북쪽인 경우
				if (snake_y[0] <= 1) goto endgame; //벽 충돌

				for (int k = 0; k < length; ++k) //자기몸 충돌
					if ((snake_x[0] == snake_x[k])
						&& (snake_y[0]-1 == snake_y[k])) goto endgame;

				for (int k = 0; k < K; ++k) {
					if (snake_x[0] == apl_x[k] //사과 먹기
						&& snake_y[0] -1 == apl_y[k]) {

						length++;

					}
				}

					for (int k = length - 1; k > 0; --k) {
						snake_x[k] = snake_x[k - 1];
						snake_y[k] = snake_y[k - 1];
					}
					snake_y[0]--;

				break;
			}
		
		}
		if (C == 'D')
		{
			if (dir == 3) dir = 4;
			else dir = (dir + 1) % 4; 
		}
		else
		{
			if (dir == 1) dir = 5;
			dir--;
		}

	}

endgame:
	cout << time;
	return 0;

}