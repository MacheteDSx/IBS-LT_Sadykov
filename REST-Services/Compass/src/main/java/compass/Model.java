package compass;

import java.util.HashMap;
import java.util.Map;

public class Model {

    private static final Model instance = new Model();
    private Map<String, String> ranges = new HashMap<>();

    private Model() {
    }

    public static Model getInstance() {
        return instance;
    }

    public void setRanges(Map<String, String> newRanges) {
        this.ranges = newRanges;
    }

    public Map<String, String> getRanges() {
        return ranges;
    }

    public String getSide(int degree) {
        for (Map.Entry<String, String> entry : ranges.entrySet()) {
            String[] range = entry.getValue().split("-");
            int start = Integer.parseInt(range[0]);
            int end = Integer.parseInt(range[1]);

            if (start <= end) {
                if (degree >= start && degree <= end) {
                    return entry.getKey();
                }
            } else {
                if (degree >= start || degree <= end) {
                    return entry.getKey();
                }
            }
        }
        return "Unknown";
    }
}
