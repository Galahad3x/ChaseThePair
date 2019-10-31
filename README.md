# Chase The Pair Challenge by HackEPS2019

## Descripción
Ejecución: Ejecutar ``` $make all ``` en la terminal y el programa pedirá tamaño de sets y número a buscar, probado en Ubuntu 18.10 de 64 bits.

Versión 1: La función ChaseThePair tiene 4 parámetros; un int toChase que es el número que vamos a buscar, dos arrays de int que son los sets que ha generado setsGenerator, y un array de int de mínimo 2 posiciones, en el que se guardarán los resultados.  
La función recorre los sets sin ordenar, ya que recorrer el set sin ordenar siempre es más barato que ordenarlo (recorrer tiene coste O(N) y ordenar mínimo orden O(N·logN)). Entonces guarda el número que tenga menos distancia con el número que buscamos.

Las pruebas se han realizado con 1000000 elementos en cada set. Es posible que al ejecutar el programa con un tamaño de set mayor salte un error, debido a falta de espacio en memoria.

Versión 2: La función ChaseThePair tiene 3 parámetros; un int toChase que es el número a buscar, un array de int de mínimo dos posiciones en el que guardaremos el resultado, y un puntero al fichero logs.txt.  

En esta versión ChaseThePair es simplemente dos llamadas a readSet, una función que recorre el set directamente desde logs.txt buscando el número más cercano a toChase, de modo que no se tiene que guardar todo el set en memoria. Tiene el mismo coste que la versión 1 (O(N)), pero tarda mucho más debido a que en esta versión hace más operaciones, que son todas en las que se lee del fichero.

Las pruebas en esta versión se pueden realizar en teoría con elementos infinitos.

## Información
- Group name: Enemy
- Cost: O(N)
- Time expend: 0.010417 seconds aprox. (Versión 1)  0,676186 seconds aprox. (Versión 2)
- Sets size: 1000000 elements

