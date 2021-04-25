package java.lang;

public class IllegalThreadStateException extends IllegalArgumentException{
    IllegalThreadStateException(){
        super();
    }
    IllegalThreadStateException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalThreadStateException.java -d data/JavaLib/