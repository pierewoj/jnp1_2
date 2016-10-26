g++ -c -Wall -O2 -std=c++14 strdeque.cc -o strdeque.o
g++ -c -Wall -O2 -std=c++14 strdequeconst.cc -o strdequeconst.o
gcc -c -Wall -O2 strdeque_test1.c -o strdeque_test1.o
g++ -c -Wall -O2 -std=c++14 strdeque_test2a.cc -o strdeque_test2a.o
g++ -c -Wall -O2 -std=c++14 strdeque_test2b.cc -o strdeque_test2b.o
g++ strdeque_test1.o strdeque.o strdequeconst.o -o strdeque_test1
g++ strdeque_test2a.o strdeque.o strdequeconst.o -o strdeque_test2a
g++ strdeque_test2b.o strdeque.o strdequeconst.o -o strdeque_test2b

