#include <iostream>
#include <functional>
#include <cmath>
#define PI 3.14159
#define e 2.71828
using namespace std;

void Integral_uno();
void Integral_dos();
float Suma_rieman(float a, float b, float Promedio, float Varianza, function<float(float, float, float, float)> Riemman);

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
        if(Varianza <= 0) cout<< "\nValor invalido"<< endl;
    }   while (Varianza <= 0);


    // Operación matemática
    auto funcion = [](float x, float a, float b, float Promedio, float Varianza)-> float
    {
        return (1 / (Varianza * sqrt(2*PI))) * pow(e, (-1 * (1/2))* pow( (x - Promedio / Varianza), 2) );
    };

    auto Operacion = [&funcion](float a, float b, float Promedio, float Varianza)-> float
    {
        float Resultado = 0;
        for(float x = 1; x < 10000; x = x + 0.01)
        {
            float Base = (b - a) / x ;  // Tiende a 0
            float Altura = funcion(x, a, b, Promedio, Varianza);
            cout<< x<< endl;
            Resultado = Resultado + Base * Altura;
        }

        return Resultado;
    };

    Resultado = Suma_rieman(a, b, Promedio, Varianza, Operacion);

    cout<< "Resultado: "<< Resultado<< endl;
    system("pause");
}

void Integral_dos()
{
    // Ejecuta la segunda integral
    system("Color F2");


    system("pause");
}


float Suma_rieman(float a, float b, float Promedio, float Varianza, function<float(float, float, float, float)> Riemman)
{
    return Riemman(a, b, Promedio, Varianza);
}