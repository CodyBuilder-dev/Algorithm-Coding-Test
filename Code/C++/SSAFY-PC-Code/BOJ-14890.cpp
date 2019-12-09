//���� : ����
//���� : �������� �̷���� ��� ���� ������ ã��, ���θ� �̿��� �� ����
//���� : (���� ���� ����). ũ�� �ִ� 100x100, ���� ���� L�� �ִ� 100
//���� : �ùķ��̼�, ���� Ž��

/*���̵�� : 
1. ���Ʈ������, �� 2�����迭�� ���Ҹ� �� �˻��ϸ鼭 ����
2. ���� ����� ���� ���� ���ΰ� �̹� �����ִ��� üũ
3. ������ �Ϲ����̹Ƿ� DFS���� �ʿ����
*/

/*���� : ������ �����Ƿ�, �Ĳ��� ������ ��
1. ���̰� ���� ��� ����
2. ���̰� �޶��� ���. �ö󰡴��� ���������� �˻�
3. �ö� ���- ���̰� 1���� 2���� �˻�
3. ���̰� 1�� ���, �׶����� 1�� � ���ӵǴ��� �˻�
4. � ���ӵǴ� ���, ���θ� ����
5. 
*/

/*����2 : ������ ����, ������ ���� �Լ� ����
1. ������ ���δ�, ������ġ�� �޺κ� ���� ���� �˻�
1. �Ǵ� ���
1.1 L��ŭ ���̰� ����
1.2 ��ġ���� �ʾҾ�� ��
2. �ȵǴ� ���
2.1 ���̰� ���� ���� ���
2.2 �̹� ��ġ�� �� ���
2.3 �� ������ ����� ���

2. ������ ���δ�, ������ġ �պκ� ���� ���� �˻�
*/


//������ :2�� if������ else if �Ʒ��� if�� ���ٸ�, else if{} �ݵ�� �߰�ȣ�� �־���� ��
//->��¥ �������δ� ���� �ϳ��� ���µ� ġ�������� ���۵��ϹǷ� �ſ� ����


#include <iostream>

using namespace std;

int N, L;

int **board;
bool **installed;

int first;
bool horizen;


//������ �� �˻�����. ���� upper lower�� �˻��ϸ� ��
//�ȵǴ� ��� ��� �� üũ �ؾ���

bool upper_dir(int y, int x) //������ ���� ��ġ���� üũ �Լ�
{
	//�ȵǴ� ��� ��쿡 ���� return false, �Ǹ� true
	//return�� �߰��� �ع����� ���� �������� �ϱ�
	int check = 0;
	if (horizen == true){ //���� �� üũ�ϴ� ���
		if (x - L < 0) return false;
		for (int i = x - L; i < x; ++i){
			if (board[y][i] != first) check = 0;
			else if (installed[y][i] == true) check = 0;
			else check++;
		}

		if (check == L) {  //�ȵǴ� ��� ��츦 ����ϸ�
			for (int i = x - L; i < x; ++i)
				installed[y][i] = true;
			first = first+1;
			return true;
		}
		else return false;
	}
	else { //���� �� üũ�ϴ� ���
		if (y - L < 0) return false;
		for (int i = y - L; i < y; ++i) {
			if (board[i][x] != first) check = 0;
			else if (installed[i][x] == true) check = 0;
			else check++;
		}
		if (check == L) {
			for (int i = y - L; i < y; ++i)
				installed[i][x] = true;
			first = first+1;
			return true;
		}
		else return false;
	}
}
//lower�϶� ����� �˻� �ȵ�, �� ������
bool lower_dir(int y,int x) //������ ���� ��ġ���� üũ �Լ�
{
	//�ȵǴ� ��� ��츦 üũ�� �� ������ return true
	int check = 0;
	if (horizen == true) { //���� �� üũ�ϴ� ���
		if (x + L > N) return false;
		for (int i = x; i < x+L; ++i) {
			if (board[y][i] != first-1) check = 0;
			else if (installed[y][i] == true) check = 0;
			else check++;
		}
		
		if (check == L) {
			for (int i = x; i < x+L; ++i)
				installed[y][i] = true;
			first = first-1;
			return true;
		}
		else return false;
	}
	else { //���� �� üũ�ϴ� ���
		if (y + L > N) return false;
		for (int i = y; i < y+L; ++i) {
			if (board[i][x] != first-1) check = 0;
			else if (installed[i][x] == true) check = 0;
			else check++;
		}
		if (check == L) {
			for (int i = y; i < y+L; ++i)
				installed[i][x] = true;
			first = first -1;
			return true;
		}
		else return false;
	}
}

int main()
{
	cin >> N >> L;

	board = new int*[N];
	installed = new bool*[N];
	for (int i = 0; i < N; ++i)
	{
		board[i] = new int[N]();
		installed[i] = new bool[N]();
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];

	//���⼭���� �������� �ڵ� ����
	bool okay;
	int total = 0;
	for (int i = 0; i < N; ++i) {//���� �� �˻�
		horizen = true;
		okay = true;
		first = board[i][0];
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] > first + 1 || board[i][j] < first - 1)
			{
				
				okay = false;
				break;
			}
			else if (board[i][j] == first + 1){
				if (!upper_dir(i, j)) { //�������� �˻��� ���� �����̸�
				
					okay = false;
					break;
				}
			}
			else if (board[i][j] == first - 1){ //<- �߰�ȣ ���� ����
				if(!lower_dir(i,j)){ //�������� �˻��� �����̸�
					
					okay = false;
					break;
				}
			}
			
		}
		if (okay == true)
			total++;
	
	}

	//installed �ʱ�ȭ �ѹ� ���ֱ�
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			installed[i][j] = false;

	for (int j = 0; j < N; ++j) {//���� �� �˻�
		horizen = false;
		okay = true;
		first = board[0][j];
		for (int i = 0; i < N; ++i)
		{
			if (board[i][j] > first + 1 || board[i][j] < first - 1)
			{
				
				okay = false;
				break;
			}
		else if (board[i][j] == first + 1) {
			if (!upper_dir(i, j)) {
				
				okay = false;
				break;
			}
		}
		else if (board[i][j] == first - 1) {
			if (!lower_dir(i, j)) {
				
				okay = false;
				break;
			}
		}
		}

		if (okay == true) total++;
		
	}

	cout << total;
}

