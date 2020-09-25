//제목 : 보호 필름
//목적 : 보호 필름이 주어질 때, 약품을 이용하여 성능검사를 통과하고 최소 약품 주입수를 계산하라
//조건 : 가로로 W, 세로로 D , 성능검사 K. 필름은 최대 20*13

/*아이디어 : 행을 선택하여 주입 후 완전탐색
행을 선택하는 경우의 수는 조합
조합도 2개,3개,4개...로 올라감
*/

/*구현
1. 필름은 2차원배열로 구현
2. 주입수 2부터 시작해서 열을 검사
3. 검사는 A가 발견될 경우, 같은게 나오면 ++ 다른게 나오면 0
4. 주입수가 부족할 경우 주입수 증가 및 재검사
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int **savedfilm;
int **film; //동적할당. 추후에 문제되면 정적할당 변경

int T;
int D, W, K;

vector<int> rowSelected;
int *rowidx;
int *colpassed;


int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cin >> D >> W >> K;
		savedfilm = new int*[D];
		film = new int*[D];
		for (int j = 0; j < D; ++j) {
			savedfilm[j] = new int[W];
			film[j] = new int[W];
		}
			
		
		colpassed = new int[W];
		rowidx = new int[D];

		for (int j = 0; j < D; ++j)
			for (int k = 0; k < W; ++k)
				cin >> savedfilm[j][k];

		//필름 잘 들어왔나 확인
		/*for (int j = 0; j < D; ++j)
			for (int k = 0; k < W; ++k)
				cout << film[j][k];
		*/
		//여기서부터 본격적인 코드 작성

		for (int j = 0; j < D; ++j)
			for (int k = 0; k < W; ++k)
				film[j][k] = savedfilm[j][k];

		//우선 약물주입 없이 통과되나 검사
		int rowNum = 0;
		int minima = 987654;
		for (int k = 0; k < W; ++k)
			for (int j = 0; j < D; ++j)
			{
				if (film[j][k] == 0)
				{
					int cnt = 0;
					for (int l = 0; l < K; ++l)
					{
						if (j + l > D - 1) break;
						if (film[j + l][k] != 0) break;
						else cnt++;
					}
					if (cnt == K) {
						colpassed[k] = 1;
						break;
					}
				}
				else {
					int cnt = 0;
					for (int l = 0; l < K; ++l)
					{
						if (j + l > D - 1) break;
						else if (film[j + l][k] != 1) break;
						else cnt++;
					}
					if (cnt == K) {
						colpassed[k] = 1;
						break;
					}
				}
			}

	
		//검사통과시 탈출
		if (count(colpassed, colpassed + W, 1) == W) {
			minima = (rowNum < minima) ? rowNum : minima;
			printf("#%d %d\n", i, minima);
			
			delete[] colpassed;
			delete[] rowidx;

			for (int j = 0; j < D; ++j) {
				delete[] savedfilm[j];
				delete[] film[j];
			}

			delete[] savedfilm;
			delete[] film;
			continue;
		}
		
		//약물주입 및 테스트
		rowNum = 1;
		while (rowNum <= K) //rowNum 1부터 시작. num초과까지 반복
		{
			if (rowNum == K) {
				minima = rowNum;
				break;
			}
			//조합 배열 생성
			for (int j = 0; j < D - rowNum; ++j)
				rowidx[j] = 0;
			for (int j = D-rowNum; j < D; ++j)
				rowidx[j] = 1;
			
	
			do {
				for (int j = 0; j < D; ++j)
					for (int k = 0; k < W; ++k)
						film[j][k] = savedfilm[j][k];

				/*cout << "rowidx =";
				for (int j = 0; j < D; ++j)
					cout << rowidx[j] << ' ';
				cout << '\n';
				*/
				//row정보 초기화
				rowSelected.clear();
				for (int j = 0; j < D; ++j)
					if (rowidx[j] == 1) rowSelected.push_back(j);
								
				//A 약물주입
				for (int j = 0; j < W; ++j)
					colpassed[j] = 0;

				for (int j = 0; j < rowSelected.size(); ++j)
					for (int k = 0; k < W; ++k)
						film[rowSelected[j]][k] = 0;
				//검사
				for (int k = 0; k < W; ++k)
					for (int j = 0; j < D; ++j)
					{
						if (film[j][k] == 0)
						{
							int cnt = 0;
							for (int l = 0; l < K; ++l)
							{
								if (j + l > D - 1) break;
								if (film[j + l][k] != 0) break;
								else cnt++;
							}
							if (cnt == K) {
								colpassed[k] = 1;
								break;
							}
						}
						else {
							int cnt = 0;
							for (int l = 0; l < K; ++l)
							{
								if (j + l > D - 1) break;
								else if (film[j + l][k] != 1) break;
								else cnt++;
							}
							if (cnt == K) {
								colpassed[k] = 1;
								break;
							}
						}
					}
			
				//검사통과시 탈출
				if (count(colpassed, colpassed + W, 1) == W){
					minima = (rowNum < minima) ? rowNum : minima;
					break;
				}
				
				//B 약물주입
				for (int j = 0; j < W; ++j)
					colpassed[j] = 0;
				
				for (int j = 0; j < rowSelected.size(); ++j)
					for (int k = 0; k < W; ++k)
						film[rowSelected[j]][k] = 1;
				
				//검사
				for (int k = 0; k < W; ++k)
					for (int j = 0; j < D; ++j)
					{
						if (film[j][k] == 0)
						{
							int cnt = 0;
							for (int l = 0; l < K; ++l)
							{
								if (j + l > D - 1) break;
								if (film[j + l][k] != 0) break;
								else cnt++;
							}
								
							if (cnt == K) {
								colpassed[k] = 1;
								break;
							}
						}
						else {
							int cnt = 0;
							for (int l = 0; l < K; ++l)
							{
								if (j + l > D - 1) break;
								if (film[j + l][k] != 1) break;
								else cnt++;
							}
							if (cnt == K) {
								colpassed[k] = 1;
								break;
							}
						}
					}
			
				//검사통과시 탈출
				if (count(colpassed, colpassed + W, 1) == W) {
					minima = (rowNum < minima) ? rowNum : minima;
					break;
				}
	
			} while (next_permutation(rowidx, rowidx+D));
		
			if (minima != 987654) break;
			rowNum++;

		}

		printf("#%d %d\n", i, minima);
		delete[] colpassed;
		delete[] rowidx;

		for (int j = 0; j < D; ++j) {
			delete[] savedfilm[j];
			delete[] film[j];
		}
		
		delete[] savedfilm;
		delete[] film;


	}
	return 0;
}
