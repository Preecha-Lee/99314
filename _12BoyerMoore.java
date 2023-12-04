public class _12BoyerMoore {

    private static int[] createOcc(String P) {
        int m = P.length();
        int[] occ = new int[256];

        for (int i = 0; i < 256; i++)
            occ[i] = -1;

        int a;
        for (int j = 0; j < m; j++) {
            a = (int) P.charAt(j);
            occ[a] = j;
        }

        return occ;
    }
    
    private static int[][] preBoyerMoore1(String P) {
        int m = P.length();
        int i = m;
        int j = m + 1;

        int[][] fs = new int[m + 1][2];
        for (int k = 0; k < m + 1; ++k)
            fs[k][1] = 0;

        fs[i][0] = j;

        while (i > 0) {
            while (j <= m && (P.charAt(i - 1) != P.charAt(j - 1))) {
                if (fs[j][1] == 0) {
                    fs[j][1] = j - i;
                    //System.out.println("s[" + j + "] = " + fs[j][1]);
                }

                j = fs[j][0];
            }

            i -= 1;
            j -= 1;
            fs[i][0] = j;
        }

        return fs;
    }
    
    private static void preBoyerMoore2(int[][] fs) {
        int m = fs.length - 1;
        int j = fs[0][0];

        for (int i = 0; i <= m; i++) {
            if (fs[i][1] == 0)
                fs[i][1] = j;

            if (i == j)
                j = fs[j][0];
        }

    }
    
    private static int[] preBoyerMoore(String P)
    {
        int[][] fs = preBoyerMoore1(P);
        preBoyerMoore2(fs);

        int[] s = new int[fs.length];
        for (int i = 0; i < fs.length; i++)
            s[i] = fs[i][1];

        return s;
    }

    public static void boyerMoore(String T, String P) {
        int n = T.length();
        int m = P.length();

        int i = 0;
        int j;
        int[] s = preBoyerMoore(P);
        int[] occ = createOcc(P);

        while (i <= n-m) {
            j = m - 1;

            while (j>=0 && P.charAt(j)==T.charAt(i+j))
                j -= 1;
            
            if (j < 0) {
                System.out.println(i);
                i += s[0];
            }
            else {
                i = i + Math.max(s[j + 1], j - occ[(int) T.charAt(i + j)]);
            }
        }

    }

    public static void main(String[] args) {
        String P = "*bbabab";
        String T = "fvgg*bbababaaababbababdda";

        boyerMoore(T, P);
    }

}