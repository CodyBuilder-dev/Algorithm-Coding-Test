//���� : ���ڿ�
//���� : ���ڿ� A, B�� �־����� A�� B���� ª����, A�� B�� ���� ����ϰ� �������� ���

/*���̵�� : �߻� ���� (X)
0.���� �� �ٸ� �� ���� ���� ���̴�. 
1. �� �ڿ� �ִ� ��쿡�� ���� ���̿� ����.
2. �� �տ� �ִ� ��쿡��, ��ĭ�� �ڷ� �о ���ϴ°Ͱ� ���̰� ����
3. �� �� ������ �����Ѵ�.
*/

/*���̵��2 : �̸� B�� Ž���Ͽ� ���� �ּҰ� �Ǵ� �������� ���سֱ�
0. ���� �� �ٸ��� ���� ���� ���̴�.
1. B�� Ž���Ѵ�.
2. �� ���̰� �ּҰ� �Ǵ� �κ��� ���̰� �� �����̴�.
*/

/*���� : ���ڿ� �ϳ����� ���� �ǹǷ�, string ����� �ᵵ ����*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	
	int diff=0;
	int result = 987654;
	if (A.size() < B.size()) //����� �ٸ� ���
	{
		for (int i = 0; i <= B.size()-A.size(); ++i){
			diff = 0;
			for(int j =0; j<A.size(); ++j)
				if (A[j] != B[i+j]) diff++;
			result = (result > diff) ? diff : result;
		}

	}
	else { //����� ���� ���
		for (int i = 0; i < A.size(); ++i)
			if (A[i] != B[i]) diff++;

		result = diff;
	}
	cout << result;

}