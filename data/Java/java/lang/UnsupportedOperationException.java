package java.lang;

public class UnsupportedOperationException extends RuntimeException{
    UnsupportedOperationException(){
        super();
    }
    UnsupportedOperationException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/UnsupportedOperationException.java -d data/JavaLib/