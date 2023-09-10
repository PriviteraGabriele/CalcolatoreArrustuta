#include<iostream>
using namespace std;

int main(){
    cout << "CalcolatoreArrustuta\n" << endl;

    // Caricamento Numero Partecipanti
    int numeroPartecipanti;
    cout << "Inserire il numero dei partecipanti: ";
    cin >> numeroPartecipanti;
    cout << endl;

    // Creazione Array col nome dei partecipanti
    string Partecipanti[numeroPartecipanti];
    for(int i = 0; i<numeroPartecipanti; i++){
        cout << "Inserire il nome del partecipante n." << i + 1 << " (In Maiuscolo): ";
        cin >> Partecipanti[i];
    }

    int numeroTipologieCarne = 6;

    // Creazione Array della Carne
    string carne[numeroTipologieCarne] = {"SALSICCIA SEMPLICE", "SALSICCIA CONDITA", "POLPETTA DI CAVALLO", 
                                          "SPIEDINI ALLA MESSINESE", "CIPOLLATA", "SPIEDINI AL PISTACCHIO"};

    // Creazione Array del costo totale per tipologia di carne
    cout << endl;
    double costoTotalePerTipologia[numeroTipologieCarne];
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
    double costoAlSingoloPezzoPerTipologia[numeroTipologieCarne];
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
        cout << "\nTotale per persona della carne + " << (spesaExtra/numeroPartecipanti) << " della spesa:" << endl;
        for(int i = 0; i<numeroPartecipanti; i++){
            cout << Partecipanti[i] << " -> " << totalePerPersona[i] + (spesaExtra/numeroPartecipanti) << " euro" << endl;
        }
    }
}
