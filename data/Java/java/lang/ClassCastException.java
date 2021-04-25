package java.lang;

public class ClassCastException extends RuntimeException{
    ClassCastException(){
        super();
    }
    ClassCastException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ClassCastException.java -d data/JavaLib/