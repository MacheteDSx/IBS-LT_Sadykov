package ru.Appline.logic;

public class Pet {

    private String name;
    private String type;
    private int age;
    private int id;

    public Pet() {
        super();
    }

    public Pet(String name, String type, int age, int id) {
        this.name = name;
        this.type = type;
        this.age = age;
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
