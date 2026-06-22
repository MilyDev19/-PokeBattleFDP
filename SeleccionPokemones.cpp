#include <iostream>
using namespace std;
int main(void)
{
    string ENTRENADOR1, ENTRENADOR2;
    int POKEMON1, POKEMON2;
    cout << "POKEMON CHAMPIONS" << endl;
    cout << "=================" << endl;
    cout << "Bienvenido/a, entrenador 1! Cual es tu nombre?" << endl;
    cin >> ENTRENADOR1;
    cout << "Bienvenido/a, entrenador 2! Cual es tu nombre?" << endl;
    cin >> ENTRENADOR2;
    cout << "Entrenador " << ENTRENADOR1 << ", escoje tu pokemon" << endl;
    cout << "1. Charizard" << endl;
    cout << "2. Vennusaur" << endl;
    cout << "3. Blastoise" << endl;
    cin >> POKEMON1;
    cout << endl;
    while (POKEMON1 != 1 && POKEMON1 != 2 && POKEMON1 != 3)
    {
      cout << "Pokemon invalido, intenta otra vez." << endl;
      cin >> POKEMON1;  
    }
    switch (POKEMON1)
        {
        case 1:
            cout << "ENTRENADOR/A " << ENTRENADOR1 << ", HAS ELEGIDO A: CHARIZARD." << endl;
            cout << endl;
            break;
        case 2:
            cout << "ENTRENADOR/A " << ENTRENADOR1 << ", HAS ELEGIDO A: VENNUSAUR." << endl;
            cout << endl;
            break;
        case 3:
            cout << "ENTRENADOR/A " << ENTRENADOR1 << ", HAS ELEGIDO A: BLASTOISE." << endl;
            cout << endl;
            break;
        }
    cout << "Entrenador " << ENTRENADOR2 << ", escoje tu pokemon" << endl;
    cout << "1. Charizard" << endl;
    cout << "2. Vennusaur" << endl;
    cout << "3. Blastoise" << endl;
    cin >> POKEMON2;
    cout << endl;
    while (POKEMON2 != 1 && POKEMON2 != 2 && POKEMON2 != 3)
    {
        cout << "Pokemon invalido, intenta otra vez." << endl;
        cin >> POKEMON2;
        
    }
    switch (POKEMON2)
        {
        case 1:
            cout << "ENTRENADOR/A " << ENTRENADOR2 << ", HAS ELEGIDO A: CHARIZARD." << endl;
            cout << endl;
            break;
        case 2:
            cout << "ENTRENADOR/A " << ENTRENADOR2 << ", HAS ELEGIDO A: VENNUSAUR." << endl;
            cout << endl;
            break;
        case 3:
            cout << "ENTRENADOR/A " << ENTRENADOR2 << ", HAS ELEGIDO A: BLASTOISE." << endl;
            cout << endl;
            break;
        }
}