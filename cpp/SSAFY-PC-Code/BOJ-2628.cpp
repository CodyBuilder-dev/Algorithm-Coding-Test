//제목 : 종이 자르기
//목적 : 자른 종이조각중 가장 큰 거 출력
/*
아이디어 : 
1.  종이를 자른 후 크기를 파악해야됨
2. 크기는 다 자르기 전까지는 파악 불가
3. 일단 다 자르면, 그때부터는 파악 가능?!
*/

/*
아이디어 : 네모의 넓이는 가로*세로
즉 가로길이 세로길이 중 최대로 나누는걸 찾으면 됨
잘리는 포인트들을 배열에 저장해두고, 배열의 차이가 가장 큰 놈을 찾으면 됨
*/

//주의점 : 우선순위 큐를 잘 사용하면 큐를 정렬해서 내보낼 수 있음
//hor,ver 방향 구분 잘 되도록 주의할것

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int paper_width, paper_height;
	int N;

	cin >> paper_width >> paper_height;
	cin >> N;
	
	int direction;
	int hor, ver;
	int max_hor, max_ver;
	priority_queue<int> cut_hor, cut_ver;
	
	//큐 받아오기
	for (int i=0;i<N;++i)
	{
		cin >> direction;
		if (direction == 0) {
			cin >> hor;
			cut_hor.push(hor);
		}
			
		else {
			cin >> ver;
			cut_ver.push(ver);
		}
	}
	cut_hor.push(0);
	cut_ver.push(0);
	
	
	max_hor = 0;
	max_ver = 0;
	
	hor = paper_width;
	ver = paper_height;
	
	while(!cut_ver.empty())
	{ 
		
		if ((hor - cut_ver.top()) > max_hor) max_hor = hor - cut_ver.top();
		hor = cut_ver.top();
	
		cut_ver.pop();
		
	}

	while (!cut_hor.empty())
	{

		
		if ((ver - cut_hor.top()) > max_ver) max_ver = ver - cut_hor.top();
		ver = cut_hor.top();
	
		cut_hor.pop();
	}
	
	cout << max_ver * max_hor;

}
