Ejercicio 3: Relevamiento de Exportaciones Agrícolas mediante Matrices
Consigna: La Secretaría de Agricultura realiza un relevamiento sobre la exportación de 10 productos cultivados en
6 zonas de producción. De cada producto se registra: código (1..10), nombre y precio por tonelada, datos que
deben almacenarse en una estructura adecuada. Por cada exportación realizada se ingresa: zona (1..6), código de
producto (1..10) y cantidad de toneladas vendidas.
Requerimientos: Codificar un programa en Lenguaje C que, mediante el uso de funciones óptimas, permita:
1. Cargar la matriz de exportaciones (Zonas x Productos), donde las filas representen las zonas de producción. Al
diseñar la función de carga, se debe especificar el tamaño de las columnas en el parámetro formal de la misma.
2. Implementar un módulo que reciba el número de una zona (fila) y devuelva el total de toneladas exportadas
por dicha zona al programa principal.
3. Calcular e informar el importe total exportado por cada producto (Cantidad de toneladas acumuladas x precio
unitario).
4. Identificar e informar en el main el nombre o código del producto más exportado y el menos exportado
(suponer valores únicos).

#include <stdio.h>

typedef struct
{
    int code;
    char[40] name;
    float ton_price;
} product;



int main()
{
    

