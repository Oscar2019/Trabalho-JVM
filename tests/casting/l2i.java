class l2i{
    public static void main(String[] args){
        long var1 = 10;
        int var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 1000000000000000000L;
        var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}