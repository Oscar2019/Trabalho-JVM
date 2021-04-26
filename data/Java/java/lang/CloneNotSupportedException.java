package java.lang;

public class CloneNotSupportedException extends Exception{
    CloneNotSupportedException(){
        super();
    }
    CloneNotSupportedException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/CloneNotSupportedException.java -d data/JavaLib/