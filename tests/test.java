class Class01{
    public int x = 0;
    int asddsax = 0;
    public static int as = Class04.asas;
    public static Class04 asdfh = new Class04();
    Class01(){
        x = 3;
    }
    public int met01(){
        System.out.print(x);
        ;;;;;;;;;;;
        return 0;
    }
    public void met04(){
        Class01 c = new Class01();
    }
    private int met02(){return 0;}
}
interface Class02{
    public int met01();
    public int met03();
}
class Class04 extends Class01 implements Class02{
    int x = 3;
    // public int met01(){return 0;}
    public static int asas = Class01.as;
    public static Class01 asaassa = new Class01();
    Class04(){
        x = 3;
    }
    public int met02(){
        System.out.print(asas);
        return 0;
    }
    public int met03(){
        return 0;
    }
    public int met09(int[] a, String b, long f){
        return 0;
    }
    public static void main(String[] args){
        Class02 c = new Class04();
        Class04 c1 = (Class04)c;
        c1.met02();
        int[] vat = new int[123];
        Class04.asaassa.met01();
        Class01.asdfh.met01();
        int x = vat.length;
        // c.met01();
        c.met01();
    }
}