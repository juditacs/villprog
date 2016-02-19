# Programozás alapjai 2. (villamosmérnök) órai kódrészletek

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
