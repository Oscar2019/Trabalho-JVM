class fib{
    public static int fib_s(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int ans = fib_s(n-1) + fib_s(n-2);
        System.out.print("fib_s(");
        System.out.print(n);
        System.out.print(") = ");
        System.out.println(ans); 
        return ans;
    }
    public static void main(String[] args){
        System.out.println(fib_s(0));
        System.out.println(fib_s(1));
        System.out.println(fib_s(2));
        System.out.println(fib_s(3));
        System.out.println(fib_s(4));
        System.out.println(fib_s(5));
        System.out.println(fib_s(10));
    }
}