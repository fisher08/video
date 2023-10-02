#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

unsigned long xorshift(unsigned long state[static 1]) {
    unsigned long x = state[0];
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    state[0] = x;
    return x;
}

long random_long(long min, long max) {
    int urandom = open("/dev/urandom", O_RDONLY);
    unsigned long state[1];
    read(urandom, state, sizeof(state));
    close(urandom);
    unsigned long range = (unsigned long) max - min + 1;
    unsigned long random_value = xorshift(state) % range;
    return (long) (random_value + min);
}


int main(int argv, char** argc) {
    int MAX = 1000000;

    long* data = (long*)calloc(MAX, sizeof(long));

    for (int i = 0; i < MAX; i++) {
        data[i] = random_long(0,MAX);
    }
}
