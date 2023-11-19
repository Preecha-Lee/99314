public class _09HanoiTower {
    public static void HanoiTower(int n, String source, String spare, String target) {
        if (n==1)
            System.out.println(source + " -> " + target);
        else {
            HanoiTower(n - 1, source, target, spare);
            System.out.println(source + " -> " + target);
            HanoiTower(n - 1, spare, source, target);
        }
            

    }

    public static void main(String[] args) {
        HanoiTower(3, "A", "C", "B");
    }
}
