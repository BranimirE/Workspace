import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	static BigInteger root(int i, BigInteger x){
		return new BigInteger(Long.toString((long)Math.pow(x.doubleValue(), 1.0 / (double)i)));
	}
	static BigInteger root2(int i, BigInteger num){
		BigInteger x = BigInteger.ONE, 
				iminusone = new BigInteger(Integer.toString(i-1)),
				ibignum = new BigInteger(Integer.toString(i));
		
		boolean decreased = false;
		while(true){
			BigInteger nx = num.divide(x.pow(i - 1)).add(x.multiply(iminusone)).divide(ibignum);
			if(nx.equals(x) || nx.compareTo(x) > 0 && decreased)
				break;
			decreased = nx.compareTo(x) < 0;
			x = nx;
		}
		return x;
	}
	static BigInteger MOD = new BigInteger("1000000007");
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- > 0){
			int n, q;
			n = in.nextInt();
			q = in.nextInt();
			BigInteger[] a = new BigInteger[n];
			for(int i = 0; i < n; i++)
				a[i] = in.nextBigInteger();
			while(q-- > 0){
				BigInteger x = in.nextBigInteger();
				BigInteger ans = BigInteger.ZERO;
				for(int i = 1; i <= n; i++)
					ans = ans.add(root2(i, x).multiply(a[i-1]));
				System.out.println(ans.mod(MOD));
			}
		}
	}

}
/*
1
3 2
4 5 6
8 30

*/