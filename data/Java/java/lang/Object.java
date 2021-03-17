package java.lang;

class Object{
    
    public static native void println(int value);
    
    public static void main(Object[] args){
        println(5);
    }
}