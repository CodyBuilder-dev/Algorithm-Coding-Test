//���� : FAKTOR
//���� : ��ս��� �����Ѵ�
//���� : 

/*���̵�� :
1.I = round_up((sum)/A)�� �����Ѵ�.
2.���⼭ sum�� ���Ѵ�.
round up�̹Ƿ�
*/

#include <iostream>

using namespace std;

int main()
{
	int A, I;
	scanf("%d%d", &A, &I);
	
	printf("%d", (I - 1) * A + 1);

	return 0;

}