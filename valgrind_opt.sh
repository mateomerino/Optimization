cd src 

gcc -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11 -O0 -o labopt laboratorio3_opt.c

valgrind --leak-check=yes ./labopt

rm labopt
