package testutil;


import java.util.concurrent.*;

public class TestRunner {

    private static boolean exceptionEnabled = false;
    public static void runTest(Runnable runnable, int timeout) {
        if (exceptionEnabled) {
            runnable.run();
            System.out.println();
            return;
        }
        ExecutorService executor = Executors.newSingleThreadExecutor();
        Future<?> future = executor.submit(runnable);
        try {
            future.get(timeout, TimeUnit.MILLISECONDS);
        } catch (TimeoutException e) {
//            if (exceptionEnabled) throw e;
            System.out.println("Time Limit Exceeded");
        } catch (Exception e) {
//            if (exceptionEnabled) throw e;
            System.out.println("Runtime Error");
        } finally {
            future.cancel(true);
        }
        System.out.println();
        executor.shutdown();
    }

    public static void enableException(boolean enable) {
        exceptionEnabled = enable;
    }
}


