Sistemas Operativos II - Laboratorio III Basic Optimization
###  Ingeniería en Compitación - FCEFyN - UNC - 2023
# Laboratorio 3 - Introducción a la programación eficiente y performante

## Desarrollo

    -El desarrollo del trabajo comenzó por unas pequeñas optimizaciones simples orientadas a la declaración de las variables utilizadas en el programa laboratorio3.c 

    Comenzando por las variables globales XDIM e YDIM se declararon en un #define para resolverlas en tiempo de compilación y ahorrar algo de tiempo en ejecución

    Siguiendo con las funciones particulares del programa, se redefinieron ciertas variables especificadas a continuación:

    -alloc_matrix(): Se cambió la lógica de asignación de memoria para la matriz. Primero se optó por eliminar el doble ciclo for que utilizaba la función "memset()" ya que luego en la función fill() se llena la matriz de números; por lo que solo se dejó el doble ciclo for que utiliza la función calloc() para alocar memoria. A este último doble ciclo for se lo reemplazó por un while más sencillo que realiza lo mismo; lo que permitió eliminar las variables j y k.
        A su vez, la variable i se la redefinió como register unsigned int; y de esta manera ocupa menos lugar en memoria.

    -fill(): Se optó por generar los números aleatorios con la misma semilla modificando la función srand(); de esta manera se pudo tener "control" sobre los números aleatorios ya que si son generados con la misma semilla; son siempre los mismos. Esto permitió hacer comparaciones de resultados entre el archivo original y el optimizado. Lo que permitió eliminar el #include <time.h> e #include <math.h> ya que no son necesarias.
        Finalmente, se optó por llenar las posiciones de la matriz "de a diez" modificando el doble ciclo for para ahorrar tiempo en las iteraciones del mismo.

    -compute(): En primer lugar se añadió la creación del arreglo kern en dicha función ya que solo se utiliza allí; y además se lo redefinió como __int8_t ya que de esta manera ocupa menos memoria.
        Lo más importante realizado en esta función es el simplificado de los cómputos; el hecho de modificar la manera en el que se calculan los valores de la matriz. Se pasó de un cálculo que implicaba 4 ciclos for anidados a uno que solo utiliza 2; simplificando la manera en la que se calculan los valores en el arreglo tmp_sum para una mejor performance en los cálculos.

    -print(): Esta función directamente no se utiliza; ya que se definió como objetivo el tiempo de cálculo y no es de interés ver los resultados en pantalla. (Esta función se eliminó cuando ya se había corroborado que los resultados del programa original y el optimizado eran los mismos).

    -main(): Se eliminaron ciertas variables y se crearon en otros lados especificado anteriormente.

    Es de suma importancia detallar que se agregó una función free_matrix() que lo que hace es liberar todas las llamadas a calloc previamente realizadas en la función alloc_matrix(). Ya que con el uso de valgrind se pudo observar que faltaban llamados a la función free() para la correcta gestión de la memoria.

## Scripts para observar los resultados

    El proyecto cuenta con tres scripts .sh para corroborar los resultados de la optimización. Los mismos se deben ejecutar en el siguiente orden:

    1) Se debe ejecutar el script "valgrind_unopt" que lo que hace es compilar el programa no-optimizado, y hacer uso de valgrind para poder observar todos los memory-leaks que tiene el programa. Se ve claro que hay una incorrecta gestión de la memoria.

    2) Se debe ejecutar el script "valgrind_opt" que compila el programa ejecutado con todas las flags de compilación necesarias y también hace uso de valgrind; en donde se puede observar que con las modificaciones hechas la memora se gestiona correctamente, liberando toda la memoria que se alocó en la ejecución.

    3) Por ultimo, se debe ejecutar el script "gprof.sh" el cual hace uso de la herramienta de profiling gprof para observar estadísticas de ejecución. El resultado de estas estadísticas se comparan y se marcan las diferencias; en donde se aprecian las mejoras en tiempo de ejecución con las modificaciones hechas. Cabe aclarar que se modificó el tamaño de la matriz (Se la hizo más grande) para poder apreciar mejor la diferencia entre estos tiempos
