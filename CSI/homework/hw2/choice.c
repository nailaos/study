int choice1(int x) { return (x < 0); }
int choice2(int x) { return (x << 31) & 1; }
int choice3(int x) { return 15 * x; }
int choice4(int x) { return (x + 15) / 4; }
int choice5(int x) { return x / 16; }
int choice6(int x) { return (x >> 31); }
int div(int x) { return x >> 4; }

int div2(int x) { return x /= 16; }
