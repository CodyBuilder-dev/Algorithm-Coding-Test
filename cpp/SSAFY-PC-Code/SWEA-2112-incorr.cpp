//���� : ��ȣ �ʸ�
//���� : ��ȣ �ʸ��� �־��� ��, ��ǰ�� �̿��Ͽ� ���ɰ˻縦 ����ϰ� �ּ� ��ǰ ���Լ��� ����϶�
//���� : ���η� W, ���η� D , ���ɰ˻� K. �ʸ��� �ִ� 20*13

/*���̵�� : ���� �����Ͽ� ���� �� ����Ž��
���� �����ϴ� ����� ���� ����
���յ� 2��,3��,4��...�� �ö�
*/

/*����
1. �ʸ��� 2�����迭�� ����
2. ���Լ� 2���� �����ؼ� ���� �˻�
3. �˻�� A�� �߰ߵ� ���, ������ ������ ++ �ٸ��� ������ 0
4. ���Լ��� ������ ��� ���Լ� ���� �� ��˻�
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int **savedfilm;
int **film; //�����Ҵ�. ���Ŀ� �����Ǹ� �����Ҵ� ����

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

		//�ʸ� �� ���Գ� Ȯ��
		/*for (int j = 0; j < D; ++j)
			for (int k = 0; k < W; ++k)
				cout << film[j][k];
		*/
		//���⼭���� �������� �ڵ� �ۼ�

		for (int j = 0; j < D; ++j)
			for (int k = 0; k < W; ++k)
				film[j][k] = savedfilm[j][k];

		//�켱 �๰���� ���� ����ǳ� �˻�
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

	
		//�˻������ Ż��
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
		
		//�๰���� �� �׽�Ʈ
		rowNum = 1;
		while (rowNum <= K) //rowNum 1���� ����. num�ʰ����� �ݺ�
		{
			if (rowNum == K) {
				minima = rowNum;
				break;
			}
			//���� �迭 ����
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
				//row���� �ʱ�ȭ
				rowSelected.clear();
				for (int j = 0; j < D; ++j)
					if (rowidx[j] == 1) rowSelected.push_back(j);
								
				//A �๰����
				for (int j = 0; j < W; ++j)
					colpassed[j] = 0;

				for (int j = 0; j < rowSelected.size(); ++j)
					for (int k = 0; k < W; ++k)
						film[rowSelected[j]][k] = 0;
				//�˻�
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
			
				//�˻������ Ż��
				if (count(colpassed, colpassed + W, 1) == W){
					minima = (rowNum < minima) ? rowNum : minima;
					break;
				}
				
				//B �๰����
				for (int j = 0; j < W; ++j)
					colpassed[j] = 0;
				
				for (int j = 0; j < rowSelected.size(); ++j)
					for (int k = 0; k < W; ++k)
						film[rowSelected[j]][k] = 1;
				
				//�˻�
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
			
				//�˻������ Ż��
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
