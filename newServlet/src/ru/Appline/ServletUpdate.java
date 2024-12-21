package ru.Appline;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import ru.Appline.logic.Model;
import ru.Appline.logic.User;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

@WebServlet(urlPatterns = "/update")
public class ServletUpdate extends HttpServlet {

    private Model model = Model.getInstance(); // Получаем экземпляр модели

    @Override
    protected void doPut(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        response.setCharacterEncoding("UTF-8");

        // Чтение тела запроса (JSON)
        BufferedReader reader = request.getReader();
        StringBuilder requestBody = new StringBuilder();
        String line;
        while ((line = reader.readLine()) != null) {
            requestBody.append(line);
        }

        // Используем Gson для парсинга JSON
        JsonObject jsonRequest = new Gson().fromJson(requestBody.toString(), JsonObject.class);

        // Получаем данные из JSON
        int id = jsonRequest.has("id") ? jsonRequest.get("id").getAsInt() : -1;
        String name = jsonRequest.has("name") ? jsonRequest.get("name").getAsString() : "";
        String surname = jsonRequest.has("surname") ? jsonRequest.get("surname").getAsString() : "";
        double salary = jsonRequest.has("salary") ? jsonRequest.get("salary").getAsDouble() : -1;

        JsonObject jsonResponse = new JsonObject();

        // Проверяем, что id валидный
        if (id <= 0) {
            jsonResponse.addProperty("error", "Некорректный ID!");
        } else {
            // Проверяем, существует ли пользователь с таким id
            if (model.getFromList().containsKey(id)) {
                // Обновляем информацию о пользователе
                User user = model.getFromList().get(id);
                if (!name.isEmpty()) user.setName(name);
                if (!surname.isEmpty()) user.setSurname(surname);
                if (salary >= 0) user.setSalary(salary);

                // Ответ успешного обновления
                jsonResponse.addProperty("success", "Пользователь успешно обновлен!");
                jsonResponse.addProperty("id", id);
                jsonResponse.addProperty("name", user.getName());
                jsonResponse.addProperty("surname", user.getSurname());
                jsonResponse.addProperty("salary", user.getSalary());
            } else {
                // Если такого пользователя нет, возвращаем ошибку
                jsonResponse.addProperty("error", "Пользователь с таким ID не найден!");
            }
        }

        // Отправляем ответ в формате JSON
        PrintWriter pw = response.getWriter();
        pw.print(new Gson().toJson(jsonResponse));
    }
}
