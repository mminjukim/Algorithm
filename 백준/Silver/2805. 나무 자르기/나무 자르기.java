import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] lines = new int[N];
        long max = -1;
        long min = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            lines[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, lines[i]);
        }

        long answer = -1;

        while (min <= max) {
            long height = (max + min) / 2;
            long count = 0;
            for (int i = 0; i < N; i++) {
                if (lines[i] >= height) count += lines[i] - height;
            }
            if (count >= M) {
                min = height + 1;
                answer = Math.max(answer, height);
            } else {
                max = height - 1;
            }
        }

        System.out.println(answer);
        br.close();
    }
}