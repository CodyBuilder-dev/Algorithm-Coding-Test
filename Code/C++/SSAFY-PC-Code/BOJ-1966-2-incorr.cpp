//���� : ������ ť
//���� : �켱������ ���� ��¼����� �����Ǵ� ť�� ���� �� �ִ°�

/*���̵�� 2 :�ִ� �켱������ ���Ѵ�. ������ �̳𸻰�� ����� �ȳ���
1. ������������ ����
2. �տ������� ������ cnt ����
3. ��ǥ�� ���޽� cnt ��ȯ
*/

//������ :���� �켱������ �ִ� ��� �ľ� �Ұ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	int total_paper, paper_idx;
	
	int out_cnt = 0;
	int paper_num;
	vector<int> paper_array;
	

	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		scanf("%d %d", &total_paper, &paper_idx);

		
		for (int j = 0; j < total_paper; ++j){
			int importance;
			scanf("%d", &importance);
			paper_array.push_back(importance);
		}

		paper_num = paper_array[paper_idx];

		sort(paper_array.begin(), paper_array.end(),less<int>());

		while (!paper_array.empty())
		{
			//�� ó������ ũ�ų�,�۰ų�,���ų� ���� �ٸ�
			if (paper_array.front() > paper_num) {
				paper_array.erase(paper_array.begin());
					out_cnt++;
			}

			else if (paper_array.front() == paper_num)
				out_cnt++;

		}
		cout << out_cnt;
	}
}