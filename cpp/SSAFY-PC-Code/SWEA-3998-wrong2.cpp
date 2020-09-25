//제목 : Inversion Counting
//목적 : i<j 일때 Ai>Aj인 Inversion의 개수를 구하여라
//조건 : 순열 길이는 최대 10^5

/*아이디어 : 페어 사용
1. 각 숫자의 크기와 인덱스를 넣은 페어 생성
2. 숫자 크기 기준 내림차순 정렬 - O(NlogN)
3. 1번부터 인덱스 비교
(4,1번) (1,2번) (3,3번) (2,4번) (5,5번)
-정렬후-
(5,5) (4,1) (3,3) (2,4) (1,2) 
[inversion = 전체길이 - 나 포함 내 앞 개수 - 내 뒤 위치 중 나보다 큰 애]
5는 5번이므로 inversion = 5 - 5 - 0 = 0
4는 1번이므로, inversion = 5 - 1 - (내 위엣놈들 인덱스 탐색) = 3
3은 3번이므로 inversion = 5 - 3 - (내 위엣놈들 인덱스 탐색) = 1
2는 4번이므로, invesion = 5 - 4 - (내 윗놈들 인덱스 탐색) = 0

문제점 : 내 윗놈들 인덱스를 어떻게 빨리 찾지? -> 답변불가
*/

/*아이디어 : DP 사용
1. 뒤에서부터 탐색
2. 내 뒤에놈들 중 나보다 큰 놈 갯수, 나보다 작은놈 개수를 저장
3. 그래도 결국 브루트포스에서 조금 줄어드는 정도에 불과하네 -> 사용불가
*/

/*아이디어 : 근본적인 자료구조 개선?
1. 이거 약간 ㅋㅋㅋ 바이너리 서치 트리로 바꾸면 괜찮을거 같지 않냐
내 왼쪽은 나보다 작은놈 내 오른쪽은 나보다 큰놈
2. 특정수 등장-이진탐색트리에서 위치 확인- 내 왼쪽자식 개수 + 내 왼쪽부모랑 걔 자식수만 세면 됨 ㅇㅈ?

문제점 : BST 자체가 구현하는게 졸라 어려움
*/

/*구현
1. BST 생성
2. 원소 삽입
3. 원소 탐색
4. 원소의 왼쪽에 있는 개수 구하는 기능
*/

#include <iostream>

using namespace std;

int T;
int N;
int list[200000];
int inversion;

void input()
{
	//fill_n 동작 잘 하구용~
	fill_n(list, 200000, 0);
	inversion = 0;

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> list[i];
}

void find_inversion_brute()
{
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (list[i] > list[j]) inversion++;
		}
	}
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		input();

		find_inversion_brute();

		cout << '#' << i << ' ' << inversion << '\n';


	}
}