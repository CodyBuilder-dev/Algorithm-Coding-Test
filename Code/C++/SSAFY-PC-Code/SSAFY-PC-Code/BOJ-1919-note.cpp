//���� : �ֳʱ׷� �����
//���� : �� �ܾ �־����� ��, ���ĺ� ���Ÿ� ���� �ֳʱ׷��� �������� Ȯ��
//���� : �� �ܾ��� ���̴� 1000��

/*���̵�� : �̰� ���� ������ �ٲ㰡�鼭 �ϴ� ���� ����?
1. ���ĺ� �迭�� ����ؼ� ������ üũ�Ѵ�.
2. �� �ܾ��� ������ ���������� �Ѵ�? ���?
*/

//������ : �迭�� return�ϴ� �Լ� �ۼ��� �����ؾ� ��

#include <iostream>
#include <string>

using namespace std;

int *aAlpha, *bAlpha;
string a, b;

//�迭�� �Ѱ��ִºκ� �����ؼ� �ڵ�
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