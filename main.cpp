/*
La a es el coeficiente de la variable x al cuadrado
La variable b es el coeficiente de la variable x a la 1
La variable c es el témino independiente, el coeficiente de la x elevado a 0
*/
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int a = 0;
int b = 0;
int c = 0;

int bNegativo;
int bCuadrado;
int resta4;
int denominador;
int resultRaiz;

float x1;
float x2;

int raiz();
int lectura();
void sinB(); //Sin variable a la 1 - 0 = b

int main()
{
  if(lectura()==0)
  {
    cout <<" Ha ocurrido un error importando los ficheros. Modo manual: " <<endl;
    cout <<" Indica el valor de la variable a (ax^2): ";
    cin >> a;
    cout <<" Indica el valor de la variable b (bx): ";
    cin >> b;
    cout <<" Indica el valor del termino independiente (c): ";
    cin >> c;
    }
    else
    {
    //No hacer nada - Do nothing
    cout <<" Se ha completado la importacion. Modo automatico" <<endl;
  }
  if(b==0)
  {

  }
  bNegativo = b*-1; //Paso 1, cambiar el signo a B
  bCuadrado = pow(b, 2); //Paso 2
  resta4 = -4*a*c; //Paso 3
  denominador = 2*a; //Paso 4
  resultRaiz = raiz(); //Paso 5, la raiz
  //Empiezan la representación de las dos soluciones:
  if(resultRaiz < 0)
  {
    //La ecuación no tiene solución
    cout <<" Esta ecuacion no tiene solucion, no se puede calcular la raiz de un negativo (sin numeros complejos)" <<endl;
    system("PAUSE");
    exit(0);
  }
  if(resultRaiz == 0)
  {
    //La ecuación tiene solución doble, es decir, una única solución
    x1 = (bNegativo + resultRaiz/*Esta variable se puede omitir, es 0*/)/denominador;
    cout <<" La ecuacion solo tiene una solucion, que es " <<x1 <<endl;
    system("PAUSE");
    return 0;
  }
  //La ecuación tiene 2 soluciones, x sub 1 y x sub 2
  x1 = (bNegativo + resultRaiz)/denominador;
  x2 = (bNegativo - resultRaiz)/denominador;
  cout <<" Esta ecuacion tiene 2 soluciones: " <<endl;
  cout <<" x1 = " <<x1 <<endl;
  cout <<" x2 = " <<x2 <<endl;
  system("PAUSE");
  return 0;
}

int raiz()
{
  int temp = bCuadrado + resta4; //Se pone + porque con - si el otro sumando es también -, se convierte en positivo.
  int temp1 = sqrt(temp); //El resultado, pero con otro nombre
  return temp1;
}

int lectura()
{
  //Paso 0, definir rutas
  string rutas[3];
  rutas[0] = "variables/a.txt";
  rutas[1] = "variables/b.txt";
  rutas[2] = "variables/c.txt";
  ifstream importacionesA;
  ifstream importacionesB;
  ifstream importacionesC;
  //Paso 2, dirigirse a los archivos
  importacionesA.open(rutas[0], ios::in);
  importacionesB.open(rutas[1], ios::in);
  importacionesC.open(rutas[2], ios::in);
  //Paso 3, comprobar si existen y dar respuesta
  if(importacionesA.fail()||importacionesB.fail()||importacionesC.fail())
  {
    //No existen los ficheros
    return 0;
  }
  //Paso 4, realizar la importación
  while(!importacionesA.eof()) //Importar A
  {
    string importacionA;
    getline(importacionesA, importacionA); //Copiar datos
    a = atoi(importacionA.c_str()); //Conversión de los datos
  }
  while(!importacionesB.eof()) //Importar B
  {
    string importacionB;
    getline(importacionesB, importacionB);
    b = atoi(importacionB.c_str());
  }
  while(!importacionesC.eof()) //Importar C
  {
    string importacionC;
    getline(importacionesC, importacionC);
    c = atoi(importacionC.c_str());
  }
  //Paso 5, cerrar el chiringuito
  importacionesA.close();
  importacionesB.close();
  importacionesC.close();
  //Hemos terminado
  return 1;
}

void sinB()
{
  cout <<" Partimos que la ecuacion tiene la C en el lado derecho (estructura ax^2 + c = 0)" <<endl;
  int tempC = c*-1;
  int tempC2 = tempC/a;
  //Ecuación despejada
  if(tempC2 < 0)
  {
    cout <<" La ecuacion no tiene solucion real" <<endl;
    system("PAUSE");
    exit(0);
  }
  int result = sqrt(tempC2); //La raíz de la parte derecha
  if(tempC2 == 0)
  {
    cout <<" La ecuacion solo tiene una solucion, que es 0" <<endl;
    system("PAUSE");
    exit(0);
  }
  else{
    cout <<" La ecuacion tiene 2 soluciones: " <<endl;
    cout <<" x1 = " <<result <<endl;
    cout <<" x2 = " <<result*-1 <<endl;
  }
}
