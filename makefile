# Compile C source files into object files
#main.o:: main.c DataAltitudeObstacle.h Datajoystick.h DataSpeed.h Interfaces.h T1-AltitudeControl.h T2-DetectObstacle.h T3-Speed.h T4-Joystick.h T5-Control.h T6-Mode.h
C::
	gcc -c main.c -o main.o

#DataAtitudeObstacle.o: DataAltitudeObstacle.c DataAtitudeObstacle.h
	gcc -c DataAltitudeObstacle.c -o DataAltitudeObstacle.o

#DataJoystick.o: DataJoystick.c DataJoystick.h
	gcc -c DataJoystick.c -o DataJoystick.o

#DataSpeed.o: DataSpeed.c DataSpeed.h
	gcc -c DataSpeed.c -o DataSpeed.o

#Interfaces.o: Interfaces.c Interfaces.h
	gcc -c Interfaces.c -o Interfaces.o

#T1-AltitudeControl.o: T1-AltitudeControl.c T1-AltitudeControl.h
	gcc -c T1-AltitudeControl.c -o T1-AltitudeControl.o

#T2-DetectObstacle.o: T2-DetectObstacle.c T2-DetectObstacle.h
	gcc -c T2-DetectObstacle.c -o T2-DetectObstacle.o

#T3-Speed.o: T3-Speed.c T3-Speed.h
	gcc -c T3-Speed.c -o T3-Speed.o

#T4-Joystick.o: T4-Joystick.c T4-Joystick.h
	gcc -c T4-Joystick.c -o T4-Joystick.o

#T5-Control.o: T5-Control.c T5-Control.h
	gcc -c T5-EngineControl.c -o T5-EngineControl.o

#T6-Mode.o: T6-Mode.c T6-Mode.h
	gcc -c T6-Mode.c -o T6-Mode.o

# Link object files to create executables
#main:: main.o DataAtitudeObstacle.o DataJoystick.o DataSpeed.o Interfaces.o T1-AltitudeControl.o T2-DetectObstacle.o T3-Speed.o T4-Joystick.o T5-Control.o T6-Mode.o
	gcc -o main main.o DataAltitudeObstacle.o DataJoystick.o DataSpeed.o Interfaces.o T1-AltitudeControl.o T2-DetectObstacle.o T3-Speed.o T4-Joystick.o T5-EngineControl.o T6-Mode.o -lrt -lwiringPi -lpthread -lm

# Clean up intermediate object files and executables
clean::
	rm -f *.o main
all:: C
