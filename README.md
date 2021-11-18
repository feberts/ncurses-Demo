NCurses-Demo
============

Minimalbeispiel für ein [ncurses](https://en.wikipedia.org/wiki/Ncurses)-Programm als Vorlage für studentische Projekte im Modul *Programmierung mit C++*.

Installation
------------

```bash
sudo apt-get install libncurses-dev
# Kompilieren und Ausführen:
gcc hello_curses.c -lncurses -o hello_curses
./hello_curses
```

Grundlegende Funktionen
-----------------------

**Ausgabe an definierter Position:**

```c
mvaddch(int row, int col, char c);     // Einzelzeichen
mvaddstr(int row, int col, char *str); // Zeichenkette
mvprintw(int row, int col, ...);       // identisch mit C's printf()
```

**Ausgabe an aktueller Cursorposition:**

```c
addch(char c);     // Einzelzeichen
addstr(char *str); // Zeichenkette
printw(...);       // identisch mit C's printf()
```

**Versetzen des Cursors:**

```c
move(int row, int col);
```

**Eingabe:**

```c
char getch(void);                // einzelnes Zeichen, ohne enter druecken zu muessen
char* getstr(char *str);         // Zeichenkette
char* getnstr(char *str, int n); // Zeichenkette mit n Zeichen
scanw(...);                      // identisch mit C's scanf()
```

**Fensterinhalt:**

```c
refresh();            // Fensterinhalt aktualisieren
erase(); und clear(); // gesamten Fensterinhalt leeren
clrtoeol();           // von Cursor bis Zeilenende (clear to end of line)
clrtobot();           // von Cursor bis Ende des Fensters (clear to bottom of window)
```

**Ermitteln der Fenstergröße:**

```c
int maxrow, maxcol;
getmaxyx(stdscr, maxrow, maxcol);
```

Konfiguration der IDE
---------------------

**CodeBlocks:**

1. Settings > Compiler > Linker settings
2. Dann bei *Other linker options* eintragen: `-lncurses`
3. Projekt wie gewohnt kompilieren

**Atom:**

1. Edit > Preferences > Packages > gpp-compiler > Settings
2. Dann bei *C Compiler Options* eintragen: `-lncurses`
3. Projekt wie gewohnt kompilieren
