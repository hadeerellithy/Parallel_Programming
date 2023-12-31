#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char username[50];
    char password[50];
    bool is_active;
} User;

User users[100];
int userCount = 0;

void registerUser()
{
    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);
    users[userCount] = newUser;
    userCount++;
    printf("User registered successfully.\n");
}

int loginUser()
{
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Login successful.\n");
            return 1;
        }
    }
    printf("Invalid username or password.\n");
    return 0;
}

bool check_user_activity()
{
    char username[50];
    printf("Enter username: ");
    scanf("%s", username);
    for (int i = 0; i < userCount; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("User %s is active.\n");
        }
        else
        {
            printf("User %s is not active.\n");
        }
    }
    return 0;
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Check user activity:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            loginUser();
            break;
        case 3:
            check_user_activity();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}