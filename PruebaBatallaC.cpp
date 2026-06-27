#include <iostream>
#include <string>
using namespace std;
bool TurnoJugador1(const string &NPOKEMON1, int OPCION, int &SUBOPCION1, int &DMG1, string &TipoAtaque1, int &VIDAPOKEMON1, int &Pociones1, int &PocionMax1);
bool TurnoJugador2(const string &NPOKEMON2, int OPCION, int &SUBOPCION2, int &DMG2, string &TipoAtaque2, int &VIDAPOKEMON2, int &Pociones2, int &PocionMax2);
int main()
{
    string ENTRENADOR1, ENTRENADOR2;
    int POKEMON1, POKEMON2, VIDAPOKEMON1, VIDAPOKEMON2, OPCION, OPCION2, Velocidad1, Velocidad2;
    cout << "POKEBATTLE" << endl;
    cout << "=================" << endl;
    cout << "Hola, entrenador 1! Cual es tu nombre?" << endl;
    getline(cin, ENTRENADOR1);
    cout << "Hola, entrenador 2! Cual es tu nombre?" << endl;
    getline(cin, ENTRENADOR2);
    cout << "Entrenador " << ENTRENADOR1 << ", escoje tu pokemon" << endl;
    cout << "1. Charizard" << endl;
    cout << "2. Vennusaur" << endl;
    cout << "3. Blastoise" << endl;
    cin >> POKEMON1;
    cout << endl;
    while (POKEMON1 != 1 && POKEMON1 != 2 && POKEMON1 != 3)
    {
        cout << "Esta opcion no existe, intenta otra vez." << endl;
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
        cout << "Esta opcion no existe, intenta otra vez." << endl;
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

    cout << ENTRENADOR1 << " VS " << ENTRENADOR2 << endl;
    cout << endl;
    string NPOKEMON1, NPOKEMON2;
    if (POKEMON1 == 1)
    {
        NPOKEMON1 = "Charizard";
    }
    else if (POKEMON1 == 2)
    {
        NPOKEMON1 = "Vennusaur";
    }
    else
        NPOKEMON1 = "Blastoise";
    if (POKEMON2 == 1)
    {
        NPOKEMON2 = "Charizard";
    }
    else if (POKEMON2 == 2)
    {
        NPOKEMON2 = "Vennusaur";
    }
    else
        NPOKEMON2 = "Blastoise";

    cout << ENTRENADOR1 << " SACA A " << NPOKEMON1 << endl;
    cout << endl;
    cout << ENTRENADOR2 << " SACA A " << NPOKEMON2 << endl
         << endl
         << endl;
    if (NPOKEMON1 == "Charizard")
    {
        VIDAPOKEMON1 = 266;
        Velocidad1 = 100;
    }
    else if (NPOKEMON1 == "Vennusaur")
    {
        VIDAPOKEMON1 = 270;
        Velocidad1 = 80;
    }
    else
    {
        VIDAPOKEMON1 = 268;
        Velocidad1 = 78;
    }
    if (NPOKEMON2 == "Charizard")
    {
        VIDAPOKEMON2 = 266;
        Velocidad2 = 100;
    }
    else if (NPOKEMON2 == "Vennusaur")
    {
        VIDAPOKEMON2 = 270;
        Velocidad2 = 80;
    }
    else
    {
        VIDAPOKEMON2 = 268;
        Velocidad2 = 78;
    }
    int Pociones1 = 3, PocionMax1 = 1;
    int Pociones2 = 3, PocionMax2 = 1;
    while (VIDAPOKEMON1 > 0 && VIDAPOKEMON2 > 0)
    {
        int SUBOPCION1, DMG1 = 0;
        string TipoAtaque1;
        cout << NPOKEMON1 << " tiene " << Velocidad1 << " de velocidad." << endl;
        cout << NPOKEMON2 << " tiene " << Velocidad2 << " de velocidad." << endl;
        if (Velocidad1 > Velocidad2)
        {
            cout << NPOKEMON1 << " ataca primero!" << endl
                 << endl;
        }
        else if (Velocidad2 > Velocidad1)
        {
            cout << NPOKEMON2 << " ataca primero!" << endl
                 << endl;
        }
        else
        {
            cout << "Ambos pokemon tienen la misma velocidad!" << endl
                 << endl;
        }

        bool TurnoValido = false;

        while (!TurnoValido)
        {
            cout << ENTRENADOR1 << ", que quieres hacer?" << endl;
            cout << "1. COMBATE" << endl;
            cout << "2. OBJETO" << endl;

            cin >> OPCION;

            if (OPCION == 1)
            {
                TurnoValido = TurnoJugador1(NPOKEMON1,OPCION,SUBOPCION1,DMG1,TipoAtaque1,VIDAPOKEMON1,Pociones1,PocionMax1);
            }
            else if (OPCION == 2)
            {
                if (Pociones1 == 0 && PocionMax1 == 0)
                {
                    cout << "No te quedan objetos! Escoge otra accion." << endl;
                }
                else
                {
                    TurnoValido = TurnoJugador1(NPOKEMON1,OPCION,SUBOPCION1,DMG1,TipoAtaque1,VIDAPOKEMON1,Pociones1,PocionMax1);
                }
            }
            else
            {
                cout << "Escoge una accion valida." << endl;
            }
        }

        int SUBOPCION2, DMG2 = 0;
        string TipoAtaque2;
        bool TurnoValido2 = false;

        while (!TurnoValido2)
        {
            cout << ENTRENADOR2 << ", que quieres hacer?" << endl;
            cout << "1. COMBATE" << endl;
            cout << "2. OBJETO" << endl;
            cin >> OPCION2;

            if (OPCION2 == 1)
            {
                TurnoValido2 = TurnoJugador2(NPOKEMON2, OPCION2, SUBOPCION2, DMG2, TipoAtaque2, VIDAPOKEMON2, Pociones2, PocionMax2);
            }
            else if (OPCION2 == 2)
            {
                if (Pociones2 == 0 && PocionMax2 == 0)
                {
                    cout << "No te quedan objetos! Escoge otra accion." << endl;
                }
                else
                {
                    TurnoValido2 = TurnoJugador2(NPOKEMON2, OPCION2, SUBOPCION2, DMG2, TipoAtaque2, VIDAPOKEMON2, Pociones2, PocionMax2);
                }
            }
            else
            {
                cout << "Escoge una accion valida." << endl;
            }
        }
        int DANOFINAL1 = DMG1;
        int DANOFINAL2 = DMG2;
        if (TipoAtaque1 == "Fuego" && NPOKEMON2 == "Vennusaur")
        {
            DANOFINAL1 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque1 == "Hielo" && NPOKEMON2 == "Vennusaur")
        {
            DANOFINAL1 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque1 == "Veneno" && NPOKEMON2 == "Vennusaur")
        {
            DANOFINAL1 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque2 == "Veneno" && NPOKEMON1 == "Vennusaur")
        {
            DANOFINAL2 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque2 == "Hielo" && NPOKEMON1 == "Vennusaur")
        {
            DANOFINAL2 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque1 == "Fuego" && NPOKEMON2 == "Blastoise")
        {
            DANOFINAL1 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque1 == "Planta" && NPOKEMON2 == "Blastoise")
        {
            DANOFINAL1 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque1 == "Planta" && NPOKEMON2 == "Charizard")
        {
            DANOFINAL1 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque1 == "Agua" && NPOKEMON2 == "Charizard")
        {
            DANOFINAL1 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque1 == "Agua" && NPOKEMON2 == "Vennusaur")
        {
            DANOFINAL1 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        if (TipoAtaque2 == "Fuego" && NPOKEMON1 == "Vennusaur")
        {
            DANOFINAL2 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque2 == "Fuego" && NPOKEMON1 == "Blastoise")
        {
            DANOFINAL2 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque2 == "Planta" && NPOKEMON1 == "Blastoise")
        {
            DANOFINAL2 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque2 == "Planta" && NPOKEMON1 == "Charizard")
        {
            DANOFINAL2 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        else if (TipoAtaque2 == "Agua" && NPOKEMON1 == "Charizard")
        {
            DANOFINAL2 *= 2;
            cout << "Es super efectivo!" << endl;
        }
        else if (TipoAtaque2 == "Agua" && NPOKEMON1 == "Vennusaur")
        {
            DANOFINAL2 /= 2;
            cout << "No es muy efectivo..." << endl;
        }
        if (Velocidad1 > Velocidad2)
        {

            VIDAPOKEMON2 = VIDAPOKEMON2 - DANOFINAL1;

            cout << "El " << NPOKEMON1 << " de " << ENTRENADOR1
                 << " ha hecho " << DANOFINAL1 << " de dano!" << endl;

            if (VIDAPOKEMON2 <= 0)
            {
                VIDAPOKEMON2 = 0;

                cout << NPOKEMON2 << " se ha debilitado!" << endl;
                cout << endl;
                cout << ENTRENADOR1 << " ha ganado la batalla!" << endl;

                break;
            }

            cout << NPOKEMON2 << " tiene "
                 << VIDAPOKEMON2 << " HP restantes." << endl;

            cout << endl;

            VIDAPOKEMON1 = VIDAPOKEMON1 - DANOFINAL2;

            cout << "El " << NPOKEMON2 << " de " << ENTRENADOR2
                 << " ha hecho " << DANOFINAL2 << " de dano!" << endl;

            if (VIDAPOKEMON1 <= 0)
            {
                VIDAPOKEMON1 = 0;

                cout << NPOKEMON1 << " se ha debilitado!" << endl;
                cout << endl;
                cout << ENTRENADOR2 << " ha ganado la batalla!" << endl;

                break;
            }

            cout << NPOKEMON1 << " tiene "
                 << VIDAPOKEMON1 << " HP restantes." << endl;

            cout << endl;
        }
        else
        {

            VIDAPOKEMON1 = VIDAPOKEMON1 - DANOFINAL2;

            cout << "El " << NPOKEMON2 << " de " << ENTRENADOR2
                 << " ha hecho " << DANOFINAL2 << " de dano!" << endl;

            if (VIDAPOKEMON1 <= 0)
            {
                VIDAPOKEMON1 = 0;

                cout << NPOKEMON1 << " se ha debilitado!" << endl;
                cout << endl;
                cout << ENTRENADOR2 << " ha ganado la batalla!" << endl;

                break;
            }

            cout << NPOKEMON1 << " tiene "
                 << VIDAPOKEMON1 << " HP restantes." << endl;

            cout << endl;

            VIDAPOKEMON2 = VIDAPOKEMON2 - DANOFINAL1;

            cout << "El " << NPOKEMON1 << " de " << ENTRENADOR1
                 << " ha hecho " << DANOFINAL1 << " de dano!" << endl;

            if (VIDAPOKEMON2 <= 0)
            {
                VIDAPOKEMON2 = 0;

                cout << NPOKEMON2 << " se ha debilitado!" << endl;
                cout << endl;
                cout << ENTRENADOR1 << " ha ganado la batalla!" << endl;

                break;
            }

            cout << NPOKEMON2 << " tiene "
                 << VIDAPOKEMON2 << " HP restantes." << endl;

            cout << endl;
        }
    }
}

bool TurnoJugador1(const string &NPOKEMON1, int OPCION, int &SUBOPCION1, int &DMG1, string &TipoAtaque1, int &VIDAPOKEMON1, int &Pociones1, int &PocionMax1)
{
    if (NPOKEMON1 == "Charizard")
    {

        switch (OPCION)
        {
        case 1:
            cout << endl;
            cout << "1. Lanzallamas" << endl;
            cout << "2. Ascuas" << endl;
            cout << "3. Colmillo igneo" << endl;
            cout << "4. Garra dragon" << endl;

            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2 && SUBOPCION1 != 3 && SUBOPCION1 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION1;
            }

            switch (SUBOPCION1)
            {
            case 1:
                DMG1 = 90;
                TipoAtaque1 = "Fuego";
                break;

            case 2:
                DMG1 = 40;
                TipoAtaque1 = "Fuego";
                break;

            case 3:
                DMG1 = 65;
                TipoAtaque1 = "Fuego";
                break;

            case 4:
                DMG1 = 80;
                TipoAtaque1 = "Dragon";
                break;
            }

            break;

        case 2:
            cout << endl;
            cout << "1. Pocion (" << Pociones1 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax1 << " restantes)" << endl;

            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION1;
            }

            switch (SUBOPCION1)
            {
            case 1:
                if (Pociones1 > 0)
                {
                    Pociones1--;

                    if (VIDAPOKEMON1 <= 226)
                    {
                        VIDAPOKEMON1 = VIDAPOKEMON1 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON1 = 266;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl;
                    cout << "Pociones restantes: " << Pociones1 << endl
                         << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl
                         << endl;
                    return false;
                }

                break;

            case 2:
                if (PocionMax1 > 0)
                {
                    PocionMax1--;

                    VIDAPOKEMON1 = 266;

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl
                         << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl
                         << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }

    else if (NPOKEMON1 == "Vennusaur")
    {

        switch (OPCION)
        {
        case 1:
            cout << endl;
            cout << "1. Latigazo" << endl;
            cout << "2. Latigo cepa" << endl;
            cout << "3. Hoja Afilada" << endl;
            cout << "4. Bomba lodo" << endl;
            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2 && SUBOPCION1 != 3 && SUBOPCION1 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION1;
            }
            switch (SUBOPCION1)
            {
            case 1:
                DMG1 = 120;
                TipoAtaque1 = "Normal";

                break;

            case 2:
                DMG1 = 45;
                TipoAtaque1 = "Planta";

                break;

            case 3:
                DMG1 = 55;
                TipoAtaque1 = "Planta";

                break;

            case 4:
                DMG1 = 90;
                TipoAtaque1 = "Veneno";

                break;
            }

            break;

        case 2:
            cout << endl;
            cout << "1. Pocion (" << Pociones1 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax1 << " restantes)" << endl;
            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION1;
            }

            switch (SUBOPCION1)
            {
            case 1:
                if (Pociones1 > 0)
                {
                    Pociones1--;

                    if (VIDAPOKEMON1 <= 230)
                    {
                        VIDAPOKEMON1 = VIDAPOKEMON1 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON1 = 270;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl
                         << endl;
                    cout << "Pociones restantes: " << Pociones1 << endl
                         << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl
                         << endl;
                    return false;
                }

                break;

            case 2:
                if (PocionMax1 > 0)
                {
                    PocionMax1--;
                    VIDAPOKEMON1 = 270;

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl
                         << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl
                         << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }
    else
    {
        switch (OPCION)
        {
        case 1:
            cout << endl;
            cout << "1. Hidrobomba" << endl;
            cout << "2. Rayo burbuja" << endl;
            cout << "3. Acua jet" << endl;
            cout << "4. Viento hielo" << endl;

            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2 && SUBOPCION1 != 3 && SUBOPCION1 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION1;
            }

            switch (SUBOPCION1)
            {
            case 1:
                DMG1 = 110;
                TipoAtaque1 = "Agua";
                break;

            case 2:
                DMG1 = 65;
                TipoAtaque1 = "Agua";
                break;

            case 3:
                DMG1 = 40;
                TipoAtaque1 = "Agua";
                break;

            case 4:
                DMG1 = 55;
                TipoAtaque1 = "Hielo";
                break;
            }

            break;

        case 2:

            cout << "1. Pocion (" << Pociones1 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax1 << " restantes)" << endl;

            cin >> SUBOPCION1;

            while (SUBOPCION1 != 1 && SUBOPCION1 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION1;
            }

            switch (SUBOPCION1)
            {
            case 1:
                if (Pociones1 > 0)
                {
                    Pociones1--;

                    if (VIDAPOKEMON1 <= 226)
                    {
                        VIDAPOKEMON1 = VIDAPOKEMON1 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON1 = 266;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl;
                    cout << "Pociones restantes: " << Pociones1 << endl
                         << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl
                         << endl;
                    return false;
                }

                break;

            case 2:
                if (PocionMax1 > 0)
                {
                    PocionMax1--;
                    VIDAPOKEMON1 = 266;

                    cout << "Vida restaurada a: " << VIDAPOKEMON1 << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }
    return true;
}

bool TurnoJugador2(const string &NPOKEMON2, int OPCION2, int &SUBOPCION2, int &DMG2, string &TipoAtaque2, int &VIDAPOKEMON2, int &Pociones2, int &PocionMax2)
{
    if (NPOKEMON2 == "Charizard")
    {

        switch (OPCION2)
        {
        case 1:
            cout << "1. Lanzallamas" << endl;
            cout << "2. Ascuas" << endl;
            cout << "3. Colmillo igneo" << endl;
            cout << "4. Garra dragon" << endl;

            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2 && SUBOPCION2 != 3 && SUBOPCION2 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION2;
            }

            switch (SUBOPCION2)
            {
            case 1:
                DMG2 = 90;
                TipoAtaque2 = "Fuego";
                break;

            case 2:
                DMG2 = 40;
                TipoAtaque2 = "Fuego";
                break;

            case 3:
                DMG2 = 65;
                TipoAtaque2 = "Fuego";
                break;

            case 4:
                DMG2 = 80;
                TipoAtaque2 = "Dragon";
                break;
            }

            break;

        case 2:

            cout << "1. Pocion (" << Pociones2 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax2 << " restantes)" << endl;

            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION2;
            }

            switch (SUBOPCION2)
            {
            case 1:
                if (Pociones2 > 0)
                {
                    Pociones2--;

                    if (VIDAPOKEMON2 <= 226)
                    {
                        VIDAPOKEMON2 = VIDAPOKEMON2 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON2 = 266;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                    cout << "Pociones restantes: " << Pociones2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl;
                    return false;
                }

                break;

            case 2:
                if (PocionMax2 > 0)
                {
                    PocionMax2--;
                    VIDAPOKEMON2 = 266;

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }

    else if (NPOKEMON2 == "Vennusaur")
    {

        switch (OPCION2)
        {
        case 1:

            cout << "1. Latigazo" << endl;
            cout << "2. Latigo cepa" << endl;
            cout << "3. Hoja Afilada" << endl;
            cout << "4. Bomba lodo" << endl;
            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2 && SUBOPCION2 != 3 && SUBOPCION2 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION2;
            }
            switch (SUBOPCION2)
            {
            case 1:
                DMG2 = 120;
                TipoAtaque2 = "Normal";

                break;

            case 2:
                DMG2 = 45;
                TipoAtaque2 = "Planta";

                break;

            case 3:
                DMG2 = 55;
                TipoAtaque2 = "Planta";

                break;

            case 4:
                DMG2 = 90;
                TipoAtaque2 = "Veneno";

                break;
            }

            break;

        case 2:

            cout << "1. Pocion (" << Pociones2 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax2 << " restantes)" << endl;
            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION2;
            }

            switch (SUBOPCION2)
            {
            case 1:
                if (Pociones2 > 0)
                {
                    Pociones2--;
                    if (VIDAPOKEMON2 <= 230)
                    {
                        VIDAPOKEMON2 = VIDAPOKEMON2 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON2 = 270;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                    cout << "Pociones restantes: " << Pociones2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl;
                    return false;
                }
                break;

            case 2:
                if (PocionMax2 > 0)
                {
                    PocionMax2--;

                    VIDAPOKEMON2 = 270;

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }
    else
    {
        switch (OPCION2)
        {
        case 1:
            cout << "1. Hidrobomba" << endl;
            cout << "2. Rayo burbuja" << endl;
            cout << "3. Acua jet" << endl;
            cout << "4. Viento hielo" << endl;

            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2 && SUBOPCION2 != 3 && SUBOPCION2 != 4)
            {
                cout << "Escoge un ataque válido";
                cin >> SUBOPCION2;
            }

            switch (SUBOPCION2)
            {
            case 1:
                DMG2 = 110;
                TipoAtaque2 = "Agua";
                break;

            case 2:
                DMG2 = 65;
                TipoAtaque2 = "Agua";
                break;

            case 3:
                DMG2 = 40;
                TipoAtaque2 = "Agua";
                break;

            case 4:
                DMG2 = 55;
                TipoAtaque2 = "Hielo";
                break;
            }

            break;

        case 2:

            cout << "1. Pocion (" << Pociones2 << " restantes)" << "(+40 HP)" << endl;
            cout << "2. Pocion max (" << PocionMax2 << " restantes)" << endl;

            cin >> SUBOPCION2;

            while (SUBOPCION2 != 1 && SUBOPCION2 != 2)
            {
                cout << "Escoge un objeto valido" << endl;
                cin >> SUBOPCION2;
            }

            switch (SUBOPCION2)
            {
            case 1:
                if (Pociones2 > 0)
                {
                    Pociones2--;

                    if (VIDAPOKEMON2 <= 226)
                    {
                        VIDAPOKEMON2 = VIDAPOKEMON2 + 40;
                    }
                    else
                    {
                        VIDAPOKEMON2 = 266;
                    }

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                    cout << "Pociones restantes: " << Pociones2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones!" << endl;
                    return false;
                }
                break;

            case 2:
                if (PocionMax2 > 0)
                {
                    PocionMax2--;

                    VIDAPOKEMON2 = 266;

                    cout << "Vida restaurada a: " << VIDAPOKEMON2 << endl;
                }
                else
                {
                    cout << "No te quedan pociones max!" << endl;
                    return false;
                }

                break;
            }

            break;
        }
    }
    return true;
}