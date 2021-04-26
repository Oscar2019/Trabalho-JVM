class operacoes_retorno{
    public static int retInt(){
        return 2;
    }
    public static long retLong(){
        return 1000000007;
    }
    public static float retFloat(){
        return 3.14f;
    }
    public static double retDouble(){
        return 3.1415;
    }
    public static String retString(){
        return "Por favor me passe nessa matéria";
    }
    public static void main(String[] args){
        System.out.println(retInt());
        System.out.println(retLong());
        System.out.println(retFloat());
        System.out.println(retDouble());
        System.out.println(retString());
    }
}