package savingsaccount;

import testutil.TestRunner;

//import java.util.Arrays;

public class Test {
	public static void main(String[] args) {

		TestRunner.enableException(true);

		TestRunner.runTest(() -> {
			SavingsAccount saver0 = new SavingsAccount(2000);
			double balance0 = saver0.calculateMonthlyInterest();
			System.out.println("Ans: " + String.format("%.3f", balance0));
			System.out.println("Expected: " + "1.659");
			if (String.format("%.3f", balance0).equals("1.659"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			SavingsAccount saver0 = new SavingsAccount(20000);
			SavingsAccount saver1 = new SavingsAccount(30000);
			double balance00 = saver0.calculateMonthlyInterest();
			double balance01 = saver0.calculateMonthlyInterest();
			double balance10 = saver1.calculateMonthlyInterest();
			double balance11 = saver1.calculateMonthlyInterest();
			String ans = String.format("%.3f %.3f %.3f %.3f", balance00, balance01,
					balance10, balance11);
			System.out.println("Ans: " + ans);
			System.out.println("Expected: " + "16.591 16.605 24.886 24.907");
			if (ans.equals("16.591 16.605 24.886 24.907"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			SavingsAccount.modifyInterestRate(0.015);
			SavingsAccount saver0 = new SavingsAccount(240000);
			double balance0 = saver0.calculateMonthlyInterest();
			SavingsAccount.modifyInterestRate(0.01);
			String ans = String.format("%.3f", balance0);
			System.out.println("Ans: " + ans);
			System.out.println("Expected: " + "297.957");
			if (ans.equals("297.957"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			SavingsAccount saver0 = new SavingsAccount(600000);
			double balance0 = saver0.calculateMonthlyInterest();
			SavingsAccount.modifyInterestRate(0.02);
			SavingsAccount saver1 = new SavingsAccount(504000);
			double balance1 = saver0.calculateMonthlyInterest();
			double balance2 = saver1.calculateMonthlyInterest();
			SavingsAccount.modifyInterestRate(0.01);
			String ans = String.format("%.3f %.3f %.3f", balance0, balance1, balance2);
			System.out.println("Ans: " + ans);
			System.out.println("Expected: " + "497.723 991.771 832.397");
			if (ans.equals("497.723 991.771 832.397"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		System.exit(0);

	}
}
