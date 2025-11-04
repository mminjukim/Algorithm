import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int k = Integer.parseInt(br.readLine());
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < k; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if (n == 0) {
                stack.pop();
            } else {
                stack.push(n);
            }
        }

        int sum = 0;
        while (!stack.isEmpty()) {
            sum += stack.pop();
        }
        sb.append(sum);

        System.out.println(sb);
        br.close();
    }
}