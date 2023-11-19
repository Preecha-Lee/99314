import java.util.Stack;

public class _09nQueens {
    
    public static boolean validPosition(int col, Stack<Integer> S, int boardSize) {

        if (col > boardSize)
            return false;

        for (int i = 0; i < S.size(); ++i) {
            if (col == S.get(i) || (Math.abs(col - S.get(i)) == S.size() - i))
                return false;
        }

        return true;
    }
    
    public static void printBoard(Stack<Integer> S) {
        for (int i = 0; i < S.size(); ++i) {
            int col = S.get(i);
            for (int j = 0; j < S.size(); ++j) {
                if (j + 1 == col)
                    System.out.print("X");
                else
                    System.out.print("-");
            }
            System.out.println();
        }
    }

    public static int nQueens(int boardSize) {
        Stack<Integer> S = new Stack<Integer>();
        int row = 1;
        int col = 0;

        while (row <= boardSize) {
            col += 1;

            if (validPosition(col, S, boardSize)) {
                S.push(col);
                row += 1;
                col = 0;
            }

            if (col > boardSize) {
                if(!S.isEmpty())
                    col = S.pop();
                
                row -= 1;
            }

            if (row < 1) {
                System.out.println("Could not find a solution");
                return -1;
            }
            

        }

        printBoard(S);
        return 0;
    }

    public static void main(String[] args) {
        nQueens(5);
    }
}
