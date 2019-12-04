#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("rez.txt");
struct komanda{
    string vardas;
    float laikas;
    int metai;
    };

    void kiekisElementu(int &kiekis, const char byla[]);
    void skaitom(komanda Duomenys[], int kiekis, const char byla[]);
    void rasom(komanda Duomenys[], int kiekis, string text);
    void kuriam(komanda Duomenys[], int kiekis, komanda BendriDuomenys[], int nuoKiek);

int main(){

    int kiek1, kiek2;
    const char duomenys1[] = "pirmas.txt";
    const char duomenys2[] = "antras.txt";

    kiekisElementu(kiek1, duomenys1);
    kiekisElementu(kiek2, duomenys2);
    komanda begikai1[kiek1], begikai2[kiek2], bendraKomanda[kiek1+kiek2];
    int kiekisViso;
    kiekisViso = kiek1+kiek2;
    skaitom(begikai1, kiek1, duomenys1);
    skaitom(begikai2, kiek2, duomenys2);
    rasom(begikai1, kiek1, "pirma komanda \n");
    rasom(begikai2, kiek2, "antra komanda \n");
    kuriam(begikai1, kiek1, bendraKomanda, 0);
    kuriam(begikai2, kiek2, bendraKomanda, kiek1);
    rasom(bendraKomanda, kiekisViso, "bendra komanda \n");


    out.close();
    return 0;
}

 void kiekisElementu(int &kiekis, const char byla[]){
    ifstream in(byla);
    komanda LaikStruktura[1];// uztekna man vieno elemento, kad nuskaityti kieki
    kiekis=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].laikas>>LaikStruktura[0].metai;//skaitom nuo nulinio-(pirmo) elemento
        kiekis++;
    }
    in.seekg(0);
    in.close();
 }
void skaitom(komanda Duomenys[], int kiekis, const char byla[]){
    ifstream in(byla);
    for(int i=0; i<kiekis; i++){
        in>>Duomenys[i].vardas>>Duomenys[i].laikas>>Duomenys[i].metai;
    }
    in.close();
}

void rasom(komanda Duomenys[], int kiekis, string text){
    out<<text;
    for(int i=0; i<kiekis; i++){
        out<<setw(20)<<left<<Duomenys[i].vardas<<setw(4)<<right<<Duomenys[i].laikas<<setw(4)<<right<<Duomenys[i].metai;
        out<<endl;
    }

}
void kuriam(komanda Duomenys[], int kiekis, komanda BendriDuomenys[], int nuoKiek){
    for(int i=0; i<kiekis; i++){
        BendriDuomenys[nuoKiek].vardas = Duomenys[i].vardas;
        BendriDuomenys[nuoKiek].laikas = Duomenys[i].laikas;
        BendriDuomenys[nuoKiek].metai = Duomenys[i].metai;
        nuoKiek++;

    }
}
