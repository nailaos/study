import java.awt.Font;

public class DataPool {
    private static double lat = 39.906217;
    private static double lon = 116.3912757;
    private static String country = "CN";
    private static String name = "Beijing";
    private static int timezone = 28800;
    private static boolean curUpdate = true;
    private static boolean futUpdate = true;
    private static boolean airUpdate = true;
    private static boolean titleUpdate = true;
    private static boolean netConnected = true;

    public static synchronized double getLat() {
        return lat;
    }

    public static synchronized double getLon() {
        return lon;
    }

    public static synchronized String getCountry() {
        return country;
    }

    public static synchronized String getName() {
        return name;
    }

    public static synchronized int getTimezone() {
        return timezone;
    }

    public static synchronized void setLat(double newLat) {
        lat = newLat;
    }

    public static synchronized void setLon(double newLon) {
        lon = newLon;
    }

    public static synchronized void setCountry(String newCountry) {
        country = newCountry;
    }

    public static synchronized void setName(String newName) {
        name = newName;
    }

    public static synchronized void setTimezone(int newTimezone) {
        timezone = newTimezone;
    }

    public static synchronized boolean isCurUpdate() {
        return curUpdate;
    }

    public static synchronized void setCurUpdate(boolean newCurUpdate) {
        curUpdate = newCurUpdate;
    }

    public static synchronized boolean isFutUpdate() {
        return futUpdate;
    }

    public static synchronized void setFutUpdate(boolean newFutUpdate) {
        futUpdate = newFutUpdate;
    }

    public static synchronized boolean isAirUpdate() {
        return airUpdate;
    }

    public static synchronized void setAirUpdate(boolean newAirUpdate) {
        airUpdate = newAirUpdate;
    }

    public static synchronized boolean isTitleUpdate() {
        return titleUpdate;
    }

    public static synchronized void setTitleUpdate(boolean newTitleUpdate) {
        titleUpdate = newTitleUpdate;
    }

    public static synchronized boolean isNetConnect() {
        return netConnected;
    }

    public static synchronized void setNetConnect(boolean newnet) {
        netConnected = newnet;
    }

    public static Font getFont(int style, int x) {
        return new Font("楷书", style, 32 - 4 * x);
    }
}
