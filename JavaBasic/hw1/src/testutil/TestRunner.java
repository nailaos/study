package testutil;

import java.util.concurrent.*;

public class TestRunner {
    public static void runTest(Runnable runnable, int timeout) {
        ExecutorService executor = Executors.newSingleThreadExecutor();
        Future<?> future = executor.submit(runnable);
        try {
            future.get(timeout, TimeUnit.MILLISECONDS);
        } catch (TimeoutException e) {
            System.out.println("Time Limit Exceeded");
        } catch (Exception e) {
            System.out.println("Runtime Error");
        } finally {
            future.cancel(true);
        }
        System.out.println();
        executor.shutdown();
    }
}