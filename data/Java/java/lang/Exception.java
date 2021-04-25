package java.lang;

public class Exception extends Throwable{
    Exception(){
        super();
    }
    Exception(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/Exception.java -d data/JavaLib/