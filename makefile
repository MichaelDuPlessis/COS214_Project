observer.out: Main.o Thruster.o Stage.o StageObserver.o
	g++ Main.o Thruster.o Stage.o StageObserver.o -o observer.out
	
Main.o: Main.cpp Thruster.h Stage.h StageObserver.h
	g++ -c Main.cpp		

Thruster.o: Thruster.cpp Thruster.h
	g++ -c Thruster.cpp					

Stage.o: Stage.cpp Stage.h Thruster.h
	g++ -c Stage.cpp		

StageObserver.o: StageObserver.cpp StageObserver.h Stage.h
	g++ -c StageObserver.cpp			

run:
	./observer.out
	
clean:
	rm *.o observer.out