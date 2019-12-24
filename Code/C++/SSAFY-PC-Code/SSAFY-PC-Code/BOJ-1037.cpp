#include <iostream>
#include <algorithm>
using namespace std;

//아이디어 : 숫자는 소수랑 소수가 아닌 수로 나눌 수 있음
//소수가 아닌 수는 그냥 약수가 홀/짝임
//소수인 수는 진짜 약수가 없을 텐데 어떡하지 <- 생략

//진짜 약수가 홀수면 제곱수
//진짜 약수가 짝수면 맨 끝 곱
// 진짜 약수가 0이면 소수 <- 생략
//사실 홀수, 짝수 상관없이 정렬된거 맨 끝에거 곱하면 땡임

//구현 : 
//소팅을 어떤 소팅을 선택하느냐...
//약수배열 길이가 50이하이고, 시간제한 2초이니 뭘 써도 됨

//출력 :

//코딩 스타일 :
//배열의 0번째에 약수 수를 저장하고 1번지부터 약수를 넣을 경우
//sort함수 사용시 문제가 될 수 있음
int main()
{
	int N;
	int *n_list;
	int result;

	cin >> N;
	n_list = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> n_list[i]; // 배열 1번부터 약수 넣기
	}
	sort(n_list, n_list+N);
	result = n_list[0] * n_list[N-1];
	cout << result << '\n';

}