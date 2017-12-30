#include <iostream>
#include <algorithm>
#include <limits>
#include "omakirjasto.h"
using namespace std;


int main() {

    int number;
    string pelaajanimi[2];
    //ristinollaruudukko
    int ruudukko[9];


    cout << "Welcome to tic tac toe!" << endl;


    cout << "Two player game (press 1))";
    cin >> number;


    //luo ruudukkoon nollat (1 on x ja 2 on o)
    for (int i = 0; i < 10; i++) {
        ruudukko[i] = 0;
    }


    if (number == 1) {

        cout << "Player 1 name: ";
        cin >> pelaajanimi[0];
        cout << "Player 2 name: ";
        cin >> pelaajanimi[1];

        //while looppi päättyy siihen jos on kolmen suora tai tasapeli
        while (voittotarkistus(ruudukko, 9) == true) {

            piirraruudukko(ruudukko);

            for (int s = 0; s < 9; s++) {
                //kattoo kumman vuoro on
                int kummanvuoro = s%2;
                int pelaajanvalinta = 0;

                //Pelaajan valinta
                cout << endl << "First square is 1 and so on (1-9)";
                cout << endl << pelaajanimi[kummanvuoro] <<"'s turn (choose number)";
                cin >> pelaajanvalinta;
                if (voittotarkistus(ruudukko, 9) == 3) {
                    break;
                }
                // estää samaan ruutuun laittamisen
                while (true) {
                    if (samaruutuesto(ruudukko, 9, pelaajanvalinta -1) == 0) {
                        break;
                    } else {

                        cout << "Choose a new square which is not used: ";
                        cin >> pelaajanvalinta;
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> pelaajanvalinta;
                        }
                    }
                }

                for (int j = 0; j < 10; j++) {
                    if (pelaajanvalinta == j) {
                        ruudukko[j-1] = kummanvuoro + 1;
                    }
                }

                piirraruudukko(ruudukko);

                //ohjelma lopettaa toimintansa jos on kolmen suora
                if (!voittotarkistus(ruudukko, 9)) {
                    break;
                } else if (voittotarkistus(ruudukko, 9) == 3) {
                    break;
                }
            }
            //tyhjentaa ruudun jokaisen siirron jälkeen, ei välttämättä toimi windowssissa
            con_cls();



            //tarkistaa voittajan ja tulostaa kumpi voittaa tai tasapeli tarvittaessa
            if (voittajatarkastus(ruudukko, 9) == 1) {
                cout << endl << pelaajanimi[0] << " won!";
            } else if  (voittajatarkastus(ruudukko, 9) == 2) {
                cout << endl <<  pelaajanimi[1] << " won!";
            } else if (voittajatarkastus(ruudukko, 9) == 3) {
                cout << endl << "It's draw!";
            } else {
                cout << endl << "Okay something went wrong!";
                piirraruudukko(ruudukko);
            }
            cout << endl << "Game over";

            return 0;
        }

    } else {
        return 0;
    }




}
