tic tac toe
=========

C programming per il gioco forza4 (tic tac toe)

 * Forza4.c include regole.h include servizi.h
 * Gioco Forza 4 in cui lo scopo e' quello di allineare 4 segni uguali verticalmente, orizzontalmente o in obliquo
 * Si e' scelto di utilizzare main come funzione per mantenere lo standard ANSI C. Si' escelto anche di utilizzare 
 * una matrice quadrata e di dimensione variabile, aumentando la dimensione della matrice all'aumentare del livello
 * di difficolta' che i giocatori possono scegliere attraverso un apposito menu. Essendo la matrice quadrata utilizziamo 
 * una singola variabile x che determinera' il numero di colonne e il numero di righe. Per evitare di utilizzare una
 * variabile globale si e' optato per scrivere il valore della x su un file ".matrice.txt". Il valore viene scritto e
 * letto ogni volta che serve attraverso funzioni apposite, al termine del gioco il file viene cancellato.
 * Si e' scelto di includere 2 file header: il primo chiamato regole.h contiene le funzioni "di gioco" ovvero le funzioni
 * che determinano le regole del gioco e le regole per determinare l'eventuale vincitore; il secondo chiamato servizi.h 
 * contiene le funzioni di servizio ovvero quelle funzioni non legate alle regole ma che servono comunque per garantire
 * il corretto funzionamento del gioco.
 * Si e' cercato di ridurre al minimo le definizioni delle variabili globali infatti ne e' stata impostata solo una
 * chiamata matrice
