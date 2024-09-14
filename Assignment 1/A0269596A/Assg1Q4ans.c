void func(int a) {
    int i = 32, count = 0;
    while (i > 0) {
        if (a >= 0) count++;
        i--;
        if (i == 0) return;
        a *= 2;
    }
}