class array_byte{
    public static void main(String[] args){
        byte[] vet = new byte[7];
        vet[0] = 12;
        vet[1] = 14;
        vet[2] = 15;
        vet[3] = 23;
        vet[4] = 100;
        vet[5] = -123;
        vet[6] = 123;
        System.out.print("array length: ");
        System.out.println(vet.length);
        System.out.println(vet[0]);
        System.out.println(vet[1]);
        System.out.println(vet[2]);
        System.out.println(vet[3]);
        System.out.println(vet[4]);
        System.out.println(vet[5]);
        System.out.println(vet[6]);
    }
}