package java.lang;

public class LayerInstantiationException extends RuntimeException{
    LayerInstantiationException(){
        super();
    }
    LayerInstantiationException(String message){
        super(message);
    }
    
}
// javac -sourcepath data/Java/  data/Java/java/lang/LayerInstantiationException.java -d data/JavaLib/