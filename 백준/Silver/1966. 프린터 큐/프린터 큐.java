import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int testCases = Integer.parseInt(br.readLine());

        for (int t = 0; t < testCases; t++) {

            StringTokenizer st = new StringTokenizer(br.readLine());

            // 문서 개수, 궁금한 문서의 인덱스
            int n = Integer.parseInt(st.nextToken());
            int targetIndex = Integer.parseInt(st.nextToken());

            Queue<Element> q = new LinkedList<>();
            ArrayList<Integer> priorities = new ArrayList<>();

            // 큐에 모든 문서 추가
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                int priority = Integer.parseInt(st.nextToken());
                q.add(new Element(priority, i));
                priorities.add(priority);
            }

            List<Integer> orderedPriorities = priorities.stream()
                    .sorted(Collections.reverseOrder())
                    .collect(Collectors.toList());
            int maxPriority = orderedPriorities.get(0); // 현재 가장 높은 우선순위 값

            int order = 0; // 출력 순서
            while (true) {
                // 가장 높은 우선순위가 아니라면 출력하지 말고 맨 뒤로 이동
                if (!q.isEmpty() && q.peek().priority < maxPriority) {
                    q.add(q.remove());
                }
                // 출력할 우선순위인 경우
                else if (!q.isEmpty() && q.peek().priority == maxPriority) {
                    Element element = q.remove();
                    order++;
                    // 방금 출력된 문서가 궁금한 문서였다면 출력된 순서를 저장하고 break
                    if (element.index == targetIndex) {
                        sb.append(order).append("\n");
                        break;
                    }
                    // 아니라면 출력하고 우선순위를 다음으로 내림
                    maxPriority = orderedPriorities.get(order);
                }
            }
        }

        System.out.println(sb);
        br.close();
    }

    private static class Element {

        int priority;
        int index;

        public Element(int priority, int index) {
            this.priority = priority;
            this.index = index;
        }
    }
}