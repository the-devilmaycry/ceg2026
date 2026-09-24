//Static Keyword
// For Methods
 // without creating an object , we can directly access the method using class name.

// For Variable
//Same variable and its value is used for both the inherited classes
// Change in one affects other like it is common variable

//


class father1 {
    static int nolegs=4;
    static int age =18;

    static void eat(){
        System.out.println("I am Eating");
    }
    static void walk(){
        System.out.println("I am walking");
    }
}
class dau extends father1{


}




public class eight {
    public static void main(String[] args){
        System.out.println(father1.nolegs);
        father1.eat();
        System.out.println(father1.age);
        dau.age=12;
        System.out.println(father1.age);

    }
}
