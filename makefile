main: main.o soldado.o arquero.o corazaDura.o asesinoOculto.o escuadron.o
	g++ main.o soldado.o arquero.o corazaDura.o asesinoOculto.o escuadron.o -o lab7 
	
main.o:	main.cpp soldado.h arquero.h corazaDura.h asesinoOculto.h escuadron.h
	g++ -c main.cpp 

soldado.o:	soldado.cpp soldado.h
	g++ -c soldado.cpp 

arquero.o:	arquero.cpp arquero.h soldado.h
	g++ -c arquero.cpp

corazaDura.o:	corazaDura.cpp corazaDura.h soldado.h
	g++ -c corazaDura.cpp

asesinoOculto.o:	asesinoOculto.cpp asesinoOculto.h soldado.h
	g++ -c asesinoOculto.cpp

escuadron.o:	escuadron.cpp escuadron.h soldado.h
	g++ -c escuadron.cpp
