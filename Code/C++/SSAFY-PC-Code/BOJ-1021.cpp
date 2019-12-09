//���� : ȸ���ϴ� ť
//���� : �־��� ���Ǵ�� �����ϴ� ȸ���ϴ� ť �ڷᱸ���� �����.

/*���̵�� : 
1. ù��° ���Ҹ� �̴´� : ù��° ���Ҹ� ������ ��, �ٸ� ���Ҹ� ��ĭ�� ����
2. �������� ��ĭ �̵� : ù��° ���Ҹ� ������ ��, �ٸ� ���� ��ĭ�� ���� �� �ڿ� �ִ´�
3. ������ ��ĭ �̵� : ���� ����ѵ� ������ �ݴ�
*/

/*���� : (0������ 1, 1������ 2���� ����)
1.����, �޸� �̵�, ������ ����ϰ� �Ͼ�Ƿ�,
STL�߿� deque�� �Ẹ�°� �´°� ����.
2. deque �޼ҵ��߿� ���� ��Ȯ�ϰ� ���ϴ� �� �����Ƿ�,
�ʿ��� �޼ҵ�� �ۼ��ؼ� �����Ѵ�.
3. ���ڸ� ������, �ش� ������ ��ġ �ľ�
4. ������ ������ ��������, �������� ������ ����������
5. 1ȸ ����ø��� Ƚ�� +1
6. ���������� �� ������ Ƚ�� ���
*/

#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int N, M;
int total=0;

void rotate_right()
{
	if (!dq.empty()) {//�� ���ڸ��� �� ������
		int last = dq.back();
		dq.pop_back();
		dq.push_front(last);
		total++;
	}
	else cout << "empty!\n";
}
void rotate_left()
{
	if (!dq.empty()) {//�� ���ڸ��� �� �ڷ�
		int first = dq.front();
		dq.pop_front();
		dq.push_back(first);
		total++;
	}
	else cout << "empty!\n";
}
int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		dq.push_back(i);
	/*�������� �� �Ǵ°� Ȯ��
	for (int i = 0; i < N; ++i)
		cout << dq[i];
	*/

	/*dq size �� �Ǵ°� Ȯ��
	cout << dq.size();
	*/

	int numarray[50];
	for (int i = 0; i < M; ++i)
	{
		cin >> numarray[i];
	}

	for (int i = 0; i<M;++i){
		int idx;
		for (int j = 0; j < dq.size(); ++j) //idxã��
			if (dq[j] == numarray[i]) idx = j;

		while (!idx == 0)
		{

			if (idx <= dq.size() / 2){
				rotate_left();
				idx--;
			}
			else{
				rotate_right();
				if (idx == dq.size() - 1) idx = 0;
				else idx++;
			}
		}
		dq.pop_front();
				
	}
	
	cout << total;
}