#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(int argc, char** argv)
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int D, W, K;
		scanf("%d %d %d", &D, &W, &K);

		int map[25][25];
		for (int i = 1; i <= D; i++)
		{
			for (int k = 1; k <= W; k++)
				scanf("%d", &map[i][k]);
		}

		int turn;
		int t_map[25][25];
		for (turn = 0; turn < K; turn++)
		{
			vector<int> ind;
			for (int i = 1; i <= turn; i++)
				ind.push_back(1);
			for (int i = 1; i <= D - turn; i++)
				ind.push_back(2);

			/*
			for (int i = 0; i < ind.size(); ++i)
				cout << ind[i]; //1의 개수가 주입 개수
			*/

			do
			{
				//맵 복사
				for (int i = 1; i <= D; i++)
				{
					for (int k = 1; k <= W; k++)
						t_map[i][k] = map[i][k];
				}
				//A(0) 약품 투여
				for (int i = 0; i < D; i++)
				{
					if (ind[i] == 1) //i+1 행에 투여
					{
						for (int k = 1; k <= W; k++)
							t_map[i + 1][k] = 0;
					}
				}
				/*for(int i=1 ; i<=D ; i++)
				{
					for(int k=1 ; k<=W ; k++)
						printf("%d ",t_map[i][k]);
					printf("\n");
				}*/
				//성능 검사
				int cnt;
				for (int k = 1; k <= W; k++) //열 검사
				{
					//printf("%d열 => ",k);
					cnt = 1; //연속적인 알파벳 개수
					for (int i = 1; i < D; i++)
					{
						if (t_map[i][k] == t_map[i + 1][k]) cnt++;
						else cnt = 1;

						if (cnt >= K)
							break;
					}
					//printf("%d개 이상 연속\n",cnt);
					if (cnt < K)
						break;
				}
				if (cnt >= K)
					goto A;

				//B(1) 약품 투여
				for (int i = 0; i < D; i++)
				{
					if (ind[i] == 1) //i+1 행에 투여
					{
						for (int k = 1; k <= W; k++)
							t_map[i + 1][k] = 1;
					}
				}
				/*for(int i=1 ; i<=D ; i++)
				{
					for(int k=1 ; k<=W ; k++)
						printf("%d ",t_map[i][k]);
					printf("\n");
				}*/
				//성능 검사
				for (int k = 1; k <= W; k++) //열 검사
				{
					//printf("%d열 => ",k);
					cnt = 1; //연속적인 알파벳 개수
					for (int i = 1; i < D; i++)
					{
						if (t_map[i][k] == t_map[i + 1][k]) cnt++;
						else cnt = 1;

						if (cnt >= K)
							break;
					}
					//printf("%d개 이상 연속\n",cnt);
					if (cnt < K)
						break;
				}
				if (cnt >= K)
					goto A;

			} while (next_permutation(ind.begin(), ind.end()));

		}

	A:
		printf("#%d %d\n", test_case, turn);

	}

	return 0;
}