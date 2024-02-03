#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to generate a random password
string generatePassword(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>/?";
    const int charactersLength = characters.length();
    
    string password;
    
    // Seed the random number generator
    srand(time(0));
    
    for (int i = 0; i < length; ++i) {
        // Generate a random index to pick a character from the characters string
        int randomIndex = rand() % charactersLength;
        // Append the selected character to the password
        password += characters[randomIndex];
    }
    
    return password;
}

// Function to apply a hash mask to the password
string applyHashMask(const string& password, const string& hashMask) {
    string maskedPassword;

    for (size_t i = 0; i < password.length(); ++i) {
        maskedPassword += password[i] ^ hashMask[i % hashMask.length()];
    }

    return maskedPassword;
}

int main() {
    char exitKey;
    
    do {
        int passwordLength;
        string hashMask;

        // Get the desired password length from the user
        cout << "Enter the desired password length: ";
        cin >> passwordLength;

        // Generate and display the password
        string password = generatePassword(passwordLength);
        cout << "Generated Password: " << password << endl;

        // Ask the user if they want to apply a hash mask
        cout << "Do you want to apply a hash mask? (y/n): ";
        char applyMask;
        cin >> applyMask;

        if (applyMask == 'y' || applyMask == 'Y') {
            // Get the hash mask from the user
            cout << "Enter the hash mask: ";
            cin >> hashMask;

            // Apply the hash mask to the password and display the result
            string maskedPassword = applyHashMask(password, hashMask);
            cout << "Password with Hash Mask: ";
            for (char c : maskedPassword) {
                cout << hex << setw(2) << setfill('0') << static_cast<int>(c);
            }
            cout << dec << endl;
        }

        // Ask the user to press a key to exit or generate another password
        cout << "Press any key to generate another password, or press 'x' to exit: ";
        cin >> exitKey;

    } while (exitKey != 'x' && exitKey != 'X');

    return 0;
}
