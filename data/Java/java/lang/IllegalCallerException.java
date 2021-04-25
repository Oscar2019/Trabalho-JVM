package java.lang;

public class IllegalCallerException extends RuntimeException{
    IllegalCallerException(){
        super();
    }
    IllegalCallerException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalCallerException.java -d data/JavaLib/