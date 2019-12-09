//���� : 2048(easy)
//���� : �̵� Ƚ���� ������ ������, ����� ���� �� �ִ� ���� ū �� ã��
//���� : ������ ũ��� �ִ� 20x20=400, 4���� �̵��� ����� ���� 4^5 = 1024

/*���̵�� : ��/��/��/�� �� �̵����� ����
1. ���带 �����ϰų�, ����� �����ϰų�.
(�̰� ���带 �����ϴ°� ���� ��)
2.��/��/��/�� �� �̵����� ����
(���� �̵���, �迭�� ���� ���ʿ� �����ϴ� ��ϵ���� ������ ����)
3. ������ ���̸鼭 ���� ����� ���� �� ������
4. ������ ���� �ٽ� �������� �ʰ� �Ϸ��� ��...
5. ����ü�� �迭�� �����ߵǳ�
*/

/*���� : 
1. ����ü ���ο��� �� ��ǥ�� ��, �浹�� ���θ� ������
2. ���� �������� �浹���� True
3. �� ù �б⿡ False�� �ʱ�ȭ��
*/

/*������ :
1.2���� �迭 ������ ���� �� ���� �ٸ� ������ �ְ� ������ ����ü?
2.����ü�� ��°�� swap�� �ص� �Ǵ°�? ����
3.�����(f5)�� ���� �迭 index ���� ���� ���� ���� �� �ִ�.
4.����� ���̰� ���� ��� for ������ �Ἥ �� ���� �ִ�.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;

//������ ��� ����
typedef struct {
	int value;
	bool collision = false;
}BLOCK;

BLOCK **board;
BLOCK **saveBoard;
//��� �̵� �Լ� ����
void move_block(int dir)
{
	switch (dir)
	{
	case 0: //�������� �̵�
		for (int i = 0; i < N; ++i)
			for (int j = N - 1; j >= 0; --j){
				if (j == N - 1) continue;
				int k = j;
				//������ ������ ���������� ���� ����
				while ((k < N - 1) && (board[i][k + 1].value == 0)){
					swap(board[i][k + 1], board[i][k]);	
					k++;
				}
				if (k == N - 1) continue;//�浹���� ������ �������� ��� 
				//������ ���, ���� ĭ�� ����ĭ�� ������ Ȯ��
				if ((board[i][k].value == board[i][k + 1].value)
					&&(board[i][k+1].collision == false))
				{
					board[i][k + 1].value *= 2;
					board[i][k + 1].collision = true; //���� ��� ���� 2��� �ø���, �浹 true
					board[i][k].value = 0;
					board[i][k].collision = false;
				}
				
			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break; //1ȸ �̵� �� ��� �浹 �ʱ�ȭ;

	case 1: //��
		for (int i = 0; i < N; ++i)
			for (int j = 0; j <N; ++j) {
				if (j == 0) continue;
				int k = j;
				//������ ������ ���� ����
				while ((k > 0) && (board[i][k - 1].value == 0)) {
					swap(board[i][k - 1], board[i][k]);
					k--;
				}
				if (k == 0) continue; //�浹���� ������ �������� ���
				//�浹 �߻��� ������ Ȯ��
				if ((board[i][k].value == board[i][k - 1].value)
					&& (board[i][k - 1].collision == false))
				{
					board[i][k - 1].value *= 2;
					board[i][k - 1].collision = true;
					board[i][k].value = 0;
					board[i][k].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;
	case 2: //��
		for (int j = 0; j < N; ++j)
			for (int i = N - 1; i >= 0; --i) {
				if (i == N - 1) continue;
				int k = i;
				//�ƹ��͵� ������ ���� ����
				while ((k < N - 1) && (board[k+1][j].value == 0)) {
					swap(board[k][j], board[k+1][j]);
					k++;
				}
				
				if (k == N - 1) continue;//�浹���� ������ �������� ��� 
				//�浹 �߻��� ������ Ȯ��
				if ((board[k+1][j].value == board[k][j].value)
					&& (board[k+1][j].collision == false))
				{
					board[k+1][j].value *= 2;
					board[k+1][j].collision = true;
					board[k][j].value = 0;
					board[k][j].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;

	case 3: //��
		for (int j = 0; j < N; ++j)
			for (int i = 0; i <N; ++i)
			{
				if (i == 0) continue;
				int k = i;
				//�ƹ��͵� ������ ���� ����
				while ((k > 0) && (board[k - 1][j].value == 0)) {
					swap(board[k][j], board[k - 1][j]);
					k--;
				}
				if (k == 0) continue;//�浹���� ������ �������� ��� 
				//�浹 �߻��� ������ Ȯ��
				if ((board[k - 1][j].value == board[k][j].value)
					&& (board[k - 1][j].collision == false))
				{
					board[k - 1][j].value *= 2;
					board[k - 1][j].collision = true;
					board[k][j].value = 0;
					board[k][j].collision = false;
				}

			}
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				board[i][j].collision = false;
		break;
	}

}

int find_maxblock(int exMax)
{
	int maxNum = exMax;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (maxNum < board[i][j].value) maxNum = board[i][j].value;

	return maxNum;
}
int main()
{
	
	cin >> N;

	board = new BLOCK*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new BLOCK[N];

	saveBoard = new BLOCK*[N];
	for (int i = 0; i < N; ++i)
		saveBoard[i] = new BLOCK[N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j){
			cin >> saveBoard[i][j].value;
			board[i][j] = saveBoard[i][j];
		}

	/* ����ü �迭 Ȯ��
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			cout << board[i][j].value << ' ';
		cout << '\n';
	}
	*/
	int maxNum = 0;
	//������� �������� �ڵ� ����
	//�ѹ� �����̰� ��� �ʱ�ȭ�� ������ϴ� ���� �����
	//�̷��� ���� ����, movearray�� ������.
	int moveArray[5];
	for (int i = 0; i < 4; ++i){
		moveArray[0] = i;
		for(int j = 0 ; j<4;++j){
			moveArray[1] = j;
			for(int k = 0; k<4; ++k){
				moveArray[2] = k;
				for(int l = 0; l<4;++l){
					moveArray[3] = l;
					for (int m = 0; m < 4; ++m){
						moveArray[4] = m;
						for (int n = 0; n < 5; ++n)
							move_block(moveArray[n]);
						maxNum = find_maxblock(maxNum);
						for (int n = 0; n < N; ++n)
							for (int o = 0; o < N; ++o)
								board[n][o] = saveBoard[n][o];
					}			
				}
			}
		}
	}
	
	cout << maxNum;
	return 0;
}

