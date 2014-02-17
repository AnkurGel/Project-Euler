//Largest product in a series
//Author: Ankur Goel
import java.io.*;
public class Problem8 {
    public static void main(String[] args) throws IOException{
        BufferedReader b = new BufferedReader(new FileReader("Problem8_data.txt"));
        String line = "", sequence = "";
        long product = 1, longest_product = 1;
        while((line = b.readLine()) != null)
            sequence += line;
        for(int i = 0; i <= sequence.length() - 5; i++){
            product = 1;
            String substr = sequence.substring(i, i+5);
            for(char c : substr.toCharArray()){
                product *= (int)c - 48;
            }
            if(product > longest_product) longest_product = product;
        }
        System.out.println(longest_product);
    }
}
