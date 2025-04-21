import java.util.Scanner;

class VowelConsonantCounter {

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

import java.util.Scanner;

class StringOps {

    // Method to reverse a string
    public String manipulate(String[] inputData) {
        if (inputData.length == 1) {
            return new StringBuilder(inputData[0]).reverse().toString(); // Reverse single string
        } else if (inputData.length == 2) {
            return inputData[0] + inputData[1]; // Concatenate two strings
        } else {
            return "Invalid input"; // More than two strings
        }
    }
}

public class Main {
    public static void main(String[] args) {
        StringOps seetha = new StringOps();
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine().trim();
        
        // Split the input string by spaces into an array
        String[] input_data = input.split(" ");
        
        // Call manipulate method and print the result
        String result = seetha.manipulate(input_data);
        System.out.println(result);
    }
}

import java.util.Scanner;

class EncoderDecoder {

    // Method to encode the messages
    public String encode(String[] messages) {
        StringBuilder encodedString = new StringBuilder();
        for (int i = 0; i < messages.length; i++) {
            encodedString.append(messages[i]);
            if (i < messages.length - 1) {
                encodedString.append("#"); // Add the '#' delimiter between messages
            }
        }
        return encodedString.toString();
    }

    // Method to decode the encoded string
    public String[] decode(String encodedMessage) {
        return encodedMessage.split("#"); // Split the encoded string by '#' to get individual messages
    }
}

public class Main {
    public static void main(String[] args) {
        EncoderDecoder encoderDecoder = new EncoderDecoder();
        Scanner scanner = new Scanner(System.in);
        
        // Read user input
        String userInput = scanner.nextLine();
        String[] messages = userInput.split(" "); // Split input string by space for encoding
        
        // Encode the messages
        String encoded = encoderDecoder.encode(messages);
        System.out.println("Encoded: " + encoded);
        
        // Decode the encoded message
        String[] decoded = encoderDecoder.decode(encoded);
        System.out.println("Decoded: ");
        for (String message : decoded) {
            System.out.println(message); // Output each decoded message
        }

        scanner.close();
    }
}

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

public class prac{

    static void arrayElementCount(int[] arr){
        HashMap<Integer,Integer> hm = new HashMap<Integer,Integer>();
        for(int i : arr){
            if(hm.containsKey(i)){
                hm.put(i,hm.get(i)+1);
            }else {
                hm.put(i, 1);
            }
        }
        System.out.println("Input array : " + Arrays.toString(arr));
        System.out.println("Element count : " + hm);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        System.out.println("Enter no. of elements in the array:");
        n = scanner.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements in the array:");
        for(int i = 0; i < n ; i++) {
            arr[i] = scanner.nextInt();
        }
        arrayElementCount(arr);
    }
}
// comparing data fields and class object function overriding 
class Person {
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

class EqualsExample{
   public static void main(String[] args) {
         Person p1 = new Person("John", 30);
         Person p2 = new Person("John", 30);
         Person p3 = new Person("Jane", 25);
         System.out.println(p1.equals(p2)); // true
         System.out.println(p1.equals(p3)); // false
   } 
}


class Demo {
    
    //Override
    protected void finalize() {
        System.out.println("Object is garbage collected");
    }
}
class FinalizeExample {
    public static void main(String[] args) {
        Demo obj = new Demo();
        obj = null;     // marking object for garbage collection
        System.gc();    // suggest garbage collector
    }
}

// Triangle pattern printing using nested loops

class Solution {
    static class PatternPrinter {
        int n;
        
