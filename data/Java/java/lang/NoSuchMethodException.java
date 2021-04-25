package java.lang;

public class NoSuchMethodException extends ReflectiveOperationException{
    NoSuchMethodException(){
        super();
    }
    NoSuchMethodException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/NoSuchMethodException.java -d data/JavaLib/