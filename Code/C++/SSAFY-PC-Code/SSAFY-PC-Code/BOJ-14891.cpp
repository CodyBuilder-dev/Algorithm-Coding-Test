//���� : ��Ϲ���
//���� : N/S���� �޸� ��Ϲ����� ȸ����Ų ����� ��Ÿ���ÿ�
//���� : ȸ���� �ִ� 100ȸ

/*���̵�� : 
1. ��Ϲ����� ���ϴ� ��� ������� ȸ������
2. 1ȸ ȸ�� �Ŀ���, ������ ��Ϲ����� ���� ��ȭ
->�̶� �´��� ���� ��Ģ�� ���� ���� �ȵ��� ����
*/

/*���� :
1. ��Ϲ����� �迭�� �־��� ������ �迭�� �ޱ�
->12�� ������ �ε��� 0
2. 1�� 3 = 2�� 9, 2�� 3 = 3�� 9...
3. ��ȭ �Լ� ���� ������
->��Ϲ����� ��ȣ�� ������ ������ �̿� ���� ó��
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

	//�� �޾����°� Ȯ��
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
	//�������� �� ������� �Ǵ�
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

	if (dir == 1) //�ð����
	{
		for (int i = 0; i < 4; ++i)
		{
			if (check[i] == true && i % 2) shift_unclock(i); //true�� 2,4���̸�
			if (check[i] == true && !(i % 2)) shift_clock(i); //true�� 1,3���̸�
		}
	}

	else //�ݽð�
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
	if (toppni[1][2] != toppni[2][6]) //3�� ���ư����� Ȯ��
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
			if (check[i] == true && (i % 2)) shift_clock(i); //true�� 2,4���̸�
			if (check[i] == true && !(i % 2)) shift_unclock(i);  //true�� 1,3���̸�
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
	if (toppni[2][6] != toppni[1][2]) //2�� ���ư����� Ȯ��
	{
		check[1] = true;
		if (toppni[1][6] != toppni[0][2]) //1�� ���ư����� Ȯ��
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
			if (check[i] == true && i % 2) shift_unclock(i);  //true�� 2,4���̸�
			if (check[i] == true && !(i % 2)) shift_clock(i); //true�� 1,3���̸�
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
			check[j] = false; //�� ȸ������ ������ ��� �迭 �ʱ�ȭ
		int num, dir;
		cin >> num >> dir;
		move_toppni(num, dir);
	}

	calc_score();
}
