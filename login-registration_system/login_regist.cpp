#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sign_up(){
    // Registration module. Register the user + Writes the username and password in a file.
    cout << "Please enter the required information\n";

    string username, password;

    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    // Create user registration file
    ofstream registration_file("user_data.txt");
    // Write user information
    registration_file << username << endl << password;
    // Close file
    registration_file.close();

    cout << "Registration completed." << endl;
}

bool check_user(string username, string password){
    // Check if the username exists and if the password matches. Returns if the user information is valid.

    string un, pw;

    // Declare the fstream variable and connect it to a stream object by opening the file
    ifstream read("user_data.txt");
    getline(read, un);
    getline(read, pw);

    if (username == un && password == pw){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout << "Welcome to DevTech website!\n";
    cout << "[1] Sign in with your Username and Password!" << endl << "[2] Don't have an account? Sign up!" << endl;

    int user_initial_choice; cin >> user_initial_choice;

    if(user_initial_choice == 1){
        // Sign in
        string username, password;

        cout << "Username: "; cin >> username;

        cout << "Password: "; cin >> password;

        // Verify user information
        bool valid_user = check_user(username, password);

        if (valid_user){
            cout << "Successful login.";
        }
        else{
            cout << "Invalid user information. Try again.";
        }
    }

    else if(user_initial_choice == 2){
        // Sign up
        sign_up();

        cout << "Successful login.";
    }
    else{
        cout << "Invalid option. Try again.";
    }
}