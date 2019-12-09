//제목 : 트리 순회
//목적 : 트리를 구현하고, 각 순회방법에 따라 순회하기
//조건 : 노드 개수는 최대 26

/*아이디어
1. 우선 이진트리를 구현할 줄 알아야 함
2. 트리를 구현한 후, 순회하는 부분을 짤 줄 알아야 함
*/

/*구현
1.배열로 구현해보자 (X) : 부모가 n이면 자식은 2n+1,2n+2
(문제점 : 노드 개수가 n개면 배열 index가 2^n)
2. 구조체+연결리스트로 구현해보자 (O) : 
3. 노드의 이름이 영어대문자이므로 아스키코드 이용? 근데 이건 아스키를 외워야 되는데
*/

/*느낀점 : 
1.노드 구조체(혹은 내부에 자기자신 포인터 가진 구조체) 선언시
typedef로 쓰인 별명 대신 구조체 본명으로 선언해줘야 함
2.노드와 같은 구조체 배열을 쓸 때, 포인터 사용 주의!
3. 순회같은 경우엔 visit체크는 필요없고, 알아서 흐름상 갔던곳은 제외됨
4. 정적으로 할당된 배열을 delete[]하면 에러남 ㅋㅋ
(
*/
#include <iostream>

using namespace std;

//트리 구조체
typedef struct node {
	char name;
	node *left = NULL;
	node *right= NULL;
	node* parent;
}NODE;

int N;
NODE nodeArray[26];
bool visited[26];

//전위순회 함수
void preorder(NODE* start) {
	visited[start->name - 65] = true;
	printf("%c", start->name);

	if (start->left != NULL) preorder(start->left);
	if (start->right != NULL) preorder(start->right);
}
//중위순회 함수
void inorder(NODE* start) {
	if (start->left != NULL) inorder(start->left);
	visited[start->name - 65] = true;
	printf("%c", start->name);
	if (start->right != NULL) inorder(start->right);
}
//후위순회 함수
void postorder(NODE* start) { //포인터를 써야할지
	if (start->left != NULL) postorder(start->left); //아님 여기서 &를 써야할지 고민
	if (start->right != NULL) postorder(start->right);
	visited[start->name - 65] = true;
	printf("%c", start->name);
	
}

int main() {
	cin >> N;

	//루프 돌면서 name 붙여줌
	for (int i = 0; i < N; ++i)
	{
		nodeArray[i].name = i + 65;
	}

	//자식관계 받아 등록
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
