package java.lang;

public class RuntimeException extends Exception{
    RuntimeException(){
        super();
    }
    RuntimeException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/RuntimeException.java -d data/JavaLib/