//���� : ���� ���
//���� : �������� ������ ���� ��, ���� ���� �� 5���� �̾� ���ض�(��, ������ ���� �ƴ°�)

/*���̵�� : �׳� ���� ���� ��̾�����, �����ϰ� Ǯ���
1. 5��¥�� �迭 ����
2. ���� ������ �ּҰ��̶� ���ؼ� �迭���� �ּҰ� ���� �ֱ�
3. �������� �迭 ���
*/

//������ : ������ ���� �����ϱ� ��ƴ�. 
typedef struct {
	int score;
	int num;
}QUEST;

#include <iostream>
//#include <algorithm>
using namespace std;

int main()
{
	QUEST maximum[5] = { 0 };
	QUEST sorted[5] = { 0 };

	int minimum = 0;
	int minidx = 0;

	QUEST temp;
	for (int i = 0; i < 8; ++i) {
		cin >> temp.score;
		temp.num = i+1;
		
		if (temp.score > minimum) maximum[minidx] = temp;

		minimum = maximum[0].score;
		for (int j = 0; j < 5; ++j)
			if (minimum > maximum[j].score) {minimum = maximum[j].score; minidx = j;}

	}

	for (int i = 0; i < 4; ++i)
		if (maximum[i].score > maximum[i + 1].score)
			for (int j = i + 1; j > 0; --j)
				while (maximum[j].score < maximum[j - 1].score) swap(maximum[j], maximum[j - 1]);
	
	int sum = 0;
	for (int i = 0; i < 5; ++i)
		sum += maximum[i].score;
	cout << sum << '\n';
	for (int i = 0; i < 5; ++i)
		cout << maximum[i].num << ' ';
}