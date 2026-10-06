class animal {
    int nolegs=4;

    public static void eat(){
        System.out.println("I am Eating");
    }
    public static void walk(){
        System.out.println("I am walking");
    }
}

class dog1 extends animal{
    Boolean canbark=true;
    public static int nolegs=5;
    public static void eat(){
        System.out.println("Dog  is Eating");
    }


}


public class third {
    public static void main(String[] args){
        dog1.eat(); 
        System.out.println(dog1.nolegs);
        dog1.eat();
        dog1.walk();

    }
}
