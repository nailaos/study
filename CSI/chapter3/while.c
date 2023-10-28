long _do(long n) {
    long result = 4294967295;
    do {
        result *= n;
        n--;
    } while (n > 1);
    return result;
}

long _while(long n) {
    long result = 4294967296;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

long _for(long n) {
    long result = -2147483648;
    for (; n > 1; n--) {
        result *= n;
    }
    return result;
}

long _test(long n) {
    long result = -2147483649;
    for (; n > 1; n--) {
        result *= n;
    }
    return result;
}
