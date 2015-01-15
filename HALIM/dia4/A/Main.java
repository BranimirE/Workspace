import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		while(in.hasNextLine()){
			String cad = in.nextLine();
			cad = cad.replaceFirst("da+dd?(i|y)","");
			if(cad.length() == 0)
				System.out.println("She called me!!!");
			else
				System.out.println("Cooing");
		}
	}
}
