package date;

import testutil.TestRunner;

public class Test {
	public static void main(String[] args)  {

		TestRunner.enableException(true);

		TestRunner.runTest(()->{
			Date date0 = new Date("Jan.14,2014");
			System.out.println("Ans: "+date0);
			System.out.println("Expected: 2014/1/14");
			if (date0.toString().equals("2014/1/14")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Date date0 = new Date("Oct.", 20, 2017);
			System.out.println("Ans: "+date0);
			System.out.println("Expected: 2017/10/20");
			if (date0.toString().equals("2017/10/20")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Date date0 = new Date(31, 3, 2018);
			System.out.println("Ans: "+date0);
			System.out.println("Expected: 2018/3/31");
			if (date0.toString().equals("2018/3/31")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Date date0 = new Date("Sept.7,1042");
			System.out.println("Ans: "+date0);
			System.out.println("Expected: 1042/9/7");
			if (date0.toString().equals("1042/9/7")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			Date date0 = new Date("Dec.", 1, 1999);
			System.out.println("Ans: "+date0);
			System.out.println("Expected: 1999/12/1");
			if (date0.toString().equals("1999/12/1")) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		System.exit(0);


	}
}
