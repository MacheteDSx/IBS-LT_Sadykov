package ru.Appline.controller;

import org.springframework.web.bind.annotation.*;
import ru.Appline.logic.Pet;
import ru.Appline.logic.PetModel;

import java.util.Map;
import java.util.concurrent.atomic.AtomicInteger;

@RestController
public class Controller {
    private static final PetModel petModel = PetModel.getInstance();
    private static final AtomicInteger newId = new AtomicInteger(1);
    private static boolean isFirstPetCreated = false;

    @PostMapping(value = "/createPet", consumes = "application/json")
    public String createPet(@RequestBody Pet pet) {
        petModel.add(pet, newId.getAndIncrement());

        if (!isFirstPetCreated) {
            isFirstPetCreated = true;
            return "Поздравляем, вы создали первого питомца!";
        } else {
            return "Поздравляем, вы создали питомца!";
        }
    }

    @GetMapping(value = "/getAll", produces = "application/json")
    public Map<Integer, Pet> getAll() {
        return petModel.getAll();
    }

    @GetMapping(value = "/getPet", consumes = "application/json", produces = "application/json")
    public Object getPet(@RequestBody Map<String, Integer> id) {
        Pet pet = petModel.getFromList(id.get("id"));
        if (pet == null) {
            return "Ошибка: питомец с таким ID не найден.";
        }
        return pet;
    }

    @PutMapping(value = "/updatePet", consumes = "application/json", produces = "application/json")
    public String updatePet(@RequestBody Pet pet) {
        Pet existingPet = petModel.getFromList(pet.getId());
        if (existingPet == null) {
            return "Ошибка: питомец с таким ID не найден для обновления.";
        }
        petModel.update(pet);
        return "Питомец успешно обновлен!";
    }

    @DeleteMapping(value = "/deletePet", consumes = "application/json", produces = "application/json")
    public String deletePet(@RequestBody Map<String, Integer> id) {
        Pet pet = petModel.getFromList(id.get("id"));
        if (pet == null) {
            return "Ошибка: питомец с таким ID не найден для удаления.";
        }
        petModel.delete(id.get("id"));
        return "Питомец успешно удален!";
    }
}
