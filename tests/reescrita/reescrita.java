class reescrita2{
    public void print(int var1){
        System.out.println(var1);
    }
    public void print(long var1){
        System.out.println(var1);
    }
}
class reescrita1{
    public void print(int var1){
        System.out.println(var1*3);
    }
    public void print(long var1){
        System.out.println(var1*4);
    }
    public static void main(String[] args){
        reescrita1 r = new reescrita1();
        r.print(123);
        r.print(123L);
    }
}