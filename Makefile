dll:
	g++ -c ./src/*.cpp -fpic
	g++ *.o -shared -o ./bin/lib_simulate.so -fpic 
	rm *.o

functional:
	g++ -c ./test/functional/*.cpp 
	g++ *.o -o ./bin/functional -L./bin -l_simulate
	rm *.o

unit:
	g++ -c ./test/unit/*.cpp 
	g++ *.o -o ./bin/unit -L./bin -l_simulate
	rm *.o

run_functional:
	./bin/functional

run_unit:
	./bin/unit
	
clean: 
	rm -f *.o main

run:
	./main

# export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:C:\Users\thall\Documents\Sprint6Thalles\bin