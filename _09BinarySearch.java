public class _09BinarySearch {
    
    public static int binarySearch(int[] list, int key, int lower, int upper) {
        if (upper<lower)
            return -1;
        else {
            int mid = (upper + lower) / 2;
            if(list[mid]>key)
                return binarySearch(list, key, lower, mid-1);
            else if (list[mid]<key)
                return binarySearch(list, key, mid+1, upper);
            else
                return mid;
        }
    }

    public static void main(String[] args) {
        int list[] = { 2, 6, 9, 11, 14, 17, 20, 33, 42, 47, 50, 56, 57 };
        int key = 57;
        System.out.println(binarySearch(list, key, 0, list.length-1));
    }
}
