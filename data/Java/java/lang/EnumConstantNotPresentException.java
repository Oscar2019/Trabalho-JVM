package java.lang;

public class EnumConstantNotPresentException extends RuntimeException{
    EnumConstantNotPresentException(){
        super();
    }
    EnumConstantNotPresentException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/EnumConstantNotPresentException.java -d data/JavaLib/