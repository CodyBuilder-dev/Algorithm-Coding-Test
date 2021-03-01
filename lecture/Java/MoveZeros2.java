/*
접근 :
1. 0이 아닌 것들을 무조건 앞으로 다 옮긴다
2. 마지막 위치를 기억해서 그때부터 다 0으로 채운다
*/
package Java;

import java.util.Arrays;

public class MoveZeros2 {
    public static void main(String[] args) {
        int[] nums = {0,3,2,0,8,5};
        int index = 0;

        for (int i = 0 ; i<nums.length; ++i){
            if(nums[i] != 0){
                nums[index] = nums[i];
                index++;
            }
        }
        while (index < nums.length){
            nums[index] = 0;
            index++;
        }
        
        System.out.println(Arrays.toString(nums));
        
    }
}