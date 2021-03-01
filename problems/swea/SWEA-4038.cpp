//단어가 등장하는 횟수

/*아이디어 : 브루트포스
책의 단어가 5*10^5이고 찾는 단어가 10^5이므로 단순무식하게 풀면 무조건 터짐
*/

/*아이디어 : KMP 알고리즘
O(N+M)이므로 쌉가능
*/

//구현 : string 쓰지 말고 char로만 해보기
//한줄 받는데는 cin.getline

#include <iostream>
#include <string>
using namespace std;

int T;
string book;
string particle;
int pi[100000]; 



void make_pi(string str)
{
	/*pi배열 만드는법
	전체 길이가 N개일 때, 접두사 접미사 같아지는 부분 길이 찾아야 함
	
	*/
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		//잘 받아지는거 확인
		cin >> book >> particle;
		
		
		
	}
}