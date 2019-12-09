//그놈의 생성자 왜이렇게 좋아하냐 ㅋㅋㅋ
//소수 찾기가 그거잖아 다 나눠보고 나눠지면 X 안 나눠지면 O
//생성자도 비슷한듯. 생성자 찾는 마법의 공식은 없다
// 근데 그렇다고 10000번을 n^3으로 돌리면 무조건 시간초과
// for 안에 for을 넣지 말고, for + for + for

#include <iostream>

using namespace std;
int generator(int num)
{
	if (num < 1) return 0;
	return num % 10 + generator(num / 10);
}
int main()
{
	int num = 10000;
	int array[10001] = { 0, };



	for (int i = 1; i <= num; i++)
	{
		int j = i;

		while (j <= num)
		{
			j = j + generator(j);
			if (j <= num) array[j] = 1; //이거 안 넣어주면 array 범위 초과해서 error
		}
	}

	for (int i = 1; i <= num; i++)
	{
		if (array[i] == 0) cout << i << ' ';
	}





}