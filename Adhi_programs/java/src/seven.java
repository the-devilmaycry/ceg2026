interface father{
    abstract void call();
    abstract void talk();
}

interface Mother{
    abstract void call();
    abstract void talk();
}


class Interface implements father,Mother{
    //Public is used in interface
    public void call(){
        System.out.println("Calling");
    }
    public void talk(){
        System.out.println("talking");
    }
}





public class seven {

    public static void main(String[] args) {
        Interface h = new Interface();
        h.call();
        h.talk();
    }
}