class bank{
    private int code;
    private String password;

    bank(){
       this.password="hey";
       this.code=12;
    }
     bank(String pass){
        this.password=pass;
    }
    void setter(String name,String var){
        if (name==password){

            this.password=var;

        }else {
            System.out.println("you are not admin");
        }
    }
     public String getter(){
        return password;
    }


}
public class Q1 {
    public static void main(String[] args) {
        bank obj1= new bank("siraj");
//        obj1.setter("bashir","khan");
        obj1.setter("siraj","ali");
        System.out.println(obj1.getter());
    }
}