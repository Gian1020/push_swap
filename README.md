# PUSH_SWAP

## 📋 Roadmap & TODO

### 🚀 Ottimizzazione
- [ ] **Fast sort:** Migliorare l'algoritmo della funzione `fast_sort` (attuale complessità O(n^2)).

### 🧮 Indice di Disordine
- [x] **Calcolo del disordine:** Implementare la funzione che calcola l'indice di disordine.
    ```python
    function compute_disorder(stack a):
        mistakes = 0
        total_pairs = 0
        for i from 0 to size(a)-1:
            for j from i+1 to size(a)-1:
                total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
        return mistakes / total_pairs
    ```

### 🛠️ Comandi
- [x] **Implementare i comandi di base:**

| Categoria | Comandi | Descrizione (Azione) |
| :--- | :--- | :--- |
| **Swap** | `sa`, `sb`, `ss` | Scambiano i primi due elementi |
| **Push** | `pa`, `pb` | Spingono l'elemento in cima su un altro stack |
| **Rotate** | `ra`, `rb`, `rr` | Ruotano lo stack verso l'alto |
| **Reverse Rotate** | `rra`, `rrb`, `rrr` | Ruotano lo stack verso il basso |

### 🧠 Algoritmi di Ordinamento
- [ ] **Implementare Simple algorithm** *(Da scegliere O(n^2))*
    - Insertion sort adaptation
    - Selection sort adaptation
    - Bubble sort adaptation
    - Simple min/max extraction methods
- [x] **Implementare Medium algorithm** *(Chunk-based sorting O(n sqrt(n)))*
- [ ] **Implementare Complex algorithm** *(Da scegliere O(n log n))*
    - Radix sort adaptation (LSD or MSD)
    - Merge sort adaptation using two stacks
    - Quick sort adaptation with stack partitioning
    - Heap sort adaptation
    - Binary indexed tree approaches
- [ ] **Implementare Custom adaptive algorithm**
    Sceglie quale dei tre algoritmi usare in base all'indice di disordine (d):
    - **Simple:** se `d < 0.2`
    - **Medium:** se `0.2 <= d < 0.5`
    - **High:** se `d >= 0.5`

### 💻 Esecuzione, CLI e Gestione Errori
- [ ] **Parametri di avvio (ARGV ARGC):** Implementare la scelta dell'algoritmo passando i seguenti flag a `a.out`:
    - `--simple`
    - `--medium`
    - `--complex`
    - `--adaptive`
- [x] **Stampa Output:** Stampare tutti i comandi nel terminale, ognuno seguito da `\n`.
- [x] **Gestione Errori:** In caso d'errore stampare nel terminale `"Error\n"`.

### 📊 Benchmark (Opzionale)
- [ ] **Modalità `--bench`:** L'output del benchmark deve essere inviato a `stderr` e apparire **solo** quando il flag è presente. Dopo l'ordinamento deve visualizzare:
    - Il disordine calcolato (% con due cifre decimali).
    - Il nome della strategia utilizzata e la sua classe di complessità teorica.
    - Il numero totale di operazioni.
    - Il conteggio di ciascun tipo di operazione (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`). (wc -l)
    
### Funzione che stampa i float
- [x] **Funzione che stampa l'indice di disordine in percentuale e lo tronca alla seconda cifra decimale.**
