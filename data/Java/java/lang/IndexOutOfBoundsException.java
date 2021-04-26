package java.lang;

public class IndexOutOfBoundsException extends RuntimeException{
    IndexOutOfBoundsException(){
        super();
    }
    IndexOutOfBoundsException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IndexOutOfBoundsException.java -d data/JavaLib/