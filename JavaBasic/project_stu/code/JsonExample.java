import org.json.*;
public class JSONExample {
    public static void main(String[] args) {
        JSONObject js = new JSONObject(
                "{\"city\":\"chicago\",\"name\":\"jon doe\",\"age\":\"22\"}"
        );
        System.out.println(js);
        String age = (String) js.opt("age");
        System.out.println(age);
    }
}
