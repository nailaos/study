package filesearcher;
import testutil.TestRunner;


public class Test {
	public static void main(String[] args) {
		TestRunner.enableException(true);

		TestRunner.runTest(()->{
			String inputFile = "改为data/dialog.txt在您系统中的绝对路径";
			int ans = FileSearcher.search(inputFile, "we");
			System.out.println("Ans: "+ans);
			System.out.println("Expected: "+35);
			if (ans==35) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			String inputFile = "改为data/dialog.txt在您系统中的绝对路径";
			int ans = FileSearcher.search(inputFile, "google");
			System.out.println("Ans: "+ans);
			System.out.println("Expected: "+0);
			if (ans==0) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		TestRunner.runTest(()->{
			String inputFile = "改为data/dialog.txt在您系统中的绝对路径";
			int ans = FileSearcher.search(inputFile, "August");
			System.out.println("Ans: "+ans);
			System.out.println("Expected: "+46);
			if (ans==46) System.out.println("Accept");
			else System.out.println("Wrong Answer");
		},1000);

		System.exit(0);
	}
}

