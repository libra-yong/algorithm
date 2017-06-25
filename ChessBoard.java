import java.io.IOException;

/**
* @author: libra天秤
* create on 2017年6月3日 上午11:06:19
* github: https://github.com/libra-yong/demo
*/
public class ChessBoard {
	public static int N = 16;
	public static int count = 0;
	public static char[] title = new char[]{
			'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
			'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};
	public char[][] board = new char[N][N];
	public void chessBoard(int tr, int tc, int dr, int dc, int size) {
		char t = title[(count++) % 26];
		int s = size / 2;
		if (size == 1) {
//			board[tr][tc] = t;
			return;
		}
		//覆盖左上角棋盘
		if (dr < tr + s && dc < tc + s) {
			chessBoard(tr, tc, dr, dc, s);
		} else {
			board[tr + s - 1][tc + s - 1] = t;
			chessBoard(tr, tc, tr + s -1, tc + s - 1, s);
		}
		
		//覆盖右上角棋盘
		if (dr < tr + s && dc >= tc + s) {
			chessBoard(tr, tc + s, dr, dc, s);
		} else {
			board[tr + s - 1][tc + s] = t;
			chessBoard(tr, tc + s, tr + s - 1, tc + s, s);
		}
		
		//覆盖左下角棋盘
		if (dr >= tr + s && dc < tc + s) {
			chessBoard(tr + s, tc + s, dr, dc, s);
		} else {
			board[tr + s][tc + s - 1] = t;
			chessBoard(tr + s, tc, tr + s, tc + s - 1, s);
		}
		
		//覆盖右下角棋盘
		if (dr >= tr + s && dc >= tc + s) {
			chessBoard(tr + s, tc + s, dr, dc, s);
		} else {
			board[tr + s][tc + s] = t;
			chessBoard(tr + s, tc + s, tr + s, tc + s, s);
		}
	}

	public static void main(String[] args) throws IOException {
		ChessBoard chessBoard = new ChessBoard();
//		int a = System.in.read();
//		for (int i = 0; i < chessBoard.N; i++) {
//			for (int j = 0; j < chessBoard.N; j++) {
//				chessBoard.board[i][j] = 0;
//			}
//		}
		chessBoard.chessBoard(0, 0, 1, 1, 8);
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				System.out.printf("%5c", chessBoard.board[i][j]);
			}
			System.out.println();
		}
	}

}
