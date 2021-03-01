//���� : ������ ť
//���� : �켱������ ���� ��¼����� �����Ǵ� ť�� ���� �� �ִ°�

/*���̵�� : �ܼ��� �� �״�� ����
1. ť �����
2. �� ���ǰ� ���� �߿䵵 �˻�
3. queue�� ��� ������ �� Ȯ���� �˻� O(n)
4. �Ź� �ݺ� O(n2)
*/

//������ :  vector�� iterator ���� ��
//������ : ���� ���ɿ��� ��� ť�� �״�� ����, ť�� �������� �״�� �����ִ�.
// �׷��Ƿ� ť�� �� ���ְų�,�ƿ� ���� for�� �ȿ��� �������ְų� �ؾ���
// ť�� �����̳� ���ο� �����Ѱ�� �����ؾ���
#include <iostream>
#include <queue>
#include <utility>
using namespace std;



int main()
{
	int T;
	int total_paper, paper_idx;
	
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) { //���̽� ����
		int out_cnt = 0;
		scanf("%d %d", &total_paper, &paper_idx);

		vector<pair<int, int>> paper_vector;
		for (int j = 0; j < total_paper; ++j) {
			int importance;
			scanf("%d", &importance);
			paper_vector.push_back(make_pair(j, importance));
		}
		/* ���� üũ
		while (!paper_vector.empty())
		{
			pair<int, int> tempPair = paper_vector.front();
			cout << tempPair.first << ' ' << tempPair.second<<'\n';
			paper_vector.erase(paper_vector.begin());
		}
		*/
		
		/* ���� üũ, ���� ����
		for (int j = 0; j < paper_vector.size(); ++j)
		{
			cout << paper_vector[j].first << ' ' << paper_vector[j].second << '\n';
		}
		*/
		
		
		while (!paper_vector.empty()) {
			pair<int,int> tempPair = paper_vector.front();
			
			//�޺κп� �ִ밪 �ֳ� ����
			int check = 1;
	
			for (int k = 0; k < paper_vector.size(); ++k) {
				if (paper_vector[k].second > tempPair.second)
					check = 0;
				
			}
			
			//�ִ밪�� �ƴ� ���
			if (check != 1)
			{
				paper_vector.push_back(tempPair);
				paper_vector.erase(paper_vector.begin());
				check = 1;
			}
			else//�ִ밪�� ���, idx��
			{
				out_cnt += 1;
				if (tempPair.first != paper_idx) { //idx�� �� ������
					paper_vector.erase(paper_vector.begin());
					
				}
				else {
					
					break;
				}
			

			}
		}

		cout << out_cnt << '\n';
	
		
	}
}