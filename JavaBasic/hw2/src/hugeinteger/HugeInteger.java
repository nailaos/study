package hugeinteger;

public class HugeInteger {
    int[] num;
    int n;

    HugeInteger(long i) {
        num = new int[100];
        n = 0;
        if (i == 0)
            n = 1;
        while (i > 0) {
            num[n] = (int) (i % 10);
            i /= 10;
            n++;
        }
    }

    HugeInteger(String s) {
        num = new int[100];
        n = s.length();
        for (int i = 0; i < n; i++)
            num[i] = s.charAt(n - i - 1) - '0';
    }

    public String toString() {
        StringBuilder ansBuilder = new StringBuilder();
        for (int i = n - 1; i >= 0; i--) {
            ansBuilder.append(num[i]);
        }
        String ans = ansBuilder.toString();
        return ans;
    }

    public void add(HugeInteger b) {
        int last = 0;
        if (b.n > n)
            n = b.n;
        for (int i = 0; i < n; i++) {
            int tmp = num[i] + b.num[i] + last;
            num[i] = tmp % 10;
            last = tmp / 10;
        }
        if (last > 0) {
            num[n] = last;
            n++;
        }
    }

    public int compareTo(HugeInteger x) {
        if (n > x.n)
            return 1;
        if (n < x.n)
            return -1;
        return compareTo(num, x.num, n);
    }

    public int compareTo(long x) {
        if (n > 19)
            return 1;
        int[] tmp = new int[19];
        int t = 0;
        if (x == 0)
            t = 1;
        while (x > 0) {
            tmp[t] = (int) (x % 10);
            x /= 10;
            t++;
        }
        if (n > t)
            return 1;
        if (n < t)
            return -1;
        return compareTo(num, tmp, n);
    }

    private int compareTo(int[] a, int[] b, int n) {
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > b[i])
                return 1;
            if (b[i] > a[i])
                return -1;
        }
        return 0;
    }
}