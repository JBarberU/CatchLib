FOLDERS = tests/*.cpp src/GameModel/*.cpp src/GameModel/*/*.cpp  src/EventHandling/*.cpp src/Math/*.cpp src/Helper/*.cpp
OUTPUT = Tests.so

exec:
	./$(OUTPUT)
compile:
	rm -f $(OUTPUT)
	g++  $(FOLDERS) -o $(OUTPUT)
	echo "Compiling"