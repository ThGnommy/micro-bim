build:
	g++ -Wall -std=c++17 -fsanitize=address -o main *.cpp;

run:
	./main

clean:
	rm main
