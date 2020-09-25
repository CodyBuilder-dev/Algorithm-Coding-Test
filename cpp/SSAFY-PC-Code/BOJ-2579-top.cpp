//���� : ��� ������
//���� : ����� �ö� ���� �� �մ� ������ �ִ�
/*���� : 
1. ����� �ִ� 300�� -> �� Ʈ���� ������ ���̰� 100�� �Ѿ -> DP
2. 0�� �ٴ�����, ������� ������� �ʴ´�. �� ù��°�� �ι�°�� ���޾Ƽ� ���� �� �ִ�.
3. ������ ����� �ݵ�� ��ƾ� �Ѵ�. �� N-1���� 2ĭ �ö󰡴� ���� ������� �����´�.
*/

/*���̵�� : 
k��° ������� ������ �ִ밪 : k-1���� 1ĭ �ö���� �ִ밪 , k-2���� 2ĭ �ö���� �ִ밪
�� �� ū �� 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int score[301];
int dp[301][3]; //�� ĭ�� ������, ���� ĭ���κ��� 1ĭ �ö���°� 1����, ��ĭ �����κ��� 2ĭ �ö���°� 2����

int find_max(int dest, int series)
{
	if (series == 2) return 0; //3�� ������ ��� ������
	if (dest <= 0) return 0;
	
	int nowScore = score[dest];
	int finalScore;
	if (series == 1) { //�̹� ��ĭ �� ���
		//�� ������ 2ĭ �پ�� ��
		if (dp[dest - 2][0] != 0 && dp[dest - 2][1] != 0) finalScore = dp[dest - 2][0] + dp[dest - 2][1]+nowScore;
		else finalScore = find_max(dest - 2, series - 1)+nowScore;
	}
	else { //2ĭ �پ �ö�� ���
		//�� ���� 2ĭ �ٵ� 1ĭ �ٵ� �������
		finalScore = max(find_max(dest - 1, series+1)+nowScore, find_max(dest - 2, series)+nowScore);
	}

	dp[dest][series] = finalScore;
	return  finalScore;
}

int main()
{
	//�Է� �ޱ�
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> score[i];
	
	//dp�ʱ�ȭ
	dp[1][1] = score[1]; //0��° ���
	dp[1][2] = score[1];
	dp[2][1] = dp[1][1] + score[2];
	dp[2][2] = score[2];


}