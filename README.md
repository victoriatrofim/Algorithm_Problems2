## README TEMA2 - PA

# ------------------------------------------- PROBLEMA 1-----------------------------------------------------------------------
CERINTA: Gasirea numarului de lanturi elementare comune dintre 2 grafuri date.

IMPLEMENTARE: 

* MOD este definit ca 1000000007 pentru a face operații modulo, necesare în gestionarea numerelor mari.
* Functii:

[Main]

Citim numărul de noduri n și muchii m din fișierul de intrare.
Creăm listele de adiacență pentru ambele grafuri.
Inițializăm vectorul dp pentru a calcula numărul de căi până la fiecare nod.
Construim un graf comun pe baza vecinilor comuni din ambele grafuri.
Pentru fiecare nod, iterăm prin vecinii săi din primul graf și verificăm dacă aceștia există și în al doilea graf. Dacă da, îi adăugăm în lista de adiacență a grafului comun.
Setăm dp[1] la 1, deoarece există exact un drum de la nodul 1 la el însuși.
Iterăm prin fiecare nod și actualizăm numărul de drumuri pentru vecinii săi din graful comun, utilizând formula: dp[neighbor] = (dp[neighbor] + dp[node]) % MOD.
Rezultatul final reprezinta valoarea elementului n din dp si caracterizeaza cel mai lung lant comun din ambele grafuri, respectiv ulterior este scris în fișierul de ieșire.

* Analiza Complexității
- Timp: Complexitatea temporală este O(n + m), unde n este numărul de noduri și m este numărul de muchii. Citirea datelor, construirea listelor de adiacență și procesarea fiecărui nod și muchie se realizează într-un timp liniar.
- Spațiu: Complexitatea spațială este O(n + m), necesară pentru stocarea listelor de adiacență și a vectorului dp.

# ------------------------------------------- PROBLEMA 2 ------------------------------------------------------------------------
CERINȚA: Determinarea celei mai lungi căi dintre două noduri într-un graf orientat.

IMPLEMENTARE:
* Funcții:

[Main]

Citim numărul de noduri n și muchii m din fișierul de intrare.
Citim nodurile de start și de sfârșit.
Creăm lista de adiacență pentru graf.
Inițializăm vectorul dp cu -1 pentru a indica faptul că niciun nod nu a fost vizitat încă.
Inițializăm lista de orașe pentru a gestiona toate nodurile.
Construim lista de adiacență pe baza datelor din fișier.
Dacă un nod nu a fost vizitat, aplicăm sortarea topologică pe acesta.
Calculăm cea mai lungă cale folosind programarea dinamică, interogand stiva topologic ordonata luand fiecare nod si pentru fiecare vecin al acestuia, ii actualizam valoarea ca maximul dintre valoarea pe care deja o are si cea a nodului curent + 1
Incrementăm rezultatul final pentru nodul de sfârșit și îl scriem în fișierul de ieșire.

[TopologicalSort]

Marchez nodul curent ca vizitat.
Iterez prin toți vecinii nodului curent.
Dacă vecinul nu a fost vizitat, aplic sortarea topologică recursiv pe acesta.
Adaug nodul curent în stivă după ce toți vecinii săi au fost vizitați.

* Analiza Complexității
- Timp: Complexitatea temporală este O(n + m), unde n este numărul de noduri și m este numărul de muchii. Sortarea topologică și procesarea fiecărui nod și muchie se realizează într-un timp liniar.
- Spațiu: Complexitatea spațială este O(n + m), necesară pentru stocarea listei de adiacență și a structurilor de date (stack, vectori, hărți).

# ------------------------------------------- PROBLEMA 3 ------------------------------------------------------------------------

CERINȚA: Găsirea unei submulțimi de muchii cu costul minim care permite existența unui drum de la x la z și de la y la z într-un graf orientat cu costuri pe muchii.

IMPLEMENTARE:
* Pentru implementare am folosit informatii din laboratorul 9
* Funcții:

[Main]
MAXIM este definit ca 1000000000000 pentru a reprezenta valoarea inițială foarte mare utilizată în algoritmul Dijkstra, semnificând distanța "infinita".
Citim numărul de noduri n și numărul de muchii m din fișierul de intrare.
Construim listele de adiacență pentru graf și pentru graful inversat (pentru a realiza calcularea distanțelor către nodul z).
Inițializăm vectorii de distanțe dFromX, dFromY și dToZ cu MAXIM.
Executăm algoritmul Dijkstra pornind de la nodurile x, y și z (pe graful inversat) pentru a calcula cele mai scurte distanțe.
Calculăm costul minim verificand pentru fiecare nod i existent daca exista drum de la x -> i, de la y -> i si de la i -> z, astfel se verifică dacă nodul i este accesibil atât din x, cât și din y, și dacă există un drum de la i la z.
Rezultatul final va fi minimul dintre valoarea curenta si suma tuturor drumurilor mentionate mai sus.

[Dijkstra]
Aceasta functie implementează algoritmul Dijkstra pentru a găsi cele mai scurte drumuri de la nodul de start la toate celelalte noduri din graf.
Folosește un min-heap (priority queue) pentru a alege întotdeauna nodul cu cea mai mică distanță în timpul procesării.
Pentru fiecare nod, actualizează distanțele către nodurile vecine dacă găsește un drum mai scurt.

* Analiza Complexității
- Timp: Complexitatea temporală a algoritmului este O((N + M) * log N) pentru fiecare execuție a lui Dijkstra, unde N este numărul de noduri și M este numărul de muchii.
    Inițializarea cozii de priorități: O(N log N)
    Relaxarea muchiilor: O(M log N)
- Spațiu: Complexitatea spațială este O(N + M) pentru stocarea listei de adiacență și a distanțelor.