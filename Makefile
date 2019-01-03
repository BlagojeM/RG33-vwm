program: main.cpp Room.cpp Wall.cpp Person.cpp
	g++ $^ -o $@ -lGL -lGLU -lglut -lm
