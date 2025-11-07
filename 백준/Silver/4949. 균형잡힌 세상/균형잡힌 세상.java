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

        Stack<Character> stack = new Stack<>();

        String str = br.readLine();

        while (!str.equals(".")) {
            boolean valid = true;
            stack.clear();

            for (int j = 0; j < str.length(); j++) {
                char ch = str.charAt(j);
                if (ch == '(' || ch == '[') {
                    stack.push(ch);
                } else if (ch == ')' || ch == ']') {
                    if (!stack.empty()) {
                        char pop = stack.pop();
                        if (ch == ')' && pop != '(') {
                            valid = false;
                            break;
                        } else if (ch == ']' && pop != '[') {
                            valid = false;
                            break;
                        }
                    } else {
                        valid = false;
                        break;
                    }
                }
            }

            if (!stack.empty()) {
                sb.append("no\n");
            } else if (valid) {
                sb.append("yes\n");
            } else {
                sb.append("no\n");
            }

            str = br.readLine();
        }

        System.out.println(sb);
        br.close();
    }
}