        PatternPrinter(int n) {
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
    
    public static void main(String[] args) {
        new PatternPrinter(5);
    }
}

// days calculator using class and interface

class DaysCalculatorImpl { 
     public static DaysCalculator createCalculator(){ 
         return new DaysCalculator(){ 
             public int calculateDays(int[] date1, int[] date2){ 
                  
                  
                 if(date1[0]<2000 || date1[0]>2024 || date2[0]<2000 || date2[0]>2024){ 
                    throw new IllegalArgumentException("Year must be between 2000 to 2024");  
                 } 
                  
                 int days1 = date1[0]*365 + date1[1]*30 + date1[2]; 
                 int days2 = date2[0]*365 + date2[1]* 30 + date2[2]; 
                  
                 int smallerYear = Math.min(date1[0],date2[0]); 
                 int largerYear = Math.max(date1[0],date2[0]); 
                  
                 for(int year = smallerYear; year < largerYear; year++){ 
                     if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)){ 
                         if(date1[0]> date2[0]){ 
                             days1++; 
                         }else{ 
                             days2++; 
                         } 
         
                     } 
                 } 
                 return Math.abs(days2 - days1); 
             } 
         }; 
     } 
} 

    
class GrowthLogger {
    private int day;
    private double height;
    public GrowthLogger(double initialHeight) {
        day = 0;
        height = initialHeight;
    }
    public class PlantGrowth {
        public double recordgrowth(double growth) {
            day++;
            height += growth;
            return height;
        }
    }
    
    public double[] startMonitorying(int days, double dailyGrowth) {
        PlantGrowth pg = new PlantGrowth();
        double[] growthRecord = new double[days];
        for (int i = 0; i < days; i++) {
            growthRecord[i] = pg.recordgrowth(dailyGrowth);
        }
        return growthRecord;
    }
} 

// NumberProcessorLogic class with exception handling

class NumberProcessorLogic { 
    public static class NegativeNumberException extends Exception{ 
        public NegativeNumberException(String message){ 
            super(message); 
        } 
    } 
    public static int processInput(int number) throws NegativeNumberException{ 
        if(number<0){ 
            throw new NegativeNumberException(number + " is negative"); 
        } 
        return 2 * number; 
    } 
}


// phone number validator logic 

class PhoneNumberValidatorLogic { 
    public static void validatePhoneNumber(String phoneNumber) 
    { 
        if(!phoneNumber.matches("\\d+")){ 
            throw new InputMismatchException("Input mismatch. Please enter a valid 10-digit 
phone number."); 
        } 
        if(phoneNumber.length()!=10) 
        { 
            throw new IllegalArgumentException("Invalid phone number: Must be a 10-digit 
number."); 
        } 
    } 
} 
 
class PhoneNumberValidatorHandler { 
    public void handleValidation(){ 
        Scanner scanner = new Scanner(System.in); 
        try{ 
            String phoneNumber = scanner.nextLine(); 
            PhoneNumberValidatorLogic.validatePhoneNumber(phoneNumber); 
            System.out.print("Valid"); 
        } 
        catch(InputMismatchException e) 
        { 
            System.out.print("Error: "+e.getMessage()); 
        } 
        catch(IllegalArgumentException e) 
        { 
            System.out.print("Error: "+e.getMessage()); 
        } 
        finally{ 
            scanner.close(); 
        } 
    } 
} 

// date validator 

class DateValidator { 
    public static String getDayType(String dateStr){ 
        String[] parts = dateStr.split(" "); 
        int day = Integer.parseInt(parts[0]); 
        int month = Integer.parseInt(parts[1]); 
        int year = Integer.parseInt(parts[2]); 
         
        LocalDate date = LocalDate.of(year, month, day); 
        int dayOfWeek = date.getDayOfWeek().getValue(); 
         
        if(dayOfWeek == 6 || dayOfWeek == 7){ 
            return "Weekend"; 
        }else{ 
            return "Weekday"; 
        } 
    } 
     
} 

// Class 1: Basic generic method example
class GenericUtility {
    // A generic method to print any type of array
    public <T> void printArray(T[] array) {
        for (T element : array) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
    
    // A generic method that returns the same type as its input
    public <T> T getMiddleElement(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }
        return array[array.length / 2];
    }
}

// Class 2: Generic method with multiple type parameters
class PairProcessor {
    // Method with two type parameters
    public <K, V> void printPair(K key, V value) {
        System.out.println("Key: " + key + ", Value: " + value);
    }
    
    // Method that returns a map with generic key and value types
    public <K, V> Map<K, V> createMap(K[] keys, V[] values) {
        if (keys.length != values.length) {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }
        
        Map<K, V> map = new HashMap<>();
        for (int i = 0; i < keys.length; i++) {
            map.put(keys[i], values[i]);
        }
        return map;
    }
}

// Class 3: Generic method with bounded type parameters
class NumberOperations {
    // Method that accepts any Number type (Integer, Double, etc.)
    public <T extends Number> double sumArray(T[] numbers) {
        double sum = 0.0;
        for (T number : numbers) {
            sum += number.doubleValue();
        }
        return sum;
    }
    
    // Method with multiple bounds (T must be both a Number and Comparable)
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
class GenericUtility {
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
    
    public <T> T getFirstElement(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }
        return array[0];
    }
    
    public <T> T getLastElement(T[] array) {
        if (array == null || array.length == 0) {
            return null;
        }
        return array[array.length - 1];
    }
    
    public <T> void swapElements(T[] array, int i, int j) {
        if (array == null || i < 0 || j < 0 || i >= array.length || j >= array.length) {
            return;
        }
        T temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    public <T> T[] reverseArray(T[] array) {
        if (array == null) {
            return null;
        }
        for (int i = 0; i < array.length / 2; i++) {
            swapElements(array, i, array.length - i - 1);
        }
        return array;
    }
}

class PairProcessor {
    public <K, V> void printPair(K key, V value) {
        System.out.println("Key: " + key + ", Value: " + value);
    }
    
    public <K, V> Map<K, V> createMap(K[] keys, V[] values) {
        if (keys.length != values.length) {
            throw new IllegalArgumentException("Arrays must be of the same length");
        }
        
        Map<K, V> map = new HashMap<>();
        for (int i = 0; i < keys.length; i++) {
            map.put(keys[i], values[i]);
        }
        return map;
    }
    
    public <K, V> Map<V, K> invertMap(Map<K, V> map) {
        Map<V, K> inverted = new HashMap<>();
        for (Map.Entry<K, V> entry : map.entrySet()) {
            inverted.put(entry.getValue(), entry.getKey());
        }
        return inverted;
    }
    
    public <K, V> List<K> getKeysByValue(Map<K, V> map, V value) {
        List<K> keys = new ArrayList<>();
        for (Map.Entry<K, V> entry : map.entrySet()) {
            if (Objects.equals(value, entry.getValue())) {
                keys.add(entry.getKey());
            }
        }
        return keys;
    }
    
    public <T> Pair<T, T> createPair(T first, T second) {
        return new Pair<>(first, second);
    }
    
    public static class Pair<A, B> {
        private A first;
        private B second;
        
        public Pair(A first, B second) {
            this.first = first;
            this.second = second;
        }
        
        public A getFirst() { return first; }
        public B getSecond() { return second; }
        public void setFirst(A first) { this.first = first; }
        public void setSecond(B second) { this.second = second; }
        
        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }
}

class NumberOperations {
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
    
    public <T extends Number & Comparable<T>> T findMin(T[] numbers) {
        if (numbers == null || numbers.length == 0) {
            return null;
        }
        
        T min = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i].compareTo(min) < 0) {
                min = numbers[i];
            }
        }
        return min;
    }
    
