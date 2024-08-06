all: compile run

compile:
	gcc -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.c
	gcc -I ./include/ -o ./lib/MatrisOlustur.o -c ./src/MatrisOlustur.c
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c
	gcc -I ./include/ -o ./bin/Test ./lib/DosyaOku.o ./lib/MatrisOlustur.o ./lib/Canli.o  ./lib/Bitki.o ./lib/Bocek.o ./lib/Pire.o ./lib/Sinek.o ./lib/Habitat.o ./src/Test.c
	
run: 
	./bin/Test
