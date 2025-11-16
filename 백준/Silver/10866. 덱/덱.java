import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        new Main().Solution();
    }

    public void Solution() throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Queue queue = new Queue();

        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String order = st.nextToken();

            if (order.equals("push_back")) {
                int n = Integer.parseInt(st.nextToken());
                queue.addRear(n);

            } else if (order.equals("push_front")) {
                int n = Integer.parseInt(st.nextToken());
                queue.addFront(n);

            } else if (order.equals("pop_front")) {
                int n = queue.deleteFront();
                sb.append(n).append("\n");

            } else if (order.equals("pop_back")) {
                int n = queue.deleteRear();
                sb.append(n).append("\n");

            } else if (order.equals("size")) {
                sb.append(queue.getSize()).append("\n");

            } else if (order.equals("empty")) {
                if (queue.isEmpty()) {
                    sb.append("1\n");
                } else {
                    sb.append("0\n");
                }

            } else if (order.equals("front")) {
                sb.append(queue.getFront()).append("\n");

            } else if (order.equals("back")) {
                sb.append(queue.getRear()).append("\n");
            }
        }

        System.out.println(sb);
        br.close();
    }

    static class Queue {

        int MAX_QUEUE_SIZE = 10001;
        int[] data;
        int front;
        int rear;

        public Queue() {
            data = new int[MAX_QUEUE_SIZE];
            this.front = 0;
            this.rear = 0;
        }

        int getSize() {
            return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
        }

        boolean isEmpty() {
            return front == rear;
        }

        boolean isNotFull() {
            return (rear + 1) % MAX_QUEUE_SIZE != front;
        }

        void addFront(int item) {
            if (isNotFull()) {
                data[front] = item;
                front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }

        void addRear(int item) {
            if (isNotFull()) {
                rear = (rear + 1) % MAX_QUEUE_SIZE;
                data[rear] = item;
            }
        }

        int deleteFront() {
            if (!isEmpty()) {
                front = (front + 1) % MAX_QUEUE_SIZE;
                return data[front];
            }
            return -1;
        }

        int deleteRear() {
            if (!isEmpty()) {
                int prev = rear;
                rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return data[prev];
            }
            return -1;
        }

        int getFront() {
            if (!isEmpty()) {
                return data[(front + 1) % MAX_QUEUE_SIZE];
            }
            return -1;
        }

        int getRear() {
            if (!isEmpty()) {
                return data[rear];
            }
            return -1;
        }
    }
}