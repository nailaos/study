package shape;

public class Square extends Rectangle {

  Square() {
  }

  Square(double a) {
    super(a, a);
  }

  Square(double a, String c) {
    super(a, a, c);
  }

  public double getSide() {
    return getHeight();
  }

  public void setSide(double a) {
    setWidth(a);
    setHeight(a);
  }

  public String toString() {
    return String.format("Square(%s)", getColor());
  }
}
