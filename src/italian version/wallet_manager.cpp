#include <iostream>
#include <fstream> // File
#include <ctime> // Data gg/mm/aaaa
using namespace std;

// Numero di banconote di vari tagli
struct euro_paper
{
    int fivehundred = 0; // N. banconote da 500 euro
    int twohundred = 0;  // N. banconote da ...
    int onehundred = 0;
    int fifty = 0;
    int twenty = 0;
    int ten = 0;
    int five = 0;
};

// Numero di monete di vari tagli
struct euro_coins
{
    int two = 0; // N. monete da 2
    int one = 0; // N. monete da ...
    int fifty_c = 0;
    int twenty_c = 0;
    int ten_c = 0;
    int five_c = 0;
    int two_c = 0;
    int one_c = 0;
};

// Prototipi
void inserimento(euro_paper &paper, euro_coins &coins);
double calcolo(const euro_paper &paper, const euro_coins &coins);
void salva_saldo(double saldo_tot);

int main()
{
    char scelta;

    // Ciclo per far ripartire il programma a scelta dell'utente
    do {
        // Istanzia una struttura per banconote e monete
        euro_paper paper; 
        euro_coins coins;

        inserimento(paper, coins); // Chiamata per l'inserimento del numero di banconote e monete

        // Calcola il saldo totale usando i dati inseriti e lo stampa
        double saldo_tot = calcolo(paper, coins); 
        cout << "\nPortafoglio = " << saldo_tot << " euro." << endl;

        salva_saldo(saldo_tot); // Salva il saldo totale sul file (portafoglio.txt)

         // Chiede all'utente se vuole fare un nuovo conteggio di denaro usando la variabile scelta definita sopra
        cout << "\nVuoi fare un nuovo conteggio? (s/n): ";
        cin >> scelta;

    } while (scelta == 's' || scelta == 'S'); // Ripete il ciclo se l'utente sceglie 's' o 'S'

    return 0;
}

// Funzione per inserire il numero di banconote e monete
void inserimento(euro_paper &paper, euro_coins &coins)
{
    cout << "BANCONOTE:" << endl;
    // L'utente memorizza l'inserimento di ogni tipo di banconota
    cout << "n. 500 Euro: "; cin >> paper.fivehundred;
    cout << "n. 200 Euro: "; cin >> paper.twohundred;
    cout << "n. 100 Euro: "; cin >> paper.onehundred;
    cout << "n. 50 Euro: "; cin >> paper.fifty;
    cout << "n. 20 Euro: "; cin >> paper.twenty;
    cout << "n. 10 Euro: "; cin >> paper.ten;
    cout << "n. 5 Euro: "; cin >> paper.five;

    cout << "\nMONETE:" << endl; 
    // L'utente memorizza l'inserimento di ogni tipo di moneta
    cout << "n. 2 Euro: "; cin >> coins.two;
    cout << "n. 1 Euro: "; cin >> coins.one;
    cout << "n. 50 Cent: "; cin >> coins.fifty_c;
    cout << "n. 20 Cent: "; cin >> coins.twenty_c;
    cout << "n. 10 Cent: "; cin >> coins.ten_c;
    cout << "n. 5 Cent: "; cin >> coins.five_c;
    cout << "n. 2 Cent: "; cin >> coins.two_c;
    cout << "n. 1 Cent: "; cin >> coins.one_c;

    // Gestione di un input sbagliato (es: inserisce un valore diverso da int come definito nelle strutture)
    if(cin.fail()) { 
        cin.clear(); // Resetta lo stato di errore del flusso di input
        cin.ignore(10000, '\n'); // Scarta l'input non valido
        cout << "Errore nell'inserimento. Riprova.\n"; 
        inserimento(paper, coins); // Richiama la funzione per permettere all'utente di reinserire i dati
    }
}

// Funzione per calcolare il saldo totale del portafoglio
double calcolo(const euro_paper &paper, const euro_coins &coins)
{
    // Array contenenti i valori nominali di banconote e monete
    const int valori_banconote[] = {500, 200, 100, 50, 20, 10, 5};
    const int banconote[] = {paper.fivehundred, paper.twohundred, paper.onehundred, paper.fifty, paper.twenty, paper.ten, paper.five};

    const double valori_monete[] = {2.0, 1.0, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    const int monete[] = {coins.two, coins.one, coins.fifty_c, coins.twenty_c, coins.ten_c, coins.five_c, coins.two_c, coins.one_c};

    // Totale di banconote e monete. Inizializzate a 0
    int banconote_tot = 0;
    double monete_tot = 0;

    // Tot. banconote
    for(int i = 0; i < 7; i++) {
        banconote_tot += banconote[i] * valori_banconote[i];
    }

    // Tot. monete
    for(int i = 0; i < 8; i++) {
        monete_tot += monete[i] * valori_monete[i];
    }

    return banconote_tot + monete_tot; // TOTALE Finale 
}

// Funzione per salvare il saldo totale su un file
void salva_saldo(double saldo_tot)
{
    time_t t = time(0); // Ottiene il tempo attuale
    tm* now = localtime(&t); // Converte il tempo in formato locale
    char data[11]; 
    strftime(data, sizeof(data), "%d/%m/%Y", now); // Format della data come giorno/mese/anno

    ofstream file("Portafoglio.txt", ios::app); // Apre il file in modalità append(app) per aggiungere dati senza sovrascrivere valori salvati giorni prima

    if (file.is_open()) { // Controlla se il file è stato aperto correttamente
        file << data << "\t" << saldo_tot << " euro." << endl; // Scrive la data e il saldo nel file
        file.close(); // Chiude il file
        cout << "\nIl saldo totale è stato salvato nel file 'portafoglio.txt'." << endl;
    } else {
        cout << "Impossibile aprire il file!" << endl; // Segnala errore se il file non si apre
    }
}
