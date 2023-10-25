package tictactoe;

//import rational.Rational;
import testutil.TestRunner;

public class Test {
    public static void main(String[] args) {

        TestRunner.runTest(() -> {
            TicTacToe game = new TicTacToe();
            String s = "";
            s += game.place(1, 1, 1);
            System.out.println("Ans: " + s);
            System.out.println("Expected: 0");
            if (s.equals("0"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            TicTacToe game = new TicTacToe();
            String s = "";
            s += game.place(1, 1, 1);
            s += game.place(2, 1, 1);
            System.out.println("Ans: " + s);
            System.out.println("Expected: 03");
            if (s.equals("03"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            TicTacToe game = new TicTacToe();
            String s = "";
            s += game.place(1, 1, 1);
            s += game.place(2, 0, 1);
            s += game.place(1, 0, 0);
            s += game.place(2, 1, 0);
            s += game.place(1, 0, 2);
            s += game.place(2, 2, 1);
            s += game.place(1, 2, 2);
            System.out.println("Ans: " + s);
            System.out.println("Expected: 0000001");
            if (s.equals("0000001"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            TicTacToe game = new TicTacToe();
            String s = "";
            s += game.place(2, 0, 0);
            s += game.place(1, 2, 2);
            s += game.place(2, 0, 1);
            s += game.place(1, 2, 1);
            s += game.place(2, 0, 1);
            s += game.place(2, 0, 2);
            System.out.println("Ans: " + s);
            System.out.println("Expected: 000032");
            if (s.equals("000032"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            TicTacToe game = new TicTacToe();
            String s = "";
            s += game.place(2, 1, 1);
            s += game.place(1, 1, 2);
            s += game.place(2, 2, 1);
            s += game.place(1, 0, 0);
            s += game.place(2, 0, 1);
            System.out.println("Ans: " + s);
            System.out.println("Expected: 00002");
            if (s.equals("00002"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        System.exit(0);

    }
}
