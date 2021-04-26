class if_icmpge{
    public static void main(String[] args){
        int a = 42;
        if(a < 42){
            System.out.println("Naruto1");
        } else{
            System.out.println("Sasuke1");
        }
        if(a < 43){
            System.out.println("Naruto1");
        } else{
            System.out.println("Sasuke1");
        }
        if(a < 42){
            System.out.println("Naruto3");
        }
        if(a < 43){
            System.out.println("Naruto4");
        }
        System.out.println("Sakura");
    }
}