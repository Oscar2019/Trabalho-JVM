class interface_equal_meth3{
    public void meth1(){
        System.out.println(1);
    }
    public void meth2(){
        System.out.println(2);
    }
    public void meth3(){
        System.out.println(14);
    }
}
interface interface_equal_meth2{
    void meth3();
    void meth4();

}
class interface_equal_meth1 extends interface_equal_meth3 implements interface_equal_meth2{
    public void meth2(){
        System.out.println(3);
    }
    public void meth4(){
        System.out.println(5);
    }
    public static void main(String[] args){
        interface_equal_meth1 o1 = new interface_equal_meth1();
        o1.meth1();
        o1.meth2();
        o1.meth3();
        o1.meth4();
        interface_equal_meth2 o2 = o1;
        o2.meth3();
        o2.meth4();
        interface_equal_meth3 o3 = o1;
        o3.meth1();
        o3.meth2();
        o3.meth3();
        o3 = new interface_equal_meth3();
        o3.meth1();
        o3.meth2();
        o3.meth3();
    }
}