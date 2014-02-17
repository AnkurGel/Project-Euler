public class Problem3 {
    public static void main(String[] args){
        long  n = 600851475143L;
        long max = (long)Math.sqrt(n), iter = 2, max_prime_factor = 2;
        while(iter <= max){
            iter = generate_next_prime(iter);
            if(n % iter == 0)
                max_prime_factor = iter;
        }
        System.out.println(max_prime_factor);
    }
    public static boolean is_prime(long n){
        // Checks if n is prime
        // Go till sqrt(n) and check
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        else{
            long sqrt = (long)Math.sqrt(n);
            boolean result = true;
            for(long i = 2; i <= sqrt; i++)
                if(n % i == 0)
                    return false;
        }
        return true;
    }
    public static long generate_next_prime(long n){
        long next = n + 1;
        while(!is_prime(next)){
            if(next % 2 == 0)
                next++;
            else
                next+=2;
        }
        return next;
    }
}
