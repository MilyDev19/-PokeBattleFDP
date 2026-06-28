#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

struct reg {
    char fecha[9];
    char entrenador1[30];
    char entrenador2[30];
    char pokemon1[20];
    char pokemon2[20];
    char ganador[30];
};

void ingresarFecha(reg *);
void ingresarEntrenadores(string *, string *);
void mostrarEntrenadores(string, string);
void seleccionarPokemon(string, int *);
void realizarBatalla(string, string, int, int, reg *);
void guardarBatalla(reg *);
void mostrarAtaques(int);
void turno(string, int, int *, int, int *, int *, int *, bool *, bool *, bool *, int *, int *);
void atacar(int, int, int *, int *, int *, bool *, bool *, bool *);
void tableroResultados();
void reportes();
void repoTodasLasBatallas();
void repoBatallasPorFecha();
void repoBatallasPorEntrenador();
void repoBatallasPorPokemon();

int main() {
    int opcion = 1, pokemon1 = 0, pokemon2 = 0;
    bool vieneDeBatalla;
    string pausar, entrenador1, entrenador2;
    reg registro;

    while (opcion != 6) {
        system("cls");
        cout << "POKEMON CHAMPIONS" << endl;
        cout << "=================" << endl << endl;
        cout << "1) Ingresar entrenadores." << endl;
        cout << "2) Mostrar entrenadores." << endl;
        cout << "3) Realizar batalla." << endl;
        cout << "4) Tablero de resultados." << endl;
        cout << "5) Reportes." << endl;
        cout << "6) Salir." << endl << endl;
        cout << "Digite su opcion: ";
        cin >> opcion;
        cin.ignore();
        vieneDeBatalla = false;

        switch (opcion) {
        case 1:
            ingresarFecha(&registro);
            ingresarEntrenadores(&entrenador1, &entrenador2);

            for (int i = 0; i < (int)entrenador1.length(); i++)
                registro.entrenador1[i] = entrenador1[i];
            registro.entrenador1[entrenador1.length()] = '\0';

            for (int i = 0; i < (int)entrenador2.length(); i++)
                registro.entrenador2[i] = entrenador2[i];
            registro.entrenador2[entrenador2.length()] = '\0';

            seleccionarPokemon(entrenador1, &pokemon1);
            if (pokemon1 == 1) strcpy(registro.pokemon1, "Charizard");
            else if (pokemon1 == 2) strcpy(registro.pokemon1, "Venusaur");
            else strcpy(registro.pokemon1, "Blastoise");

            seleccionarPokemon(entrenador2, &pokemon2);
            if (pokemon2 == 1) strcpy(registro.pokemon2, "Charizard");
            else if (pokemon2 == 2) strcpy(registro.pokemon2, "Venusaur");
            else strcpy(registro.pokemon2, "Blastoise");
            break;

        case 2: mostrarEntrenadores(entrenador1, entrenador2); break;
        case 3:
            realizarBatalla(entrenador1, entrenador2, pokemon1, pokemon2, &registro);
            vieneDeBatalla = true;
            break;
        case 4: tableroResultados(); break;
        case 5: reportes(); break;
        case 6: cout << endl << "Hasta la vista, entrenador! Vuelve pronto." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }

        if (!vieneDeBatalla && opcion != 6) {
            cout << endl << "Menu principal. Pulse Enter para continuar...";
            getline(cin, pausar);
        }
    }
    return 0;
}

void ingresarFecha(reg *r) {
    int anho, mes, dia;
    string anhoTxt, mesTxt, diaTxt, fecha;

    cout << "Digite la fecha de la batalla" << endl;
    cout << "Anio: "; cin >> anho;
    cout << "Mes: ";  cin >> mes;
    cout << "Dia: ";  cin >> dia;
    cin.ignore();

    anhoTxt = to_string(anho);
    mesTxt  = (mes < 10) ? ("0" + to_string(mes)) : to_string(mes);
    diaTxt  = (dia < 10) ? ("0" + to_string(dia)) : to_string(dia);
    fecha   = anhoTxt + mesTxt + diaTxt;

    for (int i = 0; i < (int)fecha.length(); i++)
        r->fecha[i] = fecha[i];
    r->fecha[fecha.length()] = '\0';
}

void ingresarEntrenadores(string *e1, string *e2) {
    cout << endl << "Bienvenido/a, entrenador 1!" << endl;
    cout << "Cual es tu nombre? ";
    cin >> *e1;
    cout << endl << "Bienvenido/a, entrenador 2!" << endl;
    cout << "Cual es tu nombre? ";
    cin >> *e2;
}

