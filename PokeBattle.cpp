#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <limits>

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
void mostrarAtaques(int, int);
void turno(string, int, int *, int, int *, int *, int *, bool *, int *, bool *, int *, bool *, int *, int *, int *, bool);
void atacar(int, int, int *, int *, int *, bool *, int *, bool *, int *, bool *, int *, bool);
void tableroResultados();
void reportes();
void repoTodasLasBatallas();
void repoBatallasPorFecha();
void repoBatallasPorEntrenador();
void repoBatallasPorPokemon();
bool esFechaValida(int, int, int);
void guardarReporteEnArchivo(string);
int leerEntero(string mensaje, int minimo, int maximo);

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
        opcion = leerEntero("Digite su opcion: ", 1, 6);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        default: cout << "Opcion no valida. Por favor, seleccione un numero del 1 al 6." << endl;
        }

        if (!vieneDeBatalla && opcion != 6) {
            cout << endl << "Menu principal. Pulse Enter para continuar...";
            getline(cin, pausar);
        }
    }
    return 0;
}

bool esFechaValida(int d, int m, int a) {
    if (a < 1996 || a > 2026) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1) return false;

    int diasMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) {
        diasMes[2] = 29;
    }

    if (d > diasMes[m]) return false;

    return true;
}

void ingresarFecha(reg *r) {
    int anho, mes, dia;
    string anhoTxt, mesTxt, diaTxt, fecha;
    int diasMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    cout << "Digite la fecha de la batalla (Anio entre 1996 y 2026)" << endl;

    do {
        anho = leerEntero("Anio (1996-2026): ", 1996, 2026);
        mes  = leerEntero("Mes (1-12): ", 1, 12);

        int maxDia = diasMes[mes];
        if (anho % 4 == 0 && (anho % 100 != 0 || anho % 400 == 0) && mes == 2) {
            maxDia = 29; // febrero en anio bisiesto
        }
        dia = leerEntero("Dia (1-" + to_string(maxDia) + "): ", 1, maxDia);

        if (!esFechaValida(dia, mes, anho)) {
            cout << "Error: Fecha ilogica o fuera de rango. Intentelo de nuevo." << endl;
        }
    } while (!esFechaValida(dia, mes, anho));
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    do {
        cout << "Cual es tu nombre? (Max. 29 caracteres): ";
        cin >> *e1;
        if (e1->length() > 29) {
            cout << "Error: El nombre es demasiado largo." << endl;
        }
    } while (e1->length() > 29);

    cout << endl << "Bienvenido/a, entrenador 2!" << endl;
    do {
        cout << "Cual es tu nombre? (Max. 29 caracteres): ";
        cin >> *e2;
        if (e2->length() > 29) {
            cout << "Error: El nombre es demasiado largo." << endl;
        }
    } while (e2->length() > 29);
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
    *pokemon = leerEntero("Seleccione (1-3): ", 1, 3);
}

void guardarBatalla(reg *r) {
    ofstream arch("batallas.dat", ios::app | ios::binary);
    arch.write((char *) r, sizeof(reg));
    arch.close();
    cout << endl << "Batalla guardada correctamente." << endl;
}

// ============================================================
// Funcion adaptada de "guardarPuntosEnLeaderboard".
// Guarda cualquier linea de texto de un reporte en reportes.txt,
// siguiendo el mismo patron: ofstream + ios::app + is_open().
// ============================================================
void guardarReporteEnArchivo(string linea) {
    ofstream archivoEscritura("reportes.txt", ios::app);
    if (archivoEscritura.is_open()) {
        archivoEscritura << linea << "\n";
        archivoEscritura.close();
    } else {
        cout << "No se pudo guardar el reporte en reportes.txt" << endl;
    }
}

// ============================================================
// Lee un entero de forma segura dentro de un rango [minimo, maximo].
// Si el usuario escribe algo que no es un numero, cin queda en
// estado de fallo (failbit) y TODAS las lecturas siguientes
// devuelven 0 sin esperar entrada, causando un bucle infinito.
// Esta funcion detecta ese fallo con cin.fail(), limpia el estado
// con cin.clear() y descarta la entrada invalida con cin.ignore().
// ============================================================
int leerEntero(string mensaje, int minimo, int maximo) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor < minimo || valor > maximo) {
        if (cin.eof()) {
            cout << endl << "Error: no se pudo leer entrada del teclado (EOF). "
                 << "Verifique que el programa se este ejecutando en una consola interactiva." << endl;
            exit(1);
        }
        cin.clear();                                         // limpia failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // descarta lo que quedo en el buffer
        cout << "Entrada invalida. Ingrese un numero entre " << minimo << " y " << maximo << ": ";
        cin >> valor;
    }
    return valor;
}

