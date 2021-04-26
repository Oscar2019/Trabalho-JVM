package java.lang;

public class TypeNotPresentException extends RuntimeException{
    TypeNotPresentException(){
        super();
    }
    TypeNotPresentException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/TypeNotPresentException.java -d data/JavaLib/