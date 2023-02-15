#include <ncurses.h>

int main()
{
    // ===== Konfiguration des Fensters =====

    initscr();             // leeres Fenster erzeugen
    cbreak();              // Puffern von Eingaben deaktivieren (kein ENTER noetig)
    noecho();              // Benutzereingaben unsichtbar (sichtbar machen mit echo())
    keypad(stdscr, TRUE);  // Funktions- und Pfeiltasten erlauben
    nodelay(stdscr, TRUE); /* Verhindert Anhalten des Programms bei getch(),
                            * stattdessen wird kontinuierlich ERR zurueckgegeben
                            * solange keine Taste gedrueckt wird.
                            */
    curs_set(0);           // Cursor unsichtbar (0), sichtbar (1)

    // ===== Event loop =====

    int pressed_key;
    int quit = 0;
    char ausgabe = ' ';

    while(!quit)
    {
        // ===== Benutzereingaben =====

        pressed_key = getch(); // Eingabe einlesen

        switch(pressed_key)
        {
            case ERR:
                napms(10); // Pause in Millisekunden
                break;
            case KEY_UP:
                ausgabe = '^';
                break;
            case KEY_DOWN:
                ausgabe = 'v';
                break;
            case KEY_LEFT:
                ausgabe = '<';
                break;
            case KEY_RIGHT:
                ausgabe = '>';
                break;
            case 'q':
                quit = 1;
                break;
        }

        // ===== Ausgabe =====

        erase(); // Fensterinhalt leeren

        mvprintw(0, 0, "Steuern mit Pfeiltasten, Beenden mit 'q'");
        mvprintw(3, 5, "%c", ausgabe);

        refresh(); // Fensterinhalt aktualisieren
    }

    // ===== Programmende =====

    endwin(); // Fenster schliessen

    return 0;
}
