//아이디어 : 차량이 10^4이므로 음...매번 정렬한다 치면 10^4*10^4. 할만한데?
// 1. pair의 생성
// 2. 오름차순 정렬 및 맨 앞에놈에 갯수 추가
// 3. 다시 오름차순 정렬 및 맨 앞에놈 추가
// X. 이미 정렬 되어 있으므로, 맨앞에놈 빼서 이분탐색
// 4. 반복

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

	sort(cars.begin(), cars.end()); //우선 1차적으로 정렬

	for (int i = 0; i < k; ++i) {
		cars[0].first += drives[i];
		//1번부터 n-1까지 중에 중간 찾기
		pair<int, string> newCar = make_pair(cars[0].first, cars[0].second);
		cars.pop_front();

		int left = 0; int right = n - 1;
		
		while (right - left <= 1) {
			int mid = (left + right) / 2;
			if (cars[mid].first > newCar.first)
				right = mid - 1;
			else if (cars[mid].first < newCar.first)
				left = mid + 1;
			else //숫자가 완전 일치하는 경우
			{
				if (cars[mid].second.compare(newCar.second) < 0) // mid가 앞이면
					cars.insert(mid + 1, newCar); //deque를 insert하는법을 모르겠음...
				else

				break;
			}
		}
	}

	sort(cars.begin(), cars.end());

	string answer = cars[0].second;
	return answer;
}