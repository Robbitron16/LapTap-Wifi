import java.math.BigInteger;

public class Decoder {
	public static void main(String[] args) {
		BigInteger res = new BigInteger(args[0]);
		String range = args[1];
		res = res.multiply(new BigInteger("" + 4259870));
		long number = res.longValue();
		StringBuilder sb = new StringBuilder();
		while (number != 0) {
			sb.append(range.charAt((int) (number % range.length())));
	        number /= range.length();
		}
		sb = sb.reverse();
		sb.insert(2, '\\');
		System.out.println(sb);
	}
}
