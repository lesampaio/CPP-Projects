#include<iostream>
using namespace std;

int main (){
    cout << "*************************************" << endl;
    cout << "** * Welcome to the guessing game! * **" << endl;
    cout << "*************************************" << endl;

    const int SECRET_NUMBER = 42;

    bool incorrect = true;
    int attempts = 0;

    while(incorrect){
        attempts++;
        int player_guess;
        cout << "What's your guess? ";
        cin >> player_guess;
        cout << "Your guess value is: " << player_guess << endl;

        bool correct = player_guess == SECRET_NUMBER;
        bool greater = player_guess > SECRET_NUMBER;

        if(correct){
            cout << "Your guess is correct!"<< endl;
            incorrect = false;
        }
        else if(greater){
            cout << "Your guess is greater than the secret number! \nTry again." << endl;
        }
        else{
            cout << "Your guess is lower than the secret number! \nTry again." << endl;
        }
    }
    cout << "Player attempts: " << attempts << endl;
    cout << "You won the game with " << attempts << " tries." << endl;
    cout << "\nThe end.";
}