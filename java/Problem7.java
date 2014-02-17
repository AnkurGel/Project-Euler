import static utilities.General.is_prime;
import static utilities.General.generate_next_prime;
public class Problem7{
    public static void main(String[] args){
        int count = 1;
        long i = 2;
        while(count != 10001){
            i = generate_next_prime(i);
            count++;
        }
        System.out.println(i);
    }
    
}
