package java.lang;

public class StringIndexOutOfBoundsException extends IndexOutOfBoundsException{
    StringIndexOutOfBoundsException(){
        super();
    }
    StringIndexOutOfBoundsException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/StringIndexOutOfBoundsException.java -d data/JavaLib/