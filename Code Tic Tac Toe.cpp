#include <iostream>
#include <string>
using namespace std;

int main() {
  //Pembukaan
  cout << "Selamat datang di permainan tic tac toe 6x6!" << endl;
  cout << "peraturan: "<<endl << "1. Permainan dimulai dari pemain X"<< endl;
    cout << "2. Pemain yang menang adalah pemain yang berhasil membuat garis dengan 6 huruf yang sama" << endl;
    cout << "3. Masukkan baris dan kolom mulai dari angka 0 sampai 5, 0 = 1, 1 = 2 dst.."<< endl;
    cout << "4. Angka tidak boleh di luar jangkauan angka dan jangan masukkan input apapun kecuali angka" << endl;
    cout << "Selamat Bermain!" << endl;

    //Array papan
    char papan[6][6] = {
        {' ', ' ', ' ', ' ',' ', ' '}, 
        {' ', ' ', ' ', ' ',' ', ' '}, 
        {' ', ' ', ' ', ' ',' ', ' '},
        {' ', ' ', ' ', ' ',' ', ' '},
        {' ', ' ', ' ', ' ',' ', ' '},
        {' ', ' ', ' ', ' ',' ', ' '}
    };

    //Inisialisasi
    const char pemain_X = 'X';
    const char pemain_O = 'O';
    char pemainSekarang = pemain_X;
    int r = -1;
    int c = -1;
    char pemenang = ' ';

    for (int i = 0; i < 36; i++) {
        //print papan permainan
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[0][0] << " | " << papan[0][1] << " | " << papan[0][2] <<" | " << papan[0][3] <<" | " << papan[0][4] << " | " << papan[0][5] << endl;
        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[1][0] << " | " << papan[1][1] << " | " << papan[1][2] <<" | " << papan[1][3] <<" | " << papan[1][4] <<" | " << papan[1][5] << endl;
        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[2][0] << " | " << papan[2][1] << " | " << papan[2][2] <<" | " << papan[2][3] <<" | " << papan[2][4] <<" | " << papan[2][5] << endl;
        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[3][0] << " | " << papan[3][1] << " | " << papan[3][2] <<" | " << papan[3][3] <<" | " << papan[3][4] <<" | " << papan[3][5]<< endl;
        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[4][0] << " | " << papan[4][1] << " | " << papan[4][2] <<" | " << papan[4][3] <<" | " << papan[4][4] <<" | " << papan[4][5] << endl;
        cout << "___|___|___|___|___|___" << endl;
        cout << "   |   |   |   |   |" << endl;
        cout << " " << papan[5][0] << " | " << papan[5][1] << " | " << papan[5][2] <<" | " << papan[5][3] <<" | " << papan[5][4] <<" | " << papan[5][5] << endl;
        cout << "   |   |   |   |   |" << endl;

        if (pemenang != ' ') {
            break;
        }

        cout << "Pemain yang bermain sekarang " << pemainSekarang << endl;
        while (true) {
            cout << "Masukkan baris dan kolom, diisi mulai dari 0-5 (contoh: 1 1) : ";
            cin >> r >> c;
            //Kasus error
            if (r < 0 || r > 5 || c < 0 || c > 5) {
                cout << "Angka yang dimasukkan diluar jangkauan, masukkan baris kolom diisi dari 0-5 (contoh: 1 1)" << endl;
            }
            else if (papan[r][c] != ' ') {
                cout << "Sel sudah diisi, coba lagi!" << endl;
            }
            else {
                break;
            }
           //Pembersihan papan
            r = -1;
            c = -1;
            cin.clear(); 
            cin.ignore(10000, '\n'); 

        }

        //Penggantian Pemain
        papan[r][c] = pemainSekarang;
        pemainSekarang = (pemainSekarang == pemain_X) ? pemain_O : pemain_X;


        //baris - horizontal
        for (int r = 0; r < 3; r++) {
            if (papan[r][0] != ' ' && papan[r][0] == papan[r][1] && papan[r][1] == papan[r][2]) {
                pemenang = papan[r][0];
            }
            else if(papan[r][3] != ' ' && papan[r][3] == papan[r][4] && papan[r][4] == papan[r][5]) {
                pemenang = papan[r][0];
          }
        }

        //kolom - vertical
        for (int c = 0; c < 3; c++) {
            if (papan[0][c] != ' ' && papan[0][c] == papan[1][c] && papan[1][c] == papan[2][c]) {
                pemenang = papan[0][c];
            }
            else if (papan[3][c] != ' ' && papan[3][c] == papan[4][c] && papan[4][c] == papan[5][c]){
               pemenang = papan[0][c];
          }
        }

        //diagonal kiri
        if (papan[0][0] != ' ' && papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2] && papan[2][2] == papan[3][3] && papan[3][3] == papan[4][4] && papan[4][4] == papan[5][5]) {
            pemenang = papan[0][0];
        }
         //diagonal kanan
        else if (papan[0][5] != ' '  && papan[0][5] == papan[1][4] && papan[1][4] == papan[2][3] && papan[2][3] == papan[3][2] && papan[3][2] == papan[4][1] && papan[4][1] == papan[5][0]) {
            pemenang = papan[0][5];
        }
    }

    //Pemberitahuan akhir permainan
    if (pemenang != ' ') {
        cout << "Pemain" << pemenang << " adalah pemenangnya! " << endl;
    }
    else {
        cout << "Permainan seri!" << endl;
    }
}