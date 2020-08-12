import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";

        if(checkZero(numbers))
            return "0";

        Integer[] input = Arrays.stream(numbers).boxed().toArray(Integer[]::new);
        Arrays.sort(input, new mComparator());
        for (Integer integer : input) {
            answer += integer.toString();
        }
        return answer;
    }

    boolean checkZero(int[] numbers) {
        for(int i=0; i< numbers.length; i++){
            if(numbers[i] != 0)
                return false;
        }
        return true;
    }
}

class mComparator implements Comparator<Integer> {

    @Override
    public int compare(Integer o1, Integer o2) {
        String s1, s2, s3;
        s1 = o1.toString();
        s2 = o2.toString();

        s3 = s2+s1;
        return s3.compareTo(s1+s2);
    }
}


public class Programmers_42746 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] numbers = {3, 30, 34, 5, 9};
        System.out.println(s.solution(numbers));
    }
}
