class i2f{
    public static void main(String[] args){
        int var1 = 10;
        float var2 = (float)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 0x7FFFFFFF;
        var2 = (float)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}