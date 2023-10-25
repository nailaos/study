package complex;

public class Complex {
    public double realPart;
    public double imagePart;

    public Complex(double real, double image) {
        realPart = real;
        imagePart = image;
    }

    public String toString() {
        if (realPart == 0 && imagePart == 0)
            return "0.000";

        String realStr = (realPart != 0) ? String.format("%.3f", realPart) : "";
        String imageStr = (imagePart != 0) ? String.format("%.3fi", imagePart) : "";
        String res = realStr + ((realPart != 0 && imagePart > 0) ? "+" : "") + imageStr;

        return res;
    }

    public Complex add(Complex x) {
        double a = realPart + x.realPart;
        double b = imagePart + x.imagePart;
        return new Complex(a, b);
    }

    public Complex sub(Complex x) {
        double a = realPart - x.realPart;
        double b = imagePart - x.imagePart;
        return new Complex(a, b);
    }

    public Complex mul(Complex x) {
        double a = realPart * x.realPart - imagePart * x.imagePart;
        double b = realPart * x.imagePart + imagePart * x.realPart;
        return new Complex(a, b);
    }

    public Complex div(Complex x) {
        double tmp = x.realPart * x.realPart + x.imagePart * x.imagePart;
        double a = (realPart * x.realPart + imagePart * x.imagePart) / tmp;
        double b = (imagePart * x.realPart - realPart * x.imagePart) / tmp;
        return new Complex(a, b);
    }
}