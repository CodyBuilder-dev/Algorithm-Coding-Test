//���� : Ʈ�� ����
//���� : Ʈ�� ���, ���� �ð�, �ð��� ������ �־��� �� ������ ���
//���� :�� Ʈ���� �ӹ��� �ð��� ���� �־���

/*���̵�� : �ð����� ��ġ�� ���θ� �ľ��ؾ� ��
1. �ð��� 1~100���̹Ƿ�, for�� ������ �к� ��������� �ľ��Ѵ�.
2. ��������� �ľǵǸ�, ��*���*��� ���� ���Ŀ� ����Ѵ�.
*/

//������ : �����ð��̶� ���� ���۽ð� �� 1�ð����� ���ʿ� ����
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	int in[3], out[3];

	scanf("%d %d %d", &A, &B, &C);
	for (int i = 0; i < 3; ++i)
		scanf("%d %d", &in[i], &out[i]);
	
	/*for (int i = 0; i < 3; ++i)
		printf("%d %d\n", in[i], out[i]);
	*/
	int maxtime;
	maxtime = max(out[0], out[1]);
	maxtime = max(maxtime, out[2]);

	int time[4] = { 0 };

	for (int i = 0; i <= maxtime; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < 3; ++j)
			if (in[j] < i && i <= out[j]) cnt++;
			
		time[cnt]++;
	}
	cout << A * time[1] + B * time[2]*2 + C * time[3]*3;
}