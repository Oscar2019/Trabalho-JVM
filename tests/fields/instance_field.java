class instance_field{
    public boolean var01; 
    public byte var02; 
    public char var03; 
    public double var04; 
    public float var05; 
    public int var06; 
    public long var07; 
    public short var08; 
    public String var09; 
    public static void main(String[] args){
        instance_field instf = new instance_field();
        instf.var01 = true; 
        instf.var02 = 12; 
        instf.var03 = 'O'; 
        instf.var04 = 3.14; 
        instf.var05 = 1.2f; 
        instf.var06 = 5; 
        instf.var07 = 1000000007; 
        instf.var08 = 100; 
        instf.var09 = "Quero um 10!"; 
        System.out.println(instf.var01);
        System.out.println(instf.var02);
        System.out.println(instf.var03);
        System.out.println(instf.var04);
        System.out.println(instf.var05);
        System.out.println(instf.var06);
        System.out.println(instf.var07);
        System.out.println(instf.var08);
        System.out.println(instf.var09);
    }
}