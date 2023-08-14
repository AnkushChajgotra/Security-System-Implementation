#include<iostream>
#include<fstream>
#include<sstream> 
#include<string>

using namespace std;

struct User {
    string name;
    string password;
    string age;
};

void registerUser();
bool loginUser(User& user);
void changePassword(User& user);

int main() {
    int choice;
    
    cout << "          Security System " << endl;
    cout << "_____________________________________" << endl;
    cout << "|            1. Register            |" << endl;
    cout << "|            2. Login               |" << endl;
    cout << "|            3. Change password     |" << endl;
    cout << "|____________4. End program_________|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                registerUser();
                break;
            }

            case 2: {
                User loggedInUser;
                if (loginUser(loggedInUser)) {
                    cout << "---Login Successful---" << endl
                         << endl;
                    cout << "Details:" << endl;
                    cout << "Username: " << loggedInUser.name << endl;
                    cout << "Password: " << loggedInUser.password << endl;
                    cout << "Age: " << loggedInUser.age << endl;
                } else {
                    cout << "Incorrect Credentials" << endl;
                }
                break;
            }

            case 3: {
                User loggedInUser;
                if (loginUser(loggedInUser)) {
                    changePassword(loggedInUser);
                } else {
                    cout << "Incorrect Credentials" << endl;
                }
                break;
            }

            case 4: {
                cout << "______________________THANK YOU!______________________";
                break;
            }

            default:
                cout << "Enter a valid choice";
        }

    } while (choice != 4);

    return 0;
}

void registerUser() {
    User newUser;
    cout << " ___________________________________" << endl;
    cout << "|------------Register---------------|" << endl;
    cout << "|___________________________________|" << endl << endl;
    
    cout << "Please enter username: ";
    cin >> newUser.name;
    cout << "Please enter the password: ";
    cin >> newUser.password;
    cout << "Please enter your age: ";
    cin >> newUser.age;

    ofstream outputFile("file.txt");
    if (outputFile.is_open()) {
        outputFile << newUser.name << "\n";
        outputFile << newUser.password << "\n";
        outputFile << newUser.age << "\n";
        outputFile.close();
        cout << "Registration Successful" << endl;
    } else {
        cout << "Error: Unable to open file for writing" << endl;
    }
}

bool loginUser(User& user) {
    cout << " ___________________________________" << endl;
    cout << "|--------------Login----------------|" << endl;
    cout << "|___________________________________|" << endl << endl;
    
    string enteredUsername, enteredPassword;
    cout << "Please enter the username: ";
    cin >> enteredUsername;
    cout << "Please enter the password: ";
    cin >> enteredPassword;

    ifstream inputFile("file.txt");
    if (inputFile.is_open()) {
        string storedUsername, storedPassword, storedAge;
        inputFile >> storedUsername >> storedPassword >> storedAge;
        if (enteredUsername == storedUsername && enteredPassword == storedPassword) {
            user.name = storedUsername;
            user.password = storedPassword;
            user.age = storedAge;
            inputFile.close();
            return true;
        }
        inputFile.close();
    } else {
        cout << "Error: Unable to open file for reading" << endl;
    }

    return false;
}

void changePassword(User& user) {
    cout << "-----------------Change Password-----------------" << endl;

    string enteredOldPassword;
    cout << "Enter the old password: ";
    cin >> enteredOldPassword;

    if (enteredOldPassword == user.password) {
        string newPassword1, newPassword2;
        cout << "Enter your new password: ";
        cin >> newPassword1;
        cout << "Enter your password again: ";
        cin >> newPassword2;

        if (newPassword1 == newPassword2) {
            user.password = newPassword1;
            ofstream outputFile("file.txt");
            if (outputFile.is_open()) {
                outputFile << user.name << "\n";
                outputFile << user.password << "\n";
                outputFile << user.age << "\n";
                outputFile.close();
                cout << "Password Changed Successfully" << endl;
            } else {
                cout << "Error: Unable to open file for writing" << endl;
            }
        } else {
            cout << "Passwords do not match" << endl;
        }
    } else {
        cout << "Incorrect old password" << endl;
    }
}



// **Security System Implementation**

// Developed a C++ program for a basic security system to manage user registration, login, and password changes.
//  Incorporated file handling to store user data securely. Utilized C++ features for user authentication and password management.
//   Gained hands-on experience in C++ programming, file manipulation, user interaction, and basic security practices.