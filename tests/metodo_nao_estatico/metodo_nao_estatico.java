class metodo_nao_estatico{
    public void ola(){
        System.out.println("Olá mundo!");
    }
    public static void main(String[] args){
        metodo_nao_estatico m = new metodo_nao_estatico();
        m.ola();
    }
}