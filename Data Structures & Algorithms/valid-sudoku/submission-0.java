class Solution {
    public boolean isValidSudoku(char[][] board) {
        List<Set<Character>> clmSet = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            clmSet.add(new HashSet<>());
        }

        List<Set<Character>> boxSet = new ArrayList<>();

        for (int i = 0; i < 9; i++) {
            boxSet.add(new HashSet<>());
        }
        
        for(int i = 0; i < 9; i++){
            Set<Character> rowSet = new HashSet<>();
            for(int j = 0; j < 9; j++){
                if(Character.isDigit(board[i][j])){

                
                int box = (3 * (i / 3)) + (j / 3);
                if(rowSet.contains(board[i][j]) ||                  clmSet.get(j).contains(board[i][j])
                || boxSet.get(box).contains(board[i][j])){
                    return false;
                }
                rowSet.add(board[i][j]);
                clmSet.get(j).add(board[i][j]);
                boxSet.get(box).add(board[i][j]);
                }

            }
        }
        return true;
        
    }
}
