interface invokeinterface2{
    void meth1();
    void meth2();

}
class invokeinterface1 implements invokeinterface2{
    public void meth1(){
        System.out.println(3);
    }
    public void meth2(){
        System.out.println(4);
    }
    public static void main(String[] args){
        invokeinterface2 o2 = new invokeinterface1();
        o2.meth1();
        o2.meth2();
    }
}