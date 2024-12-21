package ru.Appline;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
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
import java.util.concurrent.atomic.AtomicInteger;

@WebServlet(urlPatterns = "/add")
public class ServletAdd extends HttpServlet {

    private AtomicInteger counter = new AtomicInteger(5);
    Model model = Model.getInstance();
    Gson gson = new GsonBuilder().setPrettyPrinting().create();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter pw = response.getWriter();

        String name = request.getParameter("name");
        String surname = request.getParameter("surname");
        String salaryParam = request.getParameter("salary");

        if (name != null && surname != null && salaryParam != null) {
            double salary = Double.parseDouble(salaryParam);

            User user = new User(name, surname, salary);
            model.add(user, counter.getAndIncrement());

            pw.print("<html>" +
                    "<h3>Пользователь " + name + " " + surname + " с зарплатой " + salary + " успешно создан! :)</h3>" +
                    "<a href=\"addUser.html\">Создать нового пользователя</a><br/>" +
                    "<a href=\"index.jsp\">Домой</a>" +
                    "</html>");
        } else {
            // Если форма не была передана, то это POST-запрос с JSON
            StringBuffer jb = new StringBuffer();
            String line;

            try {
                BufferedReader reader = request.getReader();
                while ((line = reader.readLine()) != null) {
                    jb.append(line);
                }
            } catch (Exception e) {
                System.out.println("Error reading JSON");
            }

            JsonObject jobj = gson.fromJson(String.valueOf(jb), JsonObject.class);

            String nameJson = jobj.get("name").getAsString();
            String surnameJson = jobj.get("surname").getAsString();
            double salaryJson = jobj.get("salary").getAsDouble();

            User user = new User(nameJson, surnameJson, salaryJson);
            model.add(user, counter.getAndIncrement());

            response.setContentType("application/json;charset=utf-8");
            PrintWriter jsonWriter = response.getWriter();

            jsonWriter.print(gson.toJson(model.getFromList()));
        }
    }
}
