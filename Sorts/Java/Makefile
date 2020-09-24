JAVAC=javac
JAVA=java
OUT=Classes
classes: Sorts/Main.java
	$(JAVAC) -d ./$(OUT) $^ && printf "Main-Class: Sorts.Main\n" > ./$(OUT)/Manifest.txt
run:
	$(JAVA) -cp Classes/ Sorts.Main
jar: ./$(OUT)/Sorts/*.class
	jar cf ./$(OUT)/main.jar $^
clear:
	rm -r $(OUT)