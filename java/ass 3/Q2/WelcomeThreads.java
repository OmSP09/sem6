import java.util.Scanner;

public class WelcomeThreads {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        int n = scanner.nextInt();

        Thread fyThread = new Thread(new WelcomeRunnable("FY", n));
        Thread syThread = new Thread(new WelcomeRunnable("SY", n));
        Thread tyThread = new Thread(new WelcomeRunnable("TY", n));

        fyThread.start();
        syThread.start();
        tyThread.start();
    }

    static class WelcomeRunnable implements Runnable {
        private final String year;
        private final int n;

        public WelcomeRunnable(String year, int n) {
            this.year = year;
            this.n = n;
        }

        @Override
        public void run() {
            for (int i = 0; i < n; i++) {
                System.out.println("Welcome to " + year);
                try {
                    Thread.sleep(1000); // 10 seconds delay
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
