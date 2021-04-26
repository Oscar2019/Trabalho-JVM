package java.lang;

public class ClassNotFoundException extends ReflectiveOperationException{
    ClassNotFoundException(){
        super();
    }
    ClassNotFoundException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ClassNotFoundException.java -d data/JavaLib/