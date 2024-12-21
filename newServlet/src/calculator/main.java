package calculator;

import com.google.gson.Gson;
import com.google.gson.JsonObject;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/calculator")
public class main extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        response.setCharacterEncoding("UTF-8");

        StringBuilder jsonRequest = new StringBuilder();
        String line;
        try (BufferedReader reader = request.getReader()) {
            while ((line = reader.readLine()) != null) {
                jsonRequest.append(line);
            }
        }

        Gson gson = new Gson();
        JsonObject inputJson = gson.fromJson(jsonRequest.toString(), JsonObject.class);

        double a = inputJson.get("a").getAsDouble();
        double b = inputJson.get("b").getAsDouble();
        String math = inputJson.get("math").getAsString();

        double result = 0;
        String error = null;

        switch (math) {
            case "+":
                result = a + b;
                break;
            case "-":
                result = a - b;
                break;
            case "*":
                result = a * b;
                break;
            case "/":
                if (b != 0) {
                    result = a / b;
                } else {
                    error = "Ошибка: Деление на ноль!";
                }
                break;
            default:
                error = "Ошибка: Неверная арифметическая операция!";
                break;
        }

        JsonObject jsonResponse = new JsonObject();
        if (error == null) {
            jsonResponse.addProperty("result", result);
        } else {
            jsonResponse.addProperty("error", error);
        }

        PrintWriter out = response.getWriter();
        out.print(gson.toJson(jsonResponse));
    }
}
