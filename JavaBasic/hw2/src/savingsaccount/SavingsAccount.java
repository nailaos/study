package savingsaccount;

public class SavingsAccount {
    static double rate = 0.01;
    double savings;

    SavingsAccount(double s) {
        savings = s;
    }

    public static void modifyInterestRate(double newrate) {
        rate = newrate;
    }

    public double calculateMonthlyInterest() {
        double e = Math.pow((1.0 + rate), (1.0 / 12.0)) - 1.0;
        double ans = savings * e;
        savings += ans;
        return ans;
    }
}