#include <cstdio>
#include <cstdlib>

struct S {
    int t[10000];
};

void f(S s) {
    static int i = 1;
    printf("%d\n", i++);
    f(s);
}

int main(int argc, char* argv[]) {
    S s;
    f(s);
}
