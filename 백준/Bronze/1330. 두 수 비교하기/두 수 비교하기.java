import java.util.Scanner;

public class Main {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();

    System.out.print((A > B) ? ">" : ((A < B) ? "<" : "=="));
    sc.close();
  }
}
