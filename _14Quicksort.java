public class _14Quicksort {

    private static void swap(int[] A, int node1, int node2)
    {
        int tempNum = A[node1];
        A[node1] = A[node2];
        A[node2] = tempNum;
    }

    private static void quickSort(int[] A, int indexStart, int indexEnd)
    {
        int first = indexStart;
        int last = indexEnd;
        int p;
        int pivot;

        if (indexEnd - indexStart >= 1) {
            p = indexStart;
            pivot = A[p];

            while (last > first) {
                while (A[first] <= pivot && last > first)
                    first += 1;

                while (A[last] > pivot && last >= first)
                    last -= 1;

                if (last > first)
                    swap(A, first, last);
            }

            swap(A, p, last);
            quickSort(A, indexStart, last - 1);
            quickSort(A, last + 1, indexEnd);
        }
    }
    
    public static void quickSortMain(int[] A)
    {
        int n = A.length;
        quickSort(A, 0, n - 1);
    }
    
    public static void showArr(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; ++i)
            System.out.print(A[i] + " ");

        System.out.println();
    }
    
    public static void main(String[] args) {
        //int[] A = { 3, 5, 4, 2, 9, 4, 7, 2, 1, 1, 3, 5 };
        int[] A = {12,18,4,27,32,26,11,6,8,19};
        quickSortMain(A);
        showArr(A);    
    }
}