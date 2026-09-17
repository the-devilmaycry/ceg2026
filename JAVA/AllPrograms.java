import java.util.Scanner;

public class AllPrograms {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice;
        do {
            System.out.println("\n1. Odd or Even");
            System.out.println("2. Positive or Negative");
            System.out.println("3. Factorial");
            System.out.println("4. Fibonacci Series (for loop)");
            System.out.println("5. Fibonacci Series (while loop)");
            System.out.println("6. Fibonacci Series (do-while loop)");
            System.out.println("7. Prime Number Checking");
            System.out.println("8. Sum of Digits");
            System.out.println("9. Leap Year Checking");
            System.out.println("10. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter a number: ");
                    int n1 = sc.nextInt();
                    System.out.println(n1 % 2 == 0 ? "Even" : "Odd");
                    break;
                case 2:
                    System.out.print("Enter a number: ");
                    int n2 = sc.nextInt();
                    if (n2 > 0) System.out.println("Positive");
                    else if (n2 < 0) System.out.println("Negative");
                    else System.out.println("Zero");
                    break;
                case 3:
                    System.out.print("Enter a number: ");
                    int n3 = sc.nextInt();
                    long fact = 1;
                    for (int i = 1; i <= n3; i++) fact *= i;
                    System.out.println("Factorial: " + fact);
                    break;
                case 4:
                    System.out.print("Enter number of terms: ");
                    int terms = sc.nextInt();
                    int a = 0, b = 1, c;
                    System.out.print("Fibonacci (for): ");
                    for (int i = 1; i <= terms; i++) {
                        System.out.print(a + " ");
                        c = a + b;
                        a = b;
                        b = c;
                    }
                    System.out.println();
                    break;
                case 5:
                    System.out.print("Enter number of terms: ");
                    terms = sc.nextInt();
                    a = 0; b = 1;
                    System.out.print("Fibonacci (while): ");
                    int i = 1;
                    while (i <= terms) {
                        System.out.print(a + " ");
                        c = a + b;
                        a = b;
                        b = c;
                        i++;
                    }
                    System.out.println();
                    break;
                case 6:
                    System.out.print("Enter number of terms: ");
                    terms = sc.nextInt();
                    a = 0; b = 1;
                    System.out.print("Fibonacci (do-while): ");
                    i = 1;
                    do {
                        System.out.print(a + " ");
                        c = a + b;
                        a = b;
                        b = c;
                        i++;
                    } while (i <= terms);
                    System.out.println();
                    break;
                case 7:
                    System.out.print("Enter a number: ");
                    int n7 = sc.nextInt();
                    boolean isPrime = true;
                    if (n7 <= 1) isPrime = false;
                    else {
                        for (int j = 2; j <= Math.sqrt(n7); j++) {
                            if (n7 % j == 0) { isPrime = false; break; }
                        }
                    }
                    System.out.println(isPrime ? "Prime" : "Not Prime");
                    break;
                case 8:
                    System.out.print("Enter a number: ");
                    int n8 = sc.nextInt();
                    int sum = n8;
                    while (sum > 9) {
                        int temp = sum;
                        sum = 0;
                        while (temp > 0) { sum += temp % 10; temp /= 10; }
                    }
                    System.out.println("Sum of digits: " + sum);
                    break;
                case 9:
                    System.out.print("Enter a year: ");
                    int year = sc.nextInt();
                    boolean leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
                    System.out.println(leap ? "Leap year" : "Not a leap year");
                    break;
                case 10:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 10);
        sc.close();
    }
}