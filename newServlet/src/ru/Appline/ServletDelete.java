package ru.Appline;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import ru.Appline.logic.Model;
import ru.Appline.logic.User;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

@WebServlet(urlPatterns = "/delete")
public class ServletDelete extends HttpServlet {

    private Model model = Model.getInstance();
    private Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("application/json; charset=utf-8");
        PrintWriter pw = response.getWriter();

        String idParam = request.getParameter("id");

        if (idParam == null || idParam.isEmpty()) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);  // 400 Bad Request
            pw.print("{\"message\":\"ID пользователя не передан\"}");
            return;
        }

        try {
            int id = Integer.parseInt(idParam);

            if (id > 0 && model.getFromList().containsKey(id)) {
                model.getFromList().remove(id);

                response.setStatus(HttpServletResponse.SC_OK);  // 200 OK
                pw.print("{\"message\":\"Пользователь с ID " + id + " успешно удален\"}");
            } else {
                response.setStatus(HttpServletResponse.SC_NOT_FOUND);  // 404 Not Found
                pw.print("{\"message\":\"Пользователь с таким ID не найден\"}");
            }

        } catch (NumberFormatException e) {
            response.setStatus(HttpServletResponse.SC_BAD_REQUEST);  // 400 Bad Request
            pw.print("{\"message\":\"Неверный формат ID\"}");
        }
    }
}
