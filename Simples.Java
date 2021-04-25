class Simples{
    public static void main(String[] args){
        System.out.println(123);
        Object object = (Object)new String();
        String str = (String)object;
        int[][] mat = new int[10][10];
        String[][] mat2 = new String[10][10];
        mat2[0][0] = new String();

        System.out.println(str instanceof String);
        System.out.println(str instanceof Object);
        System.out.println(mat instanceof Object);
        System.out.println(mat2 instanceof Object);
        System.out.println(mat2 instanceof Object[]);
        System.out.println(mat2 instanceof Object[][]);
        System.out.println(mat2[0] instanceof Object);
        System.out.println(mat2[0] instanceof Object[]);
        System.out.println(object instanceof Simples);
        System.out.println(mat2 instanceof String[][]);
        System.out.println(mat2[0][0] instanceof String);
        // System.out.println("Olá Mundo!𝄞木");
        // // try{
        // //     int[] vet = new int[1];
        // //     int a = vet[1];
        // //     System.out.println(a);
        // // } catch(NullPointerException e){
        // //     System.out.println("2");
        // // } finally{
        // //     System.out.println("3");
        // // }
        // try{
        //     Object[] mat = new Object[10][][];
        //     mat[0] = new Object[10];
        // } catch(ArrayStoreException e){
        //     System.out.println(123);
        // }
        // mat[0][0] = new int[10];
        // mat[0][0][0] = 1000;
        
        // int[][] mat1 = new int[2][3];
        // int[][] mat2 = new int[2][];
        // // Integer[] mat3 = new Integer[2];
        // // Object[] mat3 = (Object[])mat2;
        // // try{
        // //     mat3[1] = new Integer[2][2];
        // // } catch(Exception e){
        // //     System.out.println(e.getMessage());
        // // }
        // mat1[0][0] = 1;
        // mat1[0][1] = 2;
        // mat1[0][2] = 3;
        // mat1[1][0] = 4;
        // mat1[1][1] = 5;
        // mat1[1][2] = 6;
        // System.out.println(mat1[0][0]);
        // System.out.println(mat1[0][1]);
        // System.out.println(mat1[0][2]);
        // System.out.println(mat1[1][0]);
        // System.out.println(mat1[1][1]);
        // System.out.println(mat1[1][2]);
        // // System.out.println('\n');
        // // int[] pontoInt = {-1, 0, 1, 2, 3, 4, 5, 6};
        // // System.out.println(pontoInt[0]);
        // // System.out.println(pontoInt[1]);
        // // System.out.println(pontoInt[2]);
        // // System.out.println(pontoInt[3]);
        // // System.out.println(pontoInt[4]);
        // // System.out.println(pontoInt[5]);
        // // System.out.println(pontoInt[6]);
        // // System.out.println(pontoInt[7]);
        // // long[] pontoLong = {-1L, 0L, 1L, 2L, 8589934591L};
        // // System.out.println(pontoLong[0]);
        // // System.out.println(pontoLong[1]);
        // // System.out.println(pontoLong[2]);
        // // System.out.println(pontoLong[3]);
        // // System.out.println(pontoLong[4]);
        // // float[] pontoFloat = {-1.0f, 0.0f, 1.0f, 2.0f, 3.14f};
        // // System.out.println(pontoFloat[0]);
        // // System.out.println(pontoFloat[1]);
        // // System.out.println(pontoFloat[2]);
        // // System.out.println(pontoFloat[3]);
        // // System.out.println(pontoFloat[4]);
        // // double[] pontoDouble = {-1.0, 0.0, 1.0, 2.0, 3.14};
        // // System.out.println(pontoDouble[0]);
        // // System.out.println(pontoDouble[1]);
        // // System.out.println(pontoDouble[2]);
        // // System.out.println(pontoDouble[3]);
        // // System.out.println(pontoDouble[4]);
        // // short[] pontoShort = {-1, 0, 1, 2};
        // // System.out.println(pontoShort[0]);
        // // System.out.println(pontoShort[1]);
        // // System.out.println(pontoShort[2]);
        // // System.out.println(pontoShort[3]);
        // // byte[] pontoByte = {-1, 0, 1, 2};
        // // System.out.println(pontoByte[0]);
        // // System.out.println(pontoByte[1]);
        // // System.out.println(pontoByte[2]);
        // // System.out.println(pontoByte[3]);
        // // boolean[] pontoBool = {true, false};
        // // System.out.println(pontoBool[0]);
        // // System.out.println(pontoBool[1]);
        // // char[] pontoChar = {'O', 'l', 'á'};
        // // System.out.println(pontoChar[0]);
        // // System.out.println(pontoChar[1]);
        // // System.out.println(pontoChar[2]);
        // // System.out.println('\n');
        // // // Object[] mat = new int[2][4];
        // // // System.out.println(mat.length);
        // // System.out.println(pontoInt.length);
        // // System.out.println(pontoLong.length);
        // // System.out.println(pontoFloat.length);
        // // System.out.println(pontoDouble.length);
        // // System.out.println(pontoShort.length);
        // // System.out.println(pontoByte.length);
        // // System.out.println(pontoBool.length);
        // // System.out.println(pontoChar.length);
        // // // int[][] met2 = (int[][])mat;
        // // // mat[0] = new Integer[12];
        // // // met2.toString();
        // // // met2[0][0] = 1;
        // // // // Object mat2 = mat;
        // // // System.out.println(mat instanceof Object[][]);
        // // // // System.out.println(mat.toString());
        // // // // System.out.println(mat[0].toString());
        // // // // System.out.println(mat[1].toString());
        // // // // System.out.println(mat[2].toString());
        // // // // System.out.println(mat[0].toString());
    }
}