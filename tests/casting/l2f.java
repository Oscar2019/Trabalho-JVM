class l2f{
    public static void main(String[] args){
        long var1 = 10;
        float var2 = (float)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 1000000000000000000L;
        var2 = (float)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}