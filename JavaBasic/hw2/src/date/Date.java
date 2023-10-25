package date;

public class Date {
    int year;
    int month;
    int day;

    Date(String s) {
        String[] date = s.split("\\.");
        String[] dy = date[1].split(",");
        month = transform(date[0]);
        day = getnum(dy[0]);
        year = getnum(dy[1]);
    }

    Date(String m, int d, int y) {
        day = d;
        String mon = m.substring(0, m.length() - 1);
        month = transform(mon);
        year = y;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    public String toString() {
        return String.format("%d/%d/%d", year, month, day);
    }

    private int getnum(String d) {
        int ans = 0;
        for (int i = 0; i < d.length(); i++) {
            ans = 10 * ans + d.charAt(i) - '0';
        }
        return ans;
    }

    private int transform(String m) {
        int ans = 0;
        switch (m) {
            case "Jan":
                ans = 1;
                break;
            case "Feb":
                ans = 2;
                break;
            case "Mar":
                ans = 3;
                break;
            case "Apr":
                ans = 4;
                break;
            case "May":
                ans = 5;
                break;
            case "Jun":
                ans = 6;
                break;
            case "Jul":
                ans = 7;
                break;
            case "Aug":
                ans = 8;
                break;
            case "Sept":
                ans = 9;
                break;
            case "Oct":
                ans = 10;
                break;
            case "Nov":
                ans = 11;
                break;
            case "Dec":
                ans = 12;
                break;
            default:
                ans = 0;
                break;
        }
        return ans;
    }
}