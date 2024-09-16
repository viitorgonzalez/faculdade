import java.util.Scanner;

public class App {
    public static boolean ageValidation(int age) {
        Boolean bool = false;
        if(age >= 18) bool = true;

        return bool;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.println("Digite seu idade:");
        int age = sc.nextInt();

        System.out.println(ageValidation(age));

        sc.close();
    }
}