void mostrarEntrenadores(string e1, string e2) {
    cout << endl << "Entrenadores registrados:" << endl << endl;
    cout << "Entrenador 1: " << e1 << endl;
    cout << "Entrenador 2: " << e2 << endl;
}

void seleccionarPokemon(string entrenador, int *pokemon) {
    cout << endl << "Entrenador " << entrenador << ", escoja su pokemon" << endl;
    cout << "1. Charizard" << endl;
    cout << "2. Venusaur" << endl;
    cout << "3. Blastoise" << endl;
    cin >> *pokemon;
    while (*pokemon < 1 || *pokemon > 3) {
        cout << "Pokemon invalido." << endl;
        cin >> *pokemon;
    }
}

void guardarBatalla(reg *r) {
    ofstream arch("batallas.dat", ios::app | ios::binary);
    arch.write((char *) r, sizeof(reg));
    arch.close();
    cout << endl << "Batalla guardada correctamente." << endl;
}

void mostrarAtaques(int pokemon) {
    cout << endl;
    switch (pokemon) {
    case 1:
        cout << "1. Lanzallamas" << endl;
        cout << "2. Garra Dragon" << endl;
        cout << "3. Fuego Fatuo" << endl;
        cout << "4. Proteccion" << endl;
        break;
    case 2:
        cout << "1. Latigo Cepa" << endl;
        cout << "2. Drenadoras" << endl;
        cout << "3. Recuperacion" << endl;
        cout << "4. Hoja Afilada" << endl;
        break;
    case 3:
        cout << "1. Hidrobomba" << endl;
        cout << "2. Acua Jet" << endl;
        cout << "3. Agilidad" << endl;
        cout << "4. Viento Hielo" << endl;
        break;
    }
}

void atacar(int pokemon, int ataque, int *hpRival, int *vel, int *hp,
            bool *quemado, bool *dren, bool *protegido) {
    int dano = 0;

    switch (pokemon) {
    case 1: // Charizard
        if (ataque == 1) {
            dano = 60;
            cout << "Lanzallamas hizo " << dano << " de danio." << endl;
        } else if (ataque == 2) {
            dano = 50;
            cout << "Garra Dragon hizo " << dano << " de danio." << endl;
        } else if (ataque == 3) {
            *quemado = true;
            cout << "El rival fue quemado." << endl;
        } else if (ataque == 4) {
            *protegido = true;
            cout << "Proteccion activada." << endl;
        }
        break;

    case 2: // Venusaur
        if (ataque == 1) {
            dano = 55;
            cout << "Latigo Cepa hizo " << dano << " de danio." << endl;
        } else if (ataque == 2) {
            *dren = true;
            cout << "Drenadoras activadas." << endl;
        } else if (ataque == 3) {
            *hp += 80;
            cout << "Recuperacion usada." << endl;
        } else if (ataque == 4) {
            dano = 65;
            cout << "Hoja Afilada hizo " << dano << " de danio." << endl;
        }
        break;

    case 3: // Blastoise
        if (ataque == 1) {
            dano = 70;
            cout << "Hidrobomba hizo " << dano << " de danio." << endl;
        } else if (ataque == 2) {
            dano = 50;
            cout << "Acua Jet hizo " << dano << " de danio." << endl;
        } else if (ataque == 3) {
            *vel += 15;
            cout << "Velocidad +15." << endl;
        } else if (ataque == 4) {
            dano = 55;
            cout << "Viento Hielo hizo " << dano << " de danio." << endl;
        }
        break;
    }

    *hpRival -= dano;
    if (*hp < 0) *hp = 0;
    if (*hpRival < 0) *hpRival = 0;
}
void turno(string nombre, int pokemon, int *hp, int hpMax, int *hpRival,
           int *vel, int *velRival, bool *quemado, bool *dren, bool *protegido,
           int *pociones, int *maximas) {
    int op, obj, ataque;

    cout << endl << "Turno de " << nombre << endl;
    cout << "1. Ataque" << endl;
    cout << "2. Objeto" << endl;
    cin >> op;

    while (op < 1 || op > 2) {
        cout << "Opcion invalida." << endl;
        cin >> op;
    }

    if (op == 2) {
        cout << endl << "Elige un objeto:" << endl;
        cout << "1. Pocion (+40 HP) [" << *pociones << " restantes]" << endl;
        cout << "2. Pocion Max (HP completo) [" << *maximas << " restantes]" << endl;
        cin >> obj;

        while (obj < 1 || obj > 2) {
            cout << "Opcion invalida." << endl;
            cin >> obj;
        }

        if (obj == 1) {
            if (*pociones <= 0) {
                cout << "No te quedan pociones!" << endl;
            } else {
                *hp = *hp + 40;
                if (*hp > hpMax) *hp = hpMax;
                (*pociones)--;
                cout << "Usaste Pocion. HP actual: " << *hp << endl;
            }
        } else {
            if (*maximas <= 0) {
                cout << "No te quedan pociones max!" << endl;
            } else {
                *hp = hpMax;
                (*maximas)--;
                cout << "Usaste Pocion Max. HP actual: " << *hp << endl;
            }
        }
    } else {
        mostrarAtaques(pokemon);
        cin >> ataque;

        while (ataque < 1 || ataque > 4) {
            cout << "Ataque invalido." << endl;
            cin >> ataque;
        }

        atacar(pokemon, ataque, hpRival, vel, hp, quemado, dren, protegido);
    }
}

