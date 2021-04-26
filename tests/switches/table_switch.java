class table_switch{
    public static void main(String[] args){
        int a = 42;
        switch(a){
            case 40:
                System.out.println("quarenta");
                break;
            case 41:
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
            case 39:
                System.out.println("trinta e nove");
                break;
            case 40:
                System.out.println("quarenta");
                break;
            case 41:
                System.out.println("quarenta e um");
                break;
            default:
                System.out.println("deafult");
                break;
        }
    }
}