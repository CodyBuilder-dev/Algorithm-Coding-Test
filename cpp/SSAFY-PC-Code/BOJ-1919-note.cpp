//제목 : 애너그램 만들기
//목적 : 두 단어가 주어졌을 때, 알파벳 제거를 통해 애너그램이 가능한지 확인
//조건 : 두 단어의 길이는 1000자

/*아이디어 : 이걸 직접 순서를 바꿔가면서 하는 놈은 없지?
1. 알파벳 배열을 사용해서 개수만 체크한다.
2. 각 단어의 개수가 같아지도록 한다? 어떻게?
*/

//느낀점 : 배열을 return하는 함수 작성시 주의해야 함

#include <iostream>
#include <string>

using namespace std;

int *aAlpha, *bAlpha;
string a, b;

//배열을 넘겨주는부분 주의해서 코딩
int* check_alpha(string str,int* alpha)
{
	for (int i = 0; i < str.length(); ++i)
		alpha[str[i] - 97]++;

	return alpha;
}

int main()
{
	cin >> a >> b;
	
	aAlpha = new int[26]();
	bAlpha = new int[26]();

	aAlpha = check_alpha(a,aAlpha);
	bAlpha = check_alpha(b,bAlpha);

	/*for (int i = 0; i < 26; ++i)
		cout << "a : " << aAlpha[i] << " b : " << bAlpha[i] << '\n';
	*/
	int cntChange=0;
	for (int i = 0; i < 26; ++i)
	{
		if (aAlpha[i] > bAlpha[i]) cntChange += aAlpha[i] - bAlpha[i];
		else if (aAlpha[i] < bAlpha[i]) cntChange -= aAlpha[i] - bAlpha[i];

	}

	cout << cntChange;
}