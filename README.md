NCurses-Demo
============

Minimalbeispiel für ein [Curses](https://en.wikipedia.org/wiki/Ncurses)-Programm als Vorlage für studentische Projekte im Modul *Programmierung mit C++*

Die Curses-Bibliothek dient dem Realisieren von zeichenorientierten Benutzerschnittstellen. Sie eignet sich gut für interaktive Programme und einfache Spiele. Ein Klassiker, der mit Curses implementiert wurde, ist das Spiel [Rogue](https://de.wikipedia.org/wiki/Rogue_(Computerspiel)).

Installation
------------

**Curses installieren**

```bash
sudo apt-get install libncurses-dev
```

**Kompilieren und Ausführen**

```bash
gcc hello_curses.c -lncurses -o hello_curses
./hello_curses
```

Grundlegende Funktionen
-----------------------

**Ausgabe an definierter Position**

```c
mvaddch(int row, int col, char c);     // Einzelzeichen
mvaddstr(int row, int col, char *str); // Zeichenkette
mvprintw(int row, int col, ...);       // wie C's printf()
```

**Benutzereingaben**

```c
char getch(void);                // einzelnes Zeichen (kein Enter noetig)
char* getstr(char *str);         // Zeichenkette
char* getnstr(char *str, int n); // Zeichenkette mit n Zeichen
scanw(...);                      // wie C's scanf()
```

**Fensterinhalt**

```c
erase();   // gesamten Fensterinhalt leeren
refresh(); // Fensterinhalt aktualisieren
```

Damit lassen sich die allermeisten Aufgaben bereits bewerkstelligen.

Weitere Funktionen
------------------

**Ermitteln der Fenstergröße**

```c
int maxrow, maxcol;
getmaxyx(stdscr, maxrow, maxcol);
```

**Ausgabe an aktueller Cursorposition**

```c
addch(char c);     // Einzelzeichen
addstr(char *str); // Zeichenkette
printw(...);       // wie C's printf()
```

**Versetzen des Cursors**

```c
move(int row, int col);
```

Konfiguration der Entwicklungsumgebung
--------------------------------------

**CodeBlocks**

1. Settings > Compiler > Linker settings
2. Dann bei *Other linker options* eintragen: `-lncurses`
3. Projekt wie gewohnt kompilieren

**Atom**

1. Edit > Preferences > Packages > gpp-compiler > Settings
2. Dann bei *C Compiler Options* eintragen: `-lncurses`
3. Projekt wie gewohnt kompilieren

**Visual Studio Code** (mit *Code Runner*-Erweiterung)

1. Datei > Einstellungen > Erweiterungen
2. Links in der Navigation: Code Runner Einstellungen (Zahnrad) > Erweiterungseinstellungen
3. Haken setzen bei *Run In Terminal*
4. Bei *Executor Map* auf *In settings.json bearbeiten* gehen
5. Die Curses-Library (`-lncurses`) hinzufügen:
   - aus `"c": "cd $dir && gcc $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`  
     wird `"c": "cd $dir && gcc $fileName -lncurses -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`
   - aus `"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`  
     wird  `"cpp": "cd $dir && g++ $fileName -lncurses -o $fileNameWithoutExt && $dir$fileNameWithoutExt",`
