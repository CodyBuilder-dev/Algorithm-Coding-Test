//���� : ��� ����
//���� : Ʈ�������� ���� ������ �߿��� ��� ������ �ִ��� �����ϱ�
//���� : ������ �ִ� 1����, ���� �ֹ��� �ִ� 1����

/*���̵�� :
1.node ����ü �ȿ� ����� �־� �����ϱ�
2.�� ���� �� ������踸 �־����� ��, Ʈ�� ������ ������ �Ǵ��Ͽ� Ʈ�� �����ϱ�
3.���� �ִ�ȭ �˰���...�� ã�µ�....
3.1 ���/������ ���� �� �µ��� ���ǿ� �����ϴ��� Ž��?
3.2 �׸���� ���� ū����� ���� �� Ž��?
*/

/*������ :
1.Ʈ����� �ؼ� �ݵ�� �θ�-�ڽİ��� ��������� ������ �ʿ� ���µ�!
(�׳� ����Ŭ ���� �׷��� = Ʈ���� �ؼ��ص� ��)
2. �������� ���� ����� �� �����ؼ� ���� ����
*/


#include <iostream>
#include <vector>

using namespace std;

int N;

typedef struct village{
	int people;
	vector<village*> near;
}VILL;

//typedef struct village {
//	int people;
//	village *near1;
//	village *near2;
//}VILL;

village villArray[10000];

int main()
{
	cin >> N;


	for (int i = 0; i < N; ++i)
		cin >> villArray[i].people;

	//������� �ޱ�
	for (int i = 0; i < N - 1; ++i)
	{
		int start, end;
		cin >> start >> end;
		
		villArray[start - 1].near.push_back(&villArray[end - 1]);
		villArray[end - 1].near.push_back(&villArray[start - 1]);

		/*if (villArray[start - 1].near1 == NULL) villArray[start - 1].near1 = &villArray[end - 1];
		else villArray[start - 1].near2 = &villArray[end - 1];
		
		if (villArray[end - 1].near1 == NULL) villArray[end - 1].near1 = &villArray[start - 1];
		else villArray[end - 1].near2 = &villArray[start - 1];
		*/
	}

}