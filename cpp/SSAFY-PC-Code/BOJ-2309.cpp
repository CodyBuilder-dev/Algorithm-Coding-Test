//���� : �ϰ� ������
//���� : 9���� �� �߿� ���� 100�̵Ǵ� �� 7�� ã��

//���̵�� : �ϴ� �� �ް�, �� 100 �ɋ����� loop ���
/*���� : 
1.STL ���ͷ� �����غ���
2.7�� ������... 9C7�̹Ƿ� ������ �� ���ۿ� ���µ�
3. ������ �� ���� ��Ž���� �Ϸ���...�κ������̹Ƿ� 7�� for��?
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> dwarfs;
	vector<int> idx;
	
	int temp;
	for (int i = 0; i < 9; ++i){
		cin >> temp;
		dwarfs.push_back(temp);
	}

	sort(dwarfs.begin(), dwarfs.end());

	for (int i = 0; i < 7; ++i)
	{
		idx.push_back(1);
	}
	for (int i = 7; i < 9; ++i)
	{
		idx.push_back(0);
	}

	sort(idx.begin(), idx.end());
	
		
	do {
		int sum = 0;
		for (int i = 0; i < 9; ++i)
			if (idx[i] == 1)
				sum += dwarfs[i];
		//cout << sum<<'\n';
		if (sum == 100) {
			for (int i = 0; i < 9; ++i)
				if (idx[i] == 1)
					cout << dwarfs[i] << '\n';
			break;
		}
	} while (next_permutation(idx.begin(), idx.end()));

}