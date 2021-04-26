package java.lang;

public class IllegalArgumentException extends RuntimeException{
    IllegalArgumentException(){
        super();
    }
    IllegalArgumentException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalArgumentException.java -d data/JavaLib/