/**
 * @author Christian Müller for GCPC 2017
 */

import java.math.BigInteger;
import java.util.Scanner;

public class BuildingsBetterBigInteger {

	static final BigInteger MOD = BigInteger.valueOf(1000000007); // MOD ^ 2 fits into long
	
	public static long gcd(long a, long b) {
		return (b == 0) ? Math.abs(a) : gcd(b, a % b);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long m = sc.nextLong();
		BigInteger c = sc.nextBigInteger();

		// number of c-colorings of an n by n square
		BigInteger col = c.modPow(BigInteger.valueOf(n * n), MOD);
		
		// number of possible necklaces different up to rotation with m beads in
		// col different colors
		BigInteger sum = BigInteger.ZERO;
		for (long i = 0; i < m; i++) {

			BigInteger gcd = BigInteger.valueOf(gcd(m, i)); // gcd < m
			BigInteger part = col.modPow(gcd, MOD);
			sum = sum.add(part);
		}
		BigInteger valm = BigInteger.valueOf(m);
		BigInteger minv = valm.modInverse(MOD);
		sum = sum.multiply(minv); // result is integral (Burnsides lemma)

		System.out.println(sum.mod(MOD));
		sc.close();
	}
}
