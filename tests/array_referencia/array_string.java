class array_string{
    public static void main(String[] args){
        String[][] vet = new String[2][2];
        vet[0][0] = "Olá mundo";
        vet[0][1] = "Hello world";
        vet[1][0] = "Hola mundo";
        vet[1][1] = "Bonjour le monde";
        System.out.println(vet[0][0]);
        System.out.println(vet[0][1]);
        System.out.println(vet[1][0]);
        System.out.println(vet[1][1]);
    }
}