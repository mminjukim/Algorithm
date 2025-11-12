import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int testCases = Integer.parseInt(br.readLine());

        for (int t = 0; t < testCases; t++) {

            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String originalArr = br.readLine();
            originalArr = originalArr.substring(1, originalArr.length() - 1);

            String[] str = originalArr.split(",");
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                if (!str[i].isBlank())
                    arr[i] = Integer.parseInt(str[i]);
            }

            boolean error = false;
            boolean reversed = false;
            int start_pointer = 0;
            int end_pointer = arr.length - 1;

            for (int i = 0; i < p.length(); i++) {
                char c = p.charAt(i);
                switch (c) {
                    case 'R':
                        reversed = !reversed;
                        break;
                    case 'D':
                        if (end_pointer - start_pointer < 0) {
                            sb.append("error\n");
                            error = true;
                            i = p.length() + 2;
                        } else {
                            if (reversed) {
                                end_pointer--;
                            } else {
                                start_pointer++;
                            }
                        }
                        break;
                }
            }

            if (!error) {
                sb.append("[");
                if (reversed) {
                    for (int i = end_pointer; i >= start_pointer; i--) {
                        sb.append(arr[i]);
                        if (i != start_pointer) {
                            sb.append(",");
                        }
                    }
                } else {
                    for (int i = start_pointer; i <= end_pointer; i++) {
                        sb.append(arr[i]);
                        if (i != end_pointer) {
                            sb.append(",");
                        }
                    }
                }
                sb.append("]\n");
            }
        }

        System.out.println(sb);
        br.close();
    }
}