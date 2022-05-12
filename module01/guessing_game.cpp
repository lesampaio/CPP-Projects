#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main (){
    cout << "*************************************" << endl;
    cout << "** * Welcome to the guessing game! * **" << endl;
    cout << "*************************************" << endl;

    int number_of_attempts;
    char difficulty;

    bool valid_char = true;

    while(valid_char){
        cout << "Choose your difficulty level: " << endl;
        cout << "Easy (E), Medium (M) or Hard(H)" << endl;
        
        cin >> difficulty;
        
        if (difficulty == 'E'){
            number_of_attempts = 15;
            valid_char = false;
        }
        else if (difficulty == 'M'){
            number_of_attempts = 10;
            valid_char = false;
        }
        else if (difficulty == 'H'){
            number_of_attempts = 5;
            valid_char = false;
        }
        
        cout << "Invalid input " << difficulty << endl;
        cout << "Please enter a valid character: E, M or H." << endl;
    }
    
    srand(time(NULL));
    const int SECRET_NUMBER = rand() % 100;

    bool incorrect = true;
    int attempts = 0;

    double points = 1000.0;

    for(attempts = 1; attempts <= number_of_attempts; attempts++){
        int player_guess;
        cout << "What's your guess? ";
        cin >> player_guess;
        
        double lost_points = abs(player_guess - SECRET_NUMBER)/2.0;
        points = points - lost_points;

        bool correct = player_guess == SECRET_NUMBER;
        bool greater = player_guess > SECRET_NUMBER;

        if(correct){
            cout << "Your guess is correct!"<< endl;
            incorrect = false;
            break;
        }
        else if(greater){
            cout << "Your guess is greater than the secret number! \nTry again." << endl;
        }
        else{
            cout << "Your guess is lower than the secret number! \nTry again." << endl;
        }
    }

    cout << "The end" << endl;

    if(incorrect){
        cout << "You lost! Try again!";
    }
    else{
        cout << "You won the game with " << attempts << " tries." << endl;

        cout.precision(2);
        cout << fixed;
        cout << "Total points: " << points << endl;
    }
}