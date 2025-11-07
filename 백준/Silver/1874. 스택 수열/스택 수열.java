import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Stack<Integer> stack = new Stack<>();

        int n = Integer.parseInt(br.readLine());

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        int arrIdx = 0;
        int nextPushingNumber = 1;

        while (arrIdx < n) {
            if (nextPushingNumber <= arr[arrIdx]) {
                for (; nextPushingNumber <= arr[arrIdx]; nextPushingNumber++) {
                    stack.push(nextPushingNumber);
                    sb.append("+\n");
                }
            }
            if (stack.peek() == arr[arrIdx]) {
                stack.pop();
                sb.append("-\n");
                arrIdx++;
            } else {
                sb.delete(0, sb.length());
                sb.append("NO\n");
                break;
            }
        }

        System.out.println(sb);
        br.close();
    }
}