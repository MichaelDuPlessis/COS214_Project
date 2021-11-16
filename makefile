task3.out: Main.o Track.o concreteSections.o Decorator.o concreteDecorators.o FlagObserver.o
	g++ Main.o Track.o concreteSections.o Decorator.o concreteDecorators.o FlagObserver.o -o task3.out
	
Main.o: Main.cpp Section.h Track.h Decorator.h Observer.h
	g++ -c Main.cpp		

Track.o: Track.cpp Track.h Section.h
	g++ -c Track.cpp

Decorator.o: Decorator.cpp Decorator.h Section.h
	g++ -c Decorator.cpp

FlagObserver.o: FlagObserver.cpp FlagObserver.h Track.h Observer.h
	g++ -c FlagObserver.cpp					

concreteSections.o: concreteSections.cpp Section.h
	g++ -c concreteSections.cpp		

concreteDecorators.o: concreteDecorators.cpp Decorator.h
	g++ -c concreteDecorators.cpp			

run:
	./task3.out
	
clean:
	rm *.o task3.out