package java.lang;

public class NegativeArraySizeException extends RuntimeException{
    NegativeArraySizeException(){
        super();
    }
    NegativeArraySizeException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/NegativeArraySizeException.java -d data/JavaLib/