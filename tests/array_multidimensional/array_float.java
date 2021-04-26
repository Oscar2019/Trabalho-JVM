class array_float{
    public static void main(String[] args){
        float[][] mat = new float[2][2];
        mat[0][0] = 3.14f;
        mat[0][1] = 12.3f;
        mat[1][0] = 123.f;
        mat[1][1] = -0.4f;
        System.out.println(mat[0][0]);
        System.out.println(mat[0][1]);
        System.out.println(mat[1][0]);
        System.out.println(mat[1][1]);
    }
}