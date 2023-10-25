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
