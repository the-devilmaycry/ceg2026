class polymor{
    void display(){
        System.out.println("Iam a void function");
    }
    void display(int a){
        System.out.println(a);

    }
}

public class four {
    public static void main(String[] args){
        polymor pol=new polymor();
        pol.display();
        pol.display(3);
    }
}
