//���� : ���� �ڸ���
//���� : �ڸ� ���������� ���� ū �� ���
/*
���̵�� : 
1.  ���̸� �ڸ� �� ũ�⸦ �ľ��ؾߵ�
2. ũ��� �� �ڸ��� �������� �ľ� �Ұ�
3. �ϴ� �� �ڸ���, �׶����ʹ� �ľ� ����?!
*/

/*
���̵�� : �׸��� ���̴� ����*����
�� ���α��� ���α��� �� �ִ�� �����°� ã���� ��
�߸��� ����Ʈ���� �迭�� �����صΰ�, �迭�� ���̰� ���� ū ���� ã���� ��
*/

//������ : �켱���� ť�� �� ����ϸ� ť�� �����ؼ� ������ �� ����
//hor,ver ���� ���� �� �ǵ��� �����Ұ�

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
	
	//ť �޾ƿ���
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
