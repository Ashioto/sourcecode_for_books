g++ -g main.cpp -o main.o
g++ -g answer.cpp -o answer.o
./main.o < data.in > my.txt
./answer.o < data.in > answer.txt
diff my.txt answer.txt
