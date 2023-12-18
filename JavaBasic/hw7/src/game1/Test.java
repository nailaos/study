package game1;

import testutil.TestRunner;

public class Test {

    public static void main(String[] args) {
        TestRunner.enableException(true);
        TestRunner.runTest(() -> {
            run_case(8888, 90, 1, 100, 100, 0);
        }, 5000);
        TestRunner.runTest(() -> {
            run_case(8889, 320, 1, 1000, 1000, 1);
        }, 5000);
        TestRunner.runTest(() -> {
            run_case(8890, 190, 1, 100000, 500, 2);
        }, 5000);
        TestRunner.runTest(() -> {
            run_case(8891, 109835, 1, 10000000, 35, 3);
        }, 5000);
        TestRunner.runTest(() -> {
            run_case(8892, 10000000, 1, 10000000, 35, 4);
        }, 5000);
        System.exit(0);
    }

    public static void run_case(int port, int number, int lower_bound, int upper_bound, int limit, int case_id) {
        Game1Server server = new Game1Server(port, number, lower_bound, upper_bound, limit);
        Game1Client client = new Game1Client("localhost", port);

        server.start();
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            e.printStackTrace();
        }

        int ans = client.run();

        try {
            server.join();
        } catch (Exception e) {
            e.printStackTrace();
        }
        int count = server.return_count();

        System.out.println(
                String.format("Case %d on %d guess in (%d,%d), expected %d in %d queries, got %d in %d queries, %s",
                        case_id, port, lower_bound, upper_bound, number, limit, ans, count,
                        ans == number && count <= limit ? "Accept" : "Wrong Answer"));
    }
}
