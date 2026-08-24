/*
Desenvolva um programa em C++ que leia 3 coordenadas bi-dimensionais (x,y), e
calcule:
→o valor dos 3 lados do triângulo;
→o valor dos 3 ângulos;
→a área do triângulo formado.
→ Este exercício exige pesquisa. Note que cada coordenada (vértice) é um ponto
contendo x, y. O ângulo se calcula no próprio vértice, e o lado é sempre oposto ao vértice
(lado 1, oposto ao ângulo 1, lado 2 ao ângulo 2…).
→ Note também que pode ser um triângulo qualquer. Para isso, pesquisar sobre Teorema
de Heron.
→ Exemplo: A entrada do programa é: 0 0 0 10 10 0
Trata-se de um triângulo que contém área de 50, 2 lados de 10, e um lado de 14.142
*/
#include <iostream>
#include <cmath>

using namespace std;

float calcEdge(int x1, int y1, int x2, int y2);
float calcArea(float l1, float l2, float l3);
float calcAng(float a, float b, float c);

int main(int argc, char* argv[])
{
    if(argc != 7){
        cout << "Error, usage is <executavel x1 y1 x2 y2 x3 y3>" << endl;
        return 1;
    }

    int x1, y1, x2, y2, x3, y3;
    float l1, l2, l3, area, a1, a2, a3;

    // CARREGANDO COORDENADAS DO TRIANGULO
    x1 = atoi(argv[1]);
    y1 = atoi(argv[2]);
    x2 = atoi(argv[3]);
    y2 = atoi(argv[4]);
    x3 = atoi(argv[5]);
    y3 = atoi(argv[6]);

    cout << "Coordenadas do triângulo: " << endl;
    cout << "x1: " << x1 << " y1: " << y1 << endl;
    cout << "x2: " << x2 << " y2: " << y2 << endl;
    cout << "x3: " << x3 << " y3: " << y3 << endl;


    // CALCULANDO OS LADOS DO TRINAGULO
    l1 = calcEdge(x1, y1, x2, y2);
    l2 = calcEdge(x1, y1, x3, y3);
    l3 = calcEdge(x2, y2, x3, y3);

    cout << "Lados do triângulo: " << endl;
    cout << "l1: " << l1 << " l2: " << l2 << " l3: " << l3 << endl;

    // CALCULANDO A AREA DO TRIANGULO
    area = calcArea(l1, l2, l3);

    cout << "A area de triangulo eh " << area << endl;

    // CALCULANDO OS ANGULOS DO TRIANGULO
    a1 = calcAng(l1, l2, l3);
    a2 = calcAng(l2, l1, l3);
    a3 = calcAng(l3, l2, l1);

    cout << "Angulos do triângulo: " << endl;
    cout << "a1: " << a1 << " a2: " << a2 << " a3: " << a3 << endl;

    return 0;
}

float calcEdge(int x1, int y1, int x2, int y2)
{
    float d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return d;
}

float calcArea(float l1, float l2, float l3)
{
    float area, p;

    p = (l1 + l2 + l3) / 2;
    area = sqrt(p * (p - l1) * (p - l2) * (p - l3));

    return area;
}

float calcAng(float a, float b, float c) // 
{
    float ang, cos;

    cos = (a * a) - (b * b) - (c * c) / ((-2) * b * c);

    cout << "Cos: " << cos << endl;

    ang = acos(cos);

    return ang;
}
