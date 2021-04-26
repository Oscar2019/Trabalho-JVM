package java.lang;

public class IllegalAccessException extends ReflectiveOperationException{
    IllegalAccessException(){
        super();
    }
    IllegalAccessException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalAccessException.java -d data/JavaLib/