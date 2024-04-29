public class Demo {

  int val;
  String name;

  public static void main(String[] args) {

    Demo d = new Demo();
    Demo d2 = new Demo();

    d.val = 10;
    d.name = "Adwitiya";
    
    // * The below line, will change the reference of d2, 
    // * from an object that it was initally pointing to object d
    // * so, now the initally pointed object is lost and eligible for GARBAGE_COLLECTION
    d2 = d;

    d2.val = 20;

    System.out.println(d.val);
    System.out.println(d2.val);
  }
}