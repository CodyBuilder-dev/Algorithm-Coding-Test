//���� : ���
//���� : ������ �̸��� ������ �־��� ��, ���� ���� ����, ���� ���� �θ� ����� ã�ƶ�

/*���̵��:
������ ������ ���� �ǰ�, �����ڴ� 1�� ����ϸ� �ȴ�
1. ���� �迭 ���� ���� ���ö����� ++
2. �̸� �迭�� ���� ó�� ����̸��� ���ϱ�
*/

//������ :
//string�� ũ�Ⱑ �����ε�, �迭�� �����Ҵ��� �����Ѱ�?
//-> �����ϴ�. �ٵ� �����ϸ� ���� ����.����� �����Ⱚ ����.
//��Ʈ���� �迭�� ����ִ��� �ƴ��� ���� �˻���
//-> char* �迭�� ���� �� ��
//-> string �迭 �� NULL,\0������ compare�ص� ���� ���Ƿ�, �׳� for������ �������� �ʱ�ȭ�ؼ� ���ϰų� �ƿ� ���� ����
//���ڿ� �˻�� nullptr�� �����ִ°�?
//cin�� ��Ʈ���̳� char*�ޱ⿣ �������Ѱ�?
#include <iostream>
#include <string>

using namespace std;

int U, N;
int price[10001];
char* name[10001];
//string name[10001]; <- not good
int main()
{
	cin >> U >> N;

	char* tempName = { 0 };
	int tempPrice;

	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d", tempName, &tempPrice);
		if (strcmp(name[tempPrice],NULL) == 0 ) name[tempPrice] = tempName;
		price[tempPrice]++;

	}
	int minima = 987654;
	for (int i = 0; i <= N; ++i)
	{
		if (price[i] == 0)continue;
		minima = (minima > price[i]) ? i : minima;
	}
	cout << name[minima] << ' ' << minima;
}