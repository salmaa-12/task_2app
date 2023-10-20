#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10 
#define MAX_LEN 20 


typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
} user;

union user {
    int active; 
    struct { 
        char name[20];   
        char password[20]; 
    } info; 
};

user users[MAX_USERS];
int user_count = 0; 


int is_taken(char* username) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return 1; 
        }
    }
    return 0; 
}


void register_user() {
    char username[MAX_LEN];
    char password[MAX_LEN];
    char confirm[MAX_LEN];

    printf("Enter a username: ");
    scanf("%s", username);

    
    while (is_taken(username)) {
        printf("Sorry, that username is already taken. Please choose another one.\n");
        printf("Enter a username: ");
        scanf("%s", username);
    }

    printf("Enter a password: ");
    scanf("%s", password);

    printf("Confirm your password: ");
    scanf("%s", confirm);

    
    while (strcmp(password, confirm) != 0) {
        printf("Sorry, the passwords do not match. Please try again.\n");
        printf("Enter a password: ");
        scanf("%s", password);

        printf("Confirm your password: ");
        scanf("%s", confirm);
    }

   
    user new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    users[user_count] = new_user;
    user_count++;

    printf("You have successfully registered as %s.\n", username);
}


void login_user() {
    char username[MAX_LEN];
    char password[MAX_LEN];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    
    int valid = 0;
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            valid = 1; 
            break;
        }
    }

    if (valid) {
        printf("You have successfully logged in as %s.\n", username);
    } else {
        printf("Sorry, the username or password is incorrect. Please try again.\n");
        login_user(); 
    }
}


int main() {

    
    union user u1; 

    printf("Are you an active user? Enter 1 for yes or 0 for no\n");
    scanf("%d", &u1.active);
    int choice;
    if (u1.active == 1) {
        while (1) {
        printf("\nWelcome to the console login and register system.\n");
        printf("Please choose an option:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                login_user();
                break;
            case 3:
                printf("Thank you for using the system. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        
    }
    } else {
        printf("Sorry, you must be an active user to register.\n");
        printf("Do you want to active? Enter 1 for yes or 0 for no\n");
        scanf("%d", &u1.active);
            if (u1.active == 1){
                while (1) {
                printf("\nWelcome to the console login and register system.\n");
                printf("Please choose an option:\n");
                printf("1. Register\n");
                printf("2. Login\n");
                printf("3. Exit\n");
                printf("Your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        register_user();
                        break;
                    case 2:
                        login_user();
                        break;
                    case 3:
                        printf("Thank you for using the system. Goodbye!\n");
                        exit(0);
                        break;
                    default:
                        printf("Invalid option. Please try again.\n");
                        break;
                }
            }
            }else{
                printf("Sorry, you must be an active user to register.\n");
            }
    }
    

}