program: main.cpp Room.cpp Wall.cpp Player.cpp Camera.cpp Position.cpp Transformable.cpp
	g++ $^ -o $@ -lGL -lGLU -lglut -lm
