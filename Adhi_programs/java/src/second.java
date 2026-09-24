class appform{
    String name;
    int rollno;

    public void display(){
        System.out.println(name);
        System.out.println(rollno);
    }
    public void setname(String str,int num){
        name=str;
        rollno=num;

    }
}

public class second {
    public static void main(String[] args) {
        appform codeio = new appform();
        codeio.setname("Adhii",15);
        codeio.display();
    }
}