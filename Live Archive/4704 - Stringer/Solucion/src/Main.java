import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	static final int MAXN = 21;
	static long cant[] = new long[MAXN];
	static int n;
	static long k;
	static BigInteger factorial(long sum){
		BigInteger ans = BigInteger.ONE;
		while(sum != 0){
			ans = ans.multiply(BigInteger.valueOf(sum));
			sum--;
		}
		return ans;
	}
	static long calcular(){
		long sum = 0;
		BigInteger den = BigInteger.ONE, num;
		for(int i = 0; i < n; i++){
			sum += cant[i];
			den = den.multiply(factorial(cant[i]));
		}
		num = factorial(sum).divide(den);
		if(num.compareTo(BigInteger.valueOf(Integer.MAX_VALUE))>0)
			return Integer.MAX_VALUE;
		return num.divide(den).longValue();
	}
	static String solve(long l){
		System.out.println("entra");
		long sum = 0;
		for(int i = 0; i < n; i++){
			if(cant[i] != 0){
				cant[i]--;
				System.out.println("lugar 1");
				long tmp = calcular();
				System.out.println("lugar 2");
				//System.out.println("tmp = " + tmp);
				if(sum + tmp <= l){
					sum += tmp;
					cant[i]++;
				}
				else{
					System.out.println("va a retornar con "+(char)('a'+i));
					return (""+((char)('a'+i)))+ solve(l-sum);
				}
			}
		}
		return "";
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(true){
			n = in.nextInt();
			k = in.nextInt();
			if(n == 0 && k == 0)break;
			//long backup[] = new long [cant.length];
			for(int i = 0; i < n; i++){
				cant[i] = in.nextInt();
//				backup[i] = cant[i];
			}
			
			//long lim = calcular();
		//	for(k = 0; k < lim; k++){
	//			for(int i = 0; i < n; i++)cant[i] = (int) backup[i];
				System.out.println(solve(k));
			//}
		}
	}
}
/*
2 5 
2 3 
3 0 
2 3 1
0 0

20 0
7 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

*/