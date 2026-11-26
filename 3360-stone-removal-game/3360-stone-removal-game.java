class Solution {
    public boolean canAliceWin(int n) {
        return Math.round(Math.sqrt(110 - 2 * n)) % 2 == 1;
    }
}