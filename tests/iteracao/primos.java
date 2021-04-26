class primos{
    public static void main(String[] args){
        int[] crivo = new int[100];
        int[] primo = new int[100];
        int ind = 0;
        for(int i = 2; i < 100; i++){
            if(crivo[i] == 0){
                primo[ind] = i;
                ind++;
                for(int j = i + i; j < 100; j += i){
                    crivo[j] = 1;
                }
            }
        }
        for(int i = 0; i < ind; i++){
            if(i + 1 == ind){
                System.out.println(primo[i]);
            } else{
                System.out.print(primo[i]);
                System.out.print(' ');
            }
        }
    }
}