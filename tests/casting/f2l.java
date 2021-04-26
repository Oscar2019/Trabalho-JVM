class f2l{
    public static void main(String[] args){
        float var1 = 3.1415f;
        long var2 = (long)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 3.4e38f;
        var2 = (long)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}