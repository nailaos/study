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

    public double getWidth() {
        return width;
    }

    public void setHeight(double h) {
        height = h;
    }

    public void setWidth(double w) {
        width = w;
    }

    public double getArea() {
        return width * height;
    }

    public double getPerimeter() {
        return (width + height) * 2;
    }

    public String toString() {
        return String.format("Rectangle(%s)", getColor());
    }
}
