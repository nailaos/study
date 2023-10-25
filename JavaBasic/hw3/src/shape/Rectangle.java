package shape;

public class Rectangle extends Shape {
    private double height;
    private double width;

    Rectangle() {

    }

    Rectangle(double h, double w) {
        super();
        height = h;
        width = w;
    }

    Rectangle(double h, double w, String c) {
        super(c);
        height = h;
        width = w;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double h) {
        height = h;
    }
}