public class _12LCS {
    
    private static int[][] LCSLength(String X, String Y)
    {
        int m = X.length();
        int n = Y.length();
        int[][] C = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
            C[i][0] = 0;

        for (int j = 0; j <= m; j++)
            C[0][j] = 0;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= m; j++)
                if (X.charAt(i - 1) == Y.charAt(j - 1))
                    C[i][j] = C[i - 1][j - 1] + 1;
                else
                    C[i][j] = Math.max(C[i][j - 1], C[i - 1][j]);

        return C;
    }
    
    public static String backTrack(int[][] C, String X, String Y, int i, int j) {
        if(i==0 || j==0)
            return "";
        else
        {
            if (X.charAt(i-1) == Y.charAt(j-1))
                return backTrack(C, X, Y, i - 1, j - 1) + X.charAt(i-1);
            else if (C[i][j-1]>C[i-1][j])
                return backTrack(C, X, Y, i, j-1);
            else
                return backTrack(C, X, Y, i-1, j);
        }
    }

    public static void showTab(int[][] tab)
    {
        int numRow = tab.length;
        int numCol = tab[0].length;

        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j)
                System.out.print(tab[i][j] + " ");
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        String X = "ABAZDC";
        String Y = "BACBAD";
        int[][] C = LCSLength(X, Y);
        showTab(C);
        System.out.println(backTrack(C, X, Y, X.length(), Y.length()));
    }
}
