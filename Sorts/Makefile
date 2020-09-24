PY=python
JVC=javac -d
JV=java
OUT=./Java/Classes
gen-numbers:
	$(PY) utils/generator.py
test-python:
	$(PY) Python/test_sorts.py
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