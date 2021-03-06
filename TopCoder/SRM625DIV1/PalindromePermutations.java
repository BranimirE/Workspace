import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class PalindromePermutations
{
    BigInteger factorial(int n){
        BigInteger ans = BigInteger.ONE;
        for(int i = 2; i <= n; i++)
            ans = ans.multiply(BigInteger.valueOf(i));
        return ans;
    }
    public double palindromeProbability(String cad){
        ArrayList<Integer>   par = new ArrayList<>();
        ArrayList<Integer> impar = new ArrayList<>();
        ArrayList<Integer> total = new ArrayList<>();
        for(char car = 'a'; car <= 'z'; car++){
            int cnt = 0;
            for(int i = 0; i < cad.length(); i++)
                if(cad.charAt(i) == car)
                    cnt++;

            if(cnt % 2 == 0) par.add(cnt);
            else    		 impar.add(cnt);

            total.add(cnt);
        }

        if(cad.length() % 2 == 0){//par?
            if(impar.size() != 0)//todos tienen que ser pares
                return 0;
        }else{
            if(impar.size() > 1)//solo uno puede ser impar
                return 0;
        }

        //Numero de anagramas
        BigInteger num = factorial(cad.length()), numden = BigInteger.ONE;
        for(int i = 0; i < total.size(); i++)
            numden = numden.multiply(factorial(total.get(i)));
        num = num.divide(numden);
        //Numero de palindromes
        BigInteger den = factorial(cad.length() / 2), denden = BigInteger.ONE;
        for(int i = 0; i < total.size(); i++)
            denden = denden.multiply(factorial(total.get(i) / 2));
        den = den.divide(denden);
        return new BigDecimal(den).divide(new BigDecimal(num), new MathContext(35)).doubleValue();
    }
    // BEGIN KAWIGIEDIT TESTING
    // Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
    private static boolean KawigiEdit_RunTest(int testNum, String p0, boolean hasAnswer, double p1) {
        System.out.print("Test " + testNum + ": [" + "\"" + p0 + "\"");
        System.out.println("]");
        PalindromePermutations obj;
        double answer;
        obj = new PalindromePermutations();
        long startTime = System.currentTimeMillis();
        answer = obj.palindromeProbability(p0);
        long endTime = System.currentTimeMillis();
        boolean res;
        res = true;
        System.out.println("Time: " + (endTime - startTime) / 1000.0 + " seconds");
        if (hasAnswer) {
            System.out.println("Desired answer:");
            System.out.println("\t" + p1);
        }
        System.out.println("Your answer:");
        System.out.println("\t" + answer);
        if (hasAnswer) {
            res = answer == answer && Math.abs(p1 - answer) <= 1e-9 * Math.max(1.0, Math.abs(p1));
        }
        if (!res) {
            System.out.println("DOESN'T MATCH!!!!");
        } else if ((endTime - startTime) / 1000.0 >= 2) {
            System.out.println("FAIL the timeout");
            res = false;
        } else if (hasAnswer) {
            System.out.println("Match :-)");
        } else {
            System.out.println("OK, but is it right?");
        }
        System.out.println("");
        return res;
    }
    public static void main(String[] args) {
        boolean all_right;
        all_right = true;

        String p0;
        double p1;

        // ----- test 0 -----
        p0 = "haha";
        p1 = 0.3333333333333333D;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------

        // ----- test 1 -----
        p0 = "xxxxy";
        p1 = 0.2D;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------

        // ----- test 2 -----
        p0 = "xxxx";
        p1 = 1.0D;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------

        // ----- test 3 -----
        p0 = "abcde";
        p1 = 0.0D;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------

        // ----- test 4 -----
        p0 = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
        p1 = 0.025641025641025637D;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------

        if (all_right) {
            System.out.println("You're a stud (at least on the example cases)!");
        } else {
            System.out.println("Some of the test cases had errors.");
        }
    }
    // END KAWIGIEDIT TESTING
}
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
