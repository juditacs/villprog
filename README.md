[KisZH eredmények](http://avalon.aut.bme.hu/~judit/results/villprog2_2016.txt)

# Programozás alapjai 2. (villamosmérnök) órai kódrészletek

Az itt olvasható tartalmak Linux rendszerekre vonatkoznak.
Windows cmd-ből is futtathatók a Visual Studio-val vagy más IDÉ-vel fordított állományok, de `./` nélkül kell hívni.

## C++ programok fordítása és futtatása

Fordítás:

    g++ program.cpp -Wall -o prog

Futtatás két parancssori argumentummal:

    ./prog egyik masik

Ekkor az `argv` tartalma:

| név | érték | típus |
| ----- | ----- | ----- |
| argc | 3 | int |
| argv[0] | ./prog | nullterminált string |
| argv[1] | egyik | nullterminált string |
| argv[2] | masik | nullterminált string |

### Idő és memóriamérés

Linux alatt az alapértelmezett `time` utasítás csak idő mérésére alkalmas, de telepíthető egy okosabb változata, amivel memóriát is lehet mérni.
Ubuntun:

    sudo apt-get install time

Tetszőleges process memóriamérése:

    /usr/bin/time -f "%M" ./prog

## C programok fordítása és futtatása

Fordítás:

    gcc program.c -Wall -o prog

Futtatás két parancssori argumentummal:

    ./prog egyik masik

Ekkor az `argv` tartalma:

| név | érték | típus |
| ----- | ----- | ----- |
| argc | 3 | int |
| argv[0] | ./prog | nullterminált string |
| argv[1] | egyik | nullterminált string |
| argv[2] | masik | nullterminált string |
