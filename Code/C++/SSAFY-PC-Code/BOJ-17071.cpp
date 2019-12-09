//���� : ���ٲ���5
//���� : �� ����� �̵� ��Ģ�� �־����� ��, �����̰� ������ ������ ������ ����ϱ�
//���� : ���ѽð��� 0.25���� = �� 2500���� �ȿ� Ǯ��� ��

/*���̵�� : ���� ���ٲ��� Ǯ ���� ���
1. �ð� ���� ����
2. for�� ������
3. �̵����ǿ� ���� �����ִ°� ǥ��
4. ������ �ű� �ֳ� üũ
5. ������ ť�� �ְ� �ѱ��
->�ð��� ���� �ֳ� �ȳֳ�?
6. ������ ��� Ŀ���⸸ �ϹǷ�, �������� ���� ��ġ�� �׳� ��
*/
#include <iostream>
#include <queue>

using namespace std;

int time;
int subin;
int sis;
bool isOver;

priority_queue<int, vector<int>, greater<int>> minTime;

int main()
{
	cin >> subin >> sis;
	
	
	queue<int> timeQ;
	queue<int> sisQ;
	queue<int> subinQ;
	subinQ.push(subin);
	sisQ.push(sis);
	timeQ.push(time);

	if (subin == sis) cout << 0;
	else {
		while (!timeQ.empty()) {
			time = timeQ.front();
			sis = sisQ.front();
			subin = subinQ.front();
			timeQ.pop();
			sisQ.pop();
			subinQ.pop();

			if (sis > 500000) {
				isOver = true;
				break;
			}

			int nt = time + 1;
			int nsis = sis + nt;
			//������ ������ ��� �Ǵ�
			int nsubin = subin - 1;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else if (nsubin > nsis) { //1���� ũ�ٸ�
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}

			nsubin = subin + 1;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else if (nsubin > nsis) //1���� ũ�ٸ�
			{
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}
			nsubin = subin * 2;
			if (nsubin == nsis) {
				minTime.push(nt);
				break;
			}
			else {
				timeQ.push(nt);
				sisQ.push(nsis);
				subinQ.push(nsubin);
			}

		}

		if (minTime.empty()) cout << -1;
		else cout << minTime.top();
	}
}