    public <T extends Number> double average(T[] numbers) {
        if (numbers == null || numbers.length == 0) {
            throw new IllegalArgumentException("Array cannot be empty");
        }
        return sumArray(numbers) / numbers.length;
    }
    
    public <T extends Number> T[] sortNumbers(T[] numbers) {
        Arrays.sort(numbers, (a, b) -> Double.compare(a.doubleValue(), b.doubleValue()));
        return numbers;
    }
    
    public <T extends Number> boolean isAllPositive(List<T> numbers) {
        return numbers.stream().allMatch(n -> n.doubleValue() > 0);
    }
}

class GenericStack<T> {
    private ArrayList<T> elements = new ArrayList<>();
    
    public void push(T item) {
        elements.add(item);
    }
    
    public T pop() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return elements.remove(elements.size() - 1);
    }
    
    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        }
        return elements.get(elements.size() - 1);
    }
    
    public boolean isEmpty() {
        return elements.isEmpty();
    }
    
    public int size() {
        return elements.size();
    }
}


class Animal {
    void sound() {
        System.out.println("Animal makes a sound");
    }
}
class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
}
class Cat extends Animal {
    void sound() {
        System.out.println("Cat meows");
    }
}
class AnimalSoundDemo {
    public static void main(String[] args) {
        Animal myDog = new Dog();
        Animal myCat = new Cat();
        
        myDog.sound(); 
        myCat.sound(); 
    }
}