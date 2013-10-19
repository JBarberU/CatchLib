FOLDERS = tests/*.cpp src/GameModel/*.cpp src/GameModel/*/*.cpp  src/EventHandling/*.cpp src/Math/*.cpp src/Helper/*.cpp libBox2d.so
OUTPUT = Tests.so

BOX_LIB = $(ls libBox2d.so | grep 'No such file'); \

exec:
	./$(OUTPUT)
compile:	
	g++  $(FOLDERS) -o $(OUTPUT)
	echo "Done compiling!"
	
compile_box2d:
	mkdir tmp; \
	cd tmp; \
	g++ -c ../Box2D/*/*.cpp ../Box2D/*/*/*.cpp; \
	cd ..; \
	ar rvs libBox2d.so tmp/b2*; \
	rm -r tmp; \
	
test:
	make compile; \
	./$(OUTPUT)

clean:
	rm $(OUTPUT)
