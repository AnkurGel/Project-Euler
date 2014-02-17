package utilities;
public class General {
    public static boolean is_prime(long n){
        // Checks if n is prime
        // Go till sqrt(n) and check
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        else{
            long sqrt = (long)Math.sqrt(n);
            for(long i = 2; i <= sqrt; i++)
                if(n % i == 0)
                    return false;
        }
        return true;
    }

    public static long generate_next_prime(long n){
        long next = n + 1;
        while(!is_prime(next)){
            if(next % 2 == 0) next++;
            else next += 2;
        }
        return next;
    }

    public static boolean is_palindrome(long n){
        //Reverse a number by subsequent modulo to check for
        //palindrome
        long rev = 0, original = n;
        while(n != 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        if(original == rev) return true;
        else return false;
    }
}
