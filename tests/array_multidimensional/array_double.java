class array_double{
    public static void main(String[] args){
        double[][] mat = new double[2][2];
        mat[0][0] = 3.1415;
        mat[0][1] = 6;
        mat[1][0] = 45.4;
        mat[1][1] = 0.00001;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}