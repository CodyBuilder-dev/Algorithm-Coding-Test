//제목 : 가장 큰 금민수
//목적 : 금민수는 4와 7로만 이루어진 수 , 특정 범위 금민수 중 가장 큰 것을 출력하시오
//조건 : 최대 10^6까지 주어진다.

/*아이디어1 : 100만까지의 수를 매번 한자리한자리 살펴본다면,
시간복잡도 = 최대 자리수 7자리 * 100만 = O(7*10^6)
1.1부터 N까지 for문 
2.현재 숫자를 string으로 만들기 -> atoi의 반대
3.string의 0번지부터 끝번지까지
4.금민수일 경우 삽입
*/

/*아이디어2 : 걍 까짓거 입력 받아서 자릿수 확인하고 거기 맞는 금민수 만들기
1. 입력 자체를 한개씩 받기
2. 자릿수 확인
3. 맨 앞자리 판단. 4미만이면 한자리 빼기, 4이상 7미만이면 4XXX 7이상이면 7
4. 금민수 생성
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> result;

int main()
{
	int temp;
	while (true) {
		if (!scanf("%1d", &temp)) break;
		if (temp < 4) continue;
		else if (temp >= 4 && temp < 7) result.push_back(4);
		else result.push_back(7);
	}

	for (int i = 0; i < result.size(); ++i)
		cout << result[i];
		
}