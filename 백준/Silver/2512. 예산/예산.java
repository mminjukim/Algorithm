import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] budgetRequests = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int highestBudgetReq = -1;
        for (int i = 0; i < N; i++) {
            int budgetReq = Integer.parseInt(st.nextToken());
            budgetRequests[i] = budgetReq;
            if (budgetReq > highestBudgetReq) {
                highestBudgetReq = budgetReq;
            }
        }
        int govBudget = Integer.parseInt(br.readLine());

        int right = highestBudgetReq;
        int left = 1;
        int budgetLimit = -1;

        while (left <= right) {
            int budgetTotal = 0;
            int middle = (left + right) / 2;
            for (int i = 0; i < N; i++) {
                budgetTotal += Math.min(budgetRequests[i], middle);
            }
            if (budgetTotal > govBudget) {
                right = middle - 1;
            } else {
                if (middle > budgetLimit) {
                    budgetLimit = middle;
                }
                left = middle + 1;
            }
        }

        System.out.println(Math.min(highestBudgetReq, budgetLimit));
    }
}