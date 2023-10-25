package tictactoe;

public class TicTacToe {
    int[][] arr;

    TicTacToe() {
        arr = new int[3][3];
    }

    public int place(int player, int row, int col) {
        if (arr[row][col] > 0)
            return 3;
        arr[row][col] = player;
        if (win(player))
            return player;
        return 0;
    }

    boolean win(int player) {
        for (int i = 0; i < 3; i++) {
            if (rowsame(i, player))
                return true;
            if (colsame(i, player))
                return true;
            if (diagsame(i, player))
                return true;
        }
        return false;
    }

    boolean rowsame(int x, int player) {
        for (int i = 0; i < 3; i++)
            if (arr[x][i] != player)
                return false;
        return true;
    }

    boolean colsame(int x, int player) {
        for (int i = 0; i < 3; i++)
            if (arr[i][x] != player)
                return false;
        return true;
    }

    boolean diagsame(int x, int player) {
        if (x == 0) {
            for (int i = 0; i < 3; i++)
                if (arr[i][i] != player)
                    return false;
            return true;
        } else {
            for (int i = 0; i < 3; i++)
                if (arr[i][2 - i] != player)
                    return false;
            return true;
        }
    }
}