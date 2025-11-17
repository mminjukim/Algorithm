import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        HashMap<Integer, String> numMap = new HashMap<>();
        HashMap<String, Integer> strMap = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            numMap.put(i + 1, name);
            strMap.put(name, i + 1);
        }

        for (int i = 0; i < M; i++) {
            String key = br.readLine();
            try {
                int n = Integer.parseInt(key);
                sb.append(numMap.get(n)).append('\n');
            } catch (NumberFormatException e) {
                sb.append(strMap.get(key)).append('\n');
            }
        }

        System.out.println(sb);
        br.close();
    }
}