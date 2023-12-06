public class _14HeapSort {
    
    private static void swap(int[] A, int node1, int node2)
    {
        int tempNum = A[node1];
        A[node1] = A[node2];
        A[node2] = tempNum;
    }

    private static void shiftDown(int[] A, int startNode, int endNode)
    {
        int r = startNode;
        int leftChild;
        int s;

        while (2 * r <= endNode) {
            leftChild = 2 * r;
            s = r;

            if (A[s] < A[leftChild])
                s = leftChild;

            if ((leftChild + 1) <= endNode && A[s] < A[leftChild + 1])
                s = leftChild + 1;

            if (s != r)
            {
                swap(A, s, r);
                r = s;
            }
            else
                break;
            
        }
    }
    
    private static void heapify(int[] A)
    {
        int n = A.length;
        int start = (n + 1) / 2;

        while (start > 0) {
            shiftDown(A, start, n - 1);
            start -= 1;
        }
    }
    
    public static void heapSort(int[] A)
    {
        heapify(A);
        int r = A.length - 1;

        while (r > 1) 
        {
            swap(A, 1, r);
            r -= 1;
            shiftDown(A, 1, r);
        }
    }

    public static void showArr(int[] A) {
        int n = A.length;
        for (int i = 1; i < n; ++i)
            System.out.print(A[i] + " ");

        System.out.println();
    }

    public static void main(String[] args) {
        int[] A = {-1,12,18,4,27,32,26,11,6,8,19};
        heapSort(A);
        showArr(A);
    }
}
