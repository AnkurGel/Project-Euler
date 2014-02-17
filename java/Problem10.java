import static utilities.General.is_prime;
import static utilities.General.generate_next_prime;

public class Problem10 {
    public static void main(String[] args){
        long prime = 2, sum = 2;
        while((prime = generate_next_prime(prime)) < 2000000){
            sum += prime;
        }
        System.out.println(sum);
    }
}
