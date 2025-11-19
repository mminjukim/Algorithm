import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {

            int N = Integer.parseInt(br.readLine());
            ArrayList<Member> members = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                members.add(new Member(a, b));
            }

            Collections.sort(members);

            int minThanThis = N + 1;
            int cnt = 0;

            for (Member m : members) {
                if (m.b <= minThanThis) {
                    minThanThis = m.b;
                    cnt++;
                }
            }

            sb.append(cnt).append("\n");
        }

        System.out.println(sb);
        br.close();
    }

    private static class Member implements Comparable<Member> {

        int a;
        int b;

        public Member(int a, int b) {
            this.a = a;
            this.b = b;
        }

        @Override
        public int compareTo(Member o) {
            return Integer.compare(this.a, o.a);
        }
    }
}