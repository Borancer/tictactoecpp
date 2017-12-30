#include <iostream>
#include <limits>
#include <array>

using namespace std;


//pitäisi tyhjentää näytön aiemmista teksteistä jokaisen loopin jälkeen
void con_cls()
{
    cout << "\033[H\033[J";
}


//tarkistaa onko kolmen suora, jos on niin returnaa falsen, muuten true
bool voittotarkistus(int b[], int n) {

    if (b[0] == b[1] && b[1] == b[2] && b[0] != 0) {
        return false;
    } else if(b[3] == b[4] && b[4] == b[5] && b[3] != 0) {
        return false;
    }  else if(b[6] == b[7] && b[7] == b[8] && b[6] != 0) {
        return false;
    } else if(b[0] == b[4] && b[4] == b[8] && b[0] != 0) {
        return false;
    } else if(b[0] == b[3] && b[3] == b[6] && b[0] != 0) {
        return false;
    } else if(b[1] == b[4] && b[4] == b[7] && b[1] != 0) {
        return false;
    } else if(b[2] == b[5] && b[5] == b[8] && b[2] != 0) {
        return false;
    }  else if(b[2] == b[4] && b[4] == b[6] && b[2] != 0) {
        return false;
    }

    else {
        return true;
    }


}

//tarkistaa onko ruutu jo käytetty vai ei
int samaruutuesto(int u[], int n, int kek2) {
    if (kek2 < 0 || kek2 >= n) {
        return 4;
    }

    if (u[kek2] == 0) {
        return 0;
    } else if (u[kek2] == 1) {
        return 1;
    } else if (u[kek2] == 2) {
        return 2;
    }
    else {
        return 4;
    }

}

// tarkistaa voittajan
int voittajatarkastus(int b[], int n) {

    if (b[0] == b[1] && b[1] == b[2] && b[0] == 1) {
        return 1;
    } else if (b[0] == b[1] && b[1] == b[2] && b[0] == 2) {
        return 2;
    } else if(b[3] == b[4] && b[4] == b[5] && b[3] == 1) {
        return 1;
    }  else if(b[3] == b[4] && b[4] == b[5] && b[3] == 2) {
        return 2;
    }  else if(b[6] == b[7] && b[7] == b[8] && b[6] == 1) {
        return 1;
    }  else if(b[6] == b[7] && b[7] == b[8] && b[6] == 2) {
        return 2;
    }else if(b[0] == b[4] && b[4] == b[8] && b[0] == 1) {
        return 1;
    }else if(b[0] == b[4] && b[4] == b[8] && b[0] == 2) {
        return 2;
    } else if(b[0] == b[3] && b[3] == b[6] && b[0] == 1) {
        return 1;
    } else if(b[0] == b[3] && b[3] == b[6] && b[0] == 2) {
        return 2;
    } else if(b[1] == b[4] && b[4] == b[7] && b[1] == 1) {
        return 1;
    } else if(b[1] == b[4] && b[4] == b[7] && b[1] == 2) {
        return 2;
    } else if(b[2] == b[5] && b[5] == b[8] && b[2] == 1) {
        return 1;
    } else if(b[2] == b[5] && b[5] == b[8] && b[2] == 2) {
        return 2;
    } else if(b[2] == b[4] && b[4] == b[6] && b[2] == 1) {
        return 1;
    } else if(b[2] == b[4] && b[4] == b[6] && b[2] == 2) {
        return 2;
        //tarkistaa onko tasapeli vai ei
    } else if(b[0] != 0 && b[1] != 0 && b[2] != 0 && b[3] != 0 && b[4] != 0 && b[5] != 0 && b[6] != 0 && b[7] != 0 && b[8] != 0 ) {
        return 3;
    } else {
        return 0;
    }

}
void piirraruudukko(int ruudukko[8]) {

    for (int u = 0; u < 9; u++) {
        if (ruudukko[u] == 0) {
            cout << "[" << " " << "]";
            if (u == 2 || u == 5) {
                cout << endl;
            }
        } else if (ruudukko[u] == 1) {
            cout << "[" << "x" << "]";
            if (u == 2 || u == 5) {
                cout << endl;
            }
        } else if (ruudukko[u] == 2) {
            cout << "[" << "o" << "]";
            if (u == 2 || u == 5) {
                cout << endl;
            }
        } else { // jos error
            cout << "[" << "e" << "]";
            if (u == 2 || u == 5) {
                cout << endl;
            }
        }
    }
}
