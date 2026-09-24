class animal {
    int nolegs=4;

    public static void eat(){
        System.out.println("I am Eating");
    }
    public static void walk(){
        System.out.println("I am walking");
    }
}

class dog extends animal{
    Boolean canbark=true;

}


public class five{
    public static void main(String[] args){
        dog obj=new dog();
        obj.eat();
        obj.walk();

    }
}