void realizarBatalla(string e1, string e2, int p1, int p2, reg *registro) {
    int hp1, hp2, vel1, vel2, hpMax1, hpMax2;
    int poc1, max1, poc2, max2;
    bool quemado1, quemado2, dren1, dren2, prot1, prot2;
    string ganador;

    if (p1 == 0 || p2 == 0) {
        cout << endl << "Error: ambos entrenadores deben seleccionar un pokemon primero." << endl;
        return;
    }

    if (p1 == 1) { hp1 = 266; vel1 = 100; }
    else if (p1 == 2) { hp1 = 270; vel1 = 80; }
    else { hp1 = 268; vel1 = 78; }

    if (p2 == 1) { hp2 = 266; vel2 = 100; }
    else if (p2 == 2) { hp2 = 270; vel2 = 80; }
    else { hp2 = 268; vel2 = 78; }

    hpMax1 = hp1;
    hpMax2 = hp2;
    poc1 = 3; max1 = 1;
    poc2 = 3; max2 = 1;
    quemado1 = false; quemado2 = false;
    dren1 = false;    dren2 = false;
    prot1 = false;    prot2 = false;

    while (hp1 > 0 && hp2 > 0) {
        cout << endl << e1 << " HP: " << hp1 << "   " << e2 << " HP: " << hp2 << endl;
        cout << "Vel1: " << vel1 << "   Vel2: " << vel2 << endl;

        prot1 = false;
        prot2 = false;

        if (vel1 >= vel2) {
            turno(e1, p1, &hp1, hpMax1, &hp2, &vel1, &vel2, &quemado2, &dren2, &prot1, &poc1, &max1);
            if (hp2 <= 0) break;
            turno(e2, p2, &hp2, hpMax2, &hp1, &vel2, &vel1, &quemado1, &dren1, &prot2, &poc2, &max2);
        } else {
            turno(e2, p2, &hp2, hpMax2, &hp1, &vel2, &vel1, &quemado1, &dren1, &prot2, &poc2, &max2);
            if (hp1 <= 0) break;
            turno(e1, p1, &hp1, hpMax1, &hp2, &vel1, &vel2, &quemado2, &dren2, &prot1, &poc1, &max1);
        }

        if (quemado1 && !prot1) hp1 -= 25;
        if (quemado2 && !prot2) hp2 -= 25;

        if (dren1) {
            hp1 -= 30;
            hp2 += 30;
            if (hp2 > hpMax2) hp2 = hpMax2;
        }
        if (dren2) {
            hp2 -= 30;
            hp1 += 30;
            if (hp1 > hpMax1) hp1 = hpMax1;
        }

        if (hp1 < 0) hp1 = 0;
        if (hp2 < 0) hp2 = 0;

        cout << endl << e1 << " HP restante: " << hp1 << endl;
        cout << e2 << " HP restante: " << hp2 << endl;
    }

    if (hp1 > 0) ganador = e1;
    else ganador = e2;

    cout << endl << "=============================" << endl;
    cout << "  " << ganador << " gana la batalla!" << endl;
    cout << "=============================" << endl;

    for (int i = 0; i < (int)ganador.length(); i++)
        registro->ganador[i] = ganador[i];
    registro->ganador[ganador.length()] = '\0';

    guardarBatalla(registro);

    string pausa;
    cout << endl << "Presione Enter para volver al menu...";
    getline(cin, pausa);
    cin.ignore();
}

