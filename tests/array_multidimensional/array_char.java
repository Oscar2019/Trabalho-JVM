class array_char{
    public static void main(String[] args){
        char[][] mat = new char[2][2];
        mat[0][0] = '1';
        mat[0][1] = '木';
        mat[1][0] = '1';
        mat[1][1] = 'c';
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}