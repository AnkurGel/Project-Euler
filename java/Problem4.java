public class Problem4 {
    public static void main(String[] args){
        long product, max_product = 0;
        // Traverse 3 digits numbers. O(n^2) :(
        for(int i = 100; i <= 999; i++){
            for(int j = 100; j <= 999; j++){
                product = i * j;
                if (product > max_product && ispalindrome(product))
                    max_product = product;
            }
        }
        System.out.println(max_product);
    }
    public static boolean ispalindrome(long n){
        //Reverse a number by subsequent modulo to check for palindrome
        long rev = 0, original = n;
        while(n != 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        if(original == rev) return true;
        else return false;
    }
}
