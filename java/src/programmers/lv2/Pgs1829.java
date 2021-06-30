package programmers.lv2;
/**
 * 제목 : 카카오프렌즈 컬러링북
 *
 * 아이디어 : 섬찾기와 동일한 DFS/BFS
 * - BFS를 수행한다
 * - 이때 넓이 정보를 계속 1씩 더한다
 * - 더이상 큐에서 진행할 수 없으면 마지막으로 넓이를 배열에 저장한다
 * - visited는 당연히 있어야 한다
 */
import java.util.*;

class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        ArrayList<Integer> count = new ArrayList<>();
        boolean[][] visited = new boolean[m][n];



        ArrayList<int[]> queue = new ArrayList<>();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] != 0 && visited[i][j] == false) {
                    int color = picture[i][j];
                    int volume = 1;
                    int[][] direction = {{1, 0}, {0, 1}, {-1, 0}, {0,-1}};
                    int[] now;
                    int next_y,next_x;

                    queue.add(new int[] {i,j,volume} );
                    visited[i][j] = true;


                    while (!queue.isEmpty()){
                        now = queue.remove(0);

                        for (int[] d : direction) {
                            next_y = now[0] + d[0]; next_x = now[1] + d[1];
                            if (next_y < m && next_y >= 0 && next_x < n && next_x >= 0){
                                if (!visited[next_y][next_x] && picture[next_y][next_x] == color) {
                                    visited[next_y][next_x]= true;
                                    queue.add(new int[] {next_y, next_x, ++volume});
                                }
                            }
                        }
                    }
                    count.add(volume);
                }
            }
        }
        Collections.sort(count);
        return new int[] {count.size(), count.get(count.size()-1)};
    }
}

public class Pgs1829 {
    public static void main(String[] args) {
        Solution s = new Solution();
//        System.out.println(s.solution(6,4,));
        int[][] picture = {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}};
        System.out.println(s.solution(6,4, picture));
    }
}
