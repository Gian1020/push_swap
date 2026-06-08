# Get Next Line

*This project has been created as part of the 42 curriculum by gipimpin.*

---

## Descrizione
L'obiettivo del progetto **get_next_line** è quello di scrivere una funzione in C che, all'interno di un ciclo, permetta di leggere un file descriptor riga per riga fino alla fine, gestendo in modo efficiente la memoria ed evitando memory leak. Questo progetto introduce all'utilizzo pratico e fondamentale delle **variabili statiche** in C.

---

## Algoritmo Utilizzato
Per la realizzazione della funzione è stato implementato un meccanismo basato su una variabile statica (chiamata *stash* o *residuo*):
1. **Lettura (`read_and_allocates`)**: La funzione legge dal file descriptor a blocchi grandi quanti stabiliti dal `BUFFER_SIZE` e concatena i caratteri letti nello *stash*. Il ciclo si interrompe appena viene trovato un carattere di nuova linea (`\n`) o se si raggiunge la fine del file (EOF).
2. **Estrazione della riga (`ft_extract_line`)**: Viene analizzato lo *stash* fino al primo `\n` (compreso) per estrarre la riga completa che verrà restituita all'utente.
3. **Pulizia dello stash (`ft_clean_stash`)**: Tutto ciò che è rimasto nello *stash* oltre il carattere `\n` viene preservato e riallocato all'interno della variabile statica, fungendo da punto di partenza per la chiamata successiva.

---

## Funzioni Implementate

### Parte Mandatoria
La parte mandatoria include i file `get_next_line.c`, `get_next_line_utils.c` e `get_next_line.h`, composti dalle seguenti funzioni:

* `char *ft_get_next_line(int fd);` — Funzione principale che gestisce il flusso di lettura ed estrazione.
* `char *read_and_allocates(int fd, char *stash);` — Legge dal file descriptor e accumula i byte letti.
* `char *ft_extract_line(char *stash);` — Estrae la riga corrente da restituire.
* `char *ft_clean_stash(char *stash, int i);` — Pulisce lo *stash* rimuovendo la riga appena estratta.
* `size_t ft_strlen(char *str);` — Calcola la lunghezza di una stringa.
* `char *ft_strchr(const char *s, int c);` — Cerca la prima occorrenza di un carattere nella stringa.

### Parte Bonus
La parte bonus estende le funzionalità per gestire **molteplici file descriptor contemporaneamente**, mantenendo lo stato di lettura di ciascuno di essi senza perdere traccia dei rispettivi residui. I file includono il suffisso `_bonus`:
* `get_next_line_bonus.c`
* `get_next_line_bonus.h`
* `get_next_line_utils_bonus.c`

---

## Istruzioni di Compilazione

Il codice è predisposto per essere compilato definendo la dimensione del buffer tramite il flag `-D BUFFER_SIZE=n`.

### Compilazione Mandatoria
```bash
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
