package java.lang;

public class ArrayStoreException extends RuntimeException{
    ArrayStoreException(){
        super();
    }
    ArrayStoreException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/ArrayStoreException.java -d data/JavaLib/