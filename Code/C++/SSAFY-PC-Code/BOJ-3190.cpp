//���� : ��
//���� : �ùķ��̼� ������ �ذ��� �� �ִ°�?

/*���̵�� : N�� 100�����̹Ƿ�, ĭ�� 10000ĭ. �� ū��
���Ʈ ������ ����Ž�� �ص� �ǳ�?
���� ��ȯ Ƚ���� 100�ε�, �׷� 4^100�̹Ƿ� ��찡 �ʹ� �����Ƿ�
���Ʈ������ �ȵȴ�. ��Ʈ��ŷ?

�� �̰� ���� ó������ ��� ����� ���� �� �ʿ䰡 ����
�׳� ����� �׶� �׶� �����鼭 �����ϸ� �ǳ�
*/

/*�ڷᱸ��
�� : 2���� �迭 0
��� : 2�����迭 ���� 1
�� ��ü�� ��  : -1
��� : �ѹ��� ť�� �޾Ƽ� �ϳ��� ���ų�, �׳� �׶��׶� ������ �ްų�
*/

/*�˰��� 
for
	cin >> 2�� �ޱ�
	�ش� ��� ���డ�� ���� �Ǵ�
	���డ�ɽ� ��� ���� �Ǵ�.
	���������� ��� ����� ������ �迭 ��ȯ
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int N, K, L; //�ʱ� ����
	
	cin >> N;
	
	//��� ��ġ �ޱ�

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

	int time = 0; //���� �ð�
	int X; //��� ��
	char C; //��� ����
	int dir = 1; //��1 ��2 ��3 ��4
	
	//�̰� �� ��ü�� ���� �����߰ڳ�
	//�� ���� ��ü, index�� �� ���� ��ġ, ���� xy��ǥ��
	//0�� �Ӹ�, length-1�� ����
	int snake_x[100] = { 0 };
	int snake_y[100] = { 0 };
	int length = 1;
		
	//�Ӹ� ó�� ��ġ�� 1�� 1��
	snake_x[length-1] = 1; snake_y[length-1] = 1;
	
	//�̵� Ƚ�� �ޱ�. ť�� �ִ°� �������� �ֳ�
	cin >> L;

	for (int i = 1; i <= L; ++i)
	{
		cin >> X >> C;
		while(time<X)
		{
			time++;
			switch (dir)
			{
			case 1: //������ ���
				if (snake_x[0] >= N) goto endgame; //�� �浹

				for (int k = 0; k < length; ++k) //�ڱ�� �浹
					if ((snake_x[0] + 1 == snake_x[k])
						&& (snake_y[0] == snake_y[k])) goto endgame;

				for (int k = 0; k < K; ++k) {
					if (snake_x[0] + 1 == apl_x[k] //��� �Ա�
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
			case 2: //������ ���
				if(snake_y[0] >= N) goto endgame; //�� �浹

				for (int k = 0; k < length; ++k) //�ڱ�� �浹
					if (snake_x[0] == snake_x[k]
						&& snake_y[0]+1 == snake_y[k]) goto endgame;
				
				for (int k = 0; k < K; ++k) {
					if (snake_x[0]  == apl_x[k] //��� �Ա�
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
			case 3: //������ ���
				if (snake_x[0] <= 1) goto endgame; //�� �浹

				for (int k = 0; k < length; ++k) //�ڱ�� �浹
					if ((snake_x[0]-1 == snake_x[k])
						&& (snake_y[0] == snake_y[k])) goto endgame;
				for (int k = 0; k < K; ++k) {
					if (snake_x[0] - 1 == apl_x[k] //��� �Ա�
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
			case 4: //������ ���
				if (snake_y[0] <= 1) goto endgame; //�� �浹

				for (int k = 0; k < length; ++k) //�ڱ�� �浹
					if ((snake_x[0] == snake_x[k])
						&& (snake_y[0]-1 == snake_y[k])) goto endgame;

				for (int k = 0; k < K; ++k) {
					if (snake_x[0] == apl_x[k] //��� �Ա�
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