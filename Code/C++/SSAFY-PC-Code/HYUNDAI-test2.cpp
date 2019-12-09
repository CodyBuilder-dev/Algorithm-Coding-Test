//���̵�� : ������ 10^4�̹Ƿ� ��...�Ź� �����Ѵ� ġ�� 10^4*10^4. �Ҹ��ѵ�?
// 1. pair�� ����
// 2. �������� ���� �� �� �տ��� ���� �߰�
// 3. �ٽ� �������� ���� �� �� �տ��� �߰�
// X. �̹� ���� �Ǿ� �����Ƿ�, �Ǿտ��� ���� �̺�Ž��
// 4. �ݺ�

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>

using namespace std;

string solution(int n, vector<string> plates, vector<int> odo, int k, vector<int> drives) {
	deque<pair<int, string>> cars;
	for (int i = 0; i < plates.size(); ++i)
		cars.push_back(make_pair(odo[i], plates[i]));

	sort(cars.begin(), cars.end()); //�켱 1�������� ����

	for (int i = 0; i < k; ++i) {
		cars[0].first += drives[i];
		//1������ n-1���� �߿� �߰� ã��
		pair<int, string> newCar = make_pair(cars[0].first, cars[0].second);
		cars.pop_front();

		int left = 0; int right = n - 1;
		
		while (right - left <= 1) {
			int mid = (left + right) / 2;
			if (cars[mid].first > newCar.first)
				right = mid - 1;
			else if (cars[mid].first < newCar.first)
				left = mid + 1;
			else //���ڰ� ���� ��ġ�ϴ� ���
			{
				if (cars[mid].second.compare(newCar.second) < 0) // mid�� ���̸�
					cars.insert(mid + 1, newCar); //deque�� insert�ϴ¹��� �𸣰���...
				else

				break;
			}
		}
	}

	sort(cars.begin(), cars.end());

	string answer = cars[0].second;
	return answer;
}