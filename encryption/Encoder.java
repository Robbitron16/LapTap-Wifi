import java.math.BigInteger;
import java.util.Set;
import java.util.TreeSet;

public class Encoder {
	public static void main(String[] args) {
		String range = "";
		String text = args[0];
		Set<Character> dict = new TreeSet<Character>();
		for (char c : text.toCharArray()) {
			dict.add(c);
		}
		for (char c : dict) {
			range += c;
		}
		BigInteger res = BigInteger.ZERO;
		final BigInteger size = new BigInteger("" + range.length());
		for (char c : text.toCharArray()) {
			res = res.multiply(size);
			res = res.add(new BigInteger("" + range.indexOf(c)));
		}
		res = res.divide(new BigInteger("" + 4259870));
		System.out.println(res + " " + range);
	}
}
