//���� : ���ڼҸ� �ùķ��̼�
//���� : ���� �ùķ��̼�
/*
���� : ���� 1000��, 
������ ���μ��� ũ��� 2000, �� �Ѱ� ���ڴ� �� 2000���� ��� ����

*/
/*
���̵�� : ���� ���� ��ü�� ������ �� ��� �ùķ��̼� �ϴ°�?

���̵�� 1 : �� ������ ��θ� �� �迭�� ������ �� ��
������1 : ���� 1000��, �� 1���� ���غ��� 50����
2000������ 2000�� ���ϴ°� �̺�Ž�� ���� 2000*log2000 * 50���� = 3���
�� �ð��ʰ� �ɸ� Ȯ���� ����

���̵�� 2 : ����ġ ������ structure�� vector�� ��������
�̵���Ű�� ����, vector�� ��ȸ�� pair�� x,y��ǥ�� ������ �ִ��� Ȯ������
�׷� 
������ 2: �迭���� 2000*2000 =4�鸸, �� 1�ʿ� 4�鸸�� Ž���� �ؾ� ��.
struct vector�� ���� �� ���� �� ����. �׷��� 19�ʾ� �ɸ�.
*/

/*����ȭ
1. ���� �������� -> ����������
2. scanf���
*/
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

typedef struct element {
	int x;
	int y;
	int dir;
	int energy;
} ELEMENT;

int T; //���ɰ���
int N; //���ڰ���
int X, Y, Dir, K;//0�� 1�� 2�� 3��

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};


int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		//���� �ʱ�ȭ ����
		vector<ELEMENT> vec;

		scanf("%d",&N);

		for (int j = 0; j < N; ++j)
		{
			ELEMENT tempElement;
			scanf("%d %d %d %d",&X,&Y,&Dir,&K);
			tempElement.x = X;
			tempElement.y = Y;
			tempElement.dir = Dir;
			tempElement.energy = K;
			vec.push_back(tempElement);
		}
		
		//���⼭���� �ڵ� ����
		//sum���� �����, ��� ���ڵ��� 2000ĭ �̻� �������� ��
		int time = 0;
		int sum = 0;
		while (time <= 2000)
		{
			time++;
			//���� ��ġ ����
			for (int j = 0; j < vec.size(); ++j)
			{
				switch (vec[j].dir)
				{
				case 0: vec[j].x += dx[0]; vec[j].y += dy[0]; break;
				case 1: vec[j].x += dx[1]; vec[j].y += dy[1]; break;
				case 2: vec[j].x += dx[2]; vec[j].y += dy[2]; break;
				case 3: vec[j].x += dx[3]; vec[j].y += dy[3]; break;
				}
			}
			//���� �浹 �˻� �� �հ�
			//�̺�Ž���ϴ°� ��. �ٵ� �����غ��� ���� �ȵǳ� ���� 
			//��¿�� ���� ���� ���Ź�� ���.
			//3��, 4���̻� �浹���̽� ��� ó������ ����
			
			
			//������ �浹�ϴ����� ��� �������.
			//������ ������ �ϴ� �׳� ��ǥ ��̿� �ֱ�
			//���� ������ ���������� ��ǥ �ִ³�� �� ����
			//������ �� �׳�� �� ���ϱ�
			//������ �� ���� ��� ���������� ���� �ѱ�
					
			/*
			Ÿ���� ���̵�� : ���Ľ��Ѽ� ������ �ֵ鸸 �˻��ϱ�
			*/
			set<int> idx_set;
			for (int j = 0; j < vec.size(); ++j) {
				for (int k = 0; k < vec.size(); ++k) {
					ELEMENT tempElement = vec[k];
					if (j == k) continue;
					if (vec[j].x == tempElement.x && vec[j].y == tempElement.y)
						idx_set.insert(j);	//���� ��� j ����
				}

				//for (int k = 0; k< idx_array.size(); ++k)
					//printf("idx_array = %d ", idx_array[k]);


				//�񱳰� ���� ������ ��� ��� ����
				set<int>::iterator itr;
				while(!idx_set.empty()){
					itr = idx_set.end();
					ELEMENT tempElement = vec[*itr];
					sum += tempElement.energy;
					vec.erase(vec.begin() + (*itr));
					idx_set.erase(itr);

				}
			}
		}

		printf("#%d %d\n", i, sum);
		//���� ��. ������ ���			
	}


	return 0;
}