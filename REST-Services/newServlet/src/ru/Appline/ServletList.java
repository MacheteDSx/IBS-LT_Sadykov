package ru.Appline;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import ru.Appline.logic.Model;
import ru.Appline.logic.User;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

@WebServlet(urlPatterns = "/get")

public class ServletList extends HttpServlet {

    Model model = Model.getInstance();

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json;charset=utf-8");
        response.setCharacterEncoding("UTF-8");

        String idParam = request.getParameter("id");

        JsonObject jsonResponse = new JsonObject();

        if (idParam == null || idParam.isEmpty() || idParam.equals("0")) {
            JsonArray usersArray = new JsonArray();
            for (Map.Entry<Integer, User> entry : model.getFromList().entrySet()) {
                JsonObject userJson = new JsonObject();
                userJson.addProperty("id", entry.getKey());
                userJson.addProperty("name", entry.getValue().getName());
                userJson.addProperty("surname", entry.getValue().getSurname());
                userJson.addProperty("salary", entry.getValue().getSalary());
                usersArray.add(userJson);
            }

            jsonResponse.add("users", usersArray);

        } else {
            try {
                int id = Integer.parseInt(idParam);

                if (id > 0 && id <= model.getFromList().size()) {
                    User user = model.getFromList().get(id);

                    JsonObject userJson = new JsonObject();
                    userJson.addProperty("id", id);
                    userJson.addProperty("name", user.getName());
                    userJson.addProperty("surname", user.getSurname());
                    userJson.addProperty("salary", user.getSalary());

                    jsonResponse.add("user", userJson);
                } else {
                    jsonResponse.addProperty("error", "Такого пользователя нет!");
                }
            } catch (NumberFormatException e) {
                jsonResponse.addProperty("error", "Некорректный формат ID!");
            }
        }

        PrintWriter pw = response.getWriter();
        pw.print(new Gson().toJson(jsonResponse));
    }


}
