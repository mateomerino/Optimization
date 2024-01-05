#!/bin/bash
cd src

# Compilamos el archivo sin optimizar 
gcc -O0 -pg -o lab laboratorio3.c
#Ejecutamos
./lab
#Utilizamos gprof para observar las estadísticas
gprof lab gmon.out > unopt.txt
 

#Repetimos el proceso para el archivo optimizado

gcc -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -O0 -pg -o labopt laboratorio3_opt.c 
#Ejecutamos
./labopt
#Utilizamos gprof para observar las estadísticas
gprof labopt gmon.out > opt.txt
 
rm lab
rm labopt
rm gmon.out
#diff unopt.txt opt.txt
