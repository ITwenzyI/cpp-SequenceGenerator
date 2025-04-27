//Created by Kilian

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm> // für std::transform

struct SequenceGenerator {
    int min;
    int step;
    int max;
    int current;
    int (*transform)(int);

    bool has_next() {
        return current <= max;
    }

    int next() {
        int value = current;
        int current_transformed = transform(current);
        current += step;
        return current_transformed;
    }

};

//Normale Seqeunze mit einfach Schrittweite
int normal (int n) {
    return n;
}

// Gibt das Quadrat zurück
int square (int n) {
    n = n * n;
    return n;
}


// Gibt n hoch 3 zurück
int cube(int n) {
    return n * n * n;
}

// Eigene Ideen
int neu(int n) {
    return n;
}



// Gibt das Vorzeichen von n zurück: -1, 0 oder 1
int sign(int n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

int main() {
    int min, max, step;
    int (*funcptr) (int);
    std::string transform_eingabe;
    std::cout << "Gebe die Sqeunz ein: (Startwert) (Schrittweite) (Obergrenze) (Transform)" << std::endl;
    std::cin >> min >> step >> max >> transform_eingabe;


    if(transform_eingabe == "square")
        funcptr = square;
    else if (transform_eingabe == "cube")
        funcptr = cube;
    else if (transform_eingabe == "sign")
        funcptr = sign;
    else if (transform_eingabe == "neu")
        funcptr = neu;
    else
        funcptr = normal;

    if (step == 0) {
        std::cerr << "Fehler: Schrittweite darf nicht 0 sein!" << std::endl;
        return 0; // Programm abbrechen
    }



    SequenceGenerator seq {min, step, max, min, funcptr}; //current = min damit er korekkt startet
    while(seq.has_next()) {
        std::cout << seq.next() << std::endl;
    }
}