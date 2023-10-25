package example;

public class Test {
    public static void main(String[] args) {
        Example example = new Example();
        int y = example.show(10);
        if (y == 11) {
            System.out.println("Correct!");
        } else {
            System.out.println("Wrong!");
        }
    }
}