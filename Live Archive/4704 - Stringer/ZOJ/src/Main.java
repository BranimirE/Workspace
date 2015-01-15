import java.math.BigInteger;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.Vector;


public class Main {
	static final int MAXPRIME = 10005; 
	static boolean criba[] = new boolean[MAXPRIME] ;

	static Vector<Long> primos;
	static Vector<Long> f;
	static TreeSet<Long> set = new TreeSet<Long>();
	static void llena_criba()
	{
		for(int i = 2; i < MAXPRIME; i++)
			criba[i] = true;
		for (int i = 2; i < MAXPRIME; i++)
			if (criba[i])
			{
				primos.add((long) i);
				for (int j= i + i; j<MAXPRIME; j += i)
					criba[j] =  false;
			}
	}
	static void factorizar(long n){

		f.clear();
		int i = 0;
		while(i < primos.size() && (primos.get(i)*primos.get(i)) <= n){
			while(n%primos.get(i) == 0){
				f.add(primos.get(i));
				n /= primos.get(i);
			}
			i++;
		}
		if(n > 1){
			f.add(n);
		}
	}
	static BigInteger bi(long a){
		return BigInteger.valueOf(a);
	}
	static long solve(long n){
		factorizar(n);
		/*for(int i = 0; i < f.size(); i++){
			if(i != 0)System.out.print(" * ");
			System.out.print(f.get(i));
		}
		System.out.println("");
*/
		
		BigInteger ans = BigInteger.ZERO, N = bi(n);
		ans = bi(n).multiply(bi(n+1));
		ans = ans.multiply((bi(2).multiply(bi(n))).add(bi(1)));
		ans = ans.multiply(((bi(3).multiply(N).multiply(N)).add(bi(3).multiply(N))).subtract(bi(1)));
		ans = ans.divide(bi(30));
		//System.out.println("la suma de potencias de 4 hasta"+ n +" es = "+ans);
		int tam = f.size();
		long lim = (1 << tam);
		set.clear();
		for(int mask = 0; mask < lim; mask++){
			long mul = 1;
			for(int i = 0; i < tam; i++)
				if((mask & (1<<i)) != 0)
					mul *= f.get(i);
			if(mul != 1 && !set.contains(mul)){
				//System.out.println("le resta "+mul);
				ans = ans.subtract(bi(mul).pow(4));
				set.add(mul);
			}
		}
		return ans.mod(bi(1000000007L)).longValue();
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		primos = new Vector<Long>();
		f= new Vector<Long>();
		llena_criba();

		int t;
		long n;
		t = in.nextInt();
		while(t-- > 0){	
			n = in.nextLong();
			System.out.println(solve(n));
		}

	}

}
/*
2
4
5
 */