int main(int argc, char *argv[]) {
	int a,b;
	a= atoi(argv[1]);
	b = a*a;
	if(b==2)[[likely]] {
		a++;
		b++;
	} else {
		a--;
		b--;
	}
	return a+b;
}
