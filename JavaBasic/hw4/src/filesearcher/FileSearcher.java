package filesearcher;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileSearcher {

    public static int search(String inputfile, String keyword) {
        int ans = 0;
        try (Scanner input = new Scanner(new File(inputfile))) {
            while (input.hasNextLine()) {
                String tmp = input.nextLine();
                String[] words = tmp.split("[^a-zA-Z]+");
                for (String word : words) {
                    if (word.equalsIgnoreCase(keyword))
                        ans++;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch (Exception e) {
            System.out.println(e);
        }
        return ans;
    }
}
