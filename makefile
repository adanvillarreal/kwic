build:
	g++ -std=c++11 main.cpp -o executable

run: build
	./executable

clean:
	rm executable