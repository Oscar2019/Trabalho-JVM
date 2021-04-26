class f2i{
    public static void main(String[] args){
        float var1 = 3.1415f;
        int var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
        var1 = 3.4e38f;
        var2 = (int)var1;
        System.out.println(var1);
        System.out.println(var2);
    }
}