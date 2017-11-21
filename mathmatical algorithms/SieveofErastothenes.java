import java.util.*;
class SieveofErastothenes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int i = 0;
		boolean[] prime = new boolean[n];
		for(i = 2; i<n; i++)
			prime[i] = true;
		for(i = 0; i*i<n; i++) {
			if(prime[i]) {
				for(int j = 2*i; j<n; j+=i)
					prime[j] = false;
			}
		}
		for(i = 2; i<n; i++) {
			if(prime[i]) {
				System.out.print(i + " ");
			}
		}
	}
}
