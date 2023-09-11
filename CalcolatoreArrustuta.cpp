#include<iostream>
#include <limits>
using namespace std;

int main(){
    cout << "CalcolatoreArrustuta\n" << endl;

    // Caricamento Numero Partecipanti
    int numeroPartecipanti;
    cout << "Inserire il numero dei partecipanti: ";
    cin >> numeroPartecipanti;
    cout << endl;

    // Pulisce il buffer dopo l'input del numeroPartecipanti (Evita che venga skippato in automatico il primo inserimento)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Creazione Array col nome dei partecipanti
    string Partecipanti[numeroPartecipanti];
    for(int i = 0; i<numeroPartecipanti; i++){
        cout << "Inserire il nome del partecipante n." << i + 1 << " (In Maiuscolo): ";
        getline(cin, Partecipanti[i]);
    }

    // Caricamento numeroTipologieCarne
    int numeroTipologieCarne;
    cout << "\nInserire il numero delle diverse tipologie di carne: ";
    cin >> numeroTipologieCarne;
    cout << endl;

    // Pulisce il buffer dopo l'input del numeroTipologieCarne (Evita che venga skippato in automatico il primo inserimento)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Creazione Array col nome dei partecipanti
    string carne[numeroTipologieCarne];
    for(int i = 0; i<numeroTipologieCarne; i++){
        cout << "Inserire il nome della tipologia di carne n." << i + 1 << " (In Maiuscolo): ";
        getline(cin, carne[i]);
    }

    // Creazione Array del costo totale per tipologia di carne
    cout << endl;
    double costoTotalePerTipologia[numeroTipologieCarne] = {0};
    for(int i = 0; i<numeroTipologieCarne; i++){
        cout << "Inserire il costo totale di " << carne[i] << ": ";
        cin >> costoTotalePerTipologia[i];
    }

    // Mi creo una matrice per poter segnare il quantitativo per tipologia di carne che ha preso ogni partecipante, 
    // ogni riga rappresenta un partecipante e ogni colonna una tipologia di carne
    int matriceConsumoCarne[numeroPartecipanti][numeroTipologieCarne];

    cout << endl;
    for(int i = 0; i<numeroPartecipanti; i++){
        for(int j = 0; j<numeroTipologieCarne; j++){
            cout << "Inserire il numero di " << carne[j] << " che ha preso " << Partecipanti[i] << ": ";
            cin >> matriceConsumoCarne[i][j];
        }
        cout << endl;
    }

    // Stampa matriceConsumoCarne
    for(int i = 0; i<numeroPartecipanti; i++){
        for(int j = 0; j<numeroTipologieCarne; j++){
            cout << Partecipanti[i] << " -> " << carne[j] << ": " << matriceConsumoCarne[i][j] << endl;
        }
        cout << endl;
    }

    // Array col numero totale di pezzi per tipologia
    int numeroTotPezziPerTipologia[numeroTipologieCarne] = {0};
    for(int i = 0; i<numeroTipologieCarne; i++){
        for(int j = 0; j<numeroPartecipanti; j++){
            numeroTotPezziPerTipologia[i] += matriceConsumoCarne[j][i];
        }
    }

    // Creazione Array del costo al singolo pezzo per tipologia di carne
    double costoAlSingoloPezzoPerTipologia[numeroTipologieCarne] = {0};
    for(int i = 0; i<numeroTipologieCarne; i++){
        costoAlSingoloPezzoPerTipologia[i] = costoTotalePerTipologia[i] / numeroTotPezziPerTipologia[i];
    }

    // Stampa costoAlSingoloPezzoPerTipologia
    for(int i = 0; i<numeroTipologieCarne; i++){
        cout << carne[i] << ": " << costoAlSingoloPezzoPerTipologia[i] << " euro al pezzo" << endl;
    }

    // Array con i Totali per persona
    double totalePerPersona[numeroTipologieCarne] = {0};
    for(int i = 0; i<numeroPartecipanti; i++){
        for(int j = 0; j<numeroTipologieCarne; j++){
            totalePerPersona[i] += matriceConsumoCarne[i][j] * costoAlSingoloPezzoPerTipologia[j];
        }
    }

    // Stampa totalePerPersona
    cout << endl;
    for(int i = 0; i<numeroPartecipanti; i++){
        cout << Partecipanti[i] << " -> " << totalePerPersona[i] << " euro" << endl;
    }

    // Ipotesi ulteriori spese (es. Bevande, patatine, ...)
    string extra;
    cout << "\nCi sono ulteriori spese da dividere (es. bevande, patatine, ...)? "; 
    cin >> extra;

    if(extra == "Si" || extra == "SI"  || extra == "si"){
        double spesaExtra;
        cout << "\nInserire il costo della spesa da dividere alla romana: ";
        cin >> spesaExtra;

        // Stampa totalePerPersona
        cout << "\nTOTALE -> Conto personalizzato carne + " << (spesaExtra/numeroPartecipanti) << " della spesa:\n" << endl;
        for(int i = 0; i<numeroPartecipanti; i++){
            cout << Partecipanti[i] << " -> " << totalePerPersona[i] + (spesaExtra/numeroPartecipanti) << " euro" << endl;
        }
    }
}
