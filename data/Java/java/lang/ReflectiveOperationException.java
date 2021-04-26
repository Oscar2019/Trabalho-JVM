package java.lang;

public class ReflectiveOperationException extends Exception{
    ReflectiveOperationException(){
        super();
    }
    ReflectiveOperationException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ReflectiveOperationException.java -d data/JavaLib/