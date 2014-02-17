public class Problem2 {
    public static void main(String[] args){
        // Self explanatory. Standard fibonacci gen
        long a = 0, b = 1, temp;
        long sum = 0;
        while(a < 4000000){
            if (b % 2 == 0) sum += b;
            temp = a;
            a = b;
            b = temp + b;
        }
        System.out.println(sum);
    }
}
