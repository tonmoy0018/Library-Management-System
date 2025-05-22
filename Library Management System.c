#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_BOOKS 100
char bookList[MAX_BOOKS][100] = {
    "C Programming Language",
    "Clean Code",
    "Introduction to Algorithms",
    "Design Patterns"
};
#define MAX_USERS 50
#define MAX_BORROW 50


struct User {
    char name[50];
    char email[100];
    char password[50];
    char education[100];
    char hometown[50];
    char job[50];
    char nationality[50];
    char studentID[20];
};


struct Admin {
    char name[50];
    char email[100];
    char password[50];
};


char bookList[MAX_BOOKS][100];
int bookCount = 4;


struct BorrowDetails {
    char bookName[100];
    char borrowedBy[50];
    char studentID[20];
    char returnDate[20];
    int isReturned;
};

struct BorrowDetails borrowDetails[MAX_BORROW];
int borrowCount = 0;


struct User registeredUsers[MAX_USERS];
int userCount = 0;

int isStrongPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
    }
    return strlen(password) >= 8 && hasUpper && hasLower && hasDigit;
}

int isValidEmail(const char *email, const char *domain) {
    const char *atPos = strchr(email, '@');
    if (!atPos) return 0;
    return strcmp(atPos, domain) == 0;
}

void registerAdmin(struct Admin *admin) {
    int emailValid = 0;
    char adminDomain[] = "@admin.diu.edu.bd";// as this code is for daffodil international university

    do {
        printf("\nEnter admin email for registration: ");
        fgets(admin->email, sizeof(admin->email), stdin);
        admin->email[strcspn(admin->email, "\n")] = '\0';
        if (isValidEmail(admin->email, adminDomain)) {
            emailValid = 1;
        } else {
            printf("\nInvalid email. Please try again.\n");
        }
    } while (!emailValid);

    printf("\nEnter admin name for registration: ");
    fgets(admin->name, sizeof(admin->name), stdin);
    admin->name[strcspn(admin->name, "\n")] = '\0';

    do {
        printf("\nEnter a strong password for admin \n(at least 8 characters, with uppercase, lowercase, and digit): ");
        fgets(admin->password, sizeof(admin->password), stdin);
        admin->password[strcspn(admin->password, "\n")] = '\0';
        if (!isStrongPassword(admin->password)) {
            printf("\nPassword is not strong enough. Try again.\n");
        }
    } while (!isStrongPassword(admin->password));

    printf("\nAdmin registration successful!\n\n");
}

