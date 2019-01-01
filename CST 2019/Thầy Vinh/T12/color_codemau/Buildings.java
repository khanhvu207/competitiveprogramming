/**
 * @author Christian Müller for GCPC 2017
 */

import java.util.Scanner;

public class Buildings {

	static final long MOD = 1000000007; // MOD ^ 2 fits into long

	public static long gcd(long a, long b) {
		return (b == 0) ? Math.abs(a) : gcd(b, a % b);
	}

	// Fast Exponentiation: a ^ b modulo c
	static long powMod(long a, long b, long c) {

		long x = 1;
		long y = a;

		while (b > 0) {
			if (b % 2 == 1) {
				x = (x * y) % c;
			}
			y = (y * y) % c; // squaring the base
			b /= 2;
		}
		return x % c;
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long n = sc.nextLong();
		long m = sc.nextLong();
		long c = sc.nextLong();

		// number of c-colorings of an n by n square
		long col = powMod(c, n * n, MOD);

		// number of possible necklaces different up to rotation with m beads in
		// col different colors
		long sum = 0;
		for (long i = 0; i < m; i++) {

			long gcd = gcd(m, i); // gcd < m
			long part = powMod(col, gcd, MOD); // col ^ gcd may overflow
			sum = (sum + part) % MOD;
		}
		// sum / m = sum * m^{-1} = sum * m^{MOD - 2} (Euler). Result is integral (Burnside)
		long minv = powMod(m, MOD - 2, MOD);
		sum = (sum * minv) % MOD;		

		System.out.println(sum);
		sc.close();
	}
}
