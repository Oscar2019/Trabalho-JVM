package java.lang;

public class IllegalMonitorStateException extends RuntimeException{
    IllegalMonitorStateException(){
        super();
    }
    IllegalMonitorStateException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/IllegalMonitorStateException.java -d data/JavaLib/