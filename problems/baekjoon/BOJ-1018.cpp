//���� : ü���� �ٽ� ĥ�ϱ�
//���� : �̹� ĥ���� �ִ� ü������ �°� �����ϱ�
//���� : ü������ �ִ� ũ��� 50x50 = 2500,

/*���̵�� : ���Ʈ ����
1. ��� �߶�� �� �� �ΰ��� ������ ��ǻ�ʹ� �𸥴�.
2. ��, ��� �� �߶󺸰� ������ ���ۿ� ����
(8*8�� �߶󳽴�. ��Ģ�� �°� ĥ���������� pass, ��Ģ�� �� ������ ��ġ��)
3. ��ģ ���� ���� ����صд�
4. �ٸ��� �߶󺻴�
5/ ��� ����� ���� �������� �ּҸ� ã�´�
*/

/*����� �� : M*N�̸� �ڸ��� ����� ���� (M-7)*(N-7)
�ڸ��� ���� ĥ�غ��� ����� ���� 2����
ĥ�Ҷ� �־��� ���� 32�� ĥ�ؾ� ��
�� ����� ���� Ŀ���� 2500*32*2 = 16����. �غ��� ��
*/

/*����
1. ü������ ���¸� ���� 2�����迭 ���°� �´�.
(�ڷ��� ���Ե� �� �Ͼ�� ���� �ٲٴϱ�)
*/

/*������ : 
1.scanf�� �̿��� �ٴڴٴ� �پ��ִ� ĳ���͸� ������, 
�Է� ���� ������� �ٹٲ� \n�� ����ġ ���ѿ��� ���� �� ������ ����
2.�����迭�� �迭�� ���� �迭 �����Ϳ� �Ҵ��ϴ� ���?
->�߰� ����
*/

#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
char baseboard[50][50]; //�ٺ� ��
char chessboard[8][8]; //�߶� ��

int minima = 987654;

void input()
{
	cin >> M >> N;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j)
			//scanf("%c", &baseboard[i][j]);  //���Ⱑ ������
			cin >> baseboard[i][j];
	}
}

int main()
{
	input();

	//baseboard Ȯ��
	/*for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j)
			printf("%c", baseboard[i][j]);
	}*/
	
	//���⼭���� �ڵ� �ۼ�

	for (int i = 0; i < M - 7; ++i) {
		for (int j = 0; j < N - 7; ++j){

			for (int k = 0; k < 8; ++k) //�迭 ������
				for (int l = 0; l < 8; ++l)
					chessboard[k][l] = baseboard[i + k][j + l];
			//for (int k = 0; k < 8; ++k) { //���� �迭 Ȯ��
			//	for (int l = 0; l < 8; ++l)
			//		cout << chessboard[k][l];
			//	cout << '\n';
			//}
				//���� ������ B�� ĥ�Ҷ� ����� �� ����
				int cnt = 0;
				for (int k = 0; k < 8; ++k) {
					for (int l = 0; l < 8; ++l) {
						if ((k + l) % 2 == 0 && chessboard[k][l] == 'W') //¦���� ��� B�� ĥ�ϱ�
							cnt++;
						else if ((k + l) % 2 == 1 && chessboard[k][l] == 'B')
							cnt++;
					}
				}
				minima = (minima > cnt) ? cnt : minima;

				//���� ������ W�� ĥ�� �� ����� �� ����
				cnt = 0;
				for (int k = 0; k < 8; ++k) {
					for (int l = 0; l < 8; ++l) {
						if ((k + l) % 2 == 0 && chessboard[k][l] == 'B') //¦���� ��� B�� ĥ�ϱ�
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
