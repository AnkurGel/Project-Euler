public class Problem5 {
    public static void main(String[] args){
        //Perform prime factorization
        int hash[] = new int[21];
        long product = 1;

        int prime_power, prime = 2, i;
        for(i = 2; i < 20; i++){
            prime = 2; prime_power = 0;
            if(is_prime(i) && hash[i] == 0){
                //directly found a prime
                // no need to factorize
                hash[i] = 1;
            }
            else{
                //factorize it now
                int num = i;
                while(num != 1){
                    if(num % prime == 0){
                        prime_power++;
                        num /= prime;
                    }
                    else{
                        if(prime_power > 0 && hash[prime] < prime_power){
                            hash[prime] = prime_power;
                        }
                        //continue factorization with next prime:
                        prime = next_prime(prime);
                        prime_power = 0; // reset
                    }
                }
                if(prime_power > 0 && hash[prime] < prime_power)
                    hash[prime] = prime_power;
            }
        }

        for(i = 2; i <= 20; i++)
            if(hash[i] != 0) product = product * (long)Math.pow(i, hash[i]);
        System.out.println(product);
    }
    public static boolean is_prime(int n){
        if(n == 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false;
        else{
            for(int i = 2; i <= (int)Math.sqrt(n); i++)
                if(n % i == 0) return false;
        }
        return true;
    }
    public static int next_prime(int n){
        int next = n + 1;
        while(!is_prime(next)){
            if(next % 2 == 0) next++;
            else next += 2; // odd. +1 will make it even which won't
                            // be prime anyway
        }
        return next;
    }
}
