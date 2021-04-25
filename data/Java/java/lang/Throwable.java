package java.lang;

public class Throwable{
    private final String detailMessage;
    Throwable(){
        detailMessage = null;
    }
    Throwable(String message){
        detailMessage = message;
    }
    String getMessage(){
        return detailMessage;
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/Throwable.java -d data/JavaLib/