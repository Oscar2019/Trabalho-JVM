class array_long{
    public static void main(String[] args){
        long[][] mat = new long[2][2];
        mat[0][0] = 1000000007L;
        mat[0][1] = -1000000007L;
        mat[1][0] = 1230;
        mat[1][1] = -156;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}