package shape;

public abstract class Shape {
    private String color;

    Shape() {
        color = "#";
    }

    Shape(String c) {
        color = c;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String c) {
        color = c;
    }

    public boolean isFilled() {
        if (color == "#")
            return false;
        return true;
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public abstract String toString();
}
