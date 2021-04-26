package java.lang;

public class ArithmeticException extends RuntimeException{
    ArithmeticException(){
        super();
    }
    ArithmeticException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ArithmeticException.java -d data/JavaLib/