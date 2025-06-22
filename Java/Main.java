import java.util.*;
import java.time.LocalDate;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.println("Choose a program to run:");
            System.out.println("1. Vowel Consonant Counter");
            System.out.println("2. File Path Encoder");
            System.out.println("3. Text Search Tool");
            System.out.println("4. Number Palindrome Checker");
            System.out.println("5. String Palindrome Checker");
            System.out.println("6. Button Press Tracker");
            System.out.println("7. String Operations");
            System.out.println("8. Encoder Decoder");
            System.out.println("9. Array Element Counter");
            System.out.println("10. Pattern Printer");
            System.out.println("11. Animal Sound Demo");
            
            int choice = scanner.nextInt();
            scanner.nextLine(); // consume newline
            
            switch (choice) {
                case 1 -> VowelConsonantCounter.run(scanner);
                case 2 -> FilePathEncoder.run(scanner);
                case 3 -> TextSearchTool.run(scanner);
                case 4 -> NumberPalindromeChecker.run(scanner);
                case 5 -> PalindromeChecker.run(scanner);
                case 6 -> ButtonPressTracker.run(scanner);
                case 7 -> StringOperations.run(scanner);
                case 8 -> EncoderDecoder.run(scanner);
                case 9 -> ArrayElementCounter.run(scanner);
                case 10 -> PatternPrinter.run(scanner);
                case 11 -> AnimalSoundDemo.run();
                default -> System.out.println("Invalid choice");
            }
        }
    }

    static class VowelConsonantCounter {
        public static void run(Scanner scanner) {
            System.out.println("Enter a string:");
            String inputString = scanner.nextLine();
            
            int vowelCount = 0;
            int consonantCount = 0;
            String vowels = "AEIOUaeiou";
            
            for (int i = 0; i < inputString.length(); i++) {
                char ch = inputString.charAt(i);
                if (Character.isLetter(ch)) {
                    if (vowels.indexOf(ch) != -1) {
                        vowelCount++;
                    } else {
                        consonantCount++;
                    }
                }
            }
            
            System.out.println("Number of vowels: " + vowelCount);
            System.out.println("Number of consonants: " + consonantCount);
        }
    }

    static class FilePathEncoder {
        public static void run(Scanner scanner) {
            System.out.println("Enter file path:");
            String filePath = scanner.nextLine();
            String encodedPath = encodeFilePath(filePath);
            System.out.println(encodedPath);
        }
        
        public static String encodeFilePath(String filePath) {
            StringBuilder encodedPath = new StringBuilder();
            for (int i = 0; i < filePath.length(); i++) {
                char ch = filePath.charAt(i);
                if (ch == ' ') {
                    encodedPath.append("[space]");
                } else {
                    encodedPath.append(ch);
                }
            }
            return encodedPath.toString();
        }
    }

    static class TextSearchTool {
        public static void run(Scanner scanner) {
            System.out.println("Enter main string:");
            String mainString = scanner.nextLine();
            System.out.println("Enter target substring:");
            String targetSubstring = scanner.nextLine();
            
            if (mainString.contains(targetSubstring)) {
                System.out.println("Found Substring: " + targetSubstring);
            } else {
                System.out.println("Substring not found");
            }
        }
    }

    static class NumberPalindromeChecker {
        public static void run(Scanner scanner) {
            System.out.print("Enter a number: ");
            int number = scanner.nextInt();
            
            if (isPalindrome(number)) {
                System.out.println("The number is a palindrome.");
            } else {
                System.out.println("The number is not a palindrome.");
            }
        }
        
        public static boolean isPalindrome(int num) {
            int originalNum = num;
            int reversedNum = 0;
            
            while (num != 0) {
                int digit = num % 10;
                reversedNum = reversedNum * 10 + digit;
                num /= 10;
            }
            
            return originalNum == reversedNum;
        }
    }

    static class PalindromeChecker {
        public static void run(Scanner scanner) {
            System.out.print("Enter a string: ");
            String input = scanner.nextLine();
            
            if (isPalindrome(input)) {
                System.out.println("The string is a palindrome.");
            } else {
                System.out.println("The string is not a palindrome.");
            }
        }
        
        public static boolean isPalindrome(String str) {
            str = str.replaceAll("[^a-zA-Z0-9]", "").toLowerCase();
            int left = 0;
            int right = str.length() - 1;
            
            while (left < right) {
                if (str.charAt(left) != str.charAt(right)) {
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }
    }

    static class ButtonPressTracker {
        private int count;
        
        public ButtonPressTracker() {
            count = 0;
        }
        
        public void incrementCount(int n) {
            if (n >= 0) {
                this.count = n;
            } else {
                this.count = 0;
            }
        }
        
        public void displayCount() {
            System.out.println("Final Count: " + this.count);
        }
        
        public static void run(Scanner scanner) {
            System.out.println("Enter number of button presses:");
            int n = scanner.nextInt();
            
            ButtonPressTracker tracker = new ButtonPressTracker();
            tracker.incrementCount(n);
            tracker.displayCount();
        }
    }

    static class StringOperations {
        public static void run(Scanner scanner) {
            System.out.println("Enter string(s) separated by space:");
            String input = scanner.nextLine().trim();
            String[] inputData = input.split(" ");
            
            StringOps ops = new StringOps();
            String result = ops.manipulate(inputData);
            System.out.println(result);
        }
        
        static class StringOps {
            public String manipulate(String[] inputData) {
                if (inputData.length == 1) {
                    return new StringBuilder(inputData[0]).reverse().toString();
                } else if (inputData.length == 2) {
                    return inputData[0] + inputData[1];
                } else {
                    return "Invalid input";
                }
            }
        }
    }

    static class EncoderDecoder {
        public static void run(Scanner scanner) {
            System.out.println("Enter messages separated by space:");
            String userInput = scanner.nextLine();
            String[] messages = userInput.split(" ");
            
            EncoderDecoderLogic encoderDecoder = new EncoderDecoderLogic();
            String encoded = encoderDecoder.encode(messages);
            System.out.println("Encoded: " + encoded);
            
            String[] decoded = encoderDecoder.decode(encoded);
            System.out.println("Decoded: ");
            for (String message : decoded) {
                System.out.println(message);
            }
        }
        
        static class EncoderDecoderLogic {
            public String encode(String[] messages) {
                StringBuilder encodedString = new StringBuilder();
                for (int i = 0; i < messages.length; i++) {
                    encodedString.append(messages[i]);
                    if (i < messages.length - 1) {
                        encodedString.append("#");
                    }
                }
                return encodedString.toString();
            }
            
            public String[] decode(String encodedMessage) {
                return encodedMessage.split("#");
            }
        }
    }

    static class ArrayElementCounter {
        public static void run(Scanner scanner) {
            System.out.println("Enter no. of elements in the array:");
            int n = scanner.nextInt();
            int[] arr = new int[n];
            System.out.println("Enter elements in the array:");
            for (int i = 0; i < n; i++) {
                arr[i] = scanner.nextInt();
            }
            arrayElementCount(arr);
        }
        
        static void arrayElementCount(int[] arr) {
            HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
            for (int i : arr) {
                if (hm.containsKey(i)) {
                    hm.put(i, hm.get(i) + 1);
                } else {
                    hm.put(i, 1);
                }
            }
            System.out.println("Input array : " + Arrays.toString(arr));
            System.out.println("Element count : " + hm);
        }
    }

    static class PatternPrinter {
        public static void run(Scanner scanner) {
            System.out.println("Enter number of rows:");
            int n = scanner.nextInt();
            new PatternPrinterLogic(n);
        }
        
        static class PatternPrinterLogic {
            int n;
            
            PatternPrinterLogic(int n) {
                this.n = n;
                printPattern();
            }
            
            void printPattern() {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n - i; j++) {
                        System.out.print(" ");
                    }
                    for (int j = 1; j <= i; j++) {
                        System.out.print(j + " ");
                    }
                    System.out.println();
                }
            }
        }
    }

    static class AnimalSoundDemo {
        public static void run() {
            Animal myDog = new Dog();
            Animal myCat = new Cat();
            
            myDog.sound();
            myCat.sound();
        }
        
        static class Animal {
            void sound() {
                System.out.println("Animal makes a sound");
            }
        }
        
        static class Dog extends Animal {
            void sound() {
                System.out.println("Dog barks");
            }
        }
        
        static class Cat extends Animal {
            void sound() {
                System.out.println("Cat meows");
            }
        }
    }

    // Utility classes for advanced functionality
    static class Person {
        String name;
        int age;

        Person(String name, int age) {
            this.name = name;
            this.age = age;
        }

        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Person p = (Person) obj;
            return (age == p.age) && name.equals(p.name);
        }
    }

    static class GenericUtility {
        public <T> void printArray(T[] array) {
            for (T element : array) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
        
        public <T> T getMiddleElement(T[] array) {
            if (array == null || array.length == 0) {
                return null;
            }
            return array[array.length / 2];
        }
    }

    static class NumberOperations {
        public <T extends Number> double sumArray(T[] numbers) {
            double sum = 0.0;
            for (T number : numbers) {
                sum += number.doubleValue();
            }
            return sum;
        }
        
        public <T extends Number & Comparable<T>> T findMax(T[] numbers) {
            if (numbers == null || numbers.length == 0) {
                return null;
            }
            
            T max = numbers[0];
            for (int i = 1; i < numbers.length; i++) {
                if (numbers[i].compareTo(max) > 0) {
                    max = numbers[i];
                }
            }
            return max;
        }
    }
}
