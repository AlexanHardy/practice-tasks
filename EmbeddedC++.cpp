#include <stdio.h>
#include <string>
#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
#define KASNJENJE 2
#define PERIOD_ISPISA 5
// Definiramo varijable koje će govoriti je li stanje upaljeno ili ugašeno
int A = 0; 
int B = 0;
int C = 0;

//Definiramo funkcije za ispis, radi lakše buduće izmjene koda
void Ispis(){
    cout << "-----------" << endl;
    if (A == 1){
        cout << "A: upaljeno" << endl;
    } else {
        cout <<"A: ugaseno" << endl;
    }
    if (B == 1){
        cout << "B: upaljeno" << endl;
    } else {
        cout <<"B: ugaseno" << endl;
    }
    if (C == 1){
        cout << "C: upaljeno" << endl;
    } else {
        cout <<"C: ugaseno" << endl;
    }
    cout << "-----------" << endl;

}

//Definiramo funkcije za promjenu stanja
void StartUp(){
   sleep(KASNJENJE);
   A = 1;
   sleep(KASNJENJE);
   B = 1;
   sleep(KASNJENJE);
   C = 1;
}
void UpisanA(){
   sleep(KASNJENJE);
   A = 0;
   B = 0;
   C = 0;
   sleep(KASNJENJE);
   A = 1;
   sleep(KASNJENJE);
   B = 1;
   sleep(KASNJENJE);
   C = 1;
}
void UpisanB(){
   sleep(KASNJENJE);
   B = 0;
   C = 0;
   sleep(KASNJENJE);
   B = 1;
   sleep(KASNJENJE);
   C = 1;  
}
void UpisanC(){
   sleep(KASNJENJE);
   C = 0;
   sleep(KASNJENJE);
   C = 1;
}

void IspisStanja(){
    //Svakih 5 sekundi ispisujemo trenutna stanja
    while(true){
        sleep(PERIOD_ISPISA);
        Ispis();
    }
}
void UpisUKonzolu(){
    //Stalno provjeravamo upis u konzoli, u ovom pristupu možemo više puta pozvati funkciju za mijenanje stanja,
    //Čak i ako se neka od njih trenutno izvodi
    StartUp(); //Početno paljenje stanja
    while(true){
        char x;
        cin >> x;
        if (x == 'A'){
            cout << "Gasenje A" << endl;
            UpisanA();
            
        }
        if (x == 'B'){
            cout << "Gasenje B" << endl;
            UpisanB();
            
        }
        if (x == 'C'){
            cout << "Gasenje C" << endl;
            UpisanC();
            
        }
    }
}
int main(){
    //Koristimo dretve da program u isto vrijeme može ispisivati stanja i čitati input korisnika
    thread t1(IspisStanja);
    thread t2(UpisUKonzolu);
    t1.join();
    t2.join();
}