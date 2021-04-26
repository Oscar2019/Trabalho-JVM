package java.lang;

public class NoSuchFieldException extends ReflectiveOperationException{
    NoSuchFieldException(){
        super();
    }
    NoSuchFieldException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/NoSuchFieldException.java -d data/JavaLib/