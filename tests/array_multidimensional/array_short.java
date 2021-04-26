class array_short{
    public static void main(String[] args){
        short[][] mat = new short[2][2];
        mat[0][0] = 123;
        mat[0][1] = 243;
        mat[1][0] = -243;
        mat[1][1] = 10;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}