class array_byte{
    public static void main(String[] args){
        byte[][] mat = new byte[2][2];
        mat[0][0] = 12;
        mat[0][1] = -10;
        mat[1][0] = 55;
        mat[1][1] = 0;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}