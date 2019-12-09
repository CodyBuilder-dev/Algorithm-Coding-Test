//���� : Ʈ�� ��ȸ
//���� : Ʈ���� �����ϰ�, �� ��ȸ����� ���� ��ȸ�ϱ�
//���� : ��� ������ �ִ� 26

/*���̵��
1. �켱 ����Ʈ���� ������ �� �˾ƾ� ��
2. Ʈ���� ������ ��, ��ȸ�ϴ� �κ��� © �� �˾ƾ� ��
*/

/*����
1.�迭�� �����غ��� (X) : �θ� n�̸� �ڽ��� 2n+1,2n+2
(������ : ��� ������ n���� �迭 index�� 2^n)
2. ����ü+���Ḯ��Ʈ�� �����غ��� (O) : 
3. ����� �̸��� ����빮���̹Ƿ� �ƽ�Ű�ڵ� �̿�? �ٵ� �̰� �ƽ�Ű�� �ܿ��� �Ǵµ�
*/

/*������ : 
1.��� ����ü(Ȥ�� ���ο� �ڱ��ڽ� ������ ���� ����ü) �����
typedef�� ���� ���� ��� ����ü �������� ��������� ��
2.���� ���� ����ü �迭�� �� ��, ������ ��� ����!
3. ��ȸ���� ��쿣 visitüũ�� �ʿ����, �˾Ƽ� �帧�� �������� ���ܵ�
4. �������� �Ҵ�� �迭�� delete[]�ϸ� ������ ����
(
*/
#include <iostream>

using namespace std;

//Ʈ�� ����ü
typedef struct node {
	char name;
	node *left = NULL;
	node *right= NULL;
	node* parent;
}NODE;

int N;
NODE nodeArray[26];
bool visited[26];

//������ȸ �Լ�
void preorder(NODE* start) {
	visited[start->name - 65] = true;
	printf("%c", start->name);

	if (start->left != NULL) preorder(start->left);
	if (start->right != NULL) preorder(start->right);
}
//������ȸ �Լ�
void inorder(NODE* start) {
	if (start->left != NULL) inorder(start->left);
	visited[start->name - 65] = true;
	printf("%c", start->name);
	if (start->right != NULL) inorder(start->right);
}
//������ȸ �Լ�
void postorder(NODE* start) { //�����͸� �������
	if (start->left != NULL) postorder(start->left); //�ƴ� ���⼭ &�� ������� ���
	if (start->right != NULL) postorder(start->right);
	visited[start->name - 65] = true;
	printf("%c", start->name);
	
}

int main() {
	cin >> N;

	//���� ���鼭 name �ٿ���
	for (int i = 0; i < N; ++i)
	{
		nodeArray[i].name = i + 65;
	}

	//�ڽİ��� �޾� ���
	for (int i = 0; i < N; ++i)
	{
		char present, left, right;
		cin >> present >> left >> right;
		if (left != '.') nodeArray[present-65].left = &nodeArray[left - 65];
		if(right != '.') nodeArray[present-65].right = &nodeArray[right - 65];
	}

	preorder(&nodeArray[0]);
	cout << '\n';
	inorder(&nodeArray[0]);
	cout << '\n';
	postorder(&nodeArray[0]);
	cout << '\n';

	return 0;
}
