import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Set<String> nSet = new HashSet<>();
        Set<String> mSet = new HashSet<>();

        for (int i = 0; i < N; i++) {
            String name = br.readLine();
            nSet.add(name);
        }
        for (int i = 0; i < M; i++) {
            String name = br.readLine();
            mSet.add(name);
        }

        nSet.retainAll(mSet);
        ArrayList<String> result = new ArrayList<>(nSet);
        Collections.sort(result);

        sb.append(result.size()).append("\n");
        for (String name : result) {
            sb.append(name).append("\n");
        }

        System.out.println(sb);
        br.close();
    }
}