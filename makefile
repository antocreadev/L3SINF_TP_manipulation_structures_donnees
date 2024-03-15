# Nom du compilateur
CC=gcc

# Options de compilation
CFLAGS=-Wall -Wextra -g 

# Utiliser la variable t pour le nom de l'exécutable
t?=main

# Dossier pour les fichiers objets
OBJDIR=obj

# Dossier pour les fichiers binaires
BINDIR=bin

# Nom du fichier source sans l'extension .c
SRC=src/$(t)

# La première règle est la règle par défaut
all: $(t)

# Règle pour générer l'exécutable
$(t): $(OBJDIR)/$(t).o
	$(CC) $(CFLAGS) -o $(BINDIR)/$(t) $(OBJDIR)/$(t).o

# Règle pour compiler le fichier source en fichier objet
$(OBJDIR)/$(t).o: $(SRC).c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés lors de la compilation
clean:
	rm -f $(OBJDIR)/*.o $(t)
	rm -f bin/*


exo1 : 
	gcc -c -o obj/menghiexo1.o src/menghiexo1.c
	gcc -c -o obj/menghilisteint.o src/menghilisteint.c
	gcc -o bin/menghiexo1 obj/menghiexo1.o obj/menghilisteint.o