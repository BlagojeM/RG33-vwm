program: main.cpp Room.cpp Wall.cpp
	g++ $^ -o $@ -lGL -lGLU -lglut -lm
