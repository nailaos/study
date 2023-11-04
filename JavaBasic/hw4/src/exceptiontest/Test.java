package exceptiontest;
import testutil.TestRunner;

import java.util.Random;

public class Test {
	private static Random random;
	private static int validInt;
	
	private static ExceptionTest et;

	public static void main(String[] args) {

		TestRunner.enableException(true);

		TestRunner.runTest(()->{
			random = new Random(1);
			validInt = -1;
			et =  new ExceptionTest();
			int ans0 = et.getFirstValidInt();
			System.out.println("Ans: "+ans0);
			System.out.println("Expected: "+validInt);
			if (ans0==validInt) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			random = new Random(12);
			validInt = 0;
			et =  new ExceptionTest();
			int ans0 = et.getFirstValidInt();
			System.out.println("Ans: "+ans0);
			System.out.println("Expected: "+validInt);
			if (ans0==validInt) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			et =  new ExceptionTest();
			String ans1 = solve(2);
			System.out.println("Ans: "+ans1);
			System.out.println("Expected: 0.693");
			if (ans1.equals("0.693")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			et =  new ExceptionTest();
			String ans1 = solve(0.5);
			System.out.println("Ans: "+ans1);
			System.out.println("Expected: 0.5 is too small");
			if (ans1.equals("0.5 is too small")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		System.exit(0);


	}
	
	public static String getRandomString() {
		if (validInt == -1) return "" + validInt;
		int now = random.nextInt(10);
		switch (now) {
		case 0:
			validInt = random.nextInt();
			return "" + validInt;
		case 1:
			return "" + random.nextFloat();
		case 2:
			return "" + random.nextDouble();
		case 3:
			return "" + random.nextGaussian();
		case 4: case 5:
			return "" + random.nextBoolean();
		case 6:
			return "" + random.nextLong();
		case 7: case 8: case 9:
			byte[] bytes = new byte[10];
			random.nextBytes(bytes);
			return bytes.toString();
		}
		return "xxx";
	}

	/**
	 * 读取一个随机整数，以一定概率抛出异常
	 * @return int类型的整数
	 * @throws NumberFormatException 未读取到合法的整数
	 */
	public static int readInt() throws NumberFormatException {
		return Integer.parseInt(getRandomString());
	}

	/**
	 * 求解代数方程e^x=y，x的定义域[0,1]
	 * @param y double 参数
	 * @return String 方程的解,保留3位小数. 若x<0，返回"y is too small"，例如"0.2 is too small"; 若x>0,返回"Too large".
	 */
	public static String solve(double y)  {
		double x = -1;
		try {
			x = et.getX(y);
			return String.format("%.3f",x);
		} catch (XLessThanZeroException e) {
			return e.getInfo();
		} catch (XGreaterThanOneException e) {
			return e.getInfo();
		}
	}

}
