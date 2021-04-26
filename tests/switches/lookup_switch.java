class lookup_switch{
    public static void main(String[] args){
        int a = 42;
        switch(a){
            case 10:
                System.out.println("quarenta");
                break;
            case 12:
                System.out.println("quarenta e um");
                break;
            case 42:
                System.out.println("quarenta e dois");
                break;
            default:
                System.out.println("deafult");
                break;
        }
        switch(a){
            case 10:
                System.out.println("dez");
                break;
            case 12:
                System.out.println("doze");
                break;
            case 43:
                System.out.println("quarenta e três");
                break;
            default:
                System.out.println("deafult2");
                break;
        }
    }
}