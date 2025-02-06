import java.util.Scanner;

public class VowelConsonantCounter {

    public static void main(String[] args) {
        // Create a scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Input the string from the user
        String inputString = scanner.nextLine();

        // Initialize counters for vowels and consonants
        int vowelCount = 0;
        int consonantCount = 0;

        // Define vowels for easy checking (both uppercase and lowercase)
        String vowels = "AEIOUaeiou";

        // Iterate through each character in the string
        for (int i = 0; i < inputString.length(); i++) {
            char ch = inputString.charAt(i);

            // Check if the character is a letter (ignoring non-alphabetic characters)
            if (Character.isLetter(ch)) {
                // Check if the character is a vowel
                if (vowels.indexOf(ch) != -1) {
                    vowelCount++;
                }
                // Otherwise, it's a consonant
                else {
                    consonantCount++;
                }
            }
        }

        // Output the result
        System.out.println("Number of vowels: " + vowelCount);
        System.out.println("Number of consonants: " + consonantCount);

        // Close the scanner
        scanner.close();
    }
}


import java.util.Scanner;

class FilePathEncoderUtility {
    // Method to encode file path by replacing spaces with "[space]"
    public static String encodeFilePath(String filePath) {
        // Use StringBuilder to efficiently build the encoded string
        StringBuilder encodedPath = new StringBuilder();

        // Iterate through each character of the original file path
        for (int i = 0; i < filePath.length(); i++) {
            char ch = filePath.charAt(i);

            // If the character is a space, append "[space]" to the result
            if (ch == ' ') {
                encodedPath.append("[space]");
            } else {
                // Otherwise, append the character as is
                encodedPath.append(ch);
            }
        }

        // Return the final encoded string
        return encodedPath.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        // Create a scanner to read user input
        Scanner scanner = new Scanner(System.in);
        
        // Read the input file path from the user
        String filePath = scanner.nextLine();
        
        // Call the utility method to encode the file path
        String encodedPath = FilePathEncoderUtility.encodeFilePath(filePath);
        
        // Output the encoded path
        System.out.println(encodedPath);
        
        // Close the scanner
        scanner.close();
    }
}



public class FilePathEncoder {

    // Method to encode file path by replacing spaces with "[space]"
    public static String encodeFilePath(String filePath) {
        // Use StringBuilder to build the new string
        StringBuilder encodedPath = new StringBuilder();

        // Iterate through each character of the original file path
        for (int i = 0; i < filePath.length(); i++) {
            char ch = filePath.charAt(i);

            // If the character is a space, append "[space]" to the result
            if (ch == ' ') {
                encodedPath.append("[space]");
            } else {
                // Otherwise, append the character as is
                encodedPath.append(ch);
            }
        }

        // Return the final encoded string
        return encodedPath.toString();
    }

    public static void main(String[] args) {
        // Sample inputs for testing
        String path1 = "C:/Program Files/Java";
        String path2 = "/user/documents";
        
        // Output the encoded paths
        System.out.println(encodeFilePath(path1));  // Output: C:/Program[space]Files/Java
        System.out.println(encodeFilePath(path2));  // Output: /user/documents
    }
}



import java.util.Scanner;

public class TextSearchTool {

    public static void main(String[] args) {
        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);
        
        // Input the main string and the target substring
        String mainString = scanner.nextLine();
        String targetSubstring = scanner.nextLine();
        
        // Check if the target substring exists in the main string
        if (mainString.contains(targetSubstring)) {
            System.out.println("Found Substring: " + targetSubstring);
        } else {
            System.out.println("Substring not found");
        }
        
        // Close the scanner
        scanner.close();
    }
}




import java.util.Scanner;

public class NumberPalindromeChecker {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input a number from the user
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        
        // Check if the number is a palindrome
        if (isPalindrome(number)) {
            System.out.println("The number is a palindrome.");
        } else {
            System.out.println("The number is not a palindrome.");
        }
        
        scanner.close();
    }

    // Method to check if a number is a palindrome
    public static boolean isPalindrome(int num) {
        int originalNum = num;  // Store the original number
        int reversedNum = 0;
        
        // Reverse the digits of the number
        while (num != 0) {
            int digit = num % 10;  // Extract the last digit
            reversedNum = reversedNum * 10 + digit;  // Append the digit to reversedNum
            num /= 10;  // Remove the last digit
        }
        
        // Compare the original number with the reversed number
        return originalNum == reversedNum;
    }
}




import java.util.Scanner;

public class PalindromeChecker {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input a string from the user
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        
        // Check if the string is a palindrome
        if (isPalindrome(input)) {
            System.out.println("The string is a palindrome.");
        } else {
            System.out.println("The string is not a palindrome.");
        }
        
        scanner.close();
    }

    // Method to check if a string is a palindrome
    public static boolean isPalindrome(String str) {
        // Remove spaces and convert to lowercase for a case-insensitive check
        str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();

        int left = 0;
        int right = str.length() - 1;

        // Compare characters from both ends of the string
        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false;  // If any characters don't match, it's not a palindrome
            }
            left++;
            right--;
        }
        return true;  // If all characters match, it's a palindrome
    }
}



import java.util.Scanner;

public class ButtonPressTracker {

    // Instance variable to hold the count
    private int count;

    // Constructor to initialize the count to 0
    public ButtonPressTracker() {
        count = 0;
    }

    // Method to increment the count using the "this" keyword
    public void incrementCount(int n) {
        if (n >= 0) {
            this.count = n; // Using "this" to refer to the instance variable count
        } else {
            this.count = 0; // If a negative number is entered, set count to 0
        }
    }

    // Method to display the final count
    public void displayCount() {
        System.out.println("Final Count: " + this.count); // Using "this" to refer to the instance variable count
    }

    public static void main(String[] args) {
        // Creating a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Reading the number of button presses
        int n = scanner.nextInt();

        // Create an object of ButtonPressTracker
        ButtonPressTracker tracker = new ButtonPressTracker();

        // Increment the count based on the input value
        tracker.incrementCount(n);

        // Display the final count
        tracker.displayCount();

        // Close the scanner
        scanner.close();
    }
}
