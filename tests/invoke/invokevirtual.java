class invokevirtual{
    public void meth1(){
        System.out.println(3);
    }
    public void meth2(){
        System.out.println(4);
    }
    public static void main(String[] args){
        invokevirtual o2 = new invokevirtual();
        o2.meth1();
        o2.meth2();
    }
}
