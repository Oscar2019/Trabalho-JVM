package java.lang;

public class InterruptedException extends Exception{
    InterruptedException(){
        super();
    }
    InterruptedException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/InterruptedException.java -d data/JavaLib/