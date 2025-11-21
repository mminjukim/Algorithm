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
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        long[] lines = new long[K];
        long max = Integer.MIN_VALUE;
        long min = 1;

        for (int i = 0; i < K; i++) {
            lines[i] = Integer.parseInt(br.readLine());
            max = Math.max(max, lines[i]);
        }

        long answer = Integer.MIN_VALUE;

        while (min <= max) {
            long divider = (max + min) / 2;
            long lineCount = 0;
            for (int i = 0; i < K; i++) {
                lineCount += lines[i] / divider;
            }
            if (lineCount < N) {
                max = divider - 1;
            } else {
                answer = Math.max(answer, divider);
                min = divider + 1;
            }
        }

        System.out.println(answer);
        br.close();
    }
}