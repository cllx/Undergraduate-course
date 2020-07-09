public abstract class BaseShape implements Shape{
      protected double length;              
      protected double area;
      protected int id;
      static int counter = 1;
      public void init() {
          if(validate()) {    //�ж��Ƿ�Ϸ���״
              calculate(); //����������ܳ�
          }
      }              
      public double getLength() {
          return length;
      }              
      public double getArea() {
          return area;
      }              
      public boolean validate() {
           return true;
      }              
      protected abstract void calculate();
      public int getId() {
          return id;
     }
}