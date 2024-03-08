import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int score = sc.nextInt();

    System.out.print(
      90 <= score && score <= 100
        ? "A"
        : 80 <= score && score < 90
          ? "B"
          : 70 <= score && score < 80
            ? "C"
            : 60 <= score && score < 70 ? "D" : "F"
    );
    sc.close();
  }
}
