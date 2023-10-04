# Microbim

Realizzazione di un descrittore di facciata di casa da linea di comando e mantenerlo nel tempo, aggiornandolo e riarchitetturandolo secondo le nozioni apprese durante le lezioni.

## specifiche lato utente
### strictly necessary
- creare nuova casa

- creare nuovi piani

- creare una o più porte, scegliere per ogni porta solo la posizione orizzontale

- scegliere il numero di finestre e l'altezza all'interno del piano (disposizione automatica delle stesse) e/o creazione specifica finestra per finestra

- avere in output il disegno della facciata della casa su console con un preventivo di costo e di tempistiche per la costruzione

### nice to have
- diversi materiali per porte e finestre. con relativi costi e tempi associati

- diverse tipologie di porte e finestre, differenziate per forma o tipo (porta doppia, finestra doppia)

- controllo su eventuali errori dell'utente (controllo su collisioni porte-finestre-muri)

- salvataggio su db o file. possibilità di apertura e modifica di casa esistente

## architettura e scalabilità
progetto diviso in due parti:

- Libreria grafica: solo dedicata al disegno, completamente all'oscuro delle informazioni su cosa deve rappresentare (case finestre o porte). potenzialmente usabile per creare altre applicazioni

- Applicazione utente: applicazione che usa la suddetta libreria per visualizzare case

sistema di coordinate gerarchico. organizzazzione ad albero degli elementi in scena
