abstract class Computer{
    abstract void turnoff();
    void turnon(){
        System.out.println("Turn on");
    }
}

class HP extends Computer{
    void turnon(){
        System.out.println("Turn on 1");
    }
    void turnoff(){
        System.out.println("Turn off");
    }
}







public class six {
    public static void main(String[] args){
        HP h=new HP();
        h.turnon();
        h.turnoff();
    }
}
