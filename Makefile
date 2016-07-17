cc=g++ 
ccflags=-std=c++11
bin_path=./bin
lib_path=./lib
ga_path=./general_algorithms

btree_traverse:
	$(cc) $(ccflags) $(ga_path)/binary_tree/main.cpp \
		$(lib_path)/binary_tree/binary_tree.cpp \
		-o $(bin_path)/btree_traverse

run_btree_traverse: btree_traverse
	$(bin_path)/btree_traverse

fib:
	$(cc) $(ccflags) $(ga_path)/fibonacci.cpp -o\
		$(bin_path)/fib
 
run_fib: fib
	$(bin_path)/fib

gcb: 
	$(cc) $(ccflags) $(ga_path)/gcd.cpp -o\
		$(bin_path)/gcd

run_gcd: gcb
	$(bin_path)/gcd

stone: 
	$(cc) $(ccflags) $(ga_path)/hailstone.cpp -o\
		$(bin_path)/stone

run_stone: stone
	$(bin_path)/stone


shift: 
	$(cc) $(ccflags) $(ga_path)/shift.cpp -o\
		$(bin_path)/shift

run_shift: shift
	$(bin_path)/shift


help:
	@echo "btree_traverse"
	@echo "run_btree_traverse"
	@echo "fib"
	@echo "run_fib"
	@echo "clean"

clean:
	rm $(bin_path)/*
