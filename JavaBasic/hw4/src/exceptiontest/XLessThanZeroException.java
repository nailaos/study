package exceptiontest;

public class XLessThanZeroException extends Exception {
    private double y;

    public XLessThanZeroException(double _y) {
        y = _y;
    }

    public String getInfo() {
        return y + " is too small";
    }
}
