import java.util.ArrayList;

public class Solution {
    public ArrayList<Long> solution(int x, int n) {
        ArrayList<Long> answer = new ArrayList<Long>();
        long num = 0;
        for (int i =0; i <n ; ++i) {
            num += x;
            answer.add(num);
            
        }
        
        return answer;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int x = 2;
        int n = 5;
        for (Integer i : sol.solution(x, n)) {
            System.out.println(i);
        }
    }
}