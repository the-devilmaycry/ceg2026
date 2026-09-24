public class helloworld {
    public static void main(String[] args){
        int r=natprint(5);
        System.out.println(r);
        }
       public static int natprint(int n){
        if (n==1){
            return 1;
        }
        else {
            return (n * natprint(n-1));


        }
         
    }
}
