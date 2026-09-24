class animal1 {
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
    int nolegs=5;
    public static void eat(){
        System.out.println("Dog  am Eating");
    }


}


public class third {
    public static void main(String[] args){
        dog1 obj=new dog1();
        System.out.println(obj.nolegs);
        obj.eat();
        obj.walk();

    }
}
