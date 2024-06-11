# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: numarare trenuri drumuri scandal

# Nu compilați aici, nici măcar ca dependențe de reguli.
run-p1:
	./numarare
run-p2:
	./trenuri
run-p3:
	./drumuri
run-p4:
	./scandal

# Schimbați numele surselor (și, eventual, ale executabilelor - peste tot).
p1: numarare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: trenuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: drumuri.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: scandal.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f numarare trenuri drumuri scandal
