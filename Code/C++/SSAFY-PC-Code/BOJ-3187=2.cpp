//���� : ��ġ�� ��
//���� : ��Ÿ�� �� ��� ���� �� ��� ���� �󸶳� ��Ƴ����� ���Ͻÿ�
//���� : ������ �ִ� 250x250 = 62500

/*���̵�� : BFS������, ��ü �� BFS�� �����ؾ� �ϴ��� �� ������ �����°� �߿���
1. ��Ÿ���� �ѷ��׿� �����Ƿ�, ��Ÿ�� ���� ��Ȳ�� �ƴ� ���� �߿���
2. ��� �̰� DFS�� �ص� �ɰŰ��� ��
3. �׷����� �ұ��ϰ�, 2���� �迭 �󿡼� ���� ���� �ʰ� Ž���ϹǷ� BFS ����
*/

/*����
1. BFS����. �̶� �� y,x��ǥ�� pair�� �����ϸ� ���� ��
2. ����� int�� 2���� �迭�� ����
3. �� �޾Ƶ��̱�� ��� �ؾߵ��� �� �򰥸����ѵ� �ϴ� scanf
4. �迭�� for������ ��ȸ�ϸ鼭 BFS����
*/

#include <iostream>

using namespace std;

int R, C;
int** board;
int** visited;

void BFS(int y, int x)
{
	/*���� ���� ����ϱ�
	1. ���� ��ġ�� visited�� �ִ´�
	2. ���� ��ġ���� �۾�(��,���� ����)�� �����Ѵ�.
	3. ���� ��ġ�� ť�� �ϴ� �ѹ� �ִ´�(empty�� ���� ����) 
	4.ť���� ������ ������ǥ�� �����Ѵ�.
	4. ���� ��ġ �ֺ��� 4���� Ž���Ѵ�.
	5. �� ���� �湮���� �ʾ��� ���, �� ���� �湮�ϰ� �۾��� ������ �� visited ǥ���Ѵ�.
	6. visited ǥ���� �Ŀ��� queue�� �ִ´�.
	7. 
	*/
}
int main()
{
	cin >> R >> C;

	board = new int* [R];
	for (int i = 0; i < R; ++i)
		board[i] = new int[C];
	int temp;

	for (int i = 0; i < R; ++i)
		for (int j = 0; i < C; ++i) {
			scanf("%d", &temp);
			board[i][j] = temp;
		}
	return 0;
}
