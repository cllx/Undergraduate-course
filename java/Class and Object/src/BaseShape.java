public abstract class BaseShape implements Shape{
      protected double length;              
      protected double area;
      protected int id;
      static int counter = 1;
      public void init() {
          if(validate()) {    //判定是否合法形状
              calculate(); //计算面积、周长
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