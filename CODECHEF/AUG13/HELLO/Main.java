import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	
	final static int MAXP = 101;
	static int meses[] = new int[MAXP];
	static double rpm[] = new double[MAXP];//rupias por minuto
	static int actv[] = new int[MAXP];
	static double tb; //tarifa basica
	static long mu; // minutos ultimo mes
	static int prom; // promociones
	static BigInteger futuro = BigInteger.ZERO;
	
	static BigDecimal solve(int mes, double tarifa, int activacion){
		BigInteger activaciones = (futuro.divide(BigInteger.valueOf(mes))).multiply(BigInteger.valueOf(activacion));
		BigDecimal gasto = new BigDecimal(futuro.multiply(BigInteger.valueOf(mu))).multiply(BigDecimal.valueOf(tarifa));
		return gasto.add(new BigDecimal(activaciones));
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- != 0){
			tb = in.nextDouble();
			mu = in.nextLong();
			prom = in.nextInt();
			futuro = BigInteger.ONE;
			for(int i = 1; i <= prom; ++i){
				meses[i] = in.nextInt();
				rpm[i] = in.nextDouble();
				actv[i] = in.nextInt();
				futuro = futuro.multiply(BigInteger.valueOf(meses[i]));
			}
			int sol = 0;
			BigDecimal best = (new BigDecimal(tb * mu)).multiply(new BigDecimal(futuro));
			
			for(int i = 1; i <= prom; ++i){
				BigDecimal actual = solve(meses[i], rpm[i], actv[i]); 
				if(actual.compareTo(best) < 0){
					best = actual;
					sol = i;
				}
			}
			System.out.println(sol);
		}
		
	}
}
