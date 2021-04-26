class animal{
    protected String som;
    protected String nome;
    animal(String nome, String som){
        this.nome = nome;
        this.som = som;
    }
    public void emiteSom(){
        System.out.println(som);
    }
}
class gato extends animal{
    gato(String nome){
        super(nome, "mial");
    }
    public void emiteSom(){
        System.out.print(nome);
        System.out.print(": ");
        super.emiteSom();
    }

}
class cao extends animal{
    cao(String nome){
        super(nome, "au au");
    }
    public void emiteSom(){
        System.out.print(nome);
        System.out.print(": ");
        super.emiteSom();
    }

}
class heranca {
    public static void main(String[] args){
        gato g = new gato("Mimi");
        cao c = new cao("Toto");
        g.emiteSom();
        c.emiteSom();
    }
}