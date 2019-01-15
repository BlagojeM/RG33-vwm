program: main.cpp Room.cpp Wall.cpp Player.cpp Camera.cpp Position.cpp Transformable.cpp image.cpp objloader.cpp
	g++ $^ -o $@ -lGL -lGLU -lglut -lm
