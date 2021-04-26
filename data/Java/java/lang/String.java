package java.lang;

public class String{
    private final char[] value;

    String(){
        value = null;
    }

    String(char[] string){
        value = string;
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/String.java -d data/JavaLib/