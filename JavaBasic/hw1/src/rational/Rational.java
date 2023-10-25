package rational;

public class Rational {
    public int numerator;
    public int denominator;

    public Rational(int num, int den) {
        numerator = num;
        denominator = den;
        simplify();
    }

    public String toString() {
        if (denominator == 1)
            return String.format("%d", numerator);
        else
            return String.format("%d/%d", numerator, denominator);
    }

    public double toDouble() {
        double res = (double) numerator / denominator;
        return res;
    }

    public void add(Rational x) {
        int b = denominator * x.denominator;
        int a = numerator * x.denominator + denominator * x.numerator;
        numerator = a;
        denominator = b;
        simplify();
    }

    public void sub(Rational x) {
        int b = denominator * x.denominator;
        int a = numerator * x.denominator - denominator * x.numerator;
        numerator = a;
        denominator = b;
        simplify();
    }

    public void mul(Rational x) {
        int a = numerator * x.numerator;
        int b = denominator * x.denominator;
        numerator = a;
        denominator = b;
        simplify();
    }

    public void div(Rational x) {
        int a = numerator * x.denominator;
        int b = denominator * x.numerator;
        numerator = a;
        denominator = b;
        simplify();
    }

    void simplify() {
        int r = 1;
        int a = numerator, b = denominator;
        while (r != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        numerator /= a;
        denominator /= a;
    }
}