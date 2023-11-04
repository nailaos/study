package exceptiontest;

public class XGreaterThanOneException extends Exception {

    public String getInfo() {
        return "Too large";
    }
}
