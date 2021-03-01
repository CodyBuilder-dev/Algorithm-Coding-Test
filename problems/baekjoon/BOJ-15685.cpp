//���� : �巡�� Ŀ��
//���� : ���� ���� �巡�� Ŀ�갡 �־��� ��, �巡�� Ŀ�꿡 ���ϴ� �׸� ã��
//���� : Ŀ��� �ִ� 20���̴�. �������� ������ 0���� 100, ����� 10����, ����ũ��� ���� �� �� ���µ�
//���̰� 2�辿 �þ�Ƿ� 2^10 �ִ� 1024. ����ũ��� �Ƹ� �ִ� 1500x1500

/*���̵�� : �巡�� Ŀ���� �������� �־����Ƿ�, ���� ������ۿ� ����
1. �巡�� Ŀ�� �����
->���� üũ/�������� ���� �迭 �Ųٷ�/90�� ���� �� ���� �ݴ�->�������� ���͵��� �̵�
2. �׸� üũ
-> 0,0 0,1 1,0 1,1 ���� ��� visited�� �׸� 1�� �߰�
*/

/*����
1. ���� ��ǥ : pair
2. ���� �迭 : �ƹ� �����̳ʳ�
3. ���� ��ǥ : dy,dx
4. �湮 üũ : visited
*/

/*���� ��
1. for������ ������ i<N�� ���, i== N-1�� ������ ���� �Ŀ���, ++���� �ѹ��� ����ȴٴ� ���� ���� �� ��
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int board[101][101];
bool visited[101][101];

int dy[] = {0,-1,0,1};//�� �� �� ��
int dx[] = {1,0,-1,0};
int dir;

vector<int> route;
pair<int, int> finalPoint;
int routeIndex; //��ü route���� ���� ������ ��ġ�� ��Ÿ���� �ε���
int generation;

int squareCnt;

void append_route()
{
	for (int i = route.size() - 1; i >= 0; --i) {
		int newdir = (route[i] + 1) % 4; //90�� �ݽð� ȸ��
		route.push_back(newdir);
	}

	/*for (int i = 0; i < route.size(); ++i)
		cout << route[i];
	cout << '\n';
	cout << "routeIndex" << routeIndex << '\n';*/
}

void check_square()
{
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (visited[i][j] == true && visited[i + 1][j] == true && visited[i][j + 1] == true && visited[i + 1][j + 1] == true)
				squareCnt++;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) { //�� �巡�� Ŀ�꿡 ���� �׸���
		routeIndex = 0;
		route.clear();

		cin >> finalPoint.second >> finalPoint.first >> dir >> generation;
		visited[finalPoint.first][finalPoint.second] = true;
		route.push_back(dir);
		//cout << "start "<< finalPoint.first << ',' << finalPoint.second << '\n';
		
		for (int j = 0; j <= generation; ++j) {
			if (j == 0) {
				finalPoint.first += dy[dir];
				finalPoint.second += dx[dir];
				visited[finalPoint.first][finalPoint.second] = true;
				//cout <<"gen0 "<< finalPoint.first << ',' << finalPoint.second << '\n';
				routeIndex++;
			}
			else {
				append_route();
				for (routeIndex; routeIndex < route.size(); ++routeIndex) {
					finalPoint.first += dy[route[routeIndex]];
					finalPoint.second += dx[route[routeIndex]];
					//cout << "gen" << j << ' ' <<finalPoint.first <<',' <<finalPoint.second<<'\n';
					visited[finalPoint.first][finalPoint.second] = true;
				}
			}
		}
		


	}

	check_square();
	cout << squareCnt;
}




