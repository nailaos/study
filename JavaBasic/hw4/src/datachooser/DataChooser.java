package datachooser;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class DataChooser {

    public static void choose(String inputFile, String outputFile) {
        String[] ans = new String[50];
        ans[0] = "Department";
        int target = -1;
        int num = 1;
        try (Scanner input = new Scanner(new File(inputFile))) {
            while (input.hasNextLine()) {
                String tmp = input.nextLine();
                String[] words = tmp.split(",");
                if (target < 0) {
                    for (int i = 0; i < tmp.length(); i++) {
                        if (words[i].equals(ans[0])) {
                            target = i;
                            break;
                        }
                    }
                } else {
                    ans[num] = words[target];
                    num++;
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }

        try (PrintStream out = new PrintStream(new File(outputFile))) {
            for (int i = 0; i < num; i++)
                out.println(ans[i]);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
