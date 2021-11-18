// =============================================================================
//
//          FILE: hello_curses.c
//         USAGE: Compile and run:
//                gcc hello_curses.c -lncurses -o hello_curses
//                ./hello_curses
//   DESCRIPTION: Quick demo of the ncurses (new curses) library.
//       OPTIONS: ---
//  REQUIREMENTS: ncurses installed:
//                sudo apt-get install libncurses-dev
//          BUGS: ---
//         NOTES: ---
//        AUTHOR: Fabian Eberts
//  ORGANIZATION: Fachhochschule Suedwestfalen
//       CREATED: 2021-11-18
//      REVISION: ---
//
// =============================================================================

#include <ncurses.h>

int main()
{
    // ===== Konfiguration des Fensters =====

    initscr();             // leeres Fenster erzeugen
    cbreak();              // Puffern von Eingaben deaktivieren (kein ENTER nötig)
    noecho();              // Benutzereingaben unsichtbar (sichtbar machen mit echo())
    keypad(stdscr, TRUE);  // Funktions- und Pfeiltasten erlauben
    nodelay(stdscr, TRUE); /* verhindert Anhalten des Programms bei getch(),
                            * stattdessen wird kontinuierlich ERR zurueckgegeben
                            * solange keine Taste gedrueckt wird
                            */
    curs_set(0);           // Cursor unsichtbar (0), sichtbar (1)

    mvprintw(0, 0, "Steuern mit Pfeiltasten, Beenden mit 'q'");

    // ===== Event loop =====

    int pressed_key;
    int quit = 0;

    while(!quit)
    {
        pressed_key = getch();

        switch(pressed_key)
        {
            case ERR:
                napms(10); // Pause in Millisekunden
                break;
            case KEY_UP:
                mvprintw(3, 5, "^");
                break;
            case KEY_DOWN:
                mvprintw(3, 5, "v");
                break;
            case KEY_LEFT:
                mvprintw(3, 5, "<");
                break;
            case KEY_RIGHT:
                mvprintw(3, 5, ">");
                break;
            case 'q':
                quit = 1;
                break;
        }

        refresh(); // Fensterinhalt aktualisieren
    }

    endwin(); // Fenster schliessen

    return 0;
}
