//제목 : 5와 6의 차이
//목적 : 숫자를 문자열로 인식해서 조작하기
//조건 : 두 수는 각각 1,000,000 이하

/*아이디어 :
1. 숫자를 한개씩 받아서 배열에 따로 저장
2. 받을 때 실시간으로 5면 6으로, 6이면 5로 같이 병행 저장
3. 최소, 최대를 찾기
*/

/*구현
1. scanf 이용 1숫자씩 받기
2. 한번에 숫자로 받은 후, sprintf()로 처리하기
(string이랑 sprintf 호환되는지 확인->호환 안됨!)
*/

/*느낀점 : 
1.숫자<->str<->char*간의 능숙한 변환이 중요함
2.실시간/받고나서 or C/C++ style에 따라 다양한 풀이 가능
*/


#include <iostream>
#include <string>

using namespace std;

int A, B;

int main()
{
	int a,b;
	string aStr, bStr;
	

	scanf("%d %d", &a, &b);
	aStr = to_string(a);
	bStr = to_string(b);

	string minStr, maxStr;
	int minSum=0, maxSum=0;
	for (int i = 0; i < aStr.length(); ++i)
	{
		if (aStr[i] == '5') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else if (aStr[i] == '6') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else {
			minStr.push_back(aStr[i]);
			maxStr.push_back(aStr[i]);
		}
	}

	minSum += atoi(minStr.c_str());
	maxSum += atoi(maxStr.c_str());

	minStr.clear();
	maxStr.clear();

	for (int i = 0; i < bStr.length(); ++i)
	{
		if (bStr[i] == '5') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else if (bStr[i] == '6') {
			minStr.push_back('5');
			maxStr.push_back('6');
		}
		else {
			minStr.push_back(bStr[i]);
			maxStr.push_back(bStr[i]);
		}
	}
	minSum += atoi(minStr.c_str());
	maxSum += atoi(maxStr.c_str());

	cout << minSum << ' ' << maxSum;

}
