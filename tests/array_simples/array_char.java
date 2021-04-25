class array_char{
    public static void main(String[] args){
        char[] vet = new char[5];
        vet[0] = '1';
        vet[1] = 'ç';
        vet[2] = '木';
        vet[3] = 't';
        vet[4] = 'ã';
        System.out.print("array length: ");
        System.out.println(vet.length);
        System.out.println(vet[0]);
        System.out.println(vet[1]);
        System.out.println(vet[2]);
        System.out.println(vet[3]);
        System.out.println(vet[4]);
    }
}