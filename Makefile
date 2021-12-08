make:
	g++ *.cpp -lSDL2 -lSDL2main -lSDL2_image && ./a.out
clean:
	rm a.out
