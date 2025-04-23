#include <stdio.h>

#define MAX_TRIES 3

// Account structure
typedef struct {
    char name[30];
    int pin;
    int balance;
} Account;

// Function to check balance
void checkBalance(Account *user) {
    printf("Your balance is: ₹%d\n", user->balance);
}

// Function to deposit money
void deposit(Account *user) {
    int amount;
    printf("Enter amount to deposit: ");
    if (scanf("%d", &amount) != 1 || amount <= 0) {
        printf("Invalid amount!\n");
        while (getchar() != '\n'); // clear input buffer
        return;
    }
    user->balance += amount;
    printf("Deposited ₹%d successfully.\n", amount);
}

// Function to withdraw money
void withdraw(Account *user) {
    int amount;
    printf("Enter amount to withdraw: ");
    if (scanf("%d", &amount) != 1 || amount <= 0) {
        printf("Invalid amount!\n");
        while (getchar() != '\n');
        return;
    }
    if (amount > user->balance) {
        printf("Not enough balance. Your balance is ₹%d\n", user->balance);
    } else {
        user->balance -= amount;
        printf("Withdrew ₹%d successfully.\n", amount);
    }
}

// Function to show menu
void showMenu() {
    printf("\n--- ATM Menu ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

// Function to authenticate user
Account* login(Account accounts[], int size) {
    int enteredPin;
    for (int tries = 0; tries < MAX_TRIES; tries++) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &enteredPin) != 1) {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        for (int i = 0; i < size; i++) {
            if (accounts[i].pin == enteredPin) {
                printf("Login successful! Welcome, %s\n", accounts[i].name);
                return &accounts[i];
            }
        }

        printf("Incorrect PIN. Attempts left: %d\n", MAX_TRIES - tries - 1);
    }

    return NULL;
}

// Main function
int main() {
    // Predefined accounts
    Account accounts[] = {
        {"Navi", 1111, 900000000},
        {"Vanshika", 2222, 7000},
        {"Samiran", 3333, 15000}
    };

    printf("*** Welcome to Simple ATM ***\n");

    // Login
    Account *user = login(accounts, 3);
    if (user == NULL) {
        printf("Too many wrong attempts. Exiting.\n");
        return 0;
    }

    // Menu loop
    int choice;
    do {
        showMenu();
        printf("Enter choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: checkBalance(user); break;
            case 2: deposit(user); break;
            case 3: withdraw(user); break;
            case 4: printf("Thank you for using the ATM. Goodbye!\n"); break;
            default: printf("Invalid option. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
