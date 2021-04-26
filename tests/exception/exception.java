class exception2 extends Exception{
    private String value;
    exception2(String value){
        this.value = value;
    }
    public String getMessage(){
        return value;
    }
}

class exception1{
    public static void setIdade(int age) throws exception2{
        if(age < 0){
            throw new exception2("Idade menor que 0");
        }
    }
    public static void main(String[] args){
        try{
            setIdade(-1);
        } catch(exception2 e){
            System.out.println(e.getMessage());
        }
    }
}