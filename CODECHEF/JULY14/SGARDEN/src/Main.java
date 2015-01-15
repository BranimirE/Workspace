import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	static final int MAX = 100000;
	static final BigInteger MOD = new BigInteger("1000000007");
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static String buf[];
	static int vec[] = new int[MAX];
	static boolean v[] = new boolean[MAX];
	public static BigInteger lcm(BigInteger a, BigInteger b){
		return a.multiply(b.divide(a.gcd(b)));
	}
	public static void main(String[] args) throws Exception {
		int t = Integer.parseInt(in.readLine());
		while(t-->0){
			int n = Integer.parseInt(in.readLine());
			buf = in.readLine().split(" ");
			for(int i = 0; i < n; i++){
				vec[i] = Integer.parseInt(buf[i]) - 1;
				v[i] = true;
			}
			BigInteger ans = BigInteger.ONE;
			for(int i = 0; i < n; i++)
				if(v[i]){
					int cnt = 1;
					int sig = vec[i];
					while(sig != i){
						cnt++;
						sig = vec[sig];
					}
					ans = lcm(ans, BigInteger.valueOf(cnt));
				}
			System.out.println(ans.mod(MOD));
		}
	}
}
