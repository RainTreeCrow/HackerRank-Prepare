import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
    // Write your code here
        int n = arr.size();
        int positives = 0;
        int negatives = 0;
        int zeros = 0;

        for (int num : arr) {
            if (num > 0) {
                positives++;
            } else if (num < 0) {
                negatives++;
            } else {
                zeros++;
            }
        }

        double positive_ratio = (double) positives / n;
        double negative_ratio = (double) negatives / n;
        double zero_ratio = (double) zeros / n;

        System.out.printf("%.6f%n", positive_ratio);
        System.out.printf("%.6f%n", negative_ratio);
        System.out.printf("%.6f%n", zero_ratio);
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}
