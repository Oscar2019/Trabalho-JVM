class array_boolean{
    public static void main(String[] args){
        boolean[][] mat = new boolean[2][2];
        mat[0][0] = true;
        mat[0][1] = true;
        mat[1][0] = false;
        mat[1][1] = true;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}