package shape;

public class Shapes {
    Shape[] shapes;

    Shapes(Shape[] s) {
        shapes = s;
    }

    public double getArea() {
        double res = 0.0;
        for (int i = 0; i < shapes.length; i++) {
            res += shapes[i].getArea();
        }
        return res;
    }

    public double getFilledArea() {
        double res = 0.0;
        for (int i = 0; i < shapes.length; i++) {
            if (shapes[i].isFilled())
                res += shapes[i].getArea();
        }
        return res;
    }

    public double getPerimeter() {
        double res = 0.0;
        for (int i = 0; i < shapes.length; i++) {
            res += shapes[i].getPerimeter();
        }
        return res;
    }

    public String toString() {
        StringBuilder res = new StringBuilder("[");
        for (int i = 0; i < shapes.length; i++) {
            res.append(shapes[i].toString());
            if (i < shapes.length - 1)
                res.append(",");
        }
        res.append("]");
        return res.toString();
    }
}