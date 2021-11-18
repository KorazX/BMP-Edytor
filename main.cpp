#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
    char nazwa_pliku[20];

    string R, G, B;
    R = G = B = "0";

    //Plik 1
    cout << "Podaj nazwe pliku zrodlowego" << endl;
    cin >> nazwa_pliku;

    fstream plik;
    plik.open(nazwa_pliku, ios::in | ios::binary);
    if (!plik)
    {
        cout << "Blad otwierania pliku" << endl;
        system("PAUSE");
        return 0;
    }

    //Plik 2gi
    cout << "Podaj nazwe pliku docelowego" << endl;
    cin >> nazwa_pliku;

    fstream plik2;
    plik2.open(nazwa_pliku, ios::out | ios::binary);
    if (!plik2)
    {
        cout << "Blad otwierania pliku" << endl;
        system("PAUSE");
        return 0;
    }

    //Co zerowac?
    cout << "Wyzerowac czerwony? (T/N)" << endl;
    cin >> R;
    cout << "Wyzerowac zielony? (T/N)" << endl;
    cin >> G;
    cout << "Wyzerowac niebieski? (T/N)" << endl;
    cin >> B;

    char header[55];
    for (int i = 0; i < 55; i++) header[i] = NULL;

    plik.read(header, 54);
    plik2.write(header, 54);

    //Kopiowanie
    char bufor[13] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

    int licznik = 1;

    do {
        if (licznik == 4) licznik = 1;
        plik.read(bufor, 1);
        ////
        if (B == "T" && licznik == 1)
        {
            bufor[0] = NULL;
        }

        if (G == "T" && licznik == 2)
        {
            bufor[0] = NULL;
        }

        if (R == "T" && licznik == 3)
        {
            bufor[0] = NULL;
        }

        ///
        if (!plik.eof()) plik2.write(bufor, 1);
        licznik++;
    } while (!plik.eof());

    plik.close();
    plik2.close();
    cout << "Zmiany zostaly zapisane w " << nazwa_pliku << endl;
    system("PAUSE");

    return 0;
}
