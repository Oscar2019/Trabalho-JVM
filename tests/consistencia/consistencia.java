class consistencia{
    
    public static void main(String[] args){
        Object o = "Olá mundo";
        System.out.println(o instanceof Object);
        System.out.println(o instanceof String);
        System.out.println(o instanceof Exception);
        System.out.println(o instanceof int[]);
        try{
            String s = (String) o;
            System.out.println(s);
            int[] m = (int[]) o;
        } catch(Exception e){
            System.out.println("cap");
        }
        o = null;
        System.out.println(o instanceof Object);
        System.out.println(o instanceof String);
        System.out.println(o instanceof Exception);
        System.out.println(o instanceof int[]);
        Object ob = new int[32][32];
        System.out.println(o instanceof Object);
        System.out.println(o instanceof Object[]);
        System.out.println(o instanceof Object[][]);
        System.out.println(o instanceof int[][]);
    }
}