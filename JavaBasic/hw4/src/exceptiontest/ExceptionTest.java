package exceptiontest;

public class ExceptionTest {

    public int getFirstValidInt() {
        while (true) {
            try {
                int ans = Test.readInt();
                return ans;
            } catch (NumberFormatException e) {
            }
        }
    }

    public double getX(double y) throws XLessThanZeroException, XGreaterThanOneException {
        if (y < 1.0)
            throw new XLessThanZeroException(y);
        double x = Math.log(y);
        if (x > 1.0)
            throw new XGreaterThanOneException();
        return x;
    }
}
