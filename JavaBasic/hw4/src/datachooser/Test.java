package datachooser;

import testutil.TestRunner;

public class Test {
    public static void main(String[] args) {
        TestRunner.enableException(true);

        TestRunner.runTest(() -> {
            String inputfile = "/home/lvjx/study/JavaBasic/hw4/data/data.csv";
            String outputfile = "/home/lvjx/study/JavaBasic/hw4/data/ans.csv";
            String ans = "/home/lvjx/study/JavaBasic/hw4/data/data_out.csv";
            DataChooser.choose(inputfile, outputfile);
            System.out.println("Accept");
        }, 1000);
    }
}
