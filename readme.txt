Schiffe Versenken in C++

Ein Projekt von Paul-Benedict Burkard, Leon Jerke und Ruben Herbstreuth für die Duale Hochschule Baden-Württemberg Horb.
____________________________________________________________


Vor dem Builden des Projekts: Die Game.cpp hat OS-Sensitiven Code. Die Zeilen 167 und 169 müssen entsprechend des OS vor dem Kompilieren angepasst werden!

Die Dateien des Repos sind auf Windows ausgelegt.

Die Dateien der .ZIP sind auf MacOS ausgelegt.
_____________________________________________________________


Builden des Projekts:

In Visual Studio Code:

g++ Ship.cpp Player.cpp Board.cpp Game.cpp Main.cpp -o BattleShips.exe –std=c++14

____________________

In Visual Studio 2019:

Das öffentliche Repos https://github.com/Leon-Jerke/SchiffeVersenken Clonen und starten.

____________________________________________________________

Wie man es spielt:

Der Spielablauf wird Schrittweise in der Konsole beschrieben. Sie werden nach jedem Spielschritt zur Eingabe aufgefordert. Was Sie dabei eingeben können wird ihnen vorgegeben. Sollten Sie ausversehen etwas falsches geben wird eine Fehlermeldung ausgegeben und Sie können es erneut versuchen. 

Lesen Sie bitte immer alle ausgegebenen Texte. Womöglich müssen Sie dafür nach oben Scrollen oder die Konsole maximieren. An einigen Stellen wird nur "Drücken sie eine beliebige Taste..." ausgegeben. Dies ist die einzige Situation, in der ein einfacher Tastendruck auf der Tastatur reicht um fortzufahren. Alle Anderen Eingaben müssen mit Enter bestätigt werden.

Koordinaten müssen in der Form "BuchstabeZiffer" angegeben werden. Wollen Sie z.B. auf A7 schießen, so lautet die Eingabe an der entsprechenden Stelle auch "A7" (ohne Anführungszeichen) und mit Enter bestätigen.