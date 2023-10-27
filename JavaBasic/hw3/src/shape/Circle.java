package shape;

public class Circle extends Shape {
    private double radius;

    Circle() {

    }

    Circle(double r) {
        super();
        radius = r;
    }

    Circle(double r, String c) {
        super(c);
        radius = r;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double r) {
        radius = r;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public double getPerimeter() {
        return Math.PI * radius * 2;
    }

    public String toString() {
        return String.format("Circle(%s)", getColor());
    }
}
