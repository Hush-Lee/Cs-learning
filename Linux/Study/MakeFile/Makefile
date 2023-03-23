src= sub.o add.o div.o multiply.o main.o
target=math

$(target):$(src)
	g++  $(src) -o $(target)

sub.o:sub.cpp
	gcc -c sub.cpp -o sub.o 
add.o:add.cpp
	gcc -c add.cpp -o add.o 
multiply.o:multiply.cpp
	gcc -c multiply.cpp -o multiply.o 
div.o:div.cpp
	gcc -c div.cpp -o div.o 
main.o:main.cpp 
	gcc -c main.cpp -o main.o 
