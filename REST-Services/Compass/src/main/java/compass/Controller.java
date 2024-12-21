package compass;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.Map;

@RestController
public class Controller {

    private final Model compassModel = Model.getInstance();

    @PostMapping("/setRanges")
    public String setRanges(@RequestBody Map<String, String> ranges) {
        compassModel.setRanges(ranges);
        return "Диапазоны сторон света успешно установлены.";
    }

    @GetMapping("/getRanges")
    public Map<String, String> getRanges() {
        return compassModel.getRanges();
    }

    @GetMapping("/getSide")
    public String getSide(@RequestParam int degree) {
        if (degree < 0 || degree >= 360) {
            return "Введите число от 0 до 359";
        }
        return compassModel.getSide(degree);
    }
}
