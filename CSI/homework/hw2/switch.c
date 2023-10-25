long switch_eg(long x, long y, long z) {
	long w = 1;
	switch (x) {
		case 3:
			w = 1 + z;
			break;
		case 1:
			w = y * z;
			break;
		case 2:
			w = y / z + z;
			break;
		default:
			w = 2;
			break;
	}
	return w;
}
