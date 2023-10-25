package complex;

import testutil.TestRunner;

public class Test {
	public static void main(String[] args) {

		TestRunner.runTest(() -> {
			Complex c = new Complex(0, 0);
			System.out.println("Ans: " + c);
			System.out.println("Expected: 0.000");
			if (c.toString().equals("0.000"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex c = new Complex(1, 1);
			System.out.println("Ans: " + c);
			System.out.println("Expected: 1.000+1.000i");
			if (c.toString().equals("1.000+1.000i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(1, 1);
			Complex b = new Complex(-2, -3);
			Complex c = a.add(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: -1.000-2.000i");
			if (c.toString().equals("-1.000-2.000i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(4, 1.7);
			Complex b = new Complex(4, 0.2);
			Complex c = a.sub(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: 1.500i");
			if (c.toString().equals("1.500i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(2, 2);
			Complex b = new Complex(3, -1.5);
			Complex c = a.sub(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: -1.000+3.500i");
			if (c.toString().equals("-1.000+3.500i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(13.2, 4.7);
			Complex b = new Complex(13.2, -4.7);
			Complex c = a.mul(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: 196.330");
			if (c.toString().equals("196.330"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(12, -3);
			Complex b = new Complex(6, -24);
			Complex c = a.mul(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: -306.000i");
			if (c.toString().equals("-306.000i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		TestRunner.runTest(() -> {
			Complex a = new Complex(-512.421, -123.564);
			Complex b = new Complex(891.324, -738.731);
			Complex c = a.div(b);
			System.out.println("Ans: " + c);
			System.out.println("Expected: -0.273-0.365i");
			if (c.toString().equals("-0.273-0.365i"))
				System.out.println("Accept");
			else
				System.out.println("Wrong Answer");
		}, 1000);

		System.exit(0);

	}
}
