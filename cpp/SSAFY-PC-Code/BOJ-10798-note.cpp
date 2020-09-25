//제목 : 세로읽기
//목적 : 가로로 서로 다른 길이로 쓰여진 글자들을 세로로 읽을 수 있는가
//크기가 주어지지 않고 주어지는 글자들을 적절한 모양으로 나눠서 입력받을 수 있는가

/*아이디어 : 이건 어쩔 수 없이 2차원 배열 해야되겠는데
1. 행의 길이가 각자 다른 2차원 배열을 만들고, error처리를 수행한다.
or 행의 길이를 같게 하되,  장난감에 없는 글자(ex -1)로 초기화하고 이를 만나면 건너뛴다.
2. 위의 방법이 더 재밌을 듯 하니 위로 하겠음
*/

/*구현
1.그냥 2차원배열로 선언하면 심심하니, 2차원 벡터를 써보자
vector<vector<int>> 벡터명; 으로 선언하면 됨
2. 입력 받을때는, while문 써서 '\n'을 인식할 때 까지 읽어야 할 듯
3. 출력할때는 front, pop front 쓰고, empty일 경우 continue 하는 식으로
*/

//느낀점 : 억지로 \n이나 공백을 받아와서 저장해야 할 때가 있다. 그럴땐 scanf
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(5);

int main()
{
	//2차원벡터 받기
	for (int i = 0; i<5;++i)
		while (1)
		{
			char temp;
			scanf("%c", &temp); //cin 쓰면 공백 무시하므로 안됨
			if (temp == '\n') break;
			board[i].push_back(temp);
		}
	
	//2차원벡터 세로로 출력
	for(int j = 0; j<15;++j)
		for (int i = 0; i < 5; ++i)
		{
			if (board[i].empty()) continue;
			cout << board[i].front();
			board[i].erase(board[i].begin());
		}
	
}



