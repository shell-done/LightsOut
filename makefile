GAME_C =Game.c
WINDOW_C =Window/Window.c
EVENTS_C =Window/Events.c
LIGHTSOUT_C =LightsOut.c

GAME_H =Game.h
INCLUDES_H =Includes.h
LIGHTSOUT_H =LightsOut.h
WINDOW_H =Window/Window.h
EVENTS_H =Window/Events.h

ALL_H =$(SolveProblem.h) $(Game.h) $(Includes.h) $(LightsOut.h) $(Window.h) $(Events.h) 

LightsOut: Game.o Window.o Events.o LightsOut.o
	gcc *.o -lSDL -lSDL_image -lSDL_ttf -lm -o LightsOut

Game.o: $(GAME_C) $(ALL_H)
	gcc -Wall -c $< -o $@

Window.o: $(WINDOW_C) $(ALL_H)
	gcc -Wall -c $< -o $@

Events.o: $(EVENTS_C) $(ALL_H)
	gcc -Wall -c $< -o $@

LightsOut.o: $(LIGHTSOUT_C) $(ALL_H)
	gcc -Wall -c $< -o $@


clean:
	rm -f *.o LightsOut