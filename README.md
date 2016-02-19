# Programozás alapjai 2. (villamosmérnök) órai kódrészletek

Az itt olvasható tartalmak Linux rendszerekre vonatkoznak.
Windows cmd-ből is futtathatók a Visual Studio-val vagy más IDÉ-vel fordított állományok, de `./` nélkül kell hívni.

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
