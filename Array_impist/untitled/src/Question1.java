import java.util.Scanner;

class Test{
private String w_name;
private  int w_hours_worked;
private  double w_hours_wage;

//default constructor
    Test(){
        String w_name=null;
        int w_hours_worked = 0;
        double w_hourly_wage=0.0;
    }
//     parametrized constructor

    Test(String name,int hours, double wage){
        this.w_name=name;
        this.w_hours_worked=hours;
        this.w_hours_wage=wage;
    }

    public void set_name(String name){
        this.w_name=name;
    }
    public void set_W_hours_worked(int hour){
        if (!(hour<0)) {
            this.w_hours_worked = hour;
        }else {
            System.out.println("working hours cannot be negative ");
        }
    }
    public void set_w_hours_wage(double rate){
        if (!(rate<0)) {
            this.w_hours_wage = rate;
        }else {
            System.out.println("Wage cannot be negative");

        }
    }
    String get_name(){
        return w_name;
    }
    int get_hours_worked(){
        return w_hours_worked;
    }
    double get_hours_wage(){
        return w_hours_wage;
    }
    public double calculate_pay(){
        double pay=w_hours_worked*w_hours_wage;

        if (w_hours_worked > 40.0) {
            pay = pay + (0.5 * w_hours_wage * (w_hours_worked - 40));

        }
        return pay;
    }

}
public class Question1 {
    public static void main(String[] args) {
        Test worker1 = new Test();
        Test worker2= new Test();
        Test worker3;

        while (true){
            System.out.println("Enter 1 to enter the details of worker 1:  ");
            System.out.println("Enter 2 to enter the details of worker 2:  ");
            System.out.println("Enter 3 to get the details of worker 1:  ");
            System.out.println("Enter 4 to get the details of worker 2:  ");
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            switch (n){
                case 1:
                    System.out.println("enter the name");
                    worker1.set_name(sc.next());
                    System.out.println("enter the  hours worked ");
                    worker1.set_W_hours_worked(sc.nextInt());
                    System.out.println("enter the hourly wage");
                    worker1.set_w_hours_wage(sc.nextDouble());
                    break;
                case 2:
                    System.out.println("enter the name");
                    worker2.set_name(sc.next());
                    System.out.println("enter the  hours worked ");
                    worker2.set_W_hours_worked(sc.nextInt());
                    System.out.println("enter the hourly wage");
                    worker2.set_w_hours_wage(sc.nextDouble());
                    break;
                case 3:
                    System.out.println("Name:" + worker1.get_name()+"\tPay is " + worker1.calculate_pay());
                    System.out.println("\t\t\t****\t\t\t");
                    break;
                case 4:
                    System.out.println("Name:" + worker2.get_name()+"\tPay is " + worker2.calculate_pay());
                    System.out.println("\t\t\t****\t\t\t");
                    break;
                default:
                    System.out.println("Wrong input ");
                    return;
            }

        }
    }
}
