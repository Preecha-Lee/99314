public class _12Levenshtein {
    private static int substitutionCost(String source, String target, int[][] tab, int row, int col)
    {
        int cost = 0;
        if (source.charAt(row - 1) != target.charAt(col - 1))
            cost = 1;

        return tab[row - 1][col - 1] + cost;
    }
    
    private static int deleteCost(String source, String target, int[][] tab, int row, int col)
    {
        return tab[row - 1][col] + 1;
    }

    private static int insertCost(String source, String target, int[][] tab, int row, int col)
    {
        return tab[row][col - 1] + 1;
    }

    private static int minCost(String source, String target, int[][] tab, int row, int col)
    {
        int mSub = substitutionCost(source, target, tab, row, col);
        int mDel = deleteCost(source, target, tab, row, col);
        int mInsert = insertCost(source, target, tab, row, col);
        int mCost = Math.min(mSub, Math.min(mDel, mInsert));

        return mCost;
    }

    public static int[][] levenshtein(String source, String target)
    {
        int sourceLength = source.length();
        int targetLength = target.length();
        int[][] tab = new int[sourceLength+1][targetLength+1];

        tab[0][0] = 0;
        for (int row = 1; row <= sourceLength; row++)
            tab[row][0] = row;

        for (int col = 1; col <= targetLength; col++)
            tab[0][col] = col;

        for (int row = 1; row <= sourceLength; row++)
            for (int col = 1; col <= targetLength; col++)
                tab[row][col] = minCost(source, target, tab, row, col);

        return tab;
    }
    
    public static void showTab(int[][] tab)
    {
        int numRow = tab.length;
        int numCol = tab[0].length;

        for (int i=0; i<numRow; ++i)
        {
            for(int j=0; j<numCol; ++j)
                System.out.print(tab[i][j] + " ");
            System.out.println();                
        }
    }

    public static void main(String[] args) {
        String source = "sittisak";
        String target = "sittichai";
        int[][] tab = levenshtein(source, target);
        showTab(tab);
    }
}