void mostrarAtaques(int pokemon, int protRestante) {
    cout << endl;
    switch (pokemon) {
    case 1:
        cout << "1. Lanzallamas" << endl;
        cout << "2. Garra Dragon" << endl;
        cout << "3. Fuego Fatuo" << endl;
        cout << "4. Proteccion (usos restantes: " << protRestante << ")" << endl;
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
            bool *quemado, int *turnosQuemado, bool *dren, int *turnosDren,
            bool *protegido, int *protRestante, bool rivalProtegido) {

    bool esAtaqueAlRival = true;
    if (pokemon == 1 && ataque == 4) esAtaqueAlRival = false; // Proteccion
    if (pokemon == 2 && ataque == 3) esAtaqueAlRival = false; // Recuperacion
    if (pokemon == 3 && ataque == 3) esAtaqueAlRival = false; // Agilidad

    if (esAtaqueAlRival && rivalProtegido) {
        cout << "¡El rival se ha protegido! El ataque no surte efecto." << endl;
        return;
    }

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
            if (!*quemado) {
                *quemado = true;
                *turnosQuemado = 3;
                cout << "El rival ha sido quemado. Durara 3 turnos." << endl;
            } else {
                cout << "El ataque fallo, el rival ya estaba quemado." << endl;
            }
        } else if (ataque == 4) {
            if (*protRestante <= 0) {
                cout << "Ya no te quedan usos de Proteccion. Pierdes el turno." << endl;
            } else {
                *protegido = true;
                (*protRestante)--;
                cout << "Charizard uso Proteccion. ¡Esta protegido de ataques directos! (usos restantes: " << *protRestante << ")" << endl;
            }
        }
        break;

    case 2: // Venusaur
        if (ataque == 1) {
            dano = 55;
            cout << "Latigo Cepa hizo " << dano << " de danio." << endl;
        } else if (ataque == 2) {
            if (!*dren) {
                *dren = true;
                *turnosDren = 3;
                cout << "Drenadoras plantadas en el rival. Duraran 3 turnos." << endl;
            } else {
                cout << "El ataque fallo, el rival ya tiene drenadoras." << endl;
            }
        } else if (ataque == 3) {
            *hp += 80;
            cout << "Venusaur usa Recuperacion y restaura HP." << endl;
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
            cout << "Blastoise uso Agilidad. Su velocidad sube +15." << endl;
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
           int *vel, int *velRival, bool *quemado, int *turnosQuemado,
           bool *dren, int *turnosDren, bool *protegido, int *protRestante,
           int *pociones, int *maximas, bool rivalProtegido) {
    int obj, ataque;

    cout << endl << "Turno de " << nombre << endl;
    cout << "1. Ataque" << endl;
    cout << "2. Objeto" << endl;
    int op = leerEntero("Elige una opcion (1-2): ", 1, 2);

    if (op == 2) {
        cout << endl << "Elige un objeto:" << endl;
        cout << "1. Pocion (+40 HP) [" << *pociones << " restantes]" << endl;
        cout << "2. Pocion Max (HP completo) [" << *maximas << " restantes]" << endl;
        obj = leerEntero("Elige un objeto (1-2): ", 1, 2);

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
        mostrarAtaques(pokemon, *protRestante);
        ataque = leerEntero("Elige un ataque (1-4): ", 1, 4);

        atacar(pokemon, ataque, hpRival, vel, hp, quemado, turnosQuemado, dren, turnosDren, protegido, protRestante, rivalProtegido);
    }
}

void realizarBatalla(string e1, string e2, int p1, int p2, reg *registro) {
    int hp1, hp2, vel1, vel2, hpMax1, hpMax2;
    int poc1, max1, poc2, max2;
    bool quemado1, quemado2, dren1, dren2, prot1, prot2;
    int turnosQuemado1, turnosQuemado2, turnosDren1, turnosDren2;
    int protRestante1, protRestante2;
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
    turnosQuemado1 = 0; turnosQuemado2 = 0;
    turnosDren1 = 0;    turnosDren2 = 0;
    protRestante1 = 3;  protRestante2 = 3;

    while (hp1 > 0 && hp2 > 0) {
        cout << endl << "--- NUEVA RONDA ---" << endl;
        cout << e1 << " HP: " << hp1 << "   " << e2 << " HP: " << hp2 << endl;
        cout << "Vel1: " << vel1 << "   Vel2: " << vel2 << endl;

        prot1 = false;
        prot2 = false;

        if (vel1 >= vel2) {
            turno(e1, p1, &hp1, hpMax1, &hp2, &vel1, &vel2, &quemado2, &turnosQuemado2, &dren2, &turnosDren2, &prot1, &protRestante1, &poc1, &max1, prot2);
            if (hp2 <= 0) break;
            turno(e2, p2, &hp2, hpMax2, &hp1, &vel2, &vel1, &quemado1, &turnosQuemado1, &dren1, &turnosDren1, &prot2, &protRestante2, &poc2, &max2, prot1);
        } else {
            turno(e2, p2, &hp2, hpMax2, &hp1, &vel2, &vel1, &quemado1, &turnosQuemado1, &dren1, &turnosDren1, &prot2, &protRestante2, &poc2, &max2, prot1);
            if (hp1 <= 0) break;
            turno(e1, p1, &hp1, hpMax1, &hp2, &vel1, &vel2, &quemado2, &turnosQuemado2, &dren2, &turnosDren2, &prot1, &protRestante1, &poc1, &max1, prot2);
        }

        cout << endl << "-- EFECTOS DE ESTADO --" << endl;

        if (quemado1) {
            hp1 -= 25;
            turnosQuemado1--;
            cout << "-> " << e1 << " recibe 25 de danio por su quemadura. (turnos restantes: " << turnosQuemado1 << ")" << endl;
            if (turnosQuemado1 <= 0) {
                quemado1 = false;
                cout << "-> " << e1 << " se ha curado de la quemadura." << endl;
            }
        }
        if (quemado2) {
            hp2 -= 25;
            turnosQuemado2--;
            cout << "-> " << e2 << " recibe 25 de danio por su quemadura. (turnos restantes: " << turnosQuemado2 << ")" << endl;
            if (turnosQuemado2 <= 0) {
                quemado2 = false;
                cout << "-> " << e2 << " se ha curado de la quemadura." << endl;
            }
        }

        if (dren1) {
            hp1 -= 30;
            hp2 += 30;
            if (hp2 > hpMax2) hp2 = hpMax2;
            turnosDren1--;
            cout << "-> Las drenadoras succionan 30 HP a " << e1 << " y curan a " << e2 << ". (turnos restantes: " << turnosDren1 << ")" << endl;
            if (turnosDren1 <= 0) {
                dren1 = false;
                cout << "-> Las drenadoras sobre " << e1 << " han desaparecido." << endl;
            }
        }
        if (dren2) {
            hp2 -= 30;
            hp1 += 30;
            if (hp1 > hpMax1) hp1 = hpMax1;
            turnosDren2--;
            cout << "-> Las drenadoras succionan 30 HP a " << e2 << " y curan a " << e1 << ". (turnos restantes: " << turnosDren2 << ")" << endl;
            if (turnosDren2 <= 0) {
                dren2 = false;
                cout << "-> Las drenadoras sobre " << e2 << " han desaparecido." << endl;
            }
        }

        if (hp1 < 0) hp1 = 0;
        if (hp2 < 0) hp2 = 0;
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

void tableroResultados() {
    reg r;
    int i;
    char fechaFmt[11];

    ifstream arch("batallas.dat", ios::binary);
    if (!arch) {
        cout << endl << "No hay batallas registradas aun." << endl;
        return;
    }

    cout << endl << "============================================================" << endl;
    cout << "                  TABLERO DE RESULTADOS" << endl;
    cout << "============================================================" << endl;
    cout << "Fecha        Entrenador 1     Pokemon 1      Entrenador 2     Pokemon 2      Ganador" << endl;
    cout << "------------ ---------------- -------------- ---------------- -------------- ----------------" << endl;

    guardarReporteEnArchivo("==================== TABLERO DE RESULTADOS ====================");

    arch.read((char *) &r, sizeof(reg));
    while (!arch.eof()) {
        fechaFmt[0] = r.fecha[6]; fechaFmt[1] = r.fecha[7];
        fechaFmt[2] = '/';
        fechaFmt[3] = r.fecha[4]; fechaFmt[4] = r.fecha[5];
        fechaFmt[5] = '/';
        fechaFmt[6] = r.fecha[0]; fechaFmt[7] = r.fecha[1];
        fechaFmt[8] = r.fecha[2]; fechaFmt[9] = r.fecha[3];
        fechaFmt[10] = '\0';

        cout << fechaFmt << "  " << r.entrenador1 << "  ";
        for (i = strlen(r.entrenador1); i < 16; i++) cout << " ";
        cout << r.pokemon1 << "  ";
        for (i = strlen(r.pokemon1); i < 14; i++) cout << " ";
        cout << r.entrenador2 << "  ";
        for (i = strlen(r.entrenador2); i < 16; i++) cout << " ";
        cout << r.pokemon2 << "  ";
        for (i = strlen(r.pokemon2); i < 14; i++) cout << " ";
        cout << r.ganador << endl;

        // Misma linea que se imprime en pantalla, guardada en reportes.txt
        ostringstream linea;
        linea << fechaFmt << " | " << r.entrenador1 << " (" << r.pokemon1 << ") vs "
              << r.entrenador2 << " (" << r.pokemon2 << ") -> Gana: " << r.ganador;
        guardarReporteEnArchivo(linea.str());

        arch.read((char *) &r, sizeof(reg));
    }
    arch.close();
    cout << "============================================================" << endl;
}

void repoBatallasPorFecha() {
    int anho, mes, dia;
    string anhoTxt, mesTxt, diaTxt, buscar;
    bool encontrado;
    reg r;

    cout << endl << "REPORTE POR FECHA" << endl;

    int diasMes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    do {
        anho = leerEntero("Anio (1996-2026): ", 1996, 2026);
        mes  = leerEntero("Mes (1-12): ", 1, 12);

        int maxDia = diasMes[mes];
        if (anho % 4 == 0 && (anho % 100 != 0 || anho % 400 == 0) && mes == 2) {
            maxDia = 29;
        }
        dia = leerEntero("Dia (1-" + to_string(maxDia) + "): ", 1, maxDia);

        if (!esFechaValida(dia, mes, anho)) {
            cout << "Error: Fecha ilogica o fuera de rango. Intentelo de nuevo." << endl;
        }
    } while (!esFechaValida(dia, mes, anho));
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    anhoTxt = to_string(anho);
    mesTxt  = (mes < 10) ? ("0" + to_string(mes)) : to_string(mes);
    diaTxt  = (dia < 10) ? ("0" + to_string(dia)) : to_string(dia);
    buscar  = anhoTxt + mesTxt + diaTxt;

    ifstream arch("batallas.dat", ios::binary);
    if (!arch) { cout << "No hay batallas registradas." << endl; return; }

    encontrado = false;

    ostringstream encabezado;
    encabezado << "==================== REPORTE POR FECHA: " << dia << "/" << mes << "/" << anho << " ====================";

    arch.read((char *) &r, sizeof(reg));
    while (!arch.eof()) {
        if (strcmp(r.fecha, buscar.c_str()) == 0) {
            if (!encontrado) {
                cout << endl << "Batallas del " << dia << "/" << mes << "/" << anho << ":" << endl;
                cout << "--------------------------------------------------" << endl;
                guardarReporteEnArchivo(encabezado.str());
            }
            encontrado = true;
            cout << r.entrenador1 << " (" << r.pokemon1 << ") vs "
                 << r.entrenador2 << " (" << r.pokemon2 << ")  ->  Gana: " << r.ganador << endl;

            ostringstream linea;
            linea << r.entrenador1 << " (" << r.pokemon1 << ") vs "
                  << r.entrenador2 << " (" << r.pokemon2 << ") -> Gana: " << r.ganador;
            guardarReporteEnArchivo(linea.str());
        }
        arch.read((char *) &r, sizeof(reg));
    }
    arch.close();
    if (!encontrado) cout << "No se encontraron batallas en esa fecha." << endl;
}

void repoBatallasPorEntrenador() {
    string buscar;
    int victorias, derrotas;
    bool participo, gano;
    reg r;
    char fechaFmt[11];

    cout << endl << "REPORTE POR ENTRENADOR" << endl;
    cout << "Nombre del entrenador: ";
    cin >> buscar;
    cin.ignore();

    ifstream arch("batallas.dat", ios::binary);
    if (!arch) { cout << "No hay batallas registradas." << endl; return; }

    victorias = 0;
    derrotas  = 0;
    cout << endl << "Historial de " << buscar << ":" << endl;
    cout << "--------------------------------------------------" << endl;
    guardarReporteEnArchivo("==================== HISTORIAL DE " + buscar + " ====================");

    arch.read((char *) &r, sizeof(reg));
    while (!arch.eof()) {
        participo = (strcmp(r.entrenador1, buscar.c_str()) == 0 || strcmp(r.entrenador2, buscar.c_str()) == 0);
        if (participo) {
            fechaFmt[0] = r.fecha[6]; fechaFmt[1] = r.fecha[7];
            fechaFmt[2] = '/';
            fechaFmt[3] = r.fecha[4]; fechaFmt[4] = r.fecha[5];
            fechaFmt[5] = '/';
            fechaFmt[6] = r.fecha[0]; fechaFmt[7] = r.fecha[1];
            fechaFmt[8] = r.fecha[2]; fechaFmt[9] = r.fecha[3];
            fechaFmt[10] = '\0';

            gano = (strcmp(r.ganador, buscar.c_str()) == 0);

            ostringstream linea;
            if (strcmp(r.entrenador1, buscar.c_str()) == 0) {
                cout << fechaFmt << "  vs " << r.entrenador2;
                linea << fechaFmt << "  vs " << r.entrenador2;
            } else {
                cout << fechaFmt << "  vs " << r.entrenador1;
                linea << fechaFmt << "  vs " << r.entrenador1;
            }

            if (gano) { cout << "  ->  Victoria" << endl; linea << "  ->  Victoria"; victorias++; }
            else      { cout << "  ->  Derrota"  << endl; linea << "  ->  Derrota";  derrotas++;  }

            guardarReporteEnArchivo(linea.str());
        }
        arch.read((char *) &r, sizeof(reg));
    }
    arch.close();
    cout << "--------------------------------------------------" << endl;
    cout << "Victorias: " << victorias << "   Derrotas: " << derrotas << endl;

    ostringstream resumen;
    resumen << "Total -> Victorias: " << victorias << "   Derrotas: " << derrotas;
    guardarReporteEnArchivo(resumen.str());
}

void repoBatallasPorPokemon() {
    int opcion, victorias, derrotas;
    bool uso1, uso2, gano;
    char buscar[20];
    reg r;
    char fechaFmt[11];

    cout << endl << "REPORTE POR POKEMON" << endl;
    cout << "1. Charizard" << endl;
    cout << "2. Venusaur"  << endl;
    cout << "3. Blastoise" << endl;
    opcion = leerEntero("Seleccione (1-3): ", 1, 3);
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opcion == 1) strcpy(buscar, "Charizard");
    else if (opcion == 2) strcpy(buscar, "Venusaur");
    else strcpy(buscar, "Blastoise");

    ifstream arch("batallas.dat", ios::binary);
    if (!arch) { cout << "No hay batallas registradas." << endl; return; }

    victorias = 0;
    derrotas  = 0;
    cout << endl << "Historial de " << buscar << ":" << endl;
    cout << "--------------------------------------------------" << endl;
    guardarReporteEnArchivo("==================== HISTORIAL DE " + string(buscar) + " ====================");

    arch.read((char *) &r, sizeof(reg));
    while (!arch.eof()) {
        uso1 = (strcmp(r.pokemon1, buscar) == 0);
        uso2 = (strcmp(r.pokemon2, buscar) == 0);
        if (uso1 || uso2) {
            fechaFmt[0] = r.fecha[6]; fechaFmt[1] = r.fecha[7];
            fechaFmt[2] = '/';
            fechaFmt[3] = r.fecha[4]; fechaFmt[4] = r.fecha[5];
            fechaFmt[5] = '/';
            fechaFmt[6] = r.fecha[0]; fechaFmt[7] = r.fecha[1];
            fechaFmt[8] = r.fecha[2]; fechaFmt[9] = r.fecha[3];
            fechaFmt[10] = '\0';

            ostringstream linea;
            if (uso1) {
                gano = (strcmp(r.ganador, r.entrenador1) == 0);
                cout << fechaFmt << "  Entrenador: " << r.entrenador1;
                linea << fechaFmt << "  Entrenador: " << r.entrenador1;
            } else {
                gano = (strcmp(r.ganador, r.entrenador2) == 0);
                cout << fechaFmt << "  Entrenador: " << r.entrenador2;
                linea << fechaFmt << "  Entrenador: " << r.entrenador2;
            }

            if (gano) { cout << "  ->  Victoria" << endl; linea << "  ->  Victoria"; victorias++; }
            else      { cout << "  ->  Derrota"  << endl; linea << "  ->  Derrota";  derrotas++;  }

            guardarReporteEnArchivo(linea.str());
        }
        arch.read((char *) &r, sizeof(reg));
    }
    arch.close();
    cout << "--------------------------------------------------" << endl;
    cout << "Victorias: " << victorias << "   Derrotas: " << derrotas << endl;

    ostringstream resumen;
    resumen << "Total -> Victorias: " << victorias << "   Derrotas: " << derrotas;
    guardarReporteEnArchivo(resumen.str());
}

void repoTodasLasBatallas() {
    reg r;
    int cont;
    char fechaFmt[11];

    ifstream arch("batallas.dat", ios::binary);
    if (!arch) { cout << "No hay batallas registradas." << endl; return; }

    cout << endl << "TODAS LAS BATALLAS REGISTRADAS" << endl;
    cout << "--------------------------------------------------" << endl;
    guardarReporteEnArchivo("==================== TODAS LAS BATALLAS REGISTRADAS ====================");
    cont = 0;

    arch.read((char *) &r, sizeof(reg));
    while (!arch.eof()) {
        fechaFmt[0] = r.fecha[6]; fechaFmt[1] = r.fecha[7];
        fechaFmt[2] = '/';
        fechaFmt[3] = r.fecha[4]; fechaFmt[4] = r.fecha[5];
        fechaFmt[5] = '/';
        fechaFmt[6] = r.fecha[0]; fechaFmt[7] = r.fecha[1];
        fechaFmt[8] = r.fecha[2]; fechaFmt[9] = r.fecha[3];
        fechaFmt[10] = '\0';

        cont++;
        cout << cont << ". [" << fechaFmt << "] "
             << r.entrenador1 << " (" << r.pokemon1 << ") vs "
             << r.entrenador2 << " (" << r.pokemon2 << ")  ->  Gana: " << r.ganador << endl;

        ostringstream linea;
        linea << cont << ". [" << fechaFmt << "] "
              << r.entrenador1 << " (" << r.pokemon1 << ") vs "
              << r.entrenador2 << " (" << r.pokemon2 << ") -> Gana: " << r.ganador;
        guardarReporteEnArchivo(linea.str());

        arch.read((char *) &r, sizeof(reg));
    }
    arch.close();
    cout << "--------------------------------------------------" << endl;
    cout << "Total de batallas: " << cont << endl;

    ostringstream resumen;
    resumen << "Total de batallas: " << cont;
    guardarReporteEnArchivo(resumen.str());
}

void reportes() {
    int opcion = 1;
    string pausar;

    while (opcion != 5) {
        system("cls");
        cout << "REPORTES" << endl;
        cout << "========" << endl << endl;
        cout << "1) Batallas por fecha." << endl;
        cout << "2) Historial por entrenador." << endl;
        cout << "3) Historial por pokemon." << endl;
        cout << "4) Todas las batallas." << endl;
        cout << "5) Volver al menu principal." << endl << endl;
        opcion = leerEntero("Digite su opcion: ", 1, 5);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1: repoBatallasPorFecha(); break;
        case 2: repoBatallasPorEntrenador(); break;
        case 3: repoBatallasPorPokemon(); break;
        case 4: repoTodasLasBatallas(); break;
        case 5: cout << "Volviendo al menu principal." << endl; break;
        default: cout << "Opcion no valida. Elija del 1 al 5." << endl;
        }

        cout << endl << "Menu de reportes. Pulse Enter para continuar...";
        getline(cin, pausar);
    }
}