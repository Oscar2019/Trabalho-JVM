package java.lang;

public class InstantiationException extends ReflectiveOperationException{
    InstantiationException(){
        super();
    }
    InstantiationException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/InstantiationException.java -d data/JavaLib/