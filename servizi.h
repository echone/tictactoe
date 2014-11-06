/* 
 * Forza4.c
 * Luca Testoni matricola 820410
 * Header regole.h.h
 */

/* Inclusioni */
#include "stdio.h"
#include "servizi.h"


/* 
 * Prototipi 
 */
 
int Arbitro(char, char, int, char, char);
int Player_vs_Player();

/*
 * Funzione Arbitro()
 * input: segno1 e segno2 sono i simboli utlizzati dai 2 giocatori, x e' la dimensione della matrice, 
 *        row e column sono puntatori le cui celle contengono i valori della posizione del segno nella matrice
 * return: fine in base al fatto che ci sia un vincitore, il suo valore determina quale giocatore ha vinto
 * riferimenti: viene utilizzata da Player_vs_Player, fino a che non ritorna un valore il gioco continua
 * note: 
 */
int Arbitro(char segno1, char segno2, int x, char row, char column)
{
	x = leggi_x();
    for(row=0; row<x; row++)
    {
        for(column=0; column<x; column++)
        {
            if(matrice[row][column]==segno1)
            {
				/* vittoria giocatore 1 orizzontale */
                if(((matrice[row][column]==segno1)&&(matrice[row][column+1]==segno1)&&(matrice[row][column+2]==segno1)&&(matrice[row][column+3]==segno1))    
					/* vittoria giocatore 1 verticale */
                        ||((matrice[row-1][column]==segno1)&&(matrice[row][column]==segno1)&&(matrice[row+1][column]==segno1)&&(matrice[row+2][column]==segno1)) 
							/* vittoria giocatore 1 obliqua */ 
							||((matrice[row][column]==segno1)&&(matrice[row-1][column+1]==segno1)&&(matrice[row-2][column+2]==segno1)&&(matrice[row-3][column+3]==segno1)) 
							||((matrice[row][column]==segno1)&&(matrice[row-1][column-1]==segno1)&&(matrice[row-2][column-2]==segno1)&&(matrice[row-3][column-3]==segno1))) 
                {
                    return(1);   
                    break;
                }
            }
            if(matrice[row][column]==segno2)
            {
				/* vittoria giocatore 2 orizzontale */
                if(((matrice[row][column]==segno2)&&(matrice[row][column+1]==segno2)&&(matrice[row][column+2]==segno2)&&(matrice[row][column+3]==segno2))
						/* vittoria giocatore 2 verticale */
                        ||((matrice[row-1][column]==segno2)&&(matrice[row][column]==segno2)&&(matrice[row+1][column]==segno2)&&(matrice[row+2][column]==segno2))
							/* vittoria giocatore 2 obliqua */
							||((matrice[row][column]==segno2)&&(matrice[row-1][column+1]==segno2)&&(matrice[row-2][column+2]==segno2)&&(matrice[row-3][column+3]==segno2))
							||((matrice[row][column]==segno2)&&(matrice[row-1][column-1]==segno2)&&(matrice[row-2][column-2]==segno2)&&(matrice[row-3][column-3]==segno2))) 	
                {
                    return(2);
                    break;
                }
            }
        }
    }
    return 0;
}

/*
 * Funzione Player_vs_Player() 
 * input: nessuno dall'esterno, vedi le note per le variabili interne 
 * return: la fine del gioco e l'eventuale vincitore
 * note: e' la funzione che regola il gioco, al suo interno c'e'anche un controller per la matrice piena.
 */
int Player_vs_Player()
{
	/* Note sugli input
	 * x: e' il valore delle righe e delle colonne decise dal livello di difficolta'
	 * i = ROW
	 * j = COLUMN 
	 * SEGNO: e' il simbolo assegnato ai giocatori, passa da char a puntatore per permettere la modifica dei simboli del gioco in modo semplice
	 * contatore: inizializza il contatore per i turni dei giocatori
	 * fine: viene utilizzata per concludere il gioco e dichiarare il vincitore
	 * totalTurni: e' il contatore delle mosse
	 * maxTurni: e' il numero massimo di mosse possibili, moltiplica la dimensione delle colonne per se stessa, e' variabile in quanto e' variabile anche la dimensione della matrice di gioco
	 * j_full: e' la variabile utilizzata per determinare quando una colonna e' piena
	 * row e column: sono puntatori le cui celle contengono gli indirizzi delle celle allocate con i valori di i e j 
				
	 */
	int x,fine = 0;
	char i,j;
	int contatore = 0;
	int totalTurni = 1;
	char SEGNO1;
	char * segno1 = &SEGNO1;
	*segno1 = 'O';
	char SEGNO2;
	char * segno2 = &SEGNO2;
	*segno2 = 'X';
	char * row = &i;
	*row = i;
	char * column = &j;
	*column = j;
	CLEAR;
	x = leggi_x();
	matrix(x);
	int maxTurni = x * x; 
	int j_full[x];
	for(i=0; i<x; i++){										
		j_full[i]=0;
	}	
	do
	{
		printf("Giocatore 1 --> O\nGiocatore 2 --> X\n");
		do
		{
			/* il contatore pari e' del giocatore 1, il dispari del giocatore 2*/	
			if(contatore%2==0) {
				printf("\nGiocatore 1, digita il numero della colonna: ");
			} else {
				printf("\nGiocatore 2, digita il numero della colonna: ");
			}
			scanf("%d",&j);
		} while( (j<1) || (j>x) || (j_full[j-1]) );
		i=x-1; 
		/* Controllo che la riga abbia gia' un segno e posiziono il successivo sopra di esso */
		while (i<=x-1 && (matrice[i][j-1]==*segno1) || (matrice[i][j-1]==*segno2)) 
		{
		    i--;
		}
		if(contatore%2==0)
		    matrice[i][j-1]=*segno1;
		else
		    matrice[i][j-1]=*segno2;
		if(totalTurni == maxTurni)
		{
			printf("Non e' possibile nessuna ulteriore mossa. Parita'\n");
			return 0;
		}
		totalTurni++;	
		if (i==0)											
			j_full[j-1]=1;
		CLEAR;
		x = leggi_x();
		matrix(x);
		contatore++;
	} while(!(fine=Arbitro(*segno1,*segno2,x,*row,*column)));
	if(fine==1)
	{
		CLEAR;
		x = leggi_x();
		matrix(x);
		printf("\t\t\tVince il giocatore 1!\n");
	}
	else if(fine==2)
	{
		CLEAR;
		x = leggi_x();
		matrix(x);
		printf("\t\t\tVince il giocatore 2!\n");
	} 
}
