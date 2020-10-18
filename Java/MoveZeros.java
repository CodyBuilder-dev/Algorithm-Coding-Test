/*
제한조건 : 
1. Array의 copy를 만들어서는 안된다
2. 연산 횟수를 최소한으로 줄여야 한다

접근법 :
copy를 만들수 없으므로, swap을 이용해 접근한다
 */
package Java;

import java.util.Arrays;

public class MoveZeros {
    // public int[] a = {0,1,0,3,12};
    public int[] a = {0,3,2,0,8,5};
    
    public void swap(int startIdx){
        int pointer = startIdx;
        for (int i = startIdx ; i<a.length ; ++i) {
            if (a[i] != 0 ){
                int temp = a[i];
                a[i] = a[pointer];
                a[pointer] = temp;
                pointer = i;
            }
            else {
                continue;
            }
        }
    }
    public static void main(String[] args) {
        MoveZeros z = new MoveZeros();
        for (int i = 0; i < z.a.length; ++i){
            if (z.a[i] == 0)
                z.swap(i);
        }

        System.out.println(Arrays.toString(z.a));
    }
}