package java.lang;

public class IllegalStateException extends RuntimeException{
    IllegalStateException(){
        super();
    }
    IllegalStateException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalStateException.java -d data/JavaLib/