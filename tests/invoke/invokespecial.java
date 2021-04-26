class invokespecial{
    private void meth1(){
        System.out.println(3);
    }
    public void meth2(){
        meth1();
    }
    public static void main(String[] args){
        invokespecial o1 = new invokespecial();
        o1.meth1();
        o1.meth2();
    }
}
