#include<iostream>
#include<string>
using namespace std;

const string SECRET_WORD = "MELANCIA";

bool letter_exists(char player_guess){
    for(char letter : SECRET_WORD){
        if(player_guess == SECRET_WORD[letter]){
            return true;
        }
    }
    return false;
}

int main(){
    cout << SECRET_WORD << endl;

    bool nao_acertou = true;
    bool nao_enforcou = true;

    while(nao_acertou && nao_enforcou){
        char player_guess;
        cin >> player_guess;

        cout << "Player guess: " << player_guess << endl;

        if (letter_exists(player_guess)){
            cout << "This letter is in the secret word." << endl;
        }
        else{
            cout << "This letter is not in the secret word." << endl;
        }
    }
}