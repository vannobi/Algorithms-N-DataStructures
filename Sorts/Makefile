PY=python
JVC=javac -d
JV=java
OUT=./Java/Classes
CC=g++
CFLAGS=-O -Wall -std=c++17
all:
	make clear-numbers && make gen-numbers && make java-classes && make c-build && make test-c && make test-java && make test-python
gen-numbers:
	$(PY) utils/generator.py
test-python:
	$(PY) Python/test_sorts.py
c-build: C++/test_sorts.cc
	$(CC) $(CFLAGS) -o ./C++/build/linux-$@ $^
test-c:
	./C++/build/linux-c-build
java-classes: Java/Sorts/*.java
	$(JVC) $(OUT) $^ && printf "Main-Class: Sorts.Main\n" > $(OUT)/Manifest.txt
test-java:
	$(JV) -cp Java/Classes/ Sorts.Main 
clear-java-classes:
	rm -r $(OUT)
plot:
	$(PY) utils/plot.py
clear-numbers:
	find ./utils/random -name "*.txt" -type f -delete