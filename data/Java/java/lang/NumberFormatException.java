package java.lang;

public class NumberFormatException extends IllegalArgumentException{
    NumberFormatException(){
        super();
    }
    NumberFormatException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/NumberFormatException.java -d data/JavaLib/