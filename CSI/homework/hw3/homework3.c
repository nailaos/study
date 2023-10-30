int eat_peaches(int i) {
    if (i == 10)
        return 1;
    else
        return (eat_peaches(i + 1) + 1) * 2;
}
