class d2i{
    public static void main(String[] args){
        double var1 = 3.1415;
        int var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 1.7e308;
        var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}