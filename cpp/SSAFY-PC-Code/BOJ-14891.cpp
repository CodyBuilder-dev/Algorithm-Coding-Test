//제목 : 톱니바퀴
//목적 : N/S극이 달린 톱니바퀴를 회전시킨 결과를 나타내시오
//조건 : 회전은 최대 100회

/*아이디어 : 
1. 톱니바퀴는 원하는 대로 마음대로 회전가능
2. 1회 회전 후에는, 나머지 톱니바퀴가 따라서 변화
->이때 맞닿은 면의 규칙에 따라 도냐 안도냐 결정
*/

/*구현 :
1. 톱니바퀴는 배열로 주어져 있으니 배열로 받기
->12시 방향이 인덱스 0
2. 1의 3 = 2의 9, 2의 3 = 3의 9...
3. 변화 함수 만들어서 돌리기
->톱니바퀴의 번호와 방향이 들어오면 이에 따라 처리
*/

#include <iostream>
#include <deque>

using namespace std;

deque<int> toppni[4];
bool check[4];
int N;

void input_toppni()
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 8; ++j)
		{
			int temp;
			scanf("%1d", &temp);
			toppni[i].push_back(temp);
		}

	//잘 받아지는거 확인
	//for (int i = 0; i < 4; ++i) {
	//	for (int j = 0; j < 8; ++j)
	//		cout << toppni[i][j];
	//	cout << '\n';
	//}

}
void shift_clock(int i)
{
	int temp;
	temp = toppni[i].back();
	toppni[i].pop_back();
	toppni[i].push_front(temp);
}

void shift_unclock(int i)
{
	int temp;
	temp = toppni[i].front();
	toppni[i].pop_front();
	toppni[i].push_back(temp);
}

void M1(int dir) 
{
	//움직여야 할 대상인지 판단
	check[0] = true;
	if (toppni[0][2] != toppni[1][6])
	{
		check[1] = true; 
		if (toppni[1][2] != toppni[2][6])
		{
			check[2] = true;
			if (toppni[2][2] != toppni[3][6])
				check[3] = true;
		}
	}

	if (dir == 1) //시계방향
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_unclock(i); //true고 2,4번이면
			if (check[i] == true && !(i % 2)) shift_clock(i); //true고 1,3번이면
		}
	}

	else //반시계
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_clock(i);
			if (check[i] == true && !(i % 2)) shift_unclock(i);
		}
	}
}

void M2(int dir)
{
	check[1] = true;
	if (toppni[1][2] != toppni[2][6]) //3번 돌아가는지 확인
	{
		check[2] = true;
		if (toppni[2][2] != toppni[3][6])
		{
			check[3] = true;
		}
	}

	if (toppni[1][6] != toppni[0][2])
		check[0] = true;
	
	if (dir == 1)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && (i % 2)) shift_clock(i); //true고 2,4번이면
			if (check[i] == true && !(i % 2)) shift_unclock(i);  //true고 1,3번이면
		}
	}

	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_unclock(i);
			if (check[i] == true && !(i % 2)) shift_clock(i);
		}
	}
}


void M3(int dir)
{
	check[2] = true;
	if (toppni[2][6] != toppni[1][2]) //2번 돌아가는지 확인
	{
		check[1] = true;
		if (toppni[1][6] != toppni[0][2]) //1번 돌아가는지 확인
		{
			check[0] = true;
		}
	}

	if (toppni[2][2] != toppni[3][6])
		check[3] = true;

	if (dir ==1)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_unclock(i);  //true고 2,4번이면
			if (check[i] == true && !(i % 2)) shift_clock(i); //true고 1,3번이면
		}
	}

	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_clock(i);
			if (check[i] == true && !(i % 2)) shift_unclock(i);
		}
	}
}

void M4(int dir)
{
	check[3] = true;
	if (toppni[3][6] != toppni[2][2])
	{
		check[2] = true;
		if (toppni[2][6] != toppni[1][2])
		{
			check[1] = true;
			if (toppni[1][6] != toppni[0][2])
				check[0] = true;
		}
	}

	if (dir==1)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_clock(i);
			if (check[i] == true && !(i % 2)) shift_unclock(i);
		}
	}

	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_unclock(i);
			if (check[i] == true && !(i % 2)) shift_clock(i);
		}
	}
}

void move_toppni(int num,int dir)
{
	switch (num) {
	case 1: M1(dir); break;
	case 2: M2(dir); break;
	case 3: M3(dir); break;
	case 4: M4(dir); break;
	}
}

void calc_score()
{
	int score = 0;
	if (toppni[0][0] == 1) score += 1;
	if (toppni[1][0] == 1) score += 2;
	if (toppni[2][0] == 1) score += 4;
	if (toppni[3][0] == 1) score += 8;

	cout << score;
}
int main()
{

	input_toppni();
	
	cin >> N;

	for (int i = 0; i < N; ++i) { 
		for (int j = 0; j < 4; ++j) 
			check[j] = false; //매 회전마다 움직임 대상 배열 초기화
		int num, dir;
		cin >> num >> dir;
		move_toppni(num, dir);
	}

	calc_score();
}
