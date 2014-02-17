public class Problem6 {
    public static void main(String[] args){
        int n = 100;
        //Question:
        //Tell the idff b/w sum of squares of first n numbers and
        //sqauares of the sum
        //sum of first n numbers: (n * (n+1))/2
        long squares_of_sum = (long)Math.pow(((n * (n+1))/2), 2);

        //sum of squares: (n * (n+1) * (2n+1))/6
        long sum_of_squares = (n * (n+1) * (2*n + 1))/6;
        System.out.println(squares_of_sum - sum_of_squares);
    }
}
