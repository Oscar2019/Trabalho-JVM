package java.io;

public class PrintStream{
    public static native void print_int(int value);   
    public static native void print_char(char value);   
    public static native void print_byte(byte value);   
    public static native void print_short(short value);   
    public static native void print_bool(boolean value);   
    public static native void print_long(long value);   
    public static native void print_float(float value);   
    public static native void print_double(double value);   
    // public static print_String(int value); 

    public void print(int value){
        print_int(value);
    }
    public void print(char value){
        print_char(value);
    }
    public void print(byte value){
        print_byte(value);
    }
    public void print(short value){
        print_short(value);
    }
    public void print(boolean value){
        print_bool(value);
    }
    public void print(long value){
        print_long(value);
    }
    public void print(float value){
        print_float(value);
    }
    public void print(double value){
        print_double(value);
    }
    // public void print(String value){
    //     print_int(value);
    // }
    
    public void println(int value){
        print_int(value);
        print_char('\n');
    }
    public void println(char value){
        print_char(value);
        print_char('\n');
    }
    public void println(byte value){
        print_byte(value);
        print_char('\n');
    }
    public void println(short value){
        print_short(value);
        print_char('\n');
    }
    public void println(boolean value){
        print_bool(value);
        print_char('\n');
    }
    public void println(long value){
        print_long(value);
        print_char('\n');
    }
    public void println(float value){
        print_float(value);
        print_char('\n');
    }
    public void println(double value){
        print_double(value);
        print_char('\n');
    }
    // public void println(String value){
    //     print_int(value);
    //     print_char('\n');
    // }
}

// javac -sourcepath data/Java/  data/Java/java/io/PrintStream.java -d data/JavaLib/