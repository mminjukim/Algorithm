import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        StringBuilder sb = new StringBuilder();

        Stack<Character> stack = new Stack<>();
        String str = br.readLine();

        int pieceCount = 0;

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '(') {
                stack.push(ch);
            } else {
                stack.pop();
                if (isRazor(str, i)) {
                    pieceCount += stack.size();
                } else {
                    pieceCount++;
                }
            }
        }

        System.out.println(pieceCount);
        br.close();
    }

    private boolean isRazor(String str, int index) {
        return str.charAt(index - 1) == '(';
    }
}