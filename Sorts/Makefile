PY=python
JVC=javac -d
JV=java
OUT=./Java/Classes
CC=g++
CFLAGS=-g -Wall -std=c++17
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