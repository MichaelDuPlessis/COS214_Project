main.out: command.o land.o launch.o missionControl.o rocket.o main.o
	g++ -g  command.o land.o launch.o missionControl.o rocket.o main.o \
			-o main.out

main.o: main.cpp
	g++ -g -c main.cpp

land.o: land.cpp land.h 
	g++ -g -c land.cpp

launch.o: launch.cpp launch.h
	g++ -g -c launch.cpp

missionControl.o: missionControl.cpp missionControl.h 
	g++ -g -c missionControl.cpp 

rocket.o: rocket.cpp rocket.h
	g++ -g -c rocket.cpp

command.o: command.cpp command.h 
	g++ -g -c command.cpp

run:
	./main.out

clean:
	rm *.o