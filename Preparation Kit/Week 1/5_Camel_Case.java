import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (scanner.hasNextLine()) {
            String line = scanner.nextLine().trim();
            line = line.replaceAll("\r", "");

            char operation = line.charAt(0);
            char type = line.charAt(2);
            String input = line.substring(4);

            if (operation == 'S') {
                System.out.println(splitCamelCase(input, type));
            } else if (operation == 'C') {
                System.out.println(combineCamelCase(input, type));
            }
        }

        scanner.close();
    }

    public static String splitCamelCase(String input, char type) {
        if (type == 'M') {
            input = input.substring(0, input.length() - 2);
        }

        StringBuilder result = new StringBuilder();
        if (type == 'C') {
            result.append(Character.toLowerCase(input.charAt(0)));
        } else {
            result.append(input.charAt(0));
        }

        for (int i = 1; i < input.length(); i++) {
            char c = input.charAt(i);
            if (Character.isUpperCase(c)) {
                result.append(" ");
                result.append(Character.toLowerCase(c));
            } else {
                result.append(c);
            }
        }
        return result.toString();
    }

    public static String combineCamelCase(String input, char type) {
        String[] words = input.split(" ");
        StringBuilder result = new StringBuilder();

        if (type == 'C') {
            for (String word : words) {
                result.append(Character.toUpperCase(word.charAt(0)))
                      .append(word.substring(1));
            }
        } else {
            result.append(words[0].toLowerCase());
            for (int i = 1; i < words.length; i++) {
                result.append(Character.toUpperCase(words[i].charAt(0)))
                      .append(words[i].substring(1));
            }
            if (type == 'M') result.append("()");
        }

        return result.toString();
    }
}
