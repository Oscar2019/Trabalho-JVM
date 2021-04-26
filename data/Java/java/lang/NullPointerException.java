package java.lang;

public class NullPointerException extends RuntimeException{
    NullPointerException(){
        super();
    }
    NullPointerException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/NullPointerException.java -d data/JavaLib/