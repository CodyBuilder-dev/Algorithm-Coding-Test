//���� : ������
//���� : �ѹ��� �� �� �ִ� å �Ǽ��� �־��� ��, �ּҰ������� å�� ���󺹱� ��Ű�� ���
//���� : å�� ������ 10^4�� ����

/*���̵�� : ���Ʈ������ ��� ��쿡 ���� �ִܰ�� ã�°� �� ���ٰ�,
�ִܰŸ� ��Ģ�� ã�Ƴ��� �����ؾ���
1. å�� ������ �ִ�� ��°� ����
2. �ѹ������� �ִ��� �� ��, �����鼭 ���ƿ��� ������ �ϴ°� ����.
3. ��, �� �������� �� ��, �����鼭 ����, left max�� ����Ѵ�.
4. �ݴ�������ε� �� ��, right max����Ѵ�.
5. �� ���ΰ� ���ƿ� �ʿ� �����Ƿ�, �������� ���� �ָ� ���°� ����.
*/

/*���� : (X)
1. å ��ġ�� �ε����� ���� visited �迭�� �����
2. ������ ���� ��� ó���ؾ� �ϳĸ�... �߰����� 0���� �Ѵ�.
3. å�� ���ξ��� �� �迭�� 1�� �ٲ۴�.
*/

/*����2 : ���� �湮�� �ʿ䰡 �ֳ�?
1.�׳� �޾Ƽ� �����Ѵ�
2.�ϴ� �ִܰŸ� ����.
3. �ű⼭���� M�� �� ������ �� ���� �ִܰŸ� ã�Ƽ� ����.
3. �ִ�Ÿ��� ª�� �� ���� ����.
*/

//������ : ��� �� ���� ������ ����. �����Ϸ��� �����ϰ� ��� �ؾ� �ɱ�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> bookidx;

int main()
{
	cin >> N >> M;

	int temp;
	for (int i = 0; i < N; ++i){
		cin >> temp;
		bookidx.push_back(temp);
	}	
	
	sort(bookidx.begin(), bookidx.end());

	//���⼭���� �ڵ��ۼ�
	int now = 0;
	int total = 0;
	while(!bookidx.empty()){
		int hand = M;
		while (hand > 0) {
			if (bookidx.empty()) break;
			
			int mindis = 987654;
			int tempnow = 987654;
			int tempidx = 987654;

			for (int i = 0; i < bookidx.size(); ++i) //����ġ �ִܵ����� ã��
			{
				int tempmin = abs(bookidx[i] - now);

				if (tempmin < mindis)
				{
					mindis = tempmin;
					tempnow = bookidx[i];
					tempidx = i;
				}
			}
			total += mindis;
			bookidx.erase(bookidx.begin() + tempidx);
			now = tempnow;
			hand--;
		}
	}
	cout << total;
}

