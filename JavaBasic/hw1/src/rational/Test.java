package rational;

import testutil.TestRunner;

public class Test {
    public static void main(String[] args) {

        TestRunner.runTest(() -> {
            Rational r = new Rational(2, 4);
            System.out.println("Ans: " + r);
            System.out.println("Expected: 1/2");
            if (r.numerator == 1 && r.denominator == 2 && r.toString().equals("1/2"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(2, 4);
            r.add(new Rational(2, 3));
            System.out.println("Ans: " + r);
            System.out.println("Expected: 7/6");
            if (r.numerator == 7 && r.denominator == 6)
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(7, 6);
            r.sub(new Rational(3, 4));
            System.out.println("Ans: " + r);
            System.out.println("Expected: 5/12");
            if (r.numerator == 5 && r.denominator == 12)
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(5, 12);
            r.mul(new Rational(6, 7));
            System.out.println("Ans: " + r);
            System.out.println("Expected: 5/14");
            if (r.numerator == 5 && r.denominator == 14)
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(5, 14);
            r.div(new Rational(5, 21));
            System.out.println("Ans: " + r);
            System.out.println("Expected: 3/2");
            if (r.numerator == 3 && r.denominator == 2)
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(3, 2);
            System.out.println("Ans: " + r.toDouble());
            System.out.println("Expected: 1.5");
            if (r.toDouble() == 1.5)
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        TestRunner.runTest(() -> {
            Rational r = new Rational(3, 2);
            r.add(new Rational(1, 2));
            System.out.println("Ans: " + r);
            System.out.println("Expected: 2");
            if (r.toString().equals("2"))
                System.out.println("Accept");
            else
                System.out.println("Wrong Answer");
        }, 1000);

        System.exit(0);

    }
}
