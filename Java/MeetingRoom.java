/*
전략 : 정렬 및 이전 endtime과 다음 starttime을 비교
구현 : 
1. Tuple 클래스 구현
2. Tuple의 정렬을 위한 Comparator구현
3. Tuple을 리스트에 담아 정렬 수행

*/
import java.util.Arrays;

class Tuple {
    public int start;
    public int end;

    public Tuple(int start,int end) {
        this.start = start;
        this.end = end;
    }
}
class MeetingRoom {
    public void solution(Tuple[] tpArr) {
        Arrays.sort(tpArr);
    }

    public static void main(String[] args) {
        // 테스트 케이스
        Tuple[] tpArr = {new Tuple(0,30),new Tuple(5,10),new Tuple(15,20)};
        MeetingRoom sol = new MeetingRoom();

        // 솔루션함수 호출 및 결과 확인
        sol.solution(tpArr);

        System.out.println(tpArr);

    }
}