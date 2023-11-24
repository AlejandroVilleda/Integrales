#include <iostream>
#include <functional>
#include <cmath>
using namespace std;

void Integral_uno();
void Integral_dos();
float Suma_rieman();

int main()
{
    // Declaración de variables
    unsigned short int Respuesta;
    char RespuestaFinal;

    // Menu
    do
    {
        system("cls");
        system("Color 02");
        cout << "INTEGRALES DE PROBABILIDAD" << endl;
        cout << "[1]. Integral 1" << endl;
        cout << "[2]. Integral 2" << endl;
        cout << "[3]. Salir" << endl;
        cout << "Respuesta: ";
        cin >> Respuesta;

        switch(Respuesta)
        {
            case 1: // Integral 1
                Integral_uno();
                break;

            case 2: // Integral 2
                Integral_dos();
                break;

            default:
                // En caso de ingresar opción incorrecta
                cout<< "\nRespuesta incorrecta"<< endl;
                break;
        }

        system("Color 20");
        do  // repetición o finalizar
        {
            cout << "Repetir operacion (S/n): ";
            cin >> RespuestaFinal;

            switch (RespuestaFinal)
            {
                case 'n':
                    cout<< "Hasta luego"<< endl;
                    Respuesta = 3;
                    break;

                case 'S':
                    break;

                default:
                    cout << "Digito incorrecto" << endl;
                    break;
            }
        }   while(RespuestaFinal != 'S' && RespuestaFinal != 'n');

    }   while(Respuesta != 3);

    return 0;
}


void Integral_uno()
{
    // Ejecuta la primera integral
    system("Color F1");

    // Variables
    float Promedio;
    float Varianza;
    float a;
    float b;
    float e = 2.71828;
    float Resultado;

    // Ingresando datos
    cout<< "\n********* INTEGRAL 1 *********"<< endl;
    cout<< "Ingresa los siguientes valores"<< endl;
    cout<< "Limite inferior 'a': "; cin>> a;
    cout<< "Limite superior 'b': "; cin>> b;
    cout<< "Promedio '\u00B5': "; cin>> Promedio;

    // Restricción de ▽
    do
    {
        cout<< "Varianza '\u25BD': "; cin>> Varianza;

        if(Varianza <= 0)
        {
            cout<< "\nValor invalido"<< endl;
        }
    }   while (Varianza <= 0);


    // Operación matemática
    Resultado = Suma_rieman();

    cout<< "Resultado: "<< endl;
    system("pause");
}

void Integral_dos()
{
    // Ejecuta la segunda integral
    system("Color F2");


    system("pause");
}

