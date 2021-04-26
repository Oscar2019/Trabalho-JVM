package java.lang;

public class SecurityException extends RuntimeException{
    SecurityException(){
        super();
    }
    SecurityException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/SecurityException.java -d data/JavaLib/