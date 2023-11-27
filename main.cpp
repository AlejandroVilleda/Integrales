#include <iostream>
#include <functional>
#include <cmath>
#include <fstream>
#define PI 3.14159265
#define e 2.71828183
#define n 100000
using namespace std;

void Integral_uno();
void Integral_dos();
float Integrar(float a, float b, float Promedio, float Varianza, const function<float(float, float, float, float)>& Riemman);
void Integrar(float a, float b, const function<void(float, float)> &Riemman);

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

            case 3: // Salir
                cout<< "Hasta luego"<< endl;
                system("pause");
                exit(0);

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
    // Ejecución de la primera integral
    system("Color F1");

    // Variables
    float b; // Limite superior
    float a; // Limite inferior
    float Promedio;
    float Varianza;
    float Resultado;

    // Ingresando datos
    cout<< "\n********* INTEGRAL 1 *********"<< endl;
    cout<< "Ingresa los siguientes valores (a, b, \xC2\xB5 y \xE2\x96\xBD)"<< endl;
    cout<< "Limite inferior 'a': "; cin>> a;
    cout<< "Limite superior 'b': "; cin>> b;
    cout<< "Promedio '\xC2\xB5': "; cin>> Promedio;

    // Restricción de ▽
    do
    {
        cout<< "Varianza '\xE2\x96\xBD': "; cin>> Varianza;
        if(Varianza <= 0) cout<< "\nValor invalido"<< endl;
    }   while (Varianza <= 0);


// Operaciones matemática
    // función f(x)
    auto funcion = [](float x, float a, float b, float Promedio, float Varianza)-> float
    {
        return (1 / (Varianza * sqrt(2*PI))) * (pow(e, (-0.5)*pow( ((x - Promedio) / Varianza), 2) ));
    };

    // Suma de riemman
    auto Riemman = [&funcion](float a, float b, float Promedio, float Varianza)-> float
    {
        float Resultado = 0;
        float Base = (b - a) / n;  // Tiende a 0

        for(float x = 1; x <= n; x = x+1)
        {
            float Altura = funcion(a + Base*x, a, b, Promedio, Varianza);
            Resultado = Resultado + (Base * Altura);
        }

        return Resultado;
    };


    Resultado = Integrar(a, b, Promedio, Varianza, Riemman);

    cout<< "Resultado: "<< Resultado<< endl;
    system("pause");
}

void Integral_dos()
{
    // Ejecución de la segunda integral
    system("Color F2");

    // Variables
    float Resultado;

    // Ingresando datos
    cout<< "\n********* INTEGRAL 2 *********"<< endl;
    cout<< "Resultados de la integral de -6 a 6, en intervalos de 0.01"<< endl;


// Operaciones matemática
    // función f(x)
    auto funcion = [](double z)-> double
    {
        return (1 / sqrt(2*PI)) * (pow(e, (-0.5)*pow( z, 2) ));
    };

    // Suma de riemman
    auto Riemman = [&funcion](double a, double b)-> void
    {
        // Variables
        double Base;  // Tiende a 0
        double Altura;
        float Resultado;
        long int contador = 0;
        ofstream Archivo;

        Archivo.open("./Resultados.txt", ios::app);
        if(Archivo.fail()){cout<< "no fue posible generar el archivo txt"<< endl;}

        // Para cada iteración del intervalo final
        for(double x = a + 0.010; x <= b + 0.002; x = x + 0.01)
        {
            Resultado = 0;
            Base = (x - a) / n;

            // Calcular el area con suma de riemman
            for(long int u = 1; u <= n; u = u + 1)
            {
                Altura = funcion(a + Base*u);
                Resultado = Resultado + (Base * Altura);
            }

            cout<< "b["<< contador<< "]. \tDe: "<< a<< " hasta "<< x<<": \t"<< Resultado<<endl;
            Archivo<< "b["<< contador<< "]. De: "<< a<< " hasta "<< x<<": "<< Resultado<<endl;
            contador++;
        }

        Archivo.close();
    };

    // Resultados
    Integrar(-6, 6, Riemman);

    system("pause");
}


float Integrar(float a, float b, float Promedio, float Varianza, const function<float(float, float, float, float)> &Riemman)
{
    return Riemman(a, b, Promedio, Varianza);
}

void Integrar(float a, float b, const function<void(float, float)> &Riemman)
{
    return Riemman(a, b);
}