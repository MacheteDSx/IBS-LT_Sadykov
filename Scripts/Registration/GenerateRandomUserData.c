GenerateRandomUserData()
{
    char buffer[100];
    
    sprintf(buffer, "User%d", rand() % 99 + 1);
    lr_save_string(buffer, "Username");
    lr_output_message("Generated Username: %s", buffer);

    sprintf(buffer, "Pass_%d", rand() % 100);
    lr_save_string(buffer, "Password");
    lr_output_message("Generated Password: %s", buffer);

    sprintf(buffer, "First_%d", rand() % 100);
    lr_save_string(buffer, "Firstname");
    lr_output_message("Generated Firstname: %s", buffer);

    sprintf(buffer, "Last_%d", rand() % 100);
    lr_save_string(buffer, "Lastname");
    lr_output_message("Generated Lastname: %s", buffer);

    sprintf(buffer, "%d Random St", rand() % 100 + 1);
    lr_save_string(buffer, "StreetAddress");
    lr_output_message("Generated Street Address: %s", buffer);

    lr_save_string("Pasadena", "City");
    lr_output_message("Generated City: %s", "Pasadena");
    
    sprintf(buffer, "%s %s", lr_eval_string("{Firstname}"), lr_eval_string("{Lastname}"));
    lr_save_string(buffer, "Fullname");
    lr_output_message("Generated Fullname: %s", buffer);

    sprintf(buffer, "%04d %04d %04d %04d", rand() % 10000, rand() % 10000, rand() % 10000, rand() % 10000);
    lr_save_string(buffer, "CreditCard");
    lr_output_message("Generated Credit Card: %s", buffer);

    sprintf(buffer, "%02d/%02d", rand() % 12 + 1, rand() % 5 + 24); 
	lr_save_string(buffer, "CardExpiryDate");
	lr_output_message("Generated Card Expiry Date: %s", buffer);

    return 0;
}
