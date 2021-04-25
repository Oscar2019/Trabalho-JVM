package java.lang;

public class ArrayIndexOutOfBoundsException extends IndexOutOfBoundsException{
    ArrayIndexOutOfBoundsException(){
        super();
    }
    ArrayIndexOutOfBoundsException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ArrayIndexOutOfBoundsException.java -d data/JavaLib/