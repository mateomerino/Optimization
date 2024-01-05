cd src

gcc -O0 -o lab laboratorio3.c

valgrind --leak-check=yes ./lab

rm lab