void registerUser(struct User *user) {
    int emailValid = 0;
    char userDomain[] = "@diu.edu.bd";// as this code is for daffodil international university

    do {
        printf("\nEnter user email for registration: ");
        fgets(user->email, sizeof(user->email), stdin);
        user->email[strcspn(user->email, "\n")] = '\0';
        if (isValidEmail(user->email, userDomain)) {
            emailValid = 1;
        } else {
            printf("\nInvalid email. Please try again.\n");
        }
    } while (!emailValid);

    printf("\nEnter user name for registration: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0';

    do {
        printf("\nEnter a strong password \n(at least 8 characters, with uppercase, lowercase, and digit): ");
        fgets(user->password, sizeof(user->password), stdin);
        user->password[strcspn(user->password, "\n")] = '\0';
        if (!isStrongPassword(user->password)) {
            printf("\nPassword is not strong enough. Try again.\n");
        }
    } while (!isStrongPassword(user->password));

    printf("\nEnter student ID: ");
    fgets(user->studentID, sizeof(user->studentID), stdin);
    user->studentID[strcspn(user->studentID, "\n")] = '\0';

    printf("\nRegistration successful!\n\n");

    registeredUsers[userCount++] = *user;
}

int loginAdmin(struct Admin *admin) {
    char email[100], password[50];
    printf("Enter admin email to log in: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("Enter admin password to log in: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(email, admin->email) == 0 && strcmp(password, admin->password) == 0) {
        printf("\nAdmin login successful! Welcome, %s!\n\n", admin->name);
        return 1;
    } else {
        printf("\nInvalid admin email or password. Please try again.\n");
        return 0;
    }
}

int loginUser(struct User *user) {
    char email[100], password[50];
    printf("Enter user email to log in: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    printf("Enter user password to log in: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if (strcmp(email, user->email) == 0 && strcmp(password, user->password) == 0) {
        printf("\nUser login successful! Welcome, %s!\n\n", user->name);
        return 1;
    } else {
        printf("\nInvalid user email or password. Please try again.\n");
        return 0;
    }
}

void createProfile(struct User *user) {
    printf("Enter User Name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0';

    printf("Enter education: ");
    fgets(user->education, sizeof(user->education), stdin);
    user->education[strcspn(user->education, "\n")] = '\0';

    printf("Enter hometown: ");
    fgets(user->hometown, sizeof(user->hometown), stdin);
    user->hometown[strcspn(user->hometown, "\n")] = '\0';

    printf("Enter job: ");
    fgets(user->job, sizeof(user->job), stdin);
    user->job[strcspn(user->job, "\n")] = '\0';

    printf("Enter nationality: ");
    fgets(user->nationality, sizeof(user->nationality), stdin);
    user->nationality[strcspn(user->nationality, "\n")] = '\0';

    printf("Profile creation successful!\n\n");
}

void viewUserProfile(struct User *user) {
    printf("\nUser Profile:\n");
    printf("Name: %s\n", user->name);
    printf("Email: %s\n", user->email);
    printf("Education: %s\n", user->education);
    printf("Hometown: %s\n", user->hometown);
    printf("Job: %s\n", user->job);
    printf("Nationality: %s\n", user->nationality);
    printf("Student ID: %s\n\n", user->studentID);
}

void updateProfile(struct User *user) {
    printf("Updating profile details...\n");

    printf("Enter new name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0';

    printf("Enter new education: ");
    fgets(user->education, sizeof(user->education), stdin);
    user->education[strcspn(user->education, "\n")] = '\0';

    printf("Enter new hometown: ");
    fgets(user->hometown, sizeof(user->hometown), stdin);
    user->hometown[strcspn(user->hometown, "\n")] = '\0';

    printf("Enter new job: ");
    fgets(user->job, sizeof(user->job), stdin);
    user->job[strcspn(user->job, "\n")] = '\0';

    printf("Enter new nationality: ");
    fgets(user->nationality, sizeof(user->nationality), stdin);
    user->nationality[strcspn(user->nationality, "\n")] = '\0';

    printf("Profile updated successfully!\n\n");
}

void updatePassword(struct User *user) {
    char password[50];
    char newPassword[50];
    do {
        printf("Enter old password: ");
         fgets(password, sizeof(password), stdin);
         password[strcspn(password, "\n")] = '\0';
        printf("Enter new password \n(at least 8 characters, with uppercase, lowercase, and digit): ");
        fgets(newPassword, sizeof(newPassword), stdin);
        newPassword[strcspn(newPassword, "\n")] = '\0';

        if (!isStrongPassword(newPassword)) {
            printf("Password is not strong enough. Try again.\n");
        }
    } while (!isStrongPassword(newPassword));

    strcpy(user->password, newPassword);
    printf("Password updated successfully!\n\n");
}

void deleteAccount(struct User *user) {
    printf("Are you sure you want to delete your account? (y/n): ");
    char choice;
    scanf("%c", &choice);
    getchar();

    if (choice == 'y' || choice == 'Y') {
        printf("Account deleted successfully!\n");
        user->name[0] = '\0';  // clear user data
    } else {
        printf("Account deletion canceled.\n");
    }
}

void viewAdminProfile(struct Admin *admin) {
    printf("\nAdmin Profile:\n");
    printf("Name: %s\n", admin->name);
    printf("Email: %s\n\n", admin->email);
}
void updateAdminPassword(struct Admin *admin) {
    char password[50];
    char newPassword[50];
    do {
        printf("Enter old password: ");
         fgets(password, sizeof(password), stdin);
         password[strcspn(password, "\n")] = '\0';
        printf("Enter new password \n(at least 8 characters, with uppercase, lowercase, and digit): ");
        fgets(newPassword, sizeof(newPassword), stdin);
        newPassword[strcspn(newPassword, "\n")] = '\0';

        if (!isStrongPassword(newPassword)) {
            printf("Password is not strong enough. Try again.\n");
        }
    } while (!isStrongPassword(newPassword));

    strcpy(admin->password, newPassword);
    printf("Password updated successfully!\n\n");
}


void showBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
    } else {
        printf("The Booklist:\n\n");
        for (int i = 0; i < bookCount; i++) {
            printf("%d. %s\n", i + 1, bookList[i]);
        }
    }
}
void searchBook() {
    if (bookCount == 0) {
        printf("No books available to search.\n");
        return;
    }

    char searchQuery[100];
    printf("Enter the book name or part of the name to search: ");
    fgets(searchQuery, sizeof(searchQuery), stdin);
    searchQuery[strcspn(searchQuery, "\n")] = '\0'; // Remove newline character

    printf("Search results for '%s':\n", searchQuery);
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(bookList[i], searchQuery) != NULL) {
            printf("%d. %s\n", i + 1, bookList[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("No books found matching the search query.\n");
    }
    printf("\n");
}


void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Cannot add more books, the list is full.\n");
        return;
    }
    printf("Enter the book name to add: ");
    fgets(bookList[bookCount], sizeof(bookList[bookCount]), stdin);
    bookList[bookCount][strcspn(bookList[bookCount], "\n")] = '\0';
    bookCount++;
    printf("Book added successfully!\n\n");
}

void deleteBook() {
    if (bookCount == 0) {
        printf("No books to delete.\n");
        return;
    }

    int bookIndex;
    showBooks();

    printf("Enter the book number to delete: ");
    scanf("%d", &bookIndex);
    getchar();

    if (bookIndex < 1 || bookIndex > bookCount) {
        printf("Invalid book number.\n");
    } else {
        for (int i = bookIndex - 1; i < bookCount - 1; i++) {
            strcpy(bookList[i], bookList[i + 1]);
        }
        bookCount--;
        printf("Book deleted successfully!\n\n");
    }
}

void borrowBook(struct User *user) {
    if (bookCount == 0) {
        printf("No books available to borrow.\n");
        return;
    }

    int bookIndex;
    printf("Enter the book number you want to borrow: ");
    scanf("%d", &bookIndex);
    getchar();

    if (bookIndex < 1 || bookIndex > bookCount) {
        printf("Invalid book number.\n");
        return;
    }

    char returnDate[20];
    printf("Enter the return date (DD/MM/YYYY): ");
    fgets(returnDate, sizeof(returnDate), stdin);
    returnDate[strcspn(returnDate, "\n")] = '\0';

    struct BorrowDetails newBorrow;
    strcpy(newBorrow.bookName, bookList[bookIndex - 1]);
    strcpy(newBorrow.borrowedBy, user->name);
    strcpy(newBorrow.studentID, user->studentID);
    strcpy(newBorrow.returnDate, returnDate);
    newBorrow.isReturned = 0;

    borrowDetails[borrowCount++] = newBorrow;
    printf("Book borrowed successfully!\n\n");
}
void returnBook(struct User *user) {
    if (borrowCount == 0) {
        printf("No books have been borrowed yet.\n");
        return;
    }

    printf("Books borrowed by %s:\n", user->name);
    int found = 0;

    for (int i = 0; i < borrowCount; i++) {
        if (strcmp(borrowDetails[i].borrowedBy, user->name) == 0 && borrowDetails[i].isReturned == 0) {
            printf("%d. %s (Due: %s)\n", i + 1, borrowDetails[i].bookName, borrowDetails[i].returnDate);
            found++;
        }
    }

    if (found == 0) {
        printf("No books to return.\n");
        return;
    }

    int bookIndex;
    printf("Enter the number of the book to return: ");
    scanf("%d", &bookIndex);
    getchar();

    if (bookIndex < 1 || bookIndex > borrowCount ||
        strcmp(borrowDetails[bookIndex - 1].borrowedBy, user->name) != 0 ||
        borrowDetails[bookIndex - 1].isReturned == 1) {
        printf("Invalid selection. Please select a valid borrowed book.\n");
        return;
    }

    borrowDetails[bookIndex - 1].isReturned = 1;
    printf("Book '%s' returned successfully!\n\n", borrowDetails[bookIndex - 1].bookName);
}


void viewBorrowDetails() {
    if (borrowCount == 0) {
        printf("No borrow details available.\n");
    } else {
        for (int i = 0; i < borrowCount; i++) {
            printf("Book: %s, Borrowed by: %s, Student ID: %s, Return Date: %s, Status: %s\n",
                borrowDetails[i].bookName, borrowDetails[i].borrowedBy,
                borrowDetails[i].studentID, borrowDetails[i].returnDate,
                borrowDetails[i].isReturned ? "Returned" : "Not Returned");
        }
    }
}

void userMenu(struct User *user) {
    int choice;
    while (1) {
        printf("User Menu:\n");
        printf("1. Create Profile\n");
        printf("2. View Profile\n");
        printf("3. Update Profile\n");
        printf("4. Update Password\n");
        printf("5. View Book List\n");
        printf("6.Search book\n");
        printf("7. Borrow Book\n");
        printf("8 Return Book\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                createProfile(user);
                break;
            case 2:
                viewUserProfile(user);
                break;
            case 3:
                updateProfile(user);
                break;
            case 4:
                updatePassword(user);
                break;
            case 5:
                showBooks();
                break;
            case 6:
                searchBook();
            case 7:
                borrowBook(user);
                break;
            case 8:
                returnBook(user);
            case 9:
                deleteAccount(user);
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void adminMenu(struct Admin *admin) {
    int choice;
    while (1) {
        printf("Admin Menu:\n");
        printf("1. View Profile\n");
        printf("2. Update password\n");
        printf("3. Show Book List\n");
        printf("4. Add Book\n");
        printf("5. Delete Book\n");
        printf("6. Search Book\n");
        printf("7. View Borrow Details\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                viewAdminProfile(admin);
                break;
            case 2:
                updateAdminPassword(admin);
            case 3:
                showBooks();
                break;
            case 4:
                addBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                searchBook();
            case 7:
                viewBorrowDetails();
                break;
            case 8:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    struct User user;
    struct Admin admin;
    int choice;

    while (1) {
        printf("Welcome to the Library System!\n");
        printf("1. Register Admin\n");
        printf("2. Register User\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                registerAdmin(&admin);
                while (!loginAdmin(&admin)) {}
                adminMenu(&admin);
                break;

            case 2:
                registerUser(&user);
                while (!loginUser(&user)) {}
                userMenu(&user);
                break;

            case 3:
                printf("Exiting the Library System. